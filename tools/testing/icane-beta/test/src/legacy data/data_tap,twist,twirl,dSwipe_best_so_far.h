/*
 * This is an autogenerated file. Modifications
 * might not be persistent.
 */
namespace protoNNParam {

#ifndef __TEST_PROTONN__
    /** Gamma for gaussian kernel */
    const PROGMEM float gamma = 0.001199;
    /** Low Dimensional Projection Matrix */
    const PROGMEM unsigned int featDim = 124;
    const PROGMEM unsigned int ldDim = 10;

    /**
    * Projectino Matrix (W)
    * d_cap x d flattened (dimension of 2D array)
    * ldDim x featDim
    */
    const PROGMEM  float ldProjectionMatrix[]  = {
		2.15914,4.31002,2.83981,1.80651,-0.464786,1.98909,1.48212,0.916926,-0.636723,0.918608,0.756071,-0.197497,-0.891836,-0.563254,-0.538136,-0.557268,-0.69841,0.208153,0.60693,1.03176,0.30672,0.12692,1.61575,0.409816,2.16093,-2.05051,0.40934,-0.639024,0.587634,0.205151,-0.51006,-0.258848,0.243866,-0.748244,-0.488804,-0.588076,-0.584904,-0.199885,0.217736,0.860238,0.304242,0.377108,-0.307754,-0.973594,1.81463,1.37542,2.52055,-0.721067,-0.741745,0.0387454,-0.114819,-1.11192,-0.996489,-1.26052,-1.11219,-1.14851,-0.264094,-0.0844919,-0.104006,-0.295127,0.2547,0.374925,1.42795,2.6689,-1.76145,0.194563,0.511393,0.205555,-0.63949,0.0779754,2.02289,0.33415,1.33447,0.878993,1.067,0.0465698,-0.111947,0.169845,0.268332,-0.189181,0.0096186,-0.167041,0.081578,-1.56936,0.463208,-0.052182,-1.04532,1.28114,2.9298,0.391759,3.66066,5.07054,-0.821883,-0.655704,-0.517118,-1.9133,0.841192,-1.0228,3.22709,0.229425,-1.20393,0.360118,-0.804451,0.937577,-1.04985,1.5139,1.28918,1.08156,-0.423554,1.60905,-0.52049,2.6332,1.8158,0.659112,1.54668,-0.0822502,0.652872,-0.754429,-0.53956,2.16311,-1.21726,0.756723,-1.43005,1.12203,
		-1.55129,-1.6075,0.110653,1.11214,-2.53496,-0.522282,-2.05261,0.40478,0.972176,-1.38107,-1.12915,0.242626,0.197397,1.83135,2.35197,2.70448,1.70577,-0.253224,-1.14509,-1.85237,0.224867,-0.0129138,-2.48173,0.26268,-4.84403,-8.26841,0.408578,5.41193,-1.70098,-1.64796,1.8244,2.44776,2.94225,2.83847,2.7217,2.49869,2.13089,0.975161,-0.167936,-1.14248,-0.873843,-1.10328,0.201214,-0.00998476,-1.66134,0.0695034,-1.42266,-0.930871,-2.15709,-1.9778,-0.726463,2.16758,2.12754,2.55209,1.99547,1.88247,-0.754669,-1.15163,-1.47431,-1.95881,-1.27131,-1.77384,-0.262676,1.0541,-2.1221,-0.405501,2.16311,1.59899,1.60525,-1.08156,-0.276613,-0.437793,-1.91359,-1.61199,-1.76638,-3.00704,1.01696,0.540779,-0.913103,-0.566803,0.0569236,1.75909,1.23416,2.61026,0.532568,1.22025,0.319842,1.28631,-0.0165452,0.50509,1.83501,4.12582,-2.79518,-1.81857,-2.04297,-2.91614,1.13817,-1.40869,1.93055,0.387257,-1.02429,1.01442,0.622126,-2.59028,-0.0293534,-1.23906,-1.43647,-0.101816,-0.320833,-1.01825,-0.144601,-0.10235,-3.05443,-2.17544,-1.66783,-2.90108,-0.852768,0.219293,0.166584,0.0600205,1.22775,1.51037,-0.799028,-0.0204313,
		2.1185,-1.98751,-0.826431,-3.60888,-0.49871,-0.874633,-1.08476,-0.235818,-2.04383,-1.80633,-0.756087,0.955244,2.87938,2.8083,3.00745,1.95434,1.56712,0.312713,-1.56261,-2.46945,-0.33291,-0.321557,-1.8887,-0.205247,-4.65389,-8.07922,-0.360343,-4.76715,-1.04066,-0.828998,2.22656,4.66588,2.41176,4.65323,4.73597,6.9911,2.74177,1.79103,-0.122777,-1.64337,-0.667975,1.01032,-1.08156,-0.0255887,-2.26855,-1.43095,-0.122794,0.746461,-2.17734,-1.93682,-0.162079,1.65072,2.00762,2.60452,2.31459,2.47828,0.600148,-0.0593636,-1.96108,-2.1996,-1.75698,0.929018,-2.40925,-1.43484,-0.996309,1.36588,-2.48007,-1.10623,-0.135195,-0.0895187,-0.106816,1.77556,-1.201,-2.67271,-2.68149,-0.305656,1.02684,0.612818,-0.0432376,0.60435,0.286057,0.260122,-0.70754,0.520265,0.0362939,-0.283229,0.887263,-0.149687,-1.95784,0.40755,-1.63734,-0.614867,-1.25681,-0.711461,-0.969373,-0.0516223,-0.428042,0.249279,-1.09791,0.210696,1.45556,-0.480164,-1.01261,0.152953,-0.847206,-1.42585,0.254873,0.754781,-1.60221,0.0942065,-0.522659,0.696321,-1.37812,-0.868762,-1.02932,0.532539,-0.964758,-0.204443,-1.04532,-0.445938,-0.889633,0.34558,0.695383,0.0358837,
		-0.842682,-1.74847,-0.148678,0.921853,0.208176,-1.25747,-1.59676,-1.38501,-0.732928,1.09606,0.881498,0.826984,0.983941,-0.155015,-0.0696073,0.64185,1.01971,0.485006,1.01224,1.32769,-1.02273,-1.34532,-1.54974,0.396655,4.06704,0.699981,0.81827,-3.99968,0.350576,0.397947,-0.850679,-1.25755,-2.00517,-1.07807,-1.17405,-1.88992,-0.838476,-0.663626,1.03122,-0.014469,-0.962698,-1.07185,-0.816433,-0.320563,1.68784,-2.50634,-0.870654,-2.03064,-1.45866,1.10855,0.42029,-0.00992886,1.06908,-0.137431,-0.184648,0.0945183,0.479262,0.689135,0.914934,1.37505,-1.35151,-0.492452,-0.581967,1.21987,-0.875006,1.30734,0.428156,1.16903,-0.242347,-0.844388,-0.225425,-0.0738056,-1.53695,-0.395229,-0.365688,-0.193853,0.155485,1.21257,0.419371,-1.03178,-1.6146,1.50832,0.654938,-0.531317,0.816976,0.95844,1.71262,-0.593031,2.04848,-0.8487,2.27156,1.53454,0.479677,-0.0506651,-0.223219,0.113953,0.30697,-0.567524,-0.975415,-0.783715,-0.788225,-0.0487905,-0.240176,0.0549339,0.108518,-1.64741,-1.21257,0.664647,-0.638664,-0.704991,0.480843,0.43787,-0.192566,-0.493519,-0.584215,-0.935998,-0.374078,0.463007,-1.04532,0.213018,-1.02933,2.08545,1.02684,-0.859901,
		-0.444735,0.787173,1.37167,2.13962,-0.334714,-0.143717,-0.193695,2.96877,0.0684663,-1.67244,-1.71343,-1.08953,-0.66027,0.384517,0.0808747,-0.376622,-0.526099,-1.40774,-1.60393,-2.15734,0.393135,1.42971,0.572862,1.34159,-4.52971,-4.03041,-0.369526,9.60868,-0.840462,-1.63865,0.611539,0.901431,-0.0481552,0.632616,0.682338,0.915477,0.245509,-0.159501,-2.14579,-1.60522,-0.348763,-1.15654,-0.356699,0.903155,0.904059,-0.0317622,2.65471,1.27213,0.531249,-2.35214,-1.80258,-1.12709,-1.3805,-0.4389,-0.758126,-0.348198,-1.30139,-1.56611,-1.94122,-2.09277,1.2368,2.94102,1.63164,-1.87117,-1.08285,-0.51083,0.767092,-0.63913,-1.14079,0.0189209,1.50981,-0.497554,0.298999,-0.641146,-0.280906,-0.815933,0.164462,-1.30233,-2.27685,-1.88917,-1.28553,0.522659,-0.942846,0.0514494,-0.0556222,0.210588,0.137346,-0.0669696,0.220187,0.0498545,0.727332,2.08957,-3.09422,0.0606443,-0.327688,-0.924317,-0.233412,0.747151,1.54114,1.8821,-0.52926,2.34806,-0.943856,-1.21668,-0.250102,-0.877051,1.42644,0.0997347,-0.57356,0.827842,0.513869,-0.107536,-0.656687,-1.18816,-0.502639,0.24617,-0.721823,-0.117535,-0.558504,0.536839,1.29194,0.783166,2.76052,0.90187,
		-0.939676,0.977896,-0.277483,-0.982334,-0.406081,1.07168,0.7479,2.00402,0.388192,-0.555448,-1.31005,-0.504279,-1.30951,-0.418276,0.00917705,0.337944,0.345376,-1.06025,-0.483624,-0.543847,0.400401,0.842984,0.331858,0.160854,-0.456912,6.58594,1.98743,-7.99825,-1.97431,-2.09435,0.0254796,-0.272564,-1.16088,-0.137875,-0.845563,-2.51112,-0.724756,-0.652843,-0.186887,-1.3669,-0.131388,1.61318,-0.811634,-0.718001,-0.76242,-2.43431,0.0937113,0.598936,-0.60285,-0.364534,-0.612643,0.410291,0.589816,0.769367,0.413177,0.584387,-1.73793,-0.86746,-0.170936,0.053914,0.713703,1.11405,0.351617,0.301821,0.28365,0.0316714,0.566781,0.302608,0.0890258,0.48037,1.01469,-0.859421,-0.281149,-0.498462,-0.594211,2.1899,0.749093,0.401025,1.7772,-1.52183,-0.786491,-1.08156,-0.107039,-0.00128865,1.36454,-0.537602,0.227197,0.535883,1.6406,0.797448,-1.32747,-2.55986,0.876952,0.0240701,-0.21636,-0.902,0.518701,-0.506147,1.18047,0.442514,-2.49638,-0.306883,0.55461,-2.01823,-0.321133,0.649292,-0.64489,1.67794,0.901279,0.423791,-1.02967,-0.380786,-0.477265,-0.346708,-0.777672,0.291519,1.39372,1.01611,-0.047246,2.08581,0.756951,-0.857301,-0.254362,0.0495009,
		0.723463,2.28544,0.0253018,-1.79154,0.168315,1.13825,0.06451,-1.34217,-0.72596,0.733437,0.314183,0.274608,1.13128,-0.164455,-0.659806,-0.752374,-0.0235758,0.388951,0.643386,0.855461,-0.0494542,2.16345,0.255805,-0.3499,6.49523,4.13267,2.18618,-10.0568,0.112659,0.319741,-0.25979,-0.831124,-2.13823,-0.516093,-0.841111,0.0930481,-0.791617,-0.268571,0.870296,1.82154,-0.528912,-0.295315,1.01911,0.27091,-1.48755,0.804014,1.67239,0.0752924,0.142466,1.11415,1.01034,0.356777,0.269907,0.340101,-0.392271,0.373487,0.634015,0.974766,1.58314,1.35902,0.572639,0.676597,1.76313,-0.0480226,-0.206801,-0.377164,0.767074,0.188816,-0.856312,0.760866,1.86472,1.89501,0.788067,0.132592,0.222316,0.907658,0.183434,1.24218,1.2242,-1.15754,-0.77705,0.615535,-0.465892,2.19231,0.456337,0.412682,-0.310492,-2.47659,-0.173714,1.44234,-1.09974,-0.653016,2.02796,0.5878,-0.0357507,0.771265,0.932629,1.68686,0.160858,1.78511,-0.837795,-0.173536,-0.198564,0.533154,-0.550723,-0.875401,1.41512,-0.721484,-1.07929,-0.218902,-0.255431,-1.04498,1.36524,1.44165,0.989146,1.84402,0.951489,-1.65057,0.0077223,-0.75717,-0.189636,0.220689,-0.235825,-0.117466,
		-0.206246,0.607535,1.47089,-1.07631,1.21232,-0.638474,-3.5293,0.308476,1.43901,-0.0308492,-0.608096,-0.0487285,-0.0486016,1.10007,0.976161,1.26403,0.86049,-0.2352,0.0146441,0.0805287,0.262205,-1.5277,-0.995376,-1.30987,-0.932275,1.26248,0.607216,-2.17226,-0.478877,-0.652095,0.856491,0.656457,1.00842,1.04953,0.234113,0.769806,0.0986398,0.139603,0.567493,-1.01129,-0.224236,-0.965098,-1.17553,-0.520092,0.0854392,-0.726805,-0.0616023,-2.68069,0.857144,-0.359744,-0.44793,1.10567,0.935095,1.49483,0.79582,1.22586,-1.49704,-0.618664,0.0843605,-0.215314,0.785594,-0.132015,-1.04073,-0.200086,1.09145,-0.174142,-0.923952,-0.695886,-0.945575,-1.30352,-0.0891747,-0.548918,-0.597387,-0.956424,-1.24911,-0.15032,0.631111,0.909881,1.2122,-0.760101,1.08156,-2.06057,-0.174593,0.590397,-1.65503,2.2758,-0.462018,0.603211,-0.492193,1.40479,-0.457449,-0.640371,-0.713739,-0.513422,-0.655423,-1.56859,-2.09506,0.885542,0.662034,1.56188,1.0454,-0.553571,0.0833508,-2.48172,-1.20129,0.38228,-0.615009,0.539764,-1.21726,-0.610882,-0.620933,-1.77025,-0.589325,-0.606238,-0.693821,-0.31458,0.575308,0.899076,0.645692,-0.309074,-0.0278178,0.448565,0.917803,0.580441,
		1.40304,1.68135,0.345496,0.548461,-2.12545,-2.53073,-6.73186,-1.87817,0.0336792,1.50104,1.66315,1.92106,2.35561,1.95449,2.22939,1.50621,2.07506,1.83292,1.77048,1.20282,-0.713069,-1.37516,-4.40096,-2.75118,-1.62446,1.72467,1.43529,5.3884,-1.18773,-0.700545,-0.34184,-0.111499,-0.33625,0.0982786,-0.284515,-1.14882,-0.810568,-0.766415,-0.962887,-0.437135,-0.341331,1.22991,0.761574,0.768852,-2.07986,-1.08205,-3.12557,-1.35447,0.0942673,0.897889,1.21282,1.10662,0.773629,1.44923,1.27396,1.40898,2.03245,1.44902,0.854562,0.909333,-2.56883,-4.58908,-4.60335,-2.69638,0.000963442,-1.17589,0.128786,1.44579,-2.62584,-1.42746,-0.0284276,1.97945,-0.973706,-0.746683,-0.491129,-0.590156,-0.107569,-1.07521,0.973594,0.908855,0.0945903,0.616224,-0.309546,1.48679,0.155363,-0.823427,-0.540779,-1.13924,2.45951,1.14937,-0.055383,2.01744,-1.02331,-0.137963,-0.679636,-1.33848,0.829771,1.24218,0.832858,0.902584,0.700803,-0.154277,0.615207,-1.35619,-0.667355,-0.378475,1.11921,-1.07345,-0.0821679,-0.612718,-0.618704,0.0717649,-0.0214057,-1.14888,-0.795471,-0.821132,-1.02377,-0.128709,1.51118,1.02967,1.20769,1.35699,-0.61476,-0.291552,
		0.135201,-0.296031,-0.947443,-1.48029,0.913326,0.320027,-0.154013,1.56198,1.42324,1.8143,1.34115,0.596215,0.0582833,-1.304,-1.7512,-1.35296,-0.66644,0.516279,1.32926,1.84376,2.06947,-1.09251,0.441482,2.80531,4.07191,7.69298,0.676083,-4.69757,0.616182,0.405254,-2.51907,-3.35677,-4.9975,-3.3999,-3.14757,-3.34465,-2.27172,-2.06857,-0.411004,0.37793,-1.21101,0.491645,-0.882495,-0.211415,0.327278,0.644706,-0.469992,0.815647,0.0732757,1.12266,0.62327,-1.64499,-1.83034,-1.94851,-1.87404,-1.4919,0.201772,0.496837,1.2355,1.34917,0.913881,-0.511757,1.2135,0.0422647,1.26545,-1.14604,-0.0439739,-0.211602,-0.753351,-0.480164,0.0506877,-0.0633446,-0.856844,-0.239998,0.1064,0.22228,0.292014,-0.714209,0.701055,-1.51345,0.305095,-0.835604,1.07682,-0.898196,-0.993278,1.23239,-1.78657,0.096598,-0.344919,0.841251,0.202378,2.18043,0.684112,0.962672,0.5451,0.492845,0.53407,0.165247,-0.595609,0.305918,-0.725183,2.15906,-1.24806,0.511525,-1.51665,-0.376782,-0.154213,1.63691,1.0267,-1.84282,-0.333497,1.06237,-0.873033,0.270329,-0.272621,0.364074,0.599243,-0.277476,0.310105,0.506163,-1.22501,0.485849,-0.146289,-0.0848805,
	};
    
    /**
     * Prototypes (B)
     * m x d_cap flattened (dimension of 2D array)
     * numPrototypes x d_cap
     */
    const PROGMEM float prototypeMatrix[] = {
		-46.360300,-935.885000,-5.816740,-387.345000,-1488.970000,-140.836000,690.930000,-218.608000,355.124000,-1024.870000,
		-117.267000,-703.869000,393.005000,-291.429000,-1238.350000,-717.009000,833.876000,-23.030300,373.563000,-1238.670000,
		627.635000,-436.610000,-1327.230000,81.367600,-867.970000,-1055.520000,200.068000,-827.553000,544.939000,-1354.550000,
		448.327000,-1507.870000,725.196000,-1021.100000,-1412.600000,-1402.180000,1094.710000,-516.818000,634.779000,-1025.700000,
		128.606000,-2224.190000,-1127.190000,64.167500,-1697.730000,-1523.530000,657.854000,-369.017000,147.104000,24.922200,
		-232.690000,-179.701000,895.724000,-376.188000,-688.467000,-1894.480000,-211.887000,-364.831000,-122.708000,-1718.560000,
		-13.447000,-952.692000,233.413000,-543.170000,-1763.150000,-1334.430000,-596.198000,-476.046000,-367.068000,-1622.350000,
		-229.051000,-148.856000,144.202000,-1082.190000,-461.509000,-950.476000,-733.000000,-124.035000,853.215000,-1888.820000,
		1024.930000,-1674.690000,-1237.740000,20.571500,-255.623000,-867.543000,-66.377700,-867.544000,1226.640000,-1217.060000,
		1732.050000,-930.854000,-99.509900,-180.064000,-1349.700000,-1650.370000,285.149000,-390.867000,785.105000,-289.027000,
		427.048000,-1152.300000,-640.756000,368.845000,-1858.860000,-168.354000,841.317000,175.793000,69.697400,-269.208000,
		779.226000,-1251.050000,-1043.750000,479.368000,-614.087000,-1670.350000,856.141000,-42.402600,1739.660000,-1154.160000,
		-361.925000,-2037.820000,335.537000,-65.847300,-1282.070000,-1120.180000,1015.100000,-498.229000,174.383000,-72.999600,
		-1099.920000,-2065.390000,-138.833000,-53.273900,-1107.930000,-1418.300000,-213.639000,-811.520000,231.159000,-269.831000,
		-462.136000,-1462.620000,525.608000,216.052000,-792.929000,-1370.520000,-512.856000,-623.478000,622.451000,-61.254000,
		1687.510000,-1575.830000,-554.784000,-688.316000,-731.500000,-1105.380000,200.895000,-357.938000,1697.710000,-780.293000,
		42.081900,-1284.410000,-684.876000,-643.634000,-687.359000,-1466.320000,143.769000,-656.871000,333.039000,-202.236000,
		-212.103000,-1287.730000,-590.117000,335.334000,-1850.320000,-2385.460000,397.166000,-295.127000,775.596000,-368.544000,
		974.719000,-1591.610000,-703.528000,226.881000,-2376.580000,-1042.700000,1021.730000,-1533.660000,662.083000,-849.901000,
		431.046000,-2212.360000,-603.528000,516.540000,-1576.670000,-1543.740000,3.434850,365.170000,444.932000,-179.050000,
		651.988000,-2126.820000,-184.419000,453.988000,-936.442000,-1059.690000,-351.043000,-568.137000,-204.126000,-158.009000,
		279.105000,-2268.470000,-702.322000,428.898000,-910.950000,-1127.990000,152.029000,-500.275000,-492.154000,-534.872000,
		437.169000,-1019.890000,-246.799000,-240.345000,-2306.180000,-1630.950000,-363.841000,-411.525000,-280.659000,-1379.240000,
		499.375000,-1801.030000,-174.092000,-33.711000,-520.278000,-797.111000,-318.061000,-1069.140000,-575.083000,-473.393000,
	};
    /** Number of prototypes (m) */
    const PROGMEM unsigned int numPrototypes = 24;
    
    /**
     * Prototype Lables (Z)
     * m x L (dimension of 2D array)
     * numLabels x numPrototypes
     */
    const PROGMEM float prototypeLabelMatrix[] = {
		0.000000,-0.014882,0.000000,0.181474,0.006723,-0.008516,0.000000,0.112100,0.000000,0.039959,
		0.000000,1.167880,0.000000,-0.162283,-0.004200,0.014534,0.000000,-0.071636,0.000000,-0.030113,
		0.000000,2.036660,0.000000,0.021641,-1.496820,0.756054,0.000000,0.015200,0.000000,0.002906,
		0.000000,2.001530,0.000000,-0.000647,-0.004486,-0.185847,0.000000,0.015429,0.000000,0.003327,
		0.000000,0.064093,0.000000,-0.006976,-0.024708,0.031158,0.000000,1.292550,0.000000,0.110505,
		0.000000,-50.917000,0.000000,59.424100,-0.176600,-0.526857,0.000000,-1.736200,0.000000,-0.314801,
		0.000000,5.536610,0.000000,-7.080350,0.066420,0.198780,0.000000,1.404620,0.000000,0.124018,
		0.000000,36.126700,0.000000,-31.436000,0.294637,0.398800,0.000000,1.634940,0.000000,-0.281562,
		0.000000,-6.805400,0.000000,0.165790,23.722200,-11.511000,0.000000,0.333092,0.000000,0.413785,
		0.000000,-8.714530,0.000000,0.036973,1.866090,11.018900,0.000000,-0.086257,0.000000,0.608006,
		0.000000,5.392460,0.000000,-0.391096,-0.027022,-0.003416,0.000000,-0.522764,0.000000,-0.167227,
		0.000000,-4.931020,0.000000,0.131170,31.534900,-21.632100,0.000000,-0.359999,0.000000,0.023962,
		0.000000,2.280620,0.000000,-0.025230,-0.003516,0.017307,0.000000,-0.072318,0.000000,0.008993,
		0.000000,5.267050,0.000000,6.633910,-0.703459,3.238080,0.000000,-7.387360,0.000000,-8.256510,
		0.000000,-12.419200,0.000000,-1.964360,1.288810,-0.338836,0.000000,2.716490,0.000000,11.435200,
		0.000000,17.048700,0.000000,-0.124940,-21.864400,6.630850,0.000000,0.311276,0.000000,-0.790455,
		0.000000,6.591880,0.000000,-0.535198,-0.310788,-0.259143,0.000000,-1.526620,0.000000,-0.487660,
		0.000000,-15.931500,0.000000,-1.162580,-0.381267,-0.110339,0.000000,18.941300,0.000000,3.164900,
		0.000000,16.300000,0.000000,0.066703,-0.094247,-0.319603,0.000000,-3.380380,0.000000,-0.104301,
		0.000000,-9.474930,0.000000,1.860460,1.033750,-0.760108,0.000000,8.726670,0.000000,-20.745200,
		0.000000,-10.470300,0.000000,-2.537810,1.272830,-2.030270,0.000000,-11.815500,0.000000,4.487470,
		0.000000,-1.429500,0.000000,-0.201004,-0.258256,0.483430,0.000000,-2.476860,0.000000,10.611800,
		0.000000,12.855600,0.000000,4.256100,-0.018455,-0.761701,0.000000,-5.300890,0.000000,0.242307,
		0.000000,-7.311830,0.000000,4.090550,0.429259,-0.040146,0.000000,19.217800,0.000000,-12.736300,
};
    /** Number of output labels, (L). */
    const PROGMEM unsigned int numLabels = 10; // 0,1,2,3,4,5
    
#else
    const PROGMEM float = 1.0;
    const PROGMEM unsigned int featDim = 10;
    const PROGMEM unsigned int ldDim = 5;
    // Row Major (X.x)
    const PROGMEM  float ldProjectionMatrix[]  = {
        0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,
        1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,
        2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,
        3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,
        4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,
    };
    // Column Major
    const PROGMEM unsigned int numPrototypes = 3;
    const PROGMEM float prototypeMatrix[] = {
        -1.0,-0.5,0.0,0.5,1.0,
        -2.0,-1.0,0.0,1.0,2.0,
        -7.51,-7.51,-7.51,-7.51,-7.51,
    };
    // column major
    const PROGMEM unsigned int numLabels = 4;
    const PROGMEM float prototypeLabelMatrix[] = {
        0.96,0.01,0.01,0.02,
        0.02,0.94,0.02,0.02,
        0.10,0.15,0.55,0.20,
    };
#endif
};
    