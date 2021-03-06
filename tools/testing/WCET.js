"use strict";
class Node {
    constructor(){
        this.power = "";
        this.overhead = 0;
        this.isbranch = false;
        this.outedge = [];
        this.nodeno = -1;
        this.instructions = [];
        this.linestart = -1;
        this.lineend = -1;
        this.time = 0;
    }
    get_classname(){
        return "Node";
    }
    add_instruction(i){
        this.instructions.push(i)
    }
    addedge(edge){
        this.outedge.push(edge)
    }
    display(){
        console.log("block number " + this.nodeno + " (starts at " + this.linestart + " ends at " + this.lineend + " time taken is " + this.time + " )");
        console.log("Instructions are ");
        this.instructions.forEach(function(i){
            i.display();
        });
    }
    split(to){
        if (this.instructions[0].lineno == to){
            return false;
        }
        var flag = true;
        var node = new Node();
        var count = 0;
        var temp = [];
        var refer = this;
        temp = refer.instructions.slice();  
        temp.forEach(function(i){
            if (flag){
                if (i.lineno == to){
                    flag = false;
                    refer.instructions = temp.slice(0,count);
                    node.add_instruction(i);
                    node.linestart = i.lineno;
                    node.lineend = i.lineno;
                    linetonode[i.lineno] = node;
                    return;
                }
                refer.lineend = i.lineno;
                count = count + 1;
            }
            else{
                node.lineend = i.lineno;
                node.add_instruction(i);
                linetonode[i.lineno] = node;
            }
        });
        path.splice(path.indexOf(this)+1,0,node);
        return true;
    }
}
class Instruction{
    constructor(){
        this.isfloat = false;
        this.time = 0;
        this.command = "";
        this.to = -1;
        this.lineno = 0;
    }
    get_classname(){
        return "Instruction";
    }
    display(){
        console.log("| --> " + this.command + " " + this.time + " " + this.lineno);
    }
}
var visited;
var linetonode = {};
var path = [];
var node = new Node();
var startnode = new Node();
var readlines = [];
var adjlist;
var count;
var debug;
var jumpstatements;
var overhead;
function init(){
    path = [];
    node = new Node();
    startnode = new Node();
    readlines = [];
    linetonode = {};
}
function countwords(words,c){
    var temp = 0;
    words.forEach(function(el){
        if (el == c){
            temp = temp + 1;
        }
    });
    return temp;
}
function isjump(word){
    word = word.toUpperCase();
    if (word == "B"){
        return true;
    }
    var iter = 0;
    while (iter < jumpstatements.length){
        if (word.includes(jumpstatements[iter]) && !word.includes("SBCS")){
            return true;
        }
        iter = iter + 1;
    }
    return false;
}   
function variabletime(word,words){
    var time = 0;
    if (word.toUpperCase() == "PUSH"){
        time = 1 + countwords(words,',');
    }    
    if (word.toUpperCase() == "POP"){
        if (word.toUpperCase().search("PC") != -1){
            time = 3 + countwords(words,',');
        }
        else{
            time = 1 + countwords(words,',');
        }
    }
    if (word.toUpperCase() == "ADD"){
        if (word.toUpperCase().search("PC") != -1){
            time = 2;
        }
        else{
            time = 1;
        }
    }
    return time;
}
function removediscriminators(line){
    if (!line.includes("discriminator")){
        return line;
    }
    var iter = line.length - 1;
    while (iter >= 0 && line[iter] != '('){
        iter = iter - 1;
    }
    line = line.slice(0,iter);
    return line;
}
//main code starts from here
exports.analyseWCET = function(filename,source,arch,debugflag){
    init();
    debug = debugflag;
    var power;
    var fs = require('fs');
    var asm = JSON.parse(fs.readFileSync(__dirname + "/arch/"+arch+".json",'utf8'));
    jumpstatements = asm['jumpstatements'];
    overhead = asm['overhead'];
    var floatdata = asm['extern'];
    var code = source.code.split('\n');
    //console.log(code);
    // var lineReader = require('readline').createInterface({
    //     input: require('fs').createReadStream('code.asm')
    // });
    code.forEach(function (line) {
        if (!line || line.trim() == "..."){
            return;
        }
        line = removediscriminators(line);
        if (line.indexOf(filename) != -1){
            //finding out if the line is not code but is used to denote line numbers
            var iter = line.length - 1;
            var filelineno = "";
            while (line[iter] != ":"){
                filelineno = line[iter] + filelineno;
                iter--;
            }
            filelineno = filelineno.trim();
            if (filelineno in source['lines']){
                power = source['lines'][filelineno];
            }
            return;
        }
        var isfloat = false;
        var floatop;
        //checks whether a floting point operation is called
        for (var op in floatdata){
            if (line.indexOf(op) != -1){
                isfloat = true;
                floatop = op;
            }
        }
        var separators = [' ','\t'];
        var words = line.split(new RegExp(separators.join('|'), 'g'));
        var lineno;
        var iter = 0;
        //gets line no of the line
        while (iter < words.length){
            if (words[iter] != "" && words[iter] != " "){
                if (words[iter][words[iter].length-1] == ":"){
                    lineno = words[iter].slice(0,-1);
                }
                else{
                    lineno = words[iter];
                }
                break;                
            }
            iter = iter + 1;
        }
        //finds the command in the line
        var time = 0;
        var command = "";
        var flag = false;
        words.forEach(function(word){
            if (word.includes('.') && word != "" && word != " "){
                //commands might be like BNE.N so removing the .N
                var templist = word.split('.');
                words[words.indexOf(word)] = templist[0];
                word = templist[0]
            }
            if (word.toUpperCase() in asm['fixed']){
                flag = true;
                command = word;
                time = asm['fixed'][word.toUpperCase()];
            }
            if (asm['variable'].indexOf(word.toUpperCase()) != -1){
                flag = true;
                command = word;
                time = variabletime(word,words);
            }
        });
        if (flag){
            var i = new Instruction();
            i.lineno = lineno;
            i.time = time;
            i.command = command;
            if (i.command == "ldr" && line.includes('[') && line.includes(']')){
                i.time = i.time + 1;
            }
            if (i.command == "str"){
                i.time = i.time + 1;
            }
            if (isjump(command)){
                if (node.instructions.length != 0){
                    //finding out if there is a simple block above the jmp statement
                    path.push(node);
                }
                i.to = words[words.indexOf(i.command) + 1];
                if (i.to == "0"){
                    return;
                }
                //console.log("going to " + i.to);
                if (isfloat){
                    i.isfloat = true;
                    i.time = floatdata[floatop];
                }
                //creating a new block for the jmp statement
                node = new Node();
                node.add_instruction(i);
                node.isbranch = true;

                if (isfloat || typeof power === "undefined"){
                    //if the jmp statement is a compiler generated one or floating point operation
                    node.power = 1;
                    node.overhead = overhead;
                }
                else{
                    node.power = power;
                    //console.log("power is " + power);
                    node.overhead = power*overhead;
                    //console.log("overhead is " + node.overhead);
                    power = undefined;
                }
                node.linestart = i.lineno;
                node.lineend = i.lineno;
                linetonode[i.lineno] = node;
                path.push(node);
                node = new Node();
            }
            else{
                if (node.linestart == -1){
                    node.linestart = lineno;
                }
                node.lineend = lineno;
                linetonode[lineno] = node;
                node.add_instruction(i);
            }
        }
    });
    
    if (node.instructions.length != 0){
        //finding out if there is a last block
        path.push(node);
    }
    return splitblocks();
}
function splitblocks(){
    var i = 0;
    var flag;
    while (i < path.length){
        var obj = path[i];
        if (obj.isbranch){
            if (obj.instructions[0].to in linetonode){
                //finding out if the jmp statement points to a existing mem address
                flag = linetonode[obj.instructions[0].to].split(obj.instructions[0].to);
                if (readlines.indexOf(obj.instructions[0].to) != -1 && flag){
                    i = i + 1;
                }
                readlines.push(obj.instructions[0].lineno);
            }
            else{
                //console.log("not found");
            }
        }
        else{
            obj.instructions.forEach(function(inst){
                readlines.push(inst.lineno);
            });
        }
        i = i + 1;
    }
    return labelblocks();
}
function labelblocks(){
    count = 1;
    path.forEach(function(obj){
        obj.nodeno = count;
        count = count + 1;
        var time = 0;
        obj.instructions.forEach(function(i){
            time = time + i.time;
        });
        obj.time = time;
    });
    adjlist = new Array(count+1);
    return linkblocks();
}
function linkblocks(){
    var oldnode = startnode;
    path.forEach(function(obj){
        oldnode.addedge(obj);
        if (obj.isbranch){
            if (obj.instructions[0].isfloat || typeof linetonode[obj.instructions[0].to] === "undefined"){
                
            }
            else{
                obj.addedge(linetonode[obj.instructions[0].to]);
            }
        }
        oldnode = obj;
    });
    return calculatelooptime();
}

function calculatelooptime(){
    //displaygraph();
    path.forEach(function(obj){
        if (obj.isbranch && !obj.instructions[0].isfloat){
            visited = new Array(count+1);
            var iter = 0;
            while (iter != count + 1){
                visited[iter] = false;
                iter++;
            }
            obj.time = obj.time * obj.power;
            visited[obj.nodeno] = true;
            addpower(linetonode[obj.instructions[0].to],obj.power);
        }
    });
    var cyclecount = 0;
    path.forEach(function(obj){
        cyclecount += obj.time + obj.overhead;
    });
    if(debug){
        displaygraph();
    }
    return cyclecount;
}
function addpower(obj,power){
    if (typeof obj === "undefined"){
        if (debug){
            console.log("lost a branch");
        }
        //happens when we are trying to branch to a node which does not exist
        //ex: b lr (link register does not exist with us)
        return;
    }
    if (obj.isbranch){
        obj.overhead = obj.overhead * power;
    }
    visited[obj.nodeno] = true;
    obj.time = obj.time * power;
    obj.outedge.forEach(function(nextnode){
        if (!visited[nextnode.nodeno] && !(typeof nextnode === "undefined")){
            //console.log(nextnode);
            addpower(nextnode,power);
        }
    });
}
function displaygraph(){
    console.log("Basic Blocks are ");
    console.log("-------------------");
    path.forEach(function(obj){
        console.log(obj);
    });
    path.forEach(function(obj){
        if (obj.get_classname() == "Node"){
            adjlist[obj.nodeno] = [];
            obj.outedge.forEach(function(i){
                adjlist[obj.nodeno].push(i.nodeno);
            });
        }
    });
    console.log(adjlist);
    path.forEach(function(obj){
        console.log(obj.time + " " + obj.overhead);
    });
}