#define NOVAL_I -9999
#define NOVAL_F -9999.0

namespace scans {
  
  //________________________________________________________________________________________
  //                                 Time Delay Scans
  
  int delay_scan_no(int run, int ls) {
    switch (run) {
      // Delay Scan - 2011
    case 160413: return 0;
    case 160497: return 0; 
    case 160577: return 0;
    case 160578: return 0;
      // 2012 - April
    case 190411: return 1;
    case 190456: return 1;
      // 2012 - July
    case 198022: return 2; // New Vana Settings
    case 198023: return 2;
    case 198048: return 3; // Old Vana Settings
      
      // 2015 - 03 June - 0T
    case 246908: return 4;
    case 246919: return 4;
    case 246920: return 4;
    case 246923: return 4;
    case 246926: return 4;
    case 246930: return 4;
    case 246936: return 4;
      
      // 2015 - July - 3.8T
    case 251027: return 5;
    case 251028: return 5;
    case 251131: return 5;
    case 251134: return 5;

      // 2016 - April - 0T
    case 271188: return 6;
    case 271191: return 6;
    case 271192: return 6;
    case 271193: return 6;

      // 2016 - April - 3.8T
    case 272021: return 7;

      // 2016 - May   - 3.8T
    case 272761: return 7;
    case 272762: return 7;
      
      // 2016 - Aug
    case 277984: return 8;
    case 277990: return 8;

      // PHASE 1
      // 2017 - May
      // Scan 1
    case 294928: return 9;
    case 294929: return 9;
    case 294931: return 9;
    case 294932: return 9;
    case 294933: return 9;
    case 294934: return 9;
    case 294935: return 9;
    case 294936: return 9;
    case 294937: return 9;
    case 294939: return 9;
    case 294940: return 9;
    case 294947: return 9;
    case 294949: return 9;
    case 294950: return 9;
    case 294951: return 9;
    case 294952: return 9;
    case 294953: return 9;
    case 294954: return 9;
    case 294955: return 9;
    case 294956: return 9;
    case 294957: return 9;
    case 294960: return 9;
      // Scan 2
    case 294987: return 10;
    case 294986: return 10;
    case 294988: return 10;
      // Scan 3
    case 295123: return 11;
    case 295124: return 11;
    case 295125: return 11;
    case 295126: return 11;
    case 295133: return 11;
    case 295134: return 11;
    case 295135: return 11;
      // Scan 4
    case 295194: return 12;
    case 295197: return 12;
    case 295199: return 12;
    case 295200: return 12;
    case 295201: return 12;
    case 295202: return 12;
    case 295203: return 12;
      // Scan 5
    case 295340: return 13;
    case 295341: return 13;
    case 295342: return 13;
    case 295343: return 13;
      // Scan 6
    case 295344: return 14;
    case 295345: return 14;
    case 295346: return 14;
    case 295347: return 14;
    case 295348: return 14;
    case 295349: return 14;
      // Run 295371
    case 295371: return 15;
      // Scan 7
    case 295366: return 16;
    case 295377: return 16;
    case 295378: return 16;
    case 295379: return 16;
    case 295380: return 16;
      // Scan 8(-11) - http://cmsonline.cern.ch/cms-elog/987183
    case 295437: return 17;
    case 295438: return 17;
    case 295436: return 17;
    case 295460: return 17;
      // Scan 9
    case 295440: return 18;
    case 295445: return 18;
    case 295446: return 18;
    case 295439: return 18;
    case 295449: return 18;
    case 295447: return 18;
    case 295448: return 18;
      // Scan 10
    case 295450: return 19;
    case 295453: return 19;
    case 295454: return 19;
    case 295455: return 19;
    case 295456: return 19;
      // Scan 11
    case 295459: return 20;
    case 295458: return 20;
    case 295457: return 20;
      // Scan 12
    case 295642: return 21;
    case 295632: return 21;
    case 295628: return 21;
    case 295634: return 21;
    case 295644: return 21;
      // Scan 13
    case 295638: return 22;
    case 295649: return 22;
    case 295636: return 22;
    case 295650: return 22;
    case 295635: return 22;
    case 295645: return 22;
      // Scan 14
    case 295639: return 23;
    case 295648: return 23;
    case 295640: return 23;
    case 295647: return 23;
    case 295641: return 23;
    case 295646: return 23;
      // Scan 15
    case 296075: return 24;
    case 296083: return 24;
    case 296084: return 24;
    case 296085: return 24;
    case 296087: return 24;
    case 296088: return 24;
    case 296089: return 24;
    case 296090: return 24;
    case 296091: return 24;
    case 296111: return 24;
    case 296112: return 24;
    case 296113: return 24;
    case 296115: return 24;
    case 296116: return 24;
      // Scan 16
    case 296092: return 25;
    case 296093: return 25;
    case 296095: return 25;
    case 296096: return 25;
    case 296097: return 25;
      // Scan 17
    case 296098: return 26;
    case 296099: return 26;
    case 296100: return 26;
    case 296101: return 26;
    case 296103: return 26;
      // Scan 18
    case 296104: return 27;
    case 296107: return 27;
    case 296108: return 27;
    case 296109: return 27;
    case 296110: return 27;
      // Scan 19:
    case 296644: return 28;
    case 296646: return 28;
    case 296647: return 28;
    case 296642: return 28;
    case 296643: return 28;
      // Scan 20:
    case 296665: return 29;
    case 296666: return 29;
    case 296668: return 29;
    case 296669: return 29;
    case 296674: return 29;
    case 296664: return 29;
    case 296675: return 29;
    case 296676: return 29;
    case 296678: return 29;
    case 296679: return 29;
    case 296680: return 29;
      // Scan 21
    case 297004: return 30;
    case 297006: return 30;
    case 297007: return 30;
  //case 297009: return 30;
    case 297010: return 30;
    case 297011: return 30;
  //case 297020: return 30; // No Express
    case 297012: return 30;
    case 297015: return 30;
  //case 297016: return 30;
    case 297017: return 30;
    case 297018: return 30;
    case 297019: return 30;
    case 297048: return 30;
    case 297047: return 30;
    case 297049: return 30;
      // Scan 22
    case 297179: return 31;
    case 297180: return 31;
    case 297181: return 31;
    case 297211: return 31;
    case 297215: return 31;
      // Scan 23
    case 297281: return 32;
    case 297282: return 32;
    case 297283: return 32;
    case 297284: return 32;
    case 297285: return 32;
    case 297286: return 32;
    case 297287: return 32;
    case 297288: return 32;
    case 297289: return 32;
    case 297290: return 32;
    case 297291: return 32;
      // Scan 24
    case 299316: return 33;
    case 299317: return 33;
    case 299318: return 33;
    case 299324: return 33;
    case 299325: return 33;
    case 299326: return 33;
      // Scan 25
    case 300364: return 34;
    case 300365: return 34;
    case 300366: return 34;
    case 300367: return 34;
    case 300368: return 34;
    case 300369: return 34;
    case 300370: return 34;
    case 300371: return 34;
    case 300373: return 34;
    case 300374: return 34;
      // Scan 26
    case 300389: return 35;
    case 300390: return 35;
    case 300391: return 35;
    case 300392: return 35;
    case 300393: return 35;
    case 300394: return 35;
    case 300395: return 35;
    case 300396: return 35;
    case 300397: return 35;
    case 300398: return 35;

      // Scan 27 and 28
    case 303794: return 36;
    case 303795: return 36+(ls>95);

      // Scan 29 - 27 Oct 2017
      // http://cmsonline.cern.ch/cms-elog/1018019
//  case 305745: return 38; // ECAL TESTS
//  case 305746: return 38; // ECAL TESTS
    case 305747: return 38;
    case 305748: return 38;
    case 305749: return 38;
    case 305750: return 38;
    case 305751: return 38;
    case 305752: return 38;
    case 305753: return 38;
    case 305754: return 38;
    case 305755: return 38;

    default:
      return -1;
    }
  }

  float delay(int run, int ls, int orbit) {
    switch (run) {
      // Delay Scan - 2011
    case 160413:
      return 
        orbit   <  11531874 ?  25
        : orbit <  22836667 ?   0
        : orbit <  36525473 ? NOVAL_I // BAD
        : orbit <  47699601 ?   7 
        : orbit <  60471838 ?   8
        : orbit <  71445138 ?  10
        : orbit <  84930036 ? -25
        : orbit < 100147197 ? NOVAL_I // BAD
        : orbit < 114600000 ?  14
        : orbit < 129039651 ?  16
        : orbit < 145100000 ? -12
        : orbit < 160586081 ?  10
        : orbit < 174462084 ?  -6
        : orbit < 191550000 ?  -8
        : 12;
    case 160497:
      return
        orbit   < 11923615 ? NOVAL_I
        : orbit < 23009846 ? -4
        : orbit < 34154357 ? -2
        : NOVAL_I; // BAD 
    case 160577:
      return
        orbit   < 10359519 ? NOVAL_I
        : orbit < 26677701 ? 4
        : orbit < 40220000 ? 18
        : orbit < 53440000 ? 20
        : orbit < 66319978 ? 22
        : 14;
    case 160578:
      return
        orbit   <   1245694 ? NOVAL_I
        : orbit <  14309529 ? 14
        : orbit <  43223561 ? 16
        : orbit <  71862094 ? 15
        : orbit < 108617422 ? 13
        : NOVAL_I;
      // 2012 - April
    case 190411 :
      return
        ls   <  26 ?  13
        : ls <  44 ?  -6
        : ls <  63 ? -12
        : ls <  80 ? -18
        : ls <  94 ?   6
        : ls < 108 ?  12
        : ls < 127 ?  NOVAL_I
        : ls < 150 ?  13
        : ls < 175 ?  14
        : ls < 196 ?  15
        : ls < 214 ?  16
        : ls < 230 ?  12
        : ls < 246 ?  17
        : ls < 261 ?  18
        : ls < 277 ?  20
        : ls < 292 ?   0
        : ls < 309 ?  -2
        : -4;
    case 190456:
      return
        ls   <  70  ?  13
        : ls <  88  ?   2
        : ls < 108  ?   6
        : ls < 132  ?  10
        : ls < 149  ?  11
        : ls < 164  ?  38
        : ls < 174  ? -12
        : NOVAL_I;
      // 2012 - July
    case 198022: // New Vana Settings
      return 
        orbit   < 47500000 ? NOVAL_I
        : orbit < 49500000 ? 13
        : orbit < 53000000 ?  1
        : orbit < 56500000 ? 24
        : orbit < 60000000 ? 22
        : 20  ;
    case 198023:
      return
        orbit   <  4906628 ? 18
        : orbit <  9006831 ? 16
        : orbit < 12767345 ? 14
        : orbit < 16996865 ? 12
        : orbit < 21167493 ? 10
        : orbit < 25000000 ?  8
        : NOVAL_I;
    case 198048: // Old Vana Settings
      return
        orbit   <  2600000 ?  1
        : orbit <  5600000 ? 24
        : orbit <  8600000 ? 22
        : orbit < 12000000 ? 20
        : orbit < 15200000 ? 18
        : 16;
      // 2015 - 03 June - 0T
    case 246908:
      return ls<70 ? NOVAL_I : 11;
    case 246919:
      return
        ls   < 10 ? -10 // 11ns, but somehow l1 efficiencies are different
        : ls < 24 ? NOVAL_I // somehow l1 efficiencies are different - l1 occupancy ~0
        : ls < 38 ? 47
        : -3;
    case 246920:
      return NOVAL_I; // Bad run
    case 246923:
      return
        ls   <   9 ? NOVAL_I // Supposed to be 34ns
        : ls <  22 ? 10
        : 28;
    case 246926:
      return
	ls   <   7 ? NOVAL_I // Supposed to be 28ns, but the point is well off
        : ls <  20 ? 16
        : ls <  32 ? 26
        : ls <  43 ? 24
        : ls <  56 ? 20
        : ls <  67 ? 18
        : ls <  79 ? 14
        : ls <  91 ? 12
        : ls < 102 ? 30
        : ls < 113 ?  8
        : ls < 124 ?  6
        : ls < 135 ?  2
        : ls < 147 ?  0
        : ls < 160 ? -2
        : ls < 172 ? -5
        : ls < 183 ? 36
        : ls < 196 ? 32
        : ls < 210 ? 19
        : ls < 242 ? 16
        : 18;
    case 246930:
      return 22;
    case 246936:
      return NOVAL_I; // Supposed to be 14ns, but it likely remained at 11ns
      
      // 2015 - July - 3.8T
    case 251027:
      return NOVAL_I; // 22ns
    case 251028:
      return ls<20? 22 : 20;
    case 251131:
      return
        ls   < 25 ? 22
        : ls < 40 ? 21
        : 23;
    case 251134:
      return
        ls   < 21 ? 24
        : ls < 35 ? 25
        : ls < 48 ? 26
        : ls < 63 ? 27
        : 20;

      // 2016 - April - 0T
    case 271188: 
      return 22;
    case 271191: 
      return
	ls  >=15 && ls<= 56 ? 21
	: ls>=68 && ls<=110 ? 19
	: NOVAL_I;
    case 271192: 
      return
	ls  >= 3 && ls<= 46 ? 23
	: NOVAL_I;
    case 271193: 
      return
	ls  >= 4 && ls<= 44 ? 24
	: ls>=47 && ls<= 92 ? 25
	: ls>=95 && ls<=110 ? 20
	: NOVAL_I;
      
      // 2016 - April - 3.8T
    case 272021: 
      return
	ls  >=  5 && ls<= 17 ? 21
	: ls>= 19 && ls<= 28 ? 22
	: ls>= 29 && ls<= 38 ? 23
	: ls>= 40 && ls<= 48 ? 24
	: ls>= 50 && ls<= 58 ? 25
	: ls>= 60 && ls<= 69 ? 26
	: ls>= 71 && ls<= 80 ? 27
	: ls>= 81 && ls<= 90 ? 28
	: ls>= 92 && ls<=101 ? 29
	: ls>=102 && ls<=111 ? 30
	: ls>=113 && ls<=123 ? 31
	: NOVAL_I;
      
      // 2016 - May - 3.8T
    case 272761: 
      return
	ls  >=  5 && ls<= 14 ? 32
	: ls>= 16 && ls<= 24 ? 33
	: ls>= 25 && ls<= 34 ? 34
	: ls>= 35 && ls<= 43 ? 35
	: ls>= 45 && ls<= 53 ? 36
	: ls>= 54 && ls<= 63 ? 37
	: ls>= 64 && ls<= 72 ? 38
	: NOVAL_I;
      
    case 272762: 
      return
	ls  >=  3 && ls<=  11 ? 39
	: ls>= 12 && ls<=  21 ? 40
	: ls>= 22 && ls<=  30 ? 42
	: ls>= 32 && ls<=  40 ? 44
	: ls>= 41 && ls<=  49 ? 46
	: ls>= 51 && ls<=  59 ? 28
	: ls>= 60 && ls<=  69 ? 24
	: ls>= 70 && ls<=  78 ? 20
	: ls>= 79 && ls<=  85 ? 41
	: ls>= 86 && ls<=  92 ? 43
	: ls>= 93 && ls<=  98 ? 45
	: ls>= 99 && ls<= 104 ? 47
	: NOVAL_I;
      
    case 277984: 
      return
	ls  >= 1 && ls<= 15 ? 22
	: NOVAL_I;
      
    case 277990: 
      return
	ls  >=   4 && ls<=  27 ? 21
	: ls>=  30 && ls<=  57 ? 23
	: ls>=  59 && ls<=  84 ? 24
	: ls>=  87 && ls<= 111 ? 25
	: ls>= 115 && ls<= 140 ? 20
	: ls>= 144 && ls<= 164 ? 26
	: ls>= 167 && ls<= 181 ? 19
	: ls>= 184 && ls<= 197 ? 27
	: NOVAL_I;


      // Scan 1
    case 294928: return   31;
    //case 294929: return    6;
    case 294931: return  -19;
    case 294932: return   43;
    case 294933: return   18;
    case 294934: return   -7;
    case 294935: return  -32;
    case 294936: return  -25;
    case 294937: return   25;
    case 294939: return  -13;
    case 294940: return   12;
    //case 294947: return    0;
    case 294949: return   28;
    case 294950: return   21;
    case 294951: return   15;
    case 294952: return    9;
    case 294953: return    3;
    case 294954: return   -4;
    case 294955: return  -10; // missing run
    case 294956: return  -22; // was -10
    case 294957: return    0;
    case 294960: return    6;
      // Scan 2
    case 294987: return    0;
    case 294986: return    3;
    case 294988: return    6;
      // Scan 3
    case 295123: return    0;
    case 295124: return    2;
    case 295125: return   18;
    case 295126: return   21;
    case 295133: return    4;
    case 295134: return    8;
    case 295135: return   10;
      // Scan 4
    case 295194: return    0;
    case 295197: return    2;
    case 295199: return    4;
    case 295200: return    8;
    case 295201: return   10;
    case 295202: return   12;
    case 295203: return   18;
      // Scan 5
    case 295342: return   -7;
    case 295341: return    0;
    case 295340: return    6;
    case 295343: return  -13;
      // Scan 6
    case 295344: return   -7;
    case 295346: return    0;
    case 295347: return    0;
    case 295348: return    6;
    case 295345: return  -13;
    case 295349: return    3;
      // Run 295371
    case 295371: return    6;
      // Scan 7
    case 295366: return    6; 
    case 295377: return    0;
    case 295378: return   -4;
    case 295379: return   -7;
    case 295380: return  -13;
      // Scan 8
    case 295437: return    0;
    case 295438: return    3;
    case 295436: return    6;
    case 295460: return   12;
      // Scan 9
    case 295440: return    0;
    case 295445: return    3;
    case 295446: return    5;
    case 295439: return    6;
    case 295449: return    7;
    case 295447: return    9;
    case 295448: return   12;
      // Scan 10
    case 295450: return    0;
    case 295453: return    3;
    case 295454: return    6;
    case 295455: return    9;
    case 295456: return   12;
      // Scan 11
    case 295459: return    0;
    case 295458: return    6;
    case 295457: return   12;
      // Scan 12(-14)
    case 295642: return    0;
    case 295632: return    3;
    case 295628: return    6;
    case 295634: return    9;
    case 295644: return   12;
      // Scan 13
    case 295638: return    3;
    case 295649: return  4.5;
    case 295636: return    6;
    case 295650: return  7.5;
    case 295635: return    9;
    case 295645: return   12;
      // Scan 14
    case 295639: return    3;
    case 295648: return  4.5;
    case 295640: return    6;
    case 295647: return  7.5;
    case 295641: return    9;
    case 295646: return   12;
      // Scan 15
    //case 296075: return    6;
    case 296083: return    3;
    case 296084: return  4.5;
    case 296085: return  7.5;
    case 296087: return    9;
    case 296088: return 10.5;
    case 296089: return   12;
    case 296090: return   15;
    case 296091: return   18;
    case 296111: return  1.5;
    case 296112: return    0;
    case 296113: return   -4;
    case 296115: return   -7;
    case 296116: return    6;
      // Scan 16
    case 296092: return    3;
    case 296093: return  4.5;
    case 296095: return    6;
    case 296096: return  7.5;
    case 296097: return    9;
      // Scan 17
    case 296098: return    3;
    case 296099: return  4.5;
    case 296100: return    6;
    case 296101: return  7.5;
    case 296103: return    9;
      // Scan 18
    case 296104: return    3;
    case 296107: return  4.5;
    case 296108: return    6;
    case 296109: return  7.5;
    case 296110: return    9;
      // Scan 19:
    case 296644: return   18;
    case 296646: return   14;
    case 296647: return   11;
    case 296642: return    6;
    case 296643: return    6;
      // Scan 20:
    case 296665: return   18;
    case 296666: return   14;
    case 296668: return   11;
    case 296669: return    9;
    case 296674: return  7.5;
    case 296664: return    6;
    case 296675: return  4.5;
    case 296676: return  1.5;
    case 296678: return    0;
    case 296679: return   -3;
    case 296680: return   -7;
      // Scan 21
    case 297004: return   -7;
    case 297006: return   -4;
    case 297007: return    0;
  //case 297009: return  1.5;
    case 297010: return    3;
    case 297011: return  4.5;
  //case 297020: return    6; // No Express
    case 297012: return  7.5;
    case 297015: return    9;
  //case 297016: return 10.5;
    case 297017: return   12;
    case 297018: return   15;
    case 297019: return   18;
    case 297048: return  1.5;
    case 297047: return    6;
    case 297049: return 10.5;
      // Scan 22
    case 297179: return   11;
    case 297180: return   10;
    case 297181: return    9;
    case 297211: return   12;
    case 297215: return   11;
      // Scan 23
    case 297281: return    6;
    case 297282: return   -4;
    case 297283: return   -1;
    case 297284: return    2;
    case 297285: return    4;
    case 297286: return    8;
    case 297287: return   10;
    case 297288: return   13;
    case 297289: return   16;
    case 297290: return  5.5;
    case 297291: return  6.5;
      // Scan 24
    case 299316: return    6;
    case 299317: return    9;
    case 299318: return    9;
    case 299324: return    3;
    case 299325: return   12;
    case 299326: return   15;
      // Scan 25
    case 300364: return    6;
    case 300365: return    1;
    case 300366: return    3;
    case 300367: return    4;
    case 300368: return    5;
    case 300369: return    7;
    case 300370: return    8;
    case 300371: return    9;
    case 300373: return   11;
    case 300374: return   13;
      // Scan 26
    case 300389: return    6;
    case 300390: return    1;
    case 300391: return    3;
    case 300392: return    4;
    case 300393: return    5;
    case 300394: return    7;
    case 300395: return    8;
    case 300396: return    9;
    case 300397: return   11;
    case 300398: return   13;
      // Scan 27,28
    case 303794:
      return
	// Scan 27
	ls  >=   4 && ls<=  16 ?  1.5 
	: ls>=  17 && ls<=  22 ?  0
	: NOVAL_I;
    case 303795:
      return NOVAL_I; // Bad scan points
      /*
      return
	ls  >=   2 && ls<=  11 ?  0
	: ls>=  13 && ls<=  22 ? -2
	: ls>=  25 && ls<=  35 ? -4
	: ls>=  38 && ls<=  47 ? -6
	: ls>=  50 && ls<=  59 ?  3
	: ls>=  62 && ls<=  71 ?  5
	: ls>=  73 && ls<=  82 ?  7
	: ls>=  85 && ls<=  94 ?  9
	// Scan 28
	: ls>=  96 && ls<= 105 ?  1.5
	: ls>= 107 && ls<= 117 ? -4
	: ls>= 119 && ls<= 128 ? -2
	: ls>= 130 && ls<= 139 ?  0
	: ls>= 141 && ls<= 149 ?  3
	: ls>= 152 && ls<= 161 ?  5
	: ls>= 163 && ls<= 170 ?  7
	: ls>= 173 && ls<= 181 ? -6
	: ls>= 184 && ls<= 192 ?  9
	: NOVAL_I;
      */

      // Scan 29 - 27 Oct 2017
      // http://cmsonline.cern.ch/cms-elog/1018019
    case 305745: return  1.5;
    case 305746: return  1.5;
    case 305747: return  1.5;
    case 305748: return  0; 
    case 305749: return -2;
    case 305750: return -4;
    case 305751: return -6;
    case 305752: return  3;
    case 305753: return  5;
    case 305754: return  7;
    case 305755: return  9;
      
      /*
    case 2: 
      return
	ls  >=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: NOVAL_I;
      */

    default:
      return NOVAL_I;
    }
  }
  
  //________________________________________________________________________________________
  //                                  HV Bias Scans
  
  int hv_scan_no(int run) {
    switch (run) {
    case 295127: return 0; // 2017 May24-25 - FPix Only http://cmsonline.cern.ch/cms-elog/985913
    case 295128: return 0;
    case 295130: return 0;
    case 295131: return 0;
    case 295132: return 0;
    case 301086: return 1; //2017 Aug 14 - BPix only http://cmsonline.cern.ch/cms-elog/1003856
    case 301665: return 1; //2017 Aug 23: http://cmsonline.cern.ch/cms-elog/1005678
    case 301912: return 1; //2017 Aug 26: http://cmsonline.cern.ch/cms-elog/1006265
    case 303795: return 2; //2017 Sep 23 - BPix + Disk 2 http://cmsonline.cern.ch/cms-elog/1011175 
    case 304366: return 3; //2017 Oct 04 - BPix Layer 1 http://cmsonline.cern.ch/cms-elog/1013433
    case 305757: return 4; //2017 Oct 27 - BPix Layer 1 http://cmsonline.cern.ch/cms-elog/1018019
    case 306458: return 5; //2017 Nov 09 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1020953
    case 314649: return 6; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314650: return 6; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314663: return 6; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 315764: return 7; //2018 May 05 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1040372
    case 316199: return 8; //2018 May 12 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1041847
    case 316876: return 9; //2018 May 25 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1044475
    case 317640: return 10; //2018 Jun 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1047188
    case 319503: return 11; //2018 Jul 11 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1052076
    case 320500: return 12; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 320570: return 12; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 321396: return 13; //2018 Aug 17 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1058599
    case 322022: return 14; //2018 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1061220
    case 322381: return 15; //2018 Sep 07 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1062364
    case 323524: return 16; //2018 Sep 26 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1065392
    case 324980: return 17; //2018 Oct 20 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1069539
    case 326483: return 18; //2018 test HI run

    default: return -1;
    }
  }
  
  int hv_scan_badroc_runnumber(int run) {
    switch (run) {
    case 306458: return 306126; //2017 Nov 09 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1020953
    case 314649: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314650: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314663: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 316199: return 316201; //2018 May 12 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1041847
    case 316876: return 316877; //2018 May 25 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1044475
    case 317640: return 317641; //2018 Jun 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1047188
    case 319503: return 319486; //2018 Jul 11 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1052076
    case 320500: return 320571; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 320570: return 320571; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 321396: return 321393; //2018 Aug 17 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1058599
    case 322381: return 322381; //!!! if running again, plese delete badROCs for 322381 then run -b for Run322381_LS410to600 and THEN run the scan
    case 323524: return 323525; //2018 Sep 26 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1065392
    default: return -1;
    }
  }

  // Define Layer 1 Scans below
  int hv_l1(int run, int ls, int orbit, size_t new_module) {
    switch (run) {
      //2017 Aug 14- BPix only
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  200
        : orbit>= 25893295 && orbit<= 27555262 ? 20
        : orbit>= 28330958 && orbit<= 30839245 ? 40
        : orbit>= 31086371 && orbit<= 33101923 ? 60
        : orbit>= 33306543 && orbit<= 35318926 ? 80
        : orbit>= 35540868 && orbit<= 37585784 ? 100
        : orbit>= 37852370 && orbit<= 39959311 ? 125
        : orbit>= 40202874 && orbit<= 42720431 ? 150
	  : NOVAL_I;
    case 301665:
      return
        orbit>= 77324157 && orbit<= 79419701 ? 250
        //: orbit>= 80455017 && orbit<= 82826044 ? 300
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 13917167 && orbit<= 15973020 ? 300
        : orbit>= 16174936 && orbit<= 18219321 ? 350
        : orbit>= 18422306 && orbit<= 20510907 ? 400
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 53187072 && orbit<= 54926159 ? 100
        : orbit>= 55109298 && orbit<= 56829492 ? 150
        : orbit>= 57013653 && orbit<= 58709677 ? 200
        : orbit>= 58946988 && orbit<= 60681763 ? 250
        : orbit>= 60815499 && orbit<= 62466968 ? 300
        : orbit>= 62654706 && orbit<= 64322635 ? 400
        : orbit>= 51050070 && orbit<= 52540652 ? 350
	  : NOVAL_I;
    case 304366:
      return
        orbit>= 361573631 && orbit<= 363516914 ? 350
        : orbit>= 364797641 && orbit<= 365891215 ? 400
        : orbit>= 366475549 && orbit<= 367517242 ? 300
        : orbit>= 367754247 && orbit<= 368789142 ? 250
        : orbit>= 369031937 && orbit<= 370069599 ? 200
        : orbit>= 370284665 && orbit<= 371345448 ? 150
        : orbit>= 371508198 && orbit<= 372549884 ? 100
	  : NOVAL_I;
    case 305757:
      return
        orbit>= 322449 && orbit<= 2318208 ? 350
        : orbit>= 2695515 && orbit<= 4688758 ? 200
        : orbit>= 4930843 && orbit<= 6965323 ? 300
        : orbit>= 7258275 && orbit<= 9263379 ? 400
        : orbit>= 9531219 && orbit<= 11597950 ? 450
        : orbit>= 11810975 && orbit<= 13835041 ? 500
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 350
        : orbit>= 33508938 && orbit<= 34863045 ? 200
        : orbit>= 35029055 && orbit<= 36385601 ? 250
        : orbit>= 36578714 && orbit<= 37900572 ? 300
        : orbit>= 38096453 && orbit<= 39448792 ? 400
        : orbit>= 39615128 && orbit<= 40968785 ? 450
        : orbit>= 41189573 && orbit<= 42519606 ? 500
        : orbit>= 65564341 && orbit<= 66916772 ? 550
        : orbit>= 67303535 && orbit<= 68633680 ? 350
	  : NOVAL_I;
	case 314650: if (!new_module) {
	  return
	    orbit>= 6420813 && orbit<= 8920028 ? 40
	    : orbit>= 9079479 && orbit<= 11564280 ? 80
	    : orbit>= 11697253 && orbit<= 14173543 ? 120
	    : orbit>= 14305228 && orbit<= 16805427 ? 160
	    : orbit>= 16938685 && orbit<= 19429425 ? 200
	    : orbit>= 19592404 && orbit<= 22037920 ? 240
	    : orbit>= 22230759 && orbit<= 24653670 ? 280
	    : orbit>= 24845652 && orbit<= 27291213 ? 320
	    : orbit>= 27425927 && orbit<= 29896275 ? 350
	    : orbit>= 30083588 && orbit<= 38039473 ? 400
	    : orbit>= 38093140 && orbit<= 40650759 ? 450
	    : orbit>= 40704334 && orbit<= 43263306 ? 500
	    : orbit>= 43317589 && orbit<= 45901087 ? 550
	    : orbit>= 45954366 && orbit<= 48526405 ? 600
	      : NOVAL_I;
		}
		else {
	return
	    orbit>= 6420813 && orbit<= 8920028 ? 40
	    : orbit>= 9079479 && orbit<= 11564280 ? 80
	    : orbit>= 11697253 && orbit<= 14173543 ? 120
	    : orbit>= 14305228 && orbit<= 16805427 ? 160
	    : orbit>= 16938685 && orbit<= 19429425 ? 200
	    : orbit>= 19592404 && orbit<= 22037920 ? 240
	    : orbit>= 22230759 && orbit<= 24653670 ? 280
	    : orbit>= 24845652 && orbit<= 27291213 ? 320
	    : orbit>= 27425927 && orbit<= 29896275 ? 350
	      : NOVAL_I;
		}
	case 314663: if (!new_module) {
	  return
	    orbit>= 911898 && orbit<= 3421960 ? 20
	    : orbit>= 3661667 && orbit<= 6308404 ? 60
	    : orbit>= 6498162 && orbit<= 8924156 ? 100
	    : orbit>= 9109692 && orbit<= 11550884 ? 140
	    : orbit>= 11738499 && orbit<= 14167802 ? 180
	    : orbit>= 52232541 && orbit<= 54814596 ? 220
	    : orbit>= 55027775 && orbit<= 57434463 ? 260
	    : orbit>= 57621826 && orbit<= 60041253 ? 300
	    : orbit>= 60282248 && orbit<= 62926161 ? 375
	    : orbit>= 62979440 && orbit<= 65587041 ? 425
	    : orbit>= 65614586 && orbit<= 68183155 ? 475
	    : orbit>= 68236952 && orbit<= 70799702 ? 525
	    : orbit>= 70853442 && orbit<= 73430481 ? 575
	      : NOVAL_I;
		}
		else {
	return
	    orbit>= 911898 && orbit<= 3421960 ? 20
	    : orbit>= 3661667 && orbit<= 6308404 ? 60
	    : orbit>= 6498162 && orbit<= 8924156 ? 100
	    : orbit>= 9109692 && orbit<= 11550884 ? 140
	    : orbit>= 11738499 && orbit<= 14167802 ? 180
	    : orbit>= 52232541 && orbit<= 54814596 ? 220
	    : orbit>= 55027775 && orbit<= 57434463 ? 260
	    : orbit>= 57621826 && orbit<= 60041253 ? 300
	      : NOVAL_I;
		}
  case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 20
	    : orbit>= 41825841 && orbit<= 44322177 ? 40
	    : orbit>= 44480767 && orbit<= 46948744 ? 60
	    : orbit>= 47135051 && orbit<= 49565502 ? 80
	    : orbit>= 49728746 && orbit<= 52187784 ? 100
	    : orbit>= 52322198 && orbit<= 54804994 ? 120
	    : orbit>= 54969957 && orbit<= 57440386 ? 140
	    : orbit>= 57553203 && orbit<= 60043347 ? 160
	    : orbit>= 60176652 && orbit<= 62671231 ? 180
	    : orbit>= 62830841 && orbit<= 65299490 ? 200
	    : orbit>= 65460761 && orbit<= 67931853 ? 240
	    : orbit>= 68119359 && orbit<= 70522726 ? 280
	    : orbit>= 70683404 && orbit<= 73153756 ? 320
	    : orbit>= 73311203 && orbit<= 75775055 ? 350
	    : orbit>= 75933126 && orbit<= 78397728 ? 400
	    : orbit>= 78988711 && orbit<= 81533957 ? 10
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 20
	    : orbit>= 27391881 && orbit<= 29910318 ? 40
	    : orbit>= 30048261 && orbit<= 32528621 ? 60
	    : orbit>= 32692410 && orbit<= 35184550 ? 80
	    : orbit>= 35347550 && orbit<= 37766749 ? 100
	    : orbit>= 37964504 && orbit<= 40393240 ? 120
	    : orbit>= 40564372 && orbit<= 43001725 ? 140
	    : orbit>= 43111459 && orbit<= 45637231 ? 160
	    : orbit>= 45800722 && orbit<= 48263040 ? 180
	    : orbit>= 48454863 && orbit<= 50886070 ? 200
	    : orbit>= 51052187 && orbit<= 53510050 ? 240
	    : orbit>= 53672834 && orbit<= 56130806 ? 280
	    : orbit>= 56294595 && orbit<= 58752882 ? 320
	    : orbit>= 58889269 && orbit<= 61372970 ? 350
	    : orbit>= 61571382 && orbit<= 63995005 ? 400
	    : orbit>= 64601416 && orbit<= 67138847 ? 10
	    : orbit>= 67357410 && orbit<= 70015053 ? 30
	    : orbit>= 70179388 && orbit<= 72631784 ? 50
	    : orbit>= 72823108 && orbit<= 75250636 ? 70
	    : orbit>= 75639209 && orbit<= 75775182 ? 400
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 20
	    : orbit>= 47613845 && orbit<= 50105260 ? 40
	    : orbit>= 50188211 && orbit<= 52709208 ? 60
	    : orbit>= 52895444 && orbit<= 55339608 ? 80
	    : orbit>= 55500867 && orbit<= 57952349 ? 100
	    : orbit>= 58141198 && orbit<= 60574900 ? 120
	    : orbit>= 60717816 && orbit<= 63221110 ? 140
	    : orbit>= 63329551 && orbit<= 65809487 ? 160
	    : orbit>= 65969746 && orbit<= 68435462 ? 180
	    : orbit>= 68575779 && orbit<= 71053332 ? 200
	    : orbit>= 71220080 && orbit<= 73688468 ? 240
	    : orbit>= 73877439 && orbit<= 76301206 ? 280
	    : orbit>= 76461185 && orbit<= 78925237 ? 320
	    : orbit>= 79058767 && orbit<= 81554007 ? 350
	    : orbit>= 81740951 && orbit<= 84170667 ? 400
	    : orbit>= 84770465 && orbit<= 87321138 ? 10
	    : orbit>= 87514391 && orbit<= 89930989 ? 30
	    : orbit>= 90122374 && orbit<= 92565760 ? 50
	    : orbit>= 92754465 && orbit<= 95185550 ? 70
	    : orbit>= 95563605 && orbit<= 95697795 ? 400
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 20
	    : orbit>= 47854891 && orbit<= 50359955 ? 40
	    : orbit>= 50522239 && orbit<= 52977308 ? 60
	    : orbit>= 53113522 && orbit<= 55616572 ? 80
	    : orbit>= 55755315 && orbit<= 58228213 ? 100
	    : orbit>= 58372274 && orbit<= 60827613 ? 120
	    : orbit>= 60995674 && orbit<= 63463695 ? 140
	    : orbit>= 63631902 && orbit<= 66076490 ? 160
	    : orbit>= 66213020 && orbit<= 68722423 ? 180
	    : orbit>= 68890165 && orbit<= 71333543 ? 200
	    : orbit>= 71498800 && orbit<= 73941265 ? 240
	    : orbit>= 74129851 && orbit<= 76570264 ? 280
	    : orbit>= 76734342 && orbit<= 79189022 ? 320
	    : orbit>= 79329459 && orbit<= 81814529 ? 350
	    : orbit>= 82013635 && orbit<= 84419465 ? 400
	    : orbit>= 85001650 && orbit<= 87569257 ? 10
	    : orbit>= 87759543 && orbit<= 90188057 ? 30
	    : orbit>= 90323314 && orbit<= 92815992 ? 50
	    : orbit>= 92953354 && orbit<= 95441167 ? 70
	    : orbit>= 95791830 && orbit<= 95961670 ? 400
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 20
	    : orbit>= 9566810 && orbit<= 12075322 ? 40
	    : orbit>= 12213121 && orbit<= 14717975 ? 60
	    : orbit>= 14853577 && orbit<= 17316216 ? 80
	    : orbit>= 17503961 && orbit<= 19935530 ? 100
	    : orbit>= 20071439 && orbit<= 22554342 ? 120
	    : orbit>= 22715316 && orbit<= 25193763 ? 140
	    : orbit>= 25355311 && orbit<= 27817230 ? 160
	    : orbit>= 27926532 && orbit<= 30416278 ? 180
	    : orbit>= 30527882 && orbit<= 33049984 ? 200
	    : orbit>= 33212050 && orbit<= 35664191 ? 240
	    : orbit>= 35826282 && orbit<= 38287417 ? 280
	    : orbit>= 38504148 && orbit<= 40914406 ? 320
	    : orbit>= 41077682 && orbit<= 43524088 ? 350
	    : orbit>= 43659205 && orbit<= 46161085 ? 400
	    : orbit>= 46728740 && orbit<= 49298332 ? 10
	    : orbit>= 49493037 && orbit<= 51915397 ? 30
	    : orbit>= 52049768 && orbit<= 54561617 ? 50
	    : orbit>= 54723510 && orbit<= 57164897 ? 70
	    : orbit>= 57487275 && orbit<= 57702598 ? 400
	      : NOVAL_I;
  case 320500:
	  return
	    orbit>= 38982534 && orbit<= 41435000 ? 80
	    : orbit>= 41649491 && orbit<= 44097390 ? 120
	    : orbit>= 44286534 && orbit<= 46932167 ? 160
	    : orbit>= 47145590 && orbit<= 49569757 ? 200
	    : orbit>= 49783965 && orbit<= 52205093 ? 240
	    : orbit>= 52338511 && orbit<= 54814731 ? 280
	    : orbit>= 55030138 && orbit<= 57699575 ? 320
	    : orbit>= 57887403 && orbit<= 60333176 ? 350
	    : orbit>= 60520568 && orbit<= 62945798 ? 400
	    : orbit>= 63240246 && orbit<= 65820242 ? 300
	    : orbit>= 66063657 && orbit<= 68711384 ? 260
	    : orbit>= 68955890 && orbit<= 71622151 ? 220
	    : orbit>= 71809121 && orbit<= 74494756 ? 180
	    : orbit>= 74684169 && orbit<= 77128923 ? 140
	    : orbit>= 77263372 && orbit<= 79715401 ? 100
	    : orbit>= 79984054 && orbit<= 82591209 ? 60
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 20
	    : orbit>= 4370646 && orbit<= 6835331 ? 40
	    : orbit>= 6998249 && orbit<= 9443899 ? 60
	    : orbit>= 9603408 && orbit<= 12088965 ? 80
	    : orbit>= 12249948 && orbit<= 14691253 ? 100
	    : orbit>= 14824908 && orbit<= 17317702 ? 120
	    : orbit>= 17479610 && orbit<= 19929276 ? 140
	    : orbit>= 20117009 && orbit<= 22560727 ? 160
	    : orbit>= 22748255 && orbit<= 25191626 ? 180
	    : orbit>= 25299297 && orbit<= 27799610 ? 200
	    : orbit>= 27936056 && orbit<= 30437130 ? 240
	    : orbit>= 30629196 && orbit<= 33078612 ? 280
	    : orbit>= 33186971 && orbit<= 35673738 ? 320
	    : orbit>= 35860673 && orbit<= 38283804 ? 350
	    : orbit>= 38417265 && orbit<= 40915199 ? 400
	    : orbit>= 41076211 && orbit<= 43523705 ? 450
	    : orbit>= 43709569 && orbit<= 46158773 ? 500
	    : orbit>= 46346107 && orbit<= 48766767 ? 550
	    : orbit>= 48954620 && orbit<= 51396578 ? 600
	    : orbit>= 51746675 && orbit<= 51933237 ? 400
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 20
	    : orbit>= 63075867 && orbit<= 65549032 ? 40
	    : orbit>= 65683169 && orbit<= 68178385 ? 60
	    : orbit>= 68339788 && orbit<= 70786533 ? 80
	    : orbit>= 70945624 && orbit<= 73405782 ? 100
	    : orbit>= 73539162 && orbit<= 76031847 ? 120
	    : orbit>= 76194593 && orbit<= 78661829 ? 140
	    : orbit>= 78793861 && orbit<= 81294346 ? 160
	    : orbit>= 81402558 && orbit<= 83913027 ? 180
	    : orbit>= 84019032 && orbit<= 86545026 ? 200
	    : orbit>= 86678270 && orbit<= 89173927 ? 240
	    : orbit>= 89360682 && orbit<= 91778781 ? 280
	    : orbit>= 91965880 && orbit<= 94679839 ? 320
	    : orbit>= 94865315 && orbit<= 97286456 ? 350
	    : orbit>= 97472797 && orbit<= 99884436 ? 400
	    : orbit>= 100098900 && orbit<= 102523723 ? 450
	    : orbit>= 102708961 && orbit<= 105133240 ? 500
	    : orbit>= 105290722 && orbit<= 107757020 ? 550
	    : orbit>= 107888477 && orbit<= 110382854 ? 600
	    : orbit>= 110727354 && orbit<= 110914389 ? 400
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 20
	    : orbit>= 58114200 && orbit<= 60588212 ? 40
	    : orbit>= 60724340 && orbit<= 63202264 ? 60
	    : orbit>= 63340322 && orbit<= 65817097 ? 80
	    : orbit>= 65979355 && orbit<= 68425849 ? 100
	    : orbit>= 68561709 && orbit<= 71071128 ? 120
	    : orbit>= 71233215 && orbit<= 73688647 ? 140
	    : orbit>= 73852199 && orbit<= 76310213 ? 160
	    : orbit>= 76473584 && orbit<= 78927087 ? 180
	    : orbit>= 79093199 && orbit<= 81541766 ? 200
	    : orbit>= 81704609 && orbit<= 84163799 ? 240
	    : orbit>= 84355052 && orbit<= 86800517 ? 280
	    : orbit>= 86965497 && orbit<= 89409147 ? 320
	    : orbit>= 89572559 && orbit<= 92042263 ? 350
	    : orbit>= 92204778 && orbit<= 94675917 ? 400
	    : orbit>= 94838548 && orbit<= 97280347 ? 450
	    : orbit>= 97470307 && orbit<= 99890291 ? 500
	    : orbit>= 100079665 && orbit<= 102522741 ? 550
	    : orbit>= 102712865 && orbit<= 105177376 ? 600
	    : orbit>= 105524648 && orbit<= 105659424 ? 400
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 20
	    : orbit>= 43422348 && orbit<= 45881929 ? 40
	    : orbit>= 46018056 && orbit<= 48516945 ? 60
	    : orbit>= 48678223 && orbit<= 51169750 ? 80
	    : orbit>= 51304556 && orbit<= 53771512 ? 100
	    : orbit>= 53932342 && orbit<= 56381384 ? 120
	    : orbit>= 56516448 && orbit<= 59011528 ? 140
	    : orbit>= 59200521 && orbit<= 61617940 ? 160
	    : orbit>= 61753974 && orbit<= 64253057 ? 180
	    : orbit>= 64390607 && orbit<= 66854828 ? 200
	    : orbit>= 67018750 && orbit<= 69485929 ? 240
	    : orbit>= 69648708 && orbit<= 72118854 ? 280
	    : orbit>= 72306340 && orbit<= 74742683 ? 320
	    : orbit>= 74932909 && orbit<= 77350840 ? 350
	    : orbit>= 77510220 && orbit<= 79977923 ? 400
	    : orbit>= 80140120 && orbit<= 82583218 ? 450
	    : orbit>= 82772153 && orbit<= 85219004 ? 500
	    : orbit>= 85380942 && orbit<= 87843975 ? 550
	    : orbit>= 88036981 && orbit<= 90452859 ? 600
	    : orbit>= 90754006 && orbit<= 90996042 ? 450
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 20
	    : orbit>= 52868613 && orbit<= 55321785 ? 40
	    : orbit>= 55462104 && orbit<= 57973413 ? 60
	    : orbit>= 58087326 && orbit<= 60562624 ? 80
	    : orbit>= 60709545 && orbit<= 63210483 ? 100
	    : orbit>= 63359047 && orbit<= 65804852 ? 120
	    : orbit>= 65946954 && orbit<= 68434710 ? 140
	    : orbit>= 68605001 && orbit<= 71096881 ? 160
	    : orbit>= 71238107 && orbit<= 73690920 ? 180
	    : orbit>= 73860855 && orbit<= 76295804 ? 200
	    : orbit>= 76465735 && orbit<= 78930971 ? 240
	    : orbit>= 79102261 && orbit<= 81539075 ? 280
	    : orbit>= 81714638 && orbit<= 84171548 ? 320
	    : orbit>= 84349817 && orbit<= 86788381 ? 350
	    : orbit>= 86964660 && orbit<= 89396615 ? 400
	    : orbit>= 89567078 && orbit<= 92044434 ? 450
	    : orbit>= 92212873 && orbit<= 94683362 ? 500
	    : orbit>= 94878471 && orbit<= 97549671 ? 550
	    : orbit>= 97720736 && orbit<= 100166254 ? 600
	    : orbit>= 100483993 && orbit<= 100681077 ? 450
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l1

  // Define Layer 2 Scans below
  int hv_l2(int run, int ls, int orbit) {
    switch (run) {
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  250
        : orbit>= 44709363 && orbit<= 46827299 ? 20
        : orbit>= 47071394 && orbit<= 49087949 ? 40
        : orbit>= 49394950 && orbit<= 51390927 ? 60
        : orbit>= 51679134 && orbit<= 53696916 ? 80
        : orbit>= 53938797 && orbit<= 55956366 ? 100
        : orbit>= 56199888 && orbit<= 58205548 ? 125
        : orbit>= 58450947 && orbit<= 60484847 ? 150
        : orbit>= 60841624 && orbit<= 62847234 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 64754455 && orbit<= 66710200 ? 50
        : orbit>= 66873391 && orbit<= 68611595 ? 100
        : orbit>= 68805047 && orbit<= 70485574 ? 150
        : orbit>= 70643566 && orbit<= 72331977 ? 200
        : orbit>= 51050070 && orbit<= 52540652 ? 250
        : orbit>= 85271381 && orbit<= 86949588 ? 300
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 250
        : orbit>= 43933973 && orbit<= 45279891 ? 150
        : orbit>= 45502221 && orbit<= 46856313 ? 200
        : orbit>= 47079116 && orbit<= 48431144 ? 300
        : orbit>= 48652014 && orbit<= 50012383 ? 350
        : orbit>= 50179764 && orbit<= 51532937 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 250
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 49203187 && orbit<= 51690032 ? 10
	    : orbit>= 51856967 && orbit<= 54283208 ? 20
	    : orbit>= 54445915 && orbit<= 56892967 ? 30
	    : orbit>= 57051839 && orbit<= 59538529 ? 40
	    : orbit>= 59697915 && orbit<= 62135204 ? 50
	    : orbit>= 62297225 && orbit<= 64782381 ? 60
	    : orbit>= 64943299 && orbit<= 67376977 ? 70
	    : orbit>= 67538741 && orbit<= 69999871 ? 80
	    : orbit>= 70139184 && orbit<= 72643799 ? 90
	    : orbit>= 72835854 && orbit<= 75255306 ? 100
	    : orbit>= 75446590 && orbit<= 77886498 ? 150
	    : orbit>= 78101351 && orbit<= 80773664 ? 200
	    : orbit>= 80938519 && orbit<= 83389351 ? 250
	    : orbit>= 83580458 && orbit<= 86015149 ? 300
	    : orbit>= 86258748 && orbit<= 88893999 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 14541227 && orbit<= 17055893 ? 125
	    : orbit>= 17244195 && orbit<= 19668685 ? 175
	    : orbit>= 19856002 && orbit<= 22294753 ? 225
	    : orbit>= 22585205 && orbit<= 25181837 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
  case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 250
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 250
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 250
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 320500:
	  return
	    orbit>= 84029426 && orbit<= 86514704 ? 20
	    : orbit>= 86704248 && orbit<= 89148784 ? 60
	    : orbit>= 89309079 && orbit<= 91796643 ? 100
	    : orbit>= 91955453 && orbit<= 94408266 ? 150
	    : orbit>= 94595917 && orbit<= 97306966 ? 200
	    : orbit>= 97519296 && orbit<= 100166193 ? 250
	    : orbit>= 100404858 && orbit<= 103044431 ? 300
	    : orbit>= 103257788 && orbit<= 105688471 ? 350
	    : orbit>= 105928441 && orbit<= 108559000 ? 400
	    : orbit>= 108878023 && orbit<= 111439160 ? 275
	    : orbit>= 111680359 && orbit<= 114320642 ? 225
	    : orbit>= 114454314 && orbit<= 116944501 ? 175
	    : orbit>= 117182640 && orbit<= 119852547 ? 125
	    : orbit>= 120093836 && orbit<= 122737282 ? 80
	    : orbit>= 122977071 && ls<= 477 ? 40
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 300
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 300
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l2
  
  // Define Layer 3 Scans below
  int hv_l3(int run, int ls, int orbit) {
    switch (run) {
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  100
        : orbit>= 63271699 && orbit<= 65364783 ? 20
        : orbit>= 65661133 && orbit<= 67651616 ? 40
        : orbit>= 67895036 && orbit<= 69885566 ? 60
        : orbit>= 70132973 && orbit<= 72145405 ? 80
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 22840887 && orbit<= 24889630 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 87484993 && orbit<= 89032277 ? 50
        : orbit>= 89218917 && orbit<= 90844165 ? 100
        : orbit>= 91034966 && orbit<= 92594483 ? 150
        : orbit>= 92784418 && orbit<= 94341300 ? 250
        : orbit>= 51050070 && orbit<= 52540652 ? 200
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 200
        : orbit>= 52140033 && orbit<= 53489015 ? 100
        : orbit>= 53655274 && orbit<= 55006273 ? 150
        : orbit>= 55172056 && orbit<= 56522975 ? 250
        : orbit>= 56690865 && orbit<= 58043147 ? 300
        : orbit>= 67303535 && orbit<= 68633680 ? 200
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 89689664 && orbit<= 92311119 ? 10
	    : orbit>= 92472812 && orbit<= 94927270 ? 20
	    : orbit>= 95120809 && orbit<= 97536875 ? 30
	    : orbit>= 97703946 && orbit<= 100168652 ? 40
	    : orbit>= 100334028 && orbit<= 102783139 ? 50
	    : orbit>= 102972115 && orbit<= 105406833 ? 60
	    : orbit>= 105594033 && orbit<= 108059073 ? 70
	    : orbit>= 108246648 && orbit<= 110908752 ? 80
	    : orbit>= 111095814 && orbit<= 113516127 ? 90
	    : orbit>= 113704728 && orbit<= 116158230 ? 100
	    : orbit>= 116345830 && orbit<= 118778641 ? 150
	    : orbit>= 118991865 && orbit<= 121399693 ? 200
	    : orbit>= 121481216 && orbit<= 124017418 ? 250
	    : orbit>= 124231352 && orbit<= 126620937 ? 300
	    : orbit>= 126840130 && orbit<= 129247729 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 25614942 && orbit<= 28068392 ? 125
	    : orbit>= 28261245 && orbit<= 30691838 ? 175
	    : orbit>= 30825898 && orbit<= 33304291 ? 225
	    : orbit>= 33569057 && orbit<= 36202926 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
  case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 200
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 200
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 200
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 250
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 3912124 && orbit<= 6576017 ? 10
	    : orbit>= 6739153 && orbit<= 9219039 ? 20
	    : orbit>= 9406451 && orbit<= 11820881 ? 30
	    : orbit>= 12008626 && orbit<= 14437338 ? 40
	    : orbit>= 14625889 && orbit<= 17098820 ? 50
	    : orbit>= 17260535 && orbit<= 19680876 ? 60
	    : orbit>= 19868619 && orbit<= 22292703 ? 70
	    : orbit>= 22481459 && orbit<= 24931178 ? 80
	    : orbit>= 25065836 && orbit<= 27546766 ? 90
	    : orbit>= 27706651 && orbit<= 30152915 ? 100
	    : orbit>= 30369098 && orbit<= 32798197 ? 125
	    : orbit>= 32986003 && orbit<= 35437784 ? 150
	    : orbit>= 35625697 && orbit<= 38024355 ? 175
	    : orbit>= 38213131 && orbit<= 40662809 ? 200
	    : orbit>= 40796989 && orbit<= 43264760 ? 250
	    : orbit>= 43425814 && orbit<= 45906240 ? 300
	    : orbit>= 46121187 && orbit<= 48813848 ? 400
	    : orbit>= 49136071 && orbit<= 49322439 ? 250
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 250
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 250
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 250
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 250
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 250
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l3
  
  // Define Layer 4 Scans below
  int hv_l4(int run, int ls, int orbit) {
    switch (run) {
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  100
        : orbit>= 72564229 && orbit<= 74538859 ? 20
        : orbit>= 74806268 && orbit<= 76837010 ? 40
        : orbit>= 77124490 && orbit<= 79431314 ? 60
        : orbit>= 79633779 && orbit<= 81639444 ? 80
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 22840887 && orbit<= 24889630 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 94873693 && orbit<= 96446818 ? 50
        : orbit>= 96607690 && orbit<= 98148974 ? 100
        : orbit>= 98359529 && orbit<= 99507810 ? 150
        : orbit>= 99719028 && orbit<= 101739533 ? 250
        : orbit>= 51050070 && orbit<= 52540652 ? 200
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 200
        : orbit>= 58596169 && orbit<= 59922216 ? 100
        : orbit>= 60115178 && orbit<= 61470624 ? 150
        : orbit>= 61691015 && orbit<= 63023819 ? 250
        : orbit>= 63217766 && orbit<= 64543879 ? 300
        : orbit>= 67303535 && orbit<= 68633680 ? 200
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 130381323 && orbit<= 132934980 ? 5
	    : orbit>= 133068722 && orbit<= 135540254 ? 10
	    : orbit>= 135674536 && orbit<= 138174246 ? 15
	    : orbit>= 138309330 && orbit<= 140800465 ? 20
	    : orbit>= 140971902 && orbit<= 143422950 ? 25
	    : orbit>= 143593020 && orbit<= 146031871 ? 30
	    : orbit>= 146174267 && orbit<= 148653151 ? 40
	    : orbit>= 148840032 && orbit<= 151285917 ? 50
	    : orbit>= 151418525 && orbit<= 153884225 ? 60
	    : orbit>= 154043043 && orbit<= 156531499 ? 80
	    : orbit>= 156743742 && orbit<= 159400350 ? 100
	    : orbit>= 159585302 && orbit<= 162013799 ? 150
	    : orbit>= 162225719 && orbit<= 164645494 ? 200
	    : orbit>= 164779000 && orbit<= 167279487 ? 250
	    : orbit>= 167492317 && orbit<= 170146283 ? 350
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 36637269 && orbit<= 39091295 ? 125
	    : orbit>= 39304209 && orbit<= 41964093 ? 175
	    : orbit>= 42177100 && orbit<= 44594783 ? 300
	    : orbit>= 44840392 && orbit<= 47458916 ? 400
	    : orbit>= 73868092 && orbit<= 76298442 ? 70
	    : orbit>= 76458346 && orbit<= 78926316 ? 90
	    : orbit>= 79194684 && orbit<= 81795818 ? 225
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 5
	    : orbit>= 41825841 && orbit<= 44322177 ? 10
	    : orbit>= 44480767 && orbit<= 46948744 ? 15
	    : orbit>= 47135051 && orbit<= 49565502 ? 20
	    : orbit>= 49728746 && orbit<= 52187784 ? 25
	    : orbit>= 52322198 && orbit<= 54804994 ? 30
	    : orbit>= 54969957 && orbit<= 57440386 ? 40
	    : orbit>= 57553203 && orbit<= 60043347 ? 50
	    : orbit>= 60176652 && orbit<= 62671231 ? 60
	    : orbit>= 62830841 && orbit<= 65299490 ? 80
	    : orbit>= 65460761 && orbit<= 67931853 ? 100
	    : orbit>= 68119359 && orbit<= 70522726 ? 125
	    : orbit>= 70683404 && orbit<= 73153756 ? 150
	    : orbit>= 73311203 && orbit<= 75775055 ? 175
	    : orbit>= 75933126 && orbit<= 78397728 ? 200
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 5
	    : orbit>= 27391881 && orbit<= 29910318 ? 10
	    : orbit>= 30048261 && orbit<= 32528621 ? 15
	    : orbit>= 32692410 && orbit<= 35184550 ? 20
	    : orbit>= 35347550 && orbit<= 37766749 ? 25
	    : orbit>= 37964504 && orbit<= 40393240 ? 30
	    : orbit>= 40564372 && orbit<= 43001725 ? 40
	    : orbit>= 43111459 && orbit<= 45637231 ? 50
	    : orbit>= 45800722 && orbit<= 48263040 ? 60
	    : orbit>= 48454863 && orbit<= 50886070 ? 80
	    : orbit>= 51052187 && orbit<= 53510050 ? 100
	    : orbit>= 53672834 && orbit<= 56130806 ? 125
	    : orbit>= 56294595 && orbit<= 58752882 ? 150
	    : orbit>= 58889269 && orbit<= 61372970 ? 175
	    : orbit>= 61571382 && orbit<= 63995005 ? 200
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 200
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 5
	    : orbit>= 47613845 && orbit<= 50105260 ? 10
	    : orbit>= 50188211 && orbit<= 52709208 ? 15
	    : orbit>= 52895444 && orbit<= 55339608 ? 20
	    : orbit>= 55500867 && orbit<= 57952349 ? 25
	    : orbit>= 58141198 && orbit<= 60574900 ? 30
	    : orbit>= 60717816 && orbit<= 63221110 ? 40
	    : orbit>= 63329551 && orbit<= 65809487 ? 50
	    : orbit>= 65969746 && orbit<= 68435462 ? 60
	    : orbit>= 68575779 && orbit<= 71053332 ? 80
	    : orbit>= 71220080 && orbit<= 73688468 ? 100
	    : orbit>= 73877439 && orbit<= 76301206 ? 125
	    : orbit>= 76461185 && orbit<= 78925237 ? 150
	    : orbit>= 79058767 && orbit<= 81554007 ? 175
	    : orbit>= 81740951 && orbit<= 84170667 ? 200
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 200
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 5
	    : orbit>= 47854891 && orbit<= 50359955 ? 10
	    : orbit>= 50522239 && orbit<= 52977308 ? 15
	    : orbit>= 53113522 && orbit<= 55616572 ? 20
	    : orbit>= 55755315 && orbit<= 58228213 ? 25
	    : orbit>= 58372274 && orbit<= 60827613 ? 30
	    : orbit>= 60995674 && orbit<= 63463695 ? 40
	    : orbit>= 63631902 && orbit<= 66076490 ? 50
	    : orbit>= 66213020 && orbit<= 68722423 ? 60
	    : orbit>= 68890165 && orbit<= 71333543 ? 80
	    : orbit>= 71498800 && orbit<= 73941265 ? 100
	    : orbit>= 74129851 && orbit<= 76570264 ? 125
	    : orbit>= 76734342 && orbit<= 79189022 ? 150
	    : orbit>= 79329459 && orbit<= 81814529 ? 175
	    : orbit>= 82013635 && orbit<= 84419465 ? 200
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 200
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 5
	    : orbit>= 9566810 && orbit<= 12075322 ? 10
	    : orbit>= 12213121 && orbit<= 14717975 ? 15
	    : orbit>= 14853577 && orbit<= 17316216 ? 20
	    : orbit>= 17503961 && orbit<= 19935530 ? 25
	    : orbit>= 20071439 && orbit<= 22554342 ? 30
	    : orbit>= 22715316 && orbit<= 25193763 ? 40
	    : orbit>= 25355311 && orbit<= 27817230 ? 50
	    : orbit>= 27926532 && orbit<= 30416278 ? 60
	    : orbit>= 30527882 && orbit<= 33049984 ? 80
	    : orbit>= 33212050 && orbit<= 35664191 ? 100
	    : orbit>= 35826282 && orbit<= 38287417 ? 125
	    : orbit>= 38504148 && orbit<= 40914406 ? 150
	    : orbit>= 41077682 && orbit<= 43524088 ? 175
	    : orbit>= 43659205 && orbit<= 46161085 ? 200
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 250
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 49778311 && orbit<= 52174583 ? 10
	    : orbit>= 52363057 && orbit<= 54817129 ? 20
	    : orbit>= 55005385 && orbit<= 57427140 ? 30
	    : orbit>= 57562288 && orbit<= 60062002 ? 40
	    : orbit>= 60276000 && orbit<= 62942731 ? 50
	    : orbit>= 63157045 && orbit<= 65820976 ? 60
	    : orbit>= 65955103 && orbit<= 68433339 ? 70
	    : orbit>= 68594223 && orbit<= 71098367 ? 80
	    : orbit>= 71260096 && orbit<= 73691039 ? 90
	    : orbit>= 73852017 && orbit<= 76301806 ? 100
	    : orbit>= 76437069 && orbit<= 78933364 ? 125
	    : orbit>= 79067620 && orbit<= 81537619 ? 150
	    : orbit>= 81697616 && orbit<= 84172962 ? 175
	    : orbit>= 84361974 && orbit<= 86801621 ? 200
	    : orbit>= 86988379 && orbit<= 89411122 ? 250
	    : orbit>= 89598437 && orbit<= 92041736 ? 300
	    : orbit>= 92283598 && orbit<= 94922442 ? 400
	    : orbit>= 95243781 && orbit<= 95431232 ? 250
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 5
	    : orbit>= 4370646 && orbit<= 6835331 ? 10
	    : orbit>= 6998249 && orbit<= 9443899 ? 15
	    : orbit>= 9603408 && orbit<= 12088965 ? 20
	    : orbit>= 12249948 && orbit<= 14691253 ? 25
	    : orbit>= 14824908 && orbit<= 17317702 ? 30
	    : orbit>= 17479610 && orbit<= 19929276 ? 40
	    : orbit>= 20117009 && orbit<= 22560727 ? 50
	    : orbit>= 22748255 && orbit<= 25191626 ? 60
	    : orbit>= 25299297 && orbit<= 27799610 ? 80
	    : orbit>= 27936056 && orbit<= 30437130 ? 100
	    : orbit>= 30629196 && orbit<= 33078612 ? 125
	    : orbit>= 33186971 && orbit<= 35673738 ? 150
	    : orbit>= 35860673 && orbit<= 38283804 ? 175
	    : orbit>= 38417265 && orbit<= 40915199 ? 200
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 250
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 5
	    : orbit>= 63075867 && orbit<= 65549032 ? 10
	    : orbit>= 65683169 && orbit<= 68178385 ? 15
	    : orbit>= 68339788 && orbit<= 70786533 ? 20
	    : orbit>= 70945624 && orbit<= 73405782 ? 25
	    : orbit>= 73539162 && orbit<= 76031847 ? 30
	    : orbit>= 76194593 && orbit<= 78661829 ? 40
	    : orbit>= 78793861 && orbit<= 81294346 ? 50
	    : orbit>= 81402558 && orbit<= 83913027 ? 60
	    : orbit>= 84019032 && orbit<= 86545026 ? 80
	    : orbit>= 86678270 && orbit<= 89173927 ? 100
	    : orbit>= 89360682 && orbit<= 91778781 ? 125
	    : orbit>= 91965880 && orbit<= 94679839 ? 150
	    : orbit>= 94865315 && orbit<= 97286456 ? 175
	    : orbit>= 97472797 && orbit<= 99884436 ? 200
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 250
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 5
	    : orbit>= 58114200 && orbit<= 60588212 ? 10
	    : orbit>= 60724340 && orbit<= 63202264 ? 15
	    : orbit>= 63340322 && orbit<= 65817097 ? 20
	    : orbit>= 65979355 && orbit<= 68425849 ? 25
	    : orbit>= 68561709 && orbit<= 71071128 ? 30
	    : orbit>= 71233215 && orbit<= 73688647 ? 40
	    : orbit>= 73852199 && orbit<= 76310213 ? 50
	    : orbit>= 76473584 && orbit<= 78927087 ? 60
	    : orbit>= 79093199 && orbit<= 81541766 ? 80
	    : orbit>= 81704609 && orbit<= 84163799 ? 100
	    : orbit>= 84355052 && orbit<= 86800517 ? 125
	    : orbit>= 86965497 && orbit<= 89409147 ? 150
	    : orbit>= 89572559 && orbit<= 92042263 ? 175
	    : orbit>= 92204778 && orbit<= 94675917 ? 200
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 250
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 5
	    : orbit>= 43422348 && orbit<= 45881929 ? 10
	    : orbit>= 46018056 && orbit<= 48516945 ? 15
	    : orbit>= 48678223 && orbit<= 51169750 ? 20
	    : orbit>= 51304556 && orbit<= 53771512 ? 25
	    : orbit>= 53932342 && orbit<= 56381384 ? 30
	    : orbit>= 56516448 && orbit<= 59011528 ? 40
	    : orbit>= 59200521 && orbit<= 61617940 ? 50
	    : orbit>= 61753974 && orbit<= 64253057 ? 60
	    : orbit>= 64390607 && orbit<= 66854828 ? 80
	    : orbit>= 67018750 && orbit<= 69485929 ? 100
	    : orbit>= 69648708 && orbit<= 72118854 ? 125
	    : orbit>= 72306340 && orbit<= 74742683 ? 150
	    : orbit>= 74932909 && orbit<= 77350840 ? 175
	    : orbit>= 77510220 && orbit<= 79977923 ? 200
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 250
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 5
	    : orbit>= 52868613 && orbit<= 55321785 ? 10
	    : orbit>= 55462104 && orbit<= 57973413 ? 15
	    : orbit>= 58087326 && orbit<= 60562624 ? 20
	    : orbit>= 60709545 && orbit<= 63210483 ? 25
	    : orbit>= 63359047 && orbit<= 65804852 ? 30
	    : orbit>= 65946954 && orbit<= 68434710 ? 40
	    : orbit>= 68605001 && orbit<= 71096881 ? 50
	    : orbit>= 71238107 && orbit<= 73690920 ? 60
	    : orbit>= 73860855 && orbit<= 76295804 ? 80
	    : orbit>= 76465735 && orbit<= 78930971 ? 100
	    : orbit>= 79102261 && orbit<= 81539075 ? 125
	    : orbit>= 81714638 && orbit<= 84171548 ? 150
	    : orbit>= 84349817 && orbit<= 86788381 ? 175
	    : orbit>= 86964660 && orbit<= 89396615 ? 200
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 250
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l4
  
  
  // Define Disk 1 Scans below
  int hv_d1(int run, int ls, int orbit) {
    switch (run) {
      //2017 May25 - FPix only
    case 295127:
      return
        orbit>= 2776807 && orbit<= 4835890 ? 10
        : orbit>= 6716073 && orbit<= 8715613 ? 20
	  : NOVAL_I;
    case 295128:
      return
        orbit>= 200333 && orbit<= 1961764 ? 30
        : orbit>= 3237710 && orbit<= 4971846 ? 40
        : orbit>= 7788614 && orbit<= 9517935 ? 50
        : orbit>= 10466037 && orbit<= 12197179 ? 60
        : orbit>= 13976185 && orbit<= 15773805 ? 80
        : orbit>= 17583931 && orbit<= 19359151 ? 100
        : orbit>= 21177001 && orbit<= 22918206 ? 125
        : orbit>= 88739037 && orbit<= 90548890 ? 70
        : orbit>= 91901665 && orbit<= 93666825 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 4820837 && orbit<= 6140910 ? 100
        : orbit>= 6278715 && orbit<= 7625165 ? 150
        : orbit>= 7791082 && orbit<= 9123014 ? 200
        : orbit>= 9315440 && orbit<= 10661707 ? 250
        : orbit>= 10826802 && orbit<= 12175187 ? 350
        : orbit>= 12338552 && orbit<= 13683570 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 130381323 && orbit<= 132934980 ? 10
	    : orbit>= 133068722 && orbit<= 135540254 ? 20
	    : orbit>= 135674536 && orbit<= 138174246 ? 30
	    : orbit>= 138309330 && orbit<= 140800465 ? 40
	    : orbit>= 140971902 && orbit<= 143422950 ? 50
	    : orbit>= 143593020 && orbit<= 146031871 ? 60
	    : orbit>= 146174267 && orbit<= 148653151 ? 70
	    : orbit>= 148840032 && orbit<= 151285917 ? 80
	    : orbit>= 151418525 && orbit<= 153884225 ? 90
	    : orbit>= 154043043 && orbit<= 156531499 ? 100
	    : orbit>= 156743742 && orbit<= 159400350 ? 150
	    : orbit>= 159585302 && orbit<= 162013799 ? 200
	    : orbit>= 162225719 && orbit<= 164645494 ? 250
	    : orbit>= 164779000 && orbit<= 167279487 ? 300
	    : orbit>= 167492317 && orbit<= 170146283 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 36637269 && orbit<= 39091295 ? 125
	    : orbit>= 39304209 && orbit<= 41964093 ? 175
	    : orbit>= 42177100 && orbit<= 44594783 ? 225
	    : orbit>= 44840392 && orbit<= 47458916 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 300
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 300
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 300
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 49778311 && orbit<= 52174583 ? 20
	    : orbit>= 52363057 && orbit<= 54817129 ? 40
	    : orbit>= 55005385 && orbit<= 57427140 ? 60
	    : orbit>= 57562288 && orbit<= 60062002 ? 80
	    : orbit>= 60276000 && orbit<= 62942731 ? 100
	    : orbit>= 63157045 && orbit<= 65820976 ? 125
	    : orbit>= 65955103 && orbit<= 68433339 ? 150
	    : orbit>= 68594223 && orbit<= 71098367 ? 175
	    : orbit>= 71260096 && orbit<= 73691039 ? 200
	    : orbit>= 73852017 && orbit<= 76301806 ? 225
	    : orbit>= 76437069 && orbit<= 78933364 ? 250
	    : orbit>= 79067620 && orbit<= 81537619 ? 275
	    : orbit>= 81697616 && orbit<= 84172962 ? 300
	    : orbit>= 84361974 && orbit<= 86801621 ? 325
	    : orbit>= 86988379 && orbit<= 89411122 ? 350
	    : orbit>= 89598437 && orbit<= 92041736 ? 375
	    : orbit>= 92283598 && orbit<= 94922442 ? 400
	    : orbit>= 95243781 && orbit<= 95431232 ? 300
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 350
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 350
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d1
  
  
  // Define Disk 2 Scans below
  int hv_d2(int run, int ls, int orbit) {
    switch (run) {
      //2017 May25 - FPix only
    case 295128:
      return
        orbit>= 28930462 && orbit<= 30717430 ? 20
        : orbit>= 32457066 && orbit<= 34197265 ? 40
        : orbit>= 35907256 && orbit<= 37678734 ? 60
        : orbit>= 39486371 && orbit<= 41250245 ? 80
        : orbit>= 42188777 && orbit<= 43924245 ? 100
        : orbit>= 45828839 && orbit<= 47579193 ? 125
        : orbit>= 96400768 && orbit<= 98255119 ? 10
	  : NOVAL_I;
    case 295130:
      return
        orbit>= 1504385 && orbit<= 3239211 ? 30
	  : NOVAL_I;
    case 295131:
      return
        orbit>= 1086058 && orbit<= 2849166 ? 50
        : orbit>= 4883221 && orbit<= 6660623 ? 70
        : orbit>= 8881952 && orbit<= 10668270 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 303795:
      return
        orbit>= 74609916 && orbit<= 76349774 ? 100
        : orbit>= 76533019 && orbit<= 78187809 ? 150
        : orbit>= 78380432 && orbit<= 80038745 ? 200
        : orbit>= 80255784 && orbit<= 81885676 ? 250
        : orbit>= 82097207 && orbit<= 83743814 ? 350
        : orbit>= 51050070 && orbit<= 52540652 ? 300
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 14315734 && orbit<= 15670544 ? 100
        : orbit>= 15863097 && orbit<= 17185585 ? 150
        : orbit>= 17378771 && orbit<= 18701788 ? 200
        : orbit>= 18894343 && orbit<= 20220649 ? 250
        : orbit>= 20412332 && orbit<= 21741408 ? 350
        : orbit>= 21907187 && orbit<= 23265703 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 89689664 && orbit<= 92311119 ? 10
	    : orbit>= 92472812 && orbit<= 94927270 ? 20
	    : orbit>= 95120809 && orbit<= 97536875 ? 30
	    : orbit>= 97703946 && orbit<= 100168652 ? 40
	    : orbit>= 100334028 && orbit<= 102783139 ? 50
	    : orbit>= 102972115 && orbit<= 105406833 ? 60
	    : orbit>= 105594033 && orbit<= 108059073 ? 70
	    : orbit>= 108246648 && orbit<= 110908752 ? 80
	    : orbit>= 111095814 && orbit<= 113516127 ? 90
	    : orbit>= 113704728 && orbit<= 116158230 ? 100
	    : orbit>= 116345830 && orbit<= 118778641 ? 150
	    : orbit>= 118991865 && orbit<= 121399693 ? 200
	    : orbit>= 121481216 && orbit<= 124017418 ? 250
	    : orbit>= 124231352 && orbit<= 126620937 ? 300
	    : orbit>= 126840130 && orbit<= 129247729 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 25614942 && orbit<= 28068392 ? 125
	    : orbit>= 28261245 && orbit<= 30691838 ? 175
	    : orbit>= 30825898 && orbit<= 33304291 ? 225
	    : orbit>= 33569057 && orbit<= 36202926 ? 350
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 3912124 && orbit<= 6576017 ? 20
	    : orbit>= 6739153 && orbit<= 9219039 ? 40
	    : orbit>= 9406451 && orbit<= 11820881 ? 60
	    : orbit>= 12008626 && orbit<= 14437338 ? 80
	    : orbit>= 14625889 && orbit<= 17098820 ? 100
	    : orbit>= 17260535 && orbit<= 19680876 ? 125
	    : orbit>= 19868619 && orbit<= 22292703 ? 150
	    : orbit>= 22481459 && orbit<= 24931178 ? 175
	    : orbit>= 25065836 && orbit<= 27546766 ? 200
	    : orbit>= 27706651 && orbit<= 30152915 ? 225
	    : orbit>= 30369098 && orbit<= 32798197 ? 250
	    : orbit>= 32986003 && orbit<= 35437784 ? 275
	    : orbit>= 35625697 && orbit<= 38024355 ? 300
	    : orbit>= 38213131 && orbit<= 40662809 ? 325
	    : orbit>= 40796989 && orbit<= 43264760 ? 350
	    : orbit>= 43425814 && orbit<= 45906240 ? 375
	    : orbit>= 46121187 && orbit<= 48813848 ? 400
	    : orbit>= 49136071 && orbit<= 49322439 ? 300
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d2
  
  int hv_d3(int run, int ls, int orbit) {
    switch (run) {
      //2017 May25 - FPix only
    case 295128:
      return
        orbit>= 50124837 && orbit<= 51854658 ? 20
        : orbit>= 53841226 && orbit<= 55572281 ? 40
        : orbit>= 57359349 && orbit<= 59137883 ? 60
        : orbit>= 60956178 && orbit<= 62800951 ? 80
        : orbit>= 65028459 && orbit<= 66862336 ? 100
        : orbit>= 68514163 && orbit<= 70420790 ? 125
	  : NOVAL_I;
    case 295131:
      return
        orbit>= 13480958 && orbit<= 15224488 ? 10
        : orbit>= 17053698 && orbit<= 18825620 ? 30
        : orbit>= 20990373 && orbit<= 22749603 ? 50
        : orbit>= 25048580 && orbit<= 26859190 ? 70
        : orbit>= 29047979 && orbit<= 30785239 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 23869216 && orbit<= 25219440 ? 100
        : orbit>= 25412179 && orbit<= 26740226 ? 150
        : orbit>= 26932231 && orbit<= 28276872 ? 200
        : orbit>= 28441837 && orbit<= 29804395 ? 250
        : orbit>= 29970783 && orbit<= 31324672 ? 350
        : orbit>= 31575328 && orbit<= 32923952 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 49203187 && orbit<= 51690032 ? 10
	    : orbit>= 51856967 && orbit<= 54283208 ? 20
	    : orbit>= 54445915 && orbit<= 56892967 ? 30
	    : orbit>= 57051839 && orbit<= 59538529 ? 40
	    : orbit>= 59697915 && orbit<= 62135204 ? 50
	    : orbit>= 62297225 && orbit<= 64782381 ? 60
	    : orbit>= 64943299 && orbit<= 67376977 ? 70
	    : orbit>= 67538741 && orbit<= 69999871 ? 80
	    : orbit>= 70139184 && orbit<= 72643799 ? 90
	    : orbit>= 72835854 && orbit<= 75255306 ? 100
	    : orbit>= 75446590 && orbit<= 77886498 ? 150
	    : orbit>= 78101351 && orbit<= 80773664 ? 200
	    : orbit>= 80938519 && orbit<= 83389351 ? 250
	    : orbit>= 83580458 && orbit<= 86015149 ? 300
	    : orbit>= 86258748 && orbit<= 88893999 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 14541227 && orbit<= 17055893 ? 125
	    : orbit>= 17244195 && orbit<= 19668685 ? 175
	    : orbit>= 19856002 && orbit<= 22294753 ? 225
	    : orbit>= 22585205 && orbit<= 25181837 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 300
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 300
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 300
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 300
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 300
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d3
  
  int bias_voltage(int hv_scan_no, int run, int ls, int orbit, int det, int lay, int disk, size_t l1_new_module) {
    if (hv_scan_no==-1) return det ? 300 : (run<238474 ? 150 : 200);
    return (det==1) ? ((disk==1) ? hv_d1(run, ls, orbit) : (disk==2) ? hv_d2(run, ls, orbit) : (disk==3) ? hv_d3(run, ls, orbit) : NOVAL_I) :
      ((lay==1) ? hv_l1(run, ls, orbit, l1_new_module) : (lay==2) ? hv_l2(run, ls, orbit) : (lay==3) ? hv_l3(run, ls, orbit) : (lay==4) ? hv_l4(run, ls, orbit) : NOVAL_I);
  }
  
  bool is_full_hv_scan(int n) {
    return n==0||n==1||n==2||n==3||n==4||n==5||n==6||n==12;
  }
  
  
  bool is_one_hv_group_scan(int hv_scan_no, int hv, bool det, int layer, int ladder, int module, int disk, int blade, int panel, int ring) {
    if (hv_scan_no==-1) return 0;
    if (hv==NOVAL_I) return 0;
    /*
    if (det) {
      // FPix_BmI_D1_ROG1_HV1
      if (disk==-1) return blade>0 && blade<4 && (panel+module)<4;
      else return 0;
    } else {
      //BPIX_BmO_SEC2/6_LYR1-2_HV1
      if (layer==1) return module<0  && ((hv_scan_no==1 && ladder==-3)||(hv_scan_no!=1 &&ladder==-7));
      //BPix_BpI_SEC7_LYR1-2_HV2 
      else if (layer==2) return module>0 && (ladder==13||ladder==14);
      //BPix_BpO_SEC2_LYR3_HV1
      else if (layer==3) return module>0 && (ladder==-4||ladder==-5||ladder==-6);
      else return 0;
    }
    */
    bool returnvalue=0;
    if (hv_scan_no==7 || hv_scan_no==8 || hv_scan_no==9 || hv_scan_no==10 || hv_scan_no==11) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==1) returnvalue= blade>5 && blade<9;
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC2_LYR1 (3 modules; 1 is new)
        if (layer==1) {
          if (ladder==-1 && module==-1) returnvalue= 1;
          if (ladder==-2 && module==-3) returnvalue= 1;
          if (ladder==-2 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    else if (hv_scan_no==6 || hv_scan_no==13 || hv_scan_no==14 || hv_scan_no==15 || hv_scan_no==16) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==1) returnvalue= blade>5 && blade<9;
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC7_LYR1
        if (layer==1) {
          if (ladder==-5 && module==-1) returnvalue= 1;
          if (ladder==-5 && module==-2) returnvalue= 1;
          if (ladder==-6 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    else if (hv_scan_no==17 || hv_scan_no==18) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC7_LYR1
        if (layer==1) {
          if (ladder==-5 && module==-1) returnvalue= 1;
          if (ladder==-5 && module==-2) returnvalue= 1;
          if (ladder==-6 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    return returnvalue;
  }
  
}// namespace scans
