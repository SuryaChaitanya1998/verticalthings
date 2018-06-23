var obj = {
    "name": "test_pipeline",
    "uses": [],
    "vars": [],
    "pipeline": {
        "name": "nandu",
        "block": [
            {
                "qname": [
                    "m1"
                ],
                "params": [
                    {
                        "expr": {
                            "bconst": true
                        }
                    }
                ]
            },
            {
                "qname": [
                    "m2"
                ]
            }
        ]
    },
    "fdefs": [],
    "modules": {
        "m1": {
            "name": "m1",
            "uses": [],
            "vars": [],
            "fdefs": [
                {
                    "flow": "default",
                    "id": "lol",
                    "params": [],
                    "vars": [
                        {
                            "type": {
                                "primitive": "int"
                            },
                            "is_const": false,
                            "ids": [
                                {
                                    "id": "a",
                                    "init": {
                                        "iconst": 0
                                    }
                                }
                            ]
                        }
                    ],
                    "body": {
                        "stmts": [
                            {
                                "kind": "assign",
                                "qid": [
                                    "a"
                                ],
                                "expr": {
                                    "op": "+",
                                    "lexpr": {
                                        "qid": [
                                            "a"
                                        ]
                                    },
                                    "rexpr": {
                                        "iconst": 1
                                    }
                                }
                            },
                            {
                                "fcall": {
                                    "qid": [
                                        "next"
                                    ],
                                    "params": []
                                }
                            }
                        ],
                        "kind": "block"
                    }
                },
                {
                    "type": {
                        "primitive": "int"
                    },
                    "id": "main",
                    "params": [],
                    "vars": [
                        {
                            "type": {
                                "primitive": "int"
                            },
                            "is_const": false,
                            "ids": [
                                {
                                    "id": "c",
                                    "init": {
                                        "iconst": 0
                                    }
                                }
                            ]
                        }
                    ],
                    "body": {
                        "stmts": [
                            {
                                "kind": "assign",
                                "qid": [
                                    "c"
                                ],
                                "expr": {
                                    "op": "+",
                                    "lexpr": {
                                        "qid": [
                                            "c"
                                        ]
                                    },
                                    "rexpr": {
                                        "iconst": 1
                                    }
                                }
                            },
                            {
                                "fcall": {
                                    "qid": [
                                        "next"
                                    ],
                                    "params": []
                                }
                            }
                        ],
                        "kind": "block"
                    }
                }
            ]
        },
        "m2": {
            "name": "m2",
            "uses": [],
            "vars": [],
            "fdefs": [
                {
                    "type": {
                        "primitive": "int"
                    },
                    "id": "hol",
                    "params": [],
                    "vars": [
                        {
                            "type": {
                                "primitive": "int"
                            },
                            "is_const": false,
                            "ids": [
                                {
                                    "id": "b",
                                    "init": {
                                        "iconst": 0
                                    }
                                }
                            ]
                        }
                    ],
                    "body": {
                        "stmts": [
                            {
                                "kind": "assign",
                                "qid": [
                                    "b"
                                ],
                                "expr": {
                                    "op": "+",
                                    "lexpr": {
                                        "qid": [
                                            "b"
                                        ]
                                    },
                                    "rexpr": {
                                        "iconst": 1
                                    }
                                }
                            }
                        ],
                        "kind": "block"
                    }
                }
            ]
        }
    }
};
function fcall(obj){
	var s="";
	s=s+obj.qid.join(".")+"(";
	for(var i in obj.params)
		s=s+expr(obj.params[i].expr)+", ";
	if(obj.params.length>0)
		return (s.substring(0,s.length-2)+")");
	else return s+")";
}

function expr(obj){
	// console.log(obj);
	var str="";
	if(typeof obj.op != 'undefined'){
		// console.log(obj);
		str = "("+expr(obj.lexpr) + obj.op + expr(obj.rexpr)+")";
	}
	else if(typeof obj.qid != 'undefined'){
		str = str + obj.qid.join(".");
	}
	else if(typeof obj.iconst != 'undefined'){
		str = obj.iconst;
	}
	else if(typeof obj.id != 'undefined'){
		str = obj.id;
	}
	else if(typeof obj.fcall != 'undefined'){
		str = fcall(obj.fcall);
	}
	return str;
}

function block(obj,str){
	str.push("{");
	if(typeof obj.stmts != 'undefined'){
		for(var i in obj.stmts){
			stmts(obj.stmts[i],str);
		}
	}
	str.push("}");
}

function stmts(obj,str){
	if(typeof obj.kind != 'undefined'){
		switch(obj.kind){
			case "assign":
				str.push(obj.qid.join(".") + "=" + expr(obj.expr) + ";");
				break;
			case "if":
				// console.log(obj);
				str.push("if(" + expr(obj.expr) + ")");
				stmts(obj.if_body,str);
				if(typeof obj.else_body !='undefined'){
					str.push("else");
					stmts(obj.else_body,str)
				}
				break;
			case "for":
				str.push("for(" + obj.ids[0] + "=" + expr(obj.range.from) + "; " + obj.ids[0] + "<" + expr(obj.range.to) + "; " + obj.ids[0] + "++)");
				stmts(obj.body,str);
				break;
			case "while":
				str.push("while(" + expr(obj.expr) + ")");
				stmts(obj.body,str);
				break;
			case "return":
				str.push("return " + expr(obj.expr));
				break;
			case "block":
				block(obj,str);
				break;
		}
	}
	else if(typeof obj.fcall != 'undefined'){
		str.push(fcall(obj.fcall)+";");
	}
}

function type_resolve(obj){
	var primitive=obj.primitive;
	var dim="";
	if(typeof obj.dim != 'undefined')
		for(var i in obj.dim.dim){
			dim=dim+"["+expr(obj.dim.dim[i])+"]";
		}
	return {primitive: primitive, dim: dim};
}

function vars(obj){
	var s="";
	if(typeof obj.is_const != 'undefined'){
		if(obj.is_const === "true")
			s=s+"const ";
	}
	var type = type_resolve(obj.type);
	s=s+type.primitive+" ";
	// console.log(s);
	var temp=[];
	for(var i in obj.ids){
		if(typeof obj.ids[i].init != 'undefined')
			temp.push(obj.ids[i].id+type.dim+"="+expr(obj.ids[i].init));
		else
			temp.push(obj.ids[i].id+type.dim);
	}
	s=s+temp.join(", ");
	return s;
}

function params(obj){
	var s="";
	if(typeof obj.is_const != 'undefined'){
		if(obj.is_const=="true")
			s=s+"const ";
	}
	var type=type_resolve(obj.type);
	if(typeof obj.init != 'undefined')
		s=s+type.primitive+" "+obj.id+"="+expr(obj.init);	
	else
		s=s+type.primitive+" "+obj.id;	
	return s;
}

function fdefs(obj,str){
	// console.log(code);
	var s="";
		if(cur_mod=="m2__")
			console.log(obj.type+" lololololoollolo");
	if(typeof obj.type != 'undefined'){
		s=s+obj.type.primitive+" ";
	}
	else
		s=s+"void ";
	s=s+"__"+cur_mod+obj.id+"(";
	var temp=[];
	for(var i in obj.params){
		temp.push(params(obj.params[i]));
	}
	s=s+temp.join(", ");
	s=s+")";
	str.push(s);

	str.push("{");

	for(var i in obj.vars){
		str.push(vars(obj.vars[i])+";");
	}
	stmts(obj.body,str);
    str.push("}");
}
var code=[];
// code.push("enum " + obj.pipeline.name+"{");
var states=[];
for(var i in obj.pipeline.block){
	states.push(obj.pipeline.block[i].qname.join('.'));
}
code.push("enum " + obj.pipeline.name + "{__" + states.join(", __") + "};");

var cur_mod="";
for(var j in states){
	cur_mod=states[j];
	for(var i in obj.modules[cur_mod].fdefs){
	    fdefs(obj.modules[cur_mod].fdefs[i],code);
	}
}
console.log(code.join('\n'));
// console.log(expr(str));