/*
  Author:
    Janos Karancsi (and Marton Bartok)
  E-mail:
    janos.karancsi@cern.ch, karancsij@atomki.mta.hu
    marton.bartok@cern.ch
  
  Description:
    The program is used to creat histograms
    from the TimingStudy output files
    This version of PixelHistoMaker is used for Scans
  
  Version Info:
  VER   TimingStudy Ntuple version              Date created
 -2 :   v2928 SPLIT 0                           (used for 2010/2011 Data)
 -1 :   v3029 SPLIT 0                           (used for 2010/2011 Data)
  0 :   v3431 SPLIT 0                           (2012                - by Alberto/Janos/Joco/Silvia)
  1 :   v3533 SPLIT 0                           (2013 Apr24          - by Viktor)
  2 :   v3533 SPLIT 1 + alpha/beta              (2013 Apr28-May3     - by Viktor)
  3 :   v3734 SPLIT 1 + occupancy               (2013 May 13)
  4 :   v3735 SPLIT 1 + pileup reweighting      (2014 Feb 04)
  5 :   v3836 SPLIT 1 + resolution              (2014 Jun 16)
  6 :   v3938 SPLIT 1 + sizeXY always saved     (2016 Apr 27)
  7 :   Phase1 v4 First Phase 1 ntuple version  (2017 May 17)
  8 :   Phase1 v0408 + inactive, muons, simhit/trk (2019 Oct 08) 

*/

// Set on which trees you want to run on
// For now, only select 1, set others to 0
#define EVT_LOOP 1
#define TRAJ_LOOP 1
#define CLUST_LOOP 1
// Set this if you only want to run on each Nth file
// This is used to do quick tests of binning on low statistics
#define NTHFILE 1

#define DCL_MISSING 0.1 // 1000 um
#define DCL_MISSING_NEW 0.1 // 1000 um - same for new hit efficiency

// TimingStudy versions
#define VER 8
#if VER == -2 // v2928 backported
#define SPLIT 0
#define TREEREADER_VER 29
#define DATASTRUCT_VER 28
#elif VER == -1 // v3029 backported
#define SPLIT 0
#define TREEREADER_VER 30
#define DATASTRUCT_VER 29
#elif VER == 3
#define SPLIT 1
#define TREEREADER_VER 37
#define DATASTRUCT_VER 34
#elif VER == 4
#define SPLIT 1
#define TREEREADER_VER 37
#define DATASTRUCT_VER 35
#elif VER == 5
#define SPLIT 1
#define TREEREADER_VER 38
#define DATASTRUCT_VER 36
#elif VER == 6
#define SPLIT 1
#define TREEREADER_VER 39
#define DATASTRUCT_VER 36
#elif VER == 7
#define TREEREADER_VER 104
#define DATASTRUCT_VER 105
#elif VER == 8
#define TREEREADER_VER 104
#define DATASTRUCT_VER 108
#endif

#if DATASTRUCT_VER > 100
#define PHASE 1
#else
#define PHASE 0
#endif

//#define COMPLETE 1
//#define EXPRESS 1

#define HV_Scan     1
#define Timing_Scan 0

#define SCANS 1
#include "interface/TreeLooper.h"

int main(int argc, char* argv[]) {
  // Get arguments from shell
  std::vector<std::string> filelist;
  std::string outputfile="";
  size_t opt_n = 0;
  // -n <number> option:
  // Set so the postfix that uses the v.pf_file_add
  // get overwritten by <number>-1
  // default is opt_n=0 - use with files added by editing this file
  // -o <output file> option:
  // Specify the output root filename
  // Rest of the arguments are treated as files added
  // Note:
  // If using postfixes with the v.pf_fila_add variable
  // each added file will increase this variable so when using *
  // add ""-s so instead of the shell TChain will parse the argument
  // -b option:
  // Former BADROC_RUN
  // Do not create any histos (except for ROC efficiency) to run faster
  bool BADROC_RUN = 0;
  bool is_o = false, is_n = false, is_a = false, is_b = false;
  for(int i=1; i<argc; i++) {
    std::string arg = argv[i];
    // Check existence of an option
    if (arg[0]=='-'&&arg.size()==2) { 
      is_n = (arg[1]=='n'); 
      is_o = (arg[1]=='o'); 
      if (arg[1]=='a') is_a = 1;
      if (arg[1]=='b') is_b = 1;
    }
    // Check second argument after option
    else if (is_n) { std::stringstream ss; ss<<arg; ss>>opt_n; is_n=0; } 
    else if (is_o) { outputfile=arg; is_o=0; }
    else filelist.push_back(arg);
  }
  if (is_b) BADROC_RUN = 1;
  
  // Data structs holding variables read from TTrees
  RunData run; LumiData lumi; EventData e; TrajMeasurement t; Cluster c;
  
  // Variables that are derived from Data struct members
  Variables v;
  
  // TTree reader
  TreeReader tr(&run,&lumi,&e,&e,&t,&e,&c);
  
  // Histogram storage class
  SmartHistos sh;
  if (EVT_LOOP   ||  BADROC_RUN) sh.AddHistoType("evt",  "Events");
  if (TRAJ_LOOP  ||  BADROC_RUN) sh.AddHistoType("traj", "On-track Clusters");
  if (CLUST_LOOP && !BADROC_RUN) sh.AddHistoType("clust","Clusters");

  // Colors
  // 400 kYellow  800 kOrange
  // 416 kGreen	  820 kSpring
  // 432 kCyan	  840 kTeal
  // 600 kBlue	  860 kAzure
  // 616 kMagenta 880 kViolet
  // 632 kRed     900 kPink
  
  std::string col3_red_to_blue = "633,618,601,"; // red, purple, blue
  std::string col4_cyan_to_red = "434,601,618,633,"; // cyan, blue, purple, red
  std::string col4_red_to_cyan = "633,618,601,434,"; // red, purple, blue, cyan
  std::string col5_green_to_red = "418,434,601,618,633,"; // green, cyan, blue, purple, red
  std::string col5_red_to_green = "633,618,601,434,418,"; // red, purple, blue, cyan, green
  std::string col6_rainbow_dark = "601,434,418,402,633,618,"; // blue, cyan, green, yellow, red, purple
  std::string col8 = "1,601,434,418,402,807,633,618,"; // above plus black and orange
  std::string col12 = "1,4,6,2,800,402,417,433,9,618,633,924,"; // black, blue, magenta, red, orange, darker yellow, darker green, darker cyan, blue-purple, dark purple, dark red
  std::string col12_rainbow = "402,416,433,600,617,632,802,813,833,863,883,892,"; // Go around first bright and then dark colors
  std::string col18 = col12_rainbow+col6_rainbow_dark;
  std::string col_lay = "633,417,601,799,433,633,418,601"; // Red, Green, Blue, Orange, Cyan, and again the same colors
  std::string col_lay_phase1 = col4_red_to_cyan + "799,402,417,"; // red to cyan, orange, dyellow, green

  // Tree Looper class, that uses the TreeReader 
  // and Variables classes to obtain values to Data containers
  TreeLooper looper(&tr, &v, EVT_LOOP, TRAJ_LOOP, CLUST_LOOP); // Set these in the beginning of this file
  // Define Postfixes here:
#if PHASE == 0
  sh.AddNewPostfix("Layers",            [&v]{ return v.pf_layers;       }, "Lay[1to3]", "Layer [1to3]", APPROVAL ? "1,633,418" : col3_red_to_blue);
  sh.AddNewPostfix("Ladders",           [&v]{ return v.pf_ladders;      }, "Lad[1to22]", "Ladder [1to22]", col12+col12_rainbow);
  sh.AddNewPostfix("Disks",             [&v]{ return v.pf_disks;        }, "Disk1;Disk2", "Disk 1;Disk 2", "600,617");
  sh.AddNewPostfix("DisksInOut",        [&v]{ return v.pf_disksio;      }, "Disk1In;Disk1Out;Disk2In;Disk2Out", "Disk 1 - Inner 3 Plq;Disk 1 - Outer 4 Plq;Disk 2 - Inner 3 Plq;Disk 2 - Outer 4 Plq", col4_cyan_to_red);
  sh.AddNewPostfix("LayersDisksInOut",  [&v]{ return v.pf_lays_disksio; }, "Lay[1to3];Disk1In;Disk1Out;Disk2In;Disk2Out", "Layer [1to3];Disk 1 - Inner 3 Plq;Disk 1 - Outer 4 Plq;Disk 2 - Inner 3 Plq;Disk 2 - Outer 4 Plq", col8);
  sh.AddNewPostfix("LayersDisks",       [&v]{ return v.pf_lays_disks;   }, "Lay[1to3];Disk[1to2]", "BPix, Layer [1to3];FPix, Disk [1to2]", col_lay);
  //sh.AddNewPostfix("LayersDisksOldNew", [&v]{ return v.pf_lays_disks_oldnew; }, "Lay[1to3]Old;Disk[1to2]Old;Lay[1to3]New", "Layer [1to3];Disk [1to2];L[1to3] (New)", col5_red_to_green+"632,616,600");
  sh.AddNewPostfix("LayersDisksOld",    [&v]{ return v.pf_lays_disks_oldnew< 6 ? v.pf_lays_disks_oldnew   : (size_t)-1; }, "Lay[1to3]Old;Disk[1to2]Old", "Layer [1to3];Disk [1to2]", col_lay);
  sh.AddNewPostfix("LayersNew",         [&v]{ return v.pf_lays_disks_oldnew>=6 ? v.pf_lays_disks_oldnew-5 : (size_t)-1; }, "Lay[1to3]New",               "Layer [1to3]",             col_lay);
  sh.AddNewPostfix("BPixNew",           [&v]{ return (size_t)(v.pf_new_modules ? 0 : -1); }, "BPixNew", "New modules", "1");
  sh.AddNewPostfix("LayersAllDisks",    [&v]{ return v.layers_disks-1;  }, "Lay[1to3];Diskm2;Diskm1;Diskp1;Diskp2", "BPix, Layer [1to3];FPix, Disk [-2to-1];FPix, Disk [1to2]", col8);
  sh.AddNewPostfix("HVGroupsScanned",   [&v]{ return v.pf_lays_disks;   }, "L[1to3]OneHVGrp;D[1to2]OneHVGrp", "Layer [1to3] (One HV group);Disk [1to2] (One HV group)", col5_red_to_green);
#elif PHASE == 1
  sh.AddNewPostfix("Layers",            [&v]{ return v.pf_layers;       }, "Lay[1to4]", "Layer [1to4]", col4_red_to_cyan);
  sh.AddNewPostfix("Ladders",           [&v]{ return v.pf_ladders;      }, "Lad[1to34]", "Ladder [1to34]", col12+col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("Disks",             [&v]{ return v.pf_disks;        }, "Disk[1to3]", "Disk [1to3]", col3_red_to_blue);
  sh.AddNewPostfix("ROCInOut",          [&v]{ return v.pf_fpix_roc_inout;}, "ROC \"radius\" [1to8]", "ROC \"radius\" [1to8]", col8);
  sh.AddNewPostfix("LayersDisks",       [&v]{ return v.pf_lays_disks_phase1;   }, "Lay[1to4];Disk[1to3]", "Layer [1to4];Disk [1to3]", col_lay_phase1);
  sh.AddNewPostfix("LayersAllDisks",    [&v]{ return v.layers_disks_phase1-1;  }, "Lay[1to4];Diskm3;Diskm2;Diskm1;Diskp1;Diskp2;Diskp3", "Layer [1to4];Disk [-3to-1];Disk [1to3]", col12);
  sh.AddNewPostfix("AllDisks",          [&v]{ return v.layers_disks_phase1>4?v.layers_disks_phase1-5:(size_t)-1;  }, "Diskm3;Diskm2;Diskm1;Diskp1;Diskp2;Diskp3", "Disk [-3to-1];Disk [1to3]", col6_rainbow_dark);
  sh.AddNewPostfix("HVGroupsScanned",   [&v]{ return v.pf_lays_disks_phase1; }, "L[1to4]OneHVGrp;D[1to3]OneHVGrp", "Layer [1to4] (One HV group);Disk [1to3] (One HV group)", col8);
  sh.AddNewPostfix("BPixLay1New",       [&v]{ return (v.layer==1) ? v.pf_bpix_l1_new : (size_t)-1; }, "BPixLay1Old;BPixLay1New", "Layer 1 old modules;Layer 1 new modules", "633,417");
  //sh.AddNewPostfix("Lay1HVScanned",     [&v]{ return v.pf_l1_hv_scanned; }, "BmO_SEC2_LYR1_LDR1_MOD1;BmO_SEC2_LYR1_LDR2_MOD3;BmO_SEC2_LYR1_LDR2_MOD4;", "BmO_SEC2_LYR1_LDR1_MOD1;BmO_SEC2_LYR1_LDR2_MOD3;BmO_SEC2_LYR1_LDR2_MOD4;", col3_red_to_blue);
  sh.AddNewPostfix("Lay1HVScanned",     [&v]{ return v.pf_l1_hv_scanned; }, "BmO_SEC2_LYR1_LDR5_MOD1;BmO_SEC2_LYR1_LDR5_MOD2;BmO_SEC2_LYR1_LDR6_MOD4;", "BmO_SEC2_LYR1_LDR5_MOD1;BmO_SEC2_LYR1_LDR5_MOD2;BmO_SEC2_LYR1_LDR6_MOD4;", col3_red_to_blue);
#endif
  sh.AddNewPostfix("Layer12/34",        [&v]{ return (size_t)(v.layer==1||v.layer==2 ? 0 : v.layer==3||v.layer==4 ? 1 : -1); }, "Lay12;Lay34", "Layer 1-2;Layer 3-4", "1,2");
  sh.AddNewPostfix("AllMods",           [&v]{ return v.pf_allmods;      }, "Modm[4to1--1];Modp[1to4]", "Ring [-4to-1];Ring [1to4]", col8);
  sh.AddNewPostfix("ROGRings",          [&v]{ return (size_t)(v.pf_det==0 ? v.pf_mods+(v.layer%2==0)*4 : -1); }, "OddLayRing[1to4];EvenLayRing[1to4]", "Odd layer, Ring [1to4];Even layer, Ring [1to4]", col8);
  sh.AddNewPostfix("Mods",              [&v]{ return v.pf_mods;         }, "Mod[1to4]", "Mod[1to4]", col4_cyan_to_red);
  sh.AddNewPostfix("Mod12/34",          [&v]{ return v.pf_mods>=2;      }, "Mod12;Mod34", "Mod 1,2;Mod 3,4", "633,601");
  sh.AddNewPostfix("InnerOuter",        [&v]{ return v.pf_outer;        }, "InnerLadders;OuterLadders", "Inner ladders;Outer ladders", "633,601,");
  sh.AddNewPostfix("Rings",             [&v]{ return v.ring-1;          }, "Ring[1to2]", "Ring[1to2]", "601,633,");
  sh.AddNewPostfix("DisksRings",        [&v]{ if (v.pf_det==0) return (size_t)-1; return (size_t)(v.pf_disks*2+(v.ring==2)); }, "Disk1_Ring[1to2];Disk2_Ring[1to2];Disk3_Ring[1to2]", "Disk 1 Ring [1to2];Disk 2 Ring [1to2];Disk 3 Ring [1to2]", col6_rainbow_dark);
  sh.AddNewPostfix("BPixFPix",          [&v]{ return v.is_fpix;         }, "BPix;FPix", "Barrel Pixels;Forward Pixels", "633,601");
  sh.AddNewPostfix("AllROCs",           []  { return 0;                 }, "AllROCs",  "All ROCs", "1");
  sh.AddNewPostfix("ExclMods",          []  { return 0;                 }, "ExclMods", "No bad modules", "1");
  sh.AddNewPostfix("NewModules",        [&v]{ return v.pf_new_modules;  }, "OldModules;NewModules", "Old Modules;New Modules", "633,417");
  sh.AddNewPostfix("Pileup",            [&v]{ return v.pf_pileup;       }, "pu[2.5to47.5++5]", "[2.5to47.5++5] pile-up", col12_rainbow);
  sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi;     }, "[0to10]invnbHz", "[0to10] nb^{-1}s^{-1}", col12_rainbow);
  sh.AddNewPostfix("L1Rate",            [&v]{ return v.pf_l1rate;       }, "[0to100++10]kHz", "[0to100++10]kHz", col12_rainbow);
  sh.AddNewPostfix("NBx",               [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=2500) ? -1 : v.nbx/50; }, "NBx[25to2475++50]", "[25to2475++50]#pm25b", col12+col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("WBC",               [&v]{ return v.pf_wbc;          }, "WBC0;WBC12;WBC13;WBC12HV200", "WBC 0;WBC +12;WBC +13;WBC +12 - HV_{BPix} = 200 V", col4_cyan_to_red);
  sh.AddNewPostfix("DelayScanRuns",     [&e]{ return (e.run>=246919) + (e.run>=246920) + (e.run>=246923) + (e.run>=246926) + (e.run>=246930) + (e.run>=246936); }, 
		   "246908;246919;246920;246923;246926;246930;246936", "246908;246919;246920;246923;246926;246930;246936", col8);
  sh.AddNewPostfix("TSFirst3BX",         [&e]{ return 
		       (e.bx==289||e.bx==1183||e.bx==2077) ? 0 :
		       (e.bx==290||e.bx==1184||e.bx==2078) ? 1 :
		       (e.bx==291||e.bx==1185||e.bx==2079) ? 2 :
		       (size_t)-1; }, "BXm1;BX0;BXp1", "First BX -1;First BX;First BX +1", "601,418,633");
  
  sh.AddNewPostfix("DelayScans",        [&v]{ if (v.pf_delay_scan==-1) return (size_t)-1; return (size_t)v.pf_delay_scan-38;   }, "2017Oct27_dac109_prt58", "Oct 27 Scan", "1,");
  sh.AddNewPostfix("HVBiasScans",       [&v]{ return (size_t)v.pf_hv_scan; }, "HV[1to19]", "2017 May24-25;2017 Aug 14;2017 Sep 23;2017 Oct 04;2017 Oct 27;2017 Nov 09;FullScan April 12 - 0.1pb^{-1};May 05 - 4.6fb^{-1};May 12 - 8.7fb^{-1};May 24 - 14.9fb^{-1};Jun 09 - 21.8fb^{-1};Jul 11 - 25.4fb^{-1};FullScan Jul 30/31 - 31.5fb^{-1};Aug 17 - 40.5fb^{-1};Sep 01 - 48.5fb^{-1};Sep 07 - 53fb^{-1};Sep 26 - 56.4fb^{-1};Oct 20 - 65.8fb^{-1};test", col12+col12_rainbow+col12);
  //sh.AddNewPostfix("HVBiasScans",       [&v]{ return (v.is_bpix ? v.bias_voltage==200 : v.bias_voltage==300) ? (size_t)v.pf_hv_scan : (size_t)-1; }, "HV[1to36]", "HV Scan [1to17];2015 (0T);2016 (0T);2016 (3.8T);HV Scan [21to36]", col12+col12_rainbow+col12);
  //sh.AddNewPostfix("300VModules",       [&v]{ return v.pf_300v; }, "150V;300V", "150V modules;300V modules", "601,633");
  sh.AddNewPostfix("FineDelays",        [&v]{ return size_t(v.delay>=3 &&v.delay<=9 ? v.delay-3 : -1); }, "[3to9]nsfine", "[3to9]ns", col8);
  sh.AddNewPostfix("Delays",            [&v]{ 
		     if      (v.delay== 3) return (size_t)0;
		     else if (v.delay== 6) return (size_t)1;
		     else if (v.delay== 9) return (size_t)2;
		     else if (v.delay==12) return (size_t)3;
		     else if (v.delay==15) return (size_t)4;
		     else return (size_t)-1;
		   }, "[3to15++3]ns", "[3to15++3]ns", col5_green_to_red);
  sh.AddNewPostfix("6ns",               [&v]{ return size_t(v.delay==6.0  ? 0 : -1); }, "6ns", "+6ns", "1");
  sh.AddNewPostfix("11ns",              [&v]{ return size_t(v.delay==11.0  ? 0 : -1); }, "11ns", "11ns", "1");
  
  //sh.AddNewPostfix("Voltages",          [&v]{ return v.pf_voltage;      }, "[0to15++5]V;[20to300++10]V", "[0to15++5] V;[20to300++10] V", col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("Voltages",          [&v]{ return (v.pf_voltage==50) ? 0 : (v.pf_voltage==100) ? 1 : (v.pf_voltage==150) ? 2 : (v.pf_voltage==200) ? 3 : (v.pf_voltage==300) ? 4 : -1; }, "50V;100V;150V;200V;300V", "50V;100V;150V;200V;300V", col5_green_to_red);
  sh.AddNewPostfix("Shell",             [&v]{ return v.pf_shell;        }, "BpI;BpO;BmI;BmO", "BpI;BpO;BmI;BmO", col4_cyan_to_red);
  sh.AddNewPostfix("Side",              [&v]{ return v.side-1;          }, "mZ;pZ", "-Z side;+Z side", "601,633,");
  sh.AddNewPostfix("Sectors",           [&v]{ return v.pf_sector;       }, "Sec[1to8]", "SEC[1to8]", col8);
  sh.AddNewPostfix("RingsROGs",         [&v]{ return v.pf_ring_rog;     }, "Ring1_Rog[1to4];Ring2_Rog[1to4]", "Ring1 ROG[1to4];Ring2 ROG[1to4]", col8);
  
  // Same category, but used widely to compare plots
  sh.AddNewPostfix("DcolScan",      [&v]{ return v.pf_file_add; }, "Data;Dcol[100,99.9,99.6,99.3,99,98,97,95,90,80]", "Data;Dcol[100,99.9,99.6,99.3,99,98,97,95,90,80]", col12_rainbow);

  sh.AddNewPostfix("ContrlRegScans",    [&e] {
		     return size_t(e.run==296786||e.run==296789||e.run==296790||e.run==296795 ? 0 : -1);
		   }, "2017Jun14", "ContrlReg Scan", "1");
  sh.AddNewPostfix("ThresholdScans",    [&e] {
		     if      (e.run==296867||e.run==296868||e.run==296869||e.run==296870||e.run==296871||e.run==296877||e.run==296878) return size_t(0);
		     else if (/*e.run==297494||*/e.run==297495||e.run==297496||e.run==297497||e.run==297498||e.run==297499||e.run==297501||e.run==297502||e.run==297503) return size_t(1);
		     return size_t(-1);
		   }, "2017Jun14;2017Jun26", "VcThr Scan;", "1,1");
  sh.AddNewPostfix("ViBiasScans",    [&e] {
		     return size_t(e.run==296872||e.run==296873||e.run==296874||e.run==296875||e.run==296876||e.run==296880 ? 0 : -1);
		   }, "2017Jun14", "Vibias Scan", "1");
  
  sh.AddNewFillParams("ContrlReg", { .nbin= 33, .bins={  -6.5, 26.5}, .fill=[&e] {
				       if      (e.run==296786) return 16;
				       else if (e.run==296789) return  0;
				       else if (e.run==296790) return  8;
				       else if (e.run==296795) return 24;
				       else return -9999;
				     }, .axis_title="ContrlReg"});
  sh.AddNewFillParams("VcThrShift", { .nbin= 44, .bins={  -40.5, 3.5}, .fill=[&e] {
					// Scan 1
					if      (e.run==296867) return   0;
					else if (e.run==296868) return   5;
					else if (e.run==296869) return  -5;
					else if (e.run==296870) return  10;
					else if (e.run==296871) return -10;
					else if (e.run==296877) return  15;
					else if (e.run==296878) return -15;
					// Scan 2
					//else if (e.run==297494) return   0;
					else if (e.run==297495) return  -4;
					else if (e.run==297496) return  -8;
					else if (e.run==297497) return -15;
					else if (e.run==297498) return -20;
					else if (e.run==297499) return -30;
					else if (e.run==297501) return  -1;
					else if (e.run==297502) return   1;
					else if (e.run==297503) return   0;
					else return -9999;
				      }, .axis_title="VcThr shift (wrt default)"});
  sh.AddNewFillParams("ViBias", { .nbin= 25, .bins={  7.5, 32.5}, .fill=[&e] {
				    if      (e.run==296872) return 16;
				    else if (e.run==296873) return 18;
				    else if (e.run==296874) return 22;
				    else if (e.run==296875) return 24;
				    else if (e.run==296876) return 30;
				    else if (e.run==296880) return 20;
				    else return -9999;
				  }, .axis_title="ViBias"});
  
  // Define histo parameters and filling variable
  // X/Y/Z - axis parameters:
  sh.AddNewFillParams("NVertices",          { .nbin= 50,  .bins={    0.5,   50.5}, .fill=[&e]{ return e.nvtx;          }, .axis_title="N_{Vertices}"});
  sh.AddNewFillParams("NPileup",            { .nbin=100,  .bins={      0,    100}, .fill=[&v]{ return v.pileup;        }, .axis_title="N_{Pile-up}"});
  sh.AddNewFillParams("NTracks",            { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntracks;       }, .axis_title="N_{Tracks}"});
  sh.AddNewFillParams("NTracksLay1",        { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntrackBPix[0]; }, .axis_title="N_{Tracks crossing Layer 1}"});
  sh.AddNewFillParams("NTracksDsk1",        { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntrackFPix[0]; }, .axis_title="N_{Tracks crossing Disk 1}"});
#if DATASTRUCT_VER > 28
  sh.AddNewFillParams("NClu",               { .nbin= 80,  .bins={      0,   8000}, .fill=[&v]{ return v.nclu;          }, .axis_title="N_{Clusters}"});
  sh.AddNewFillParams("NPix",               { .nbin=125,  .bins={      0,  25000}, .fill=[&v]{ return v.npix;          }, .axis_title="N_{Pixels}"});
  sh.AddNewFillParams("NCluBPix",           { .nbin=100,  .bins={      0,   5000}, .fill=[&v]{ return v.nclu_bpix;     }, .axis_title="N_{Clusters} - BPix"});
  sh.AddNewFillParams("NPixBPix",           { .nbin=100,  .bins={      0,  20000}, .fill=[&v]{ return v.npix_bpix;     }, .axis_title="N_{Pixels} - BPix"});
  sh.AddNewFillParams("NCluFPix",           { .nbin=100,  .bins={      0,   2000}, .fill=[&e]{ return e.nclu[0];       }, .axis_title="N_{Clusters} - FPix"});
  sh.AddNewFillParams("NPixFPix",           { .nbin=100,  .bins={      0,   5000}, .fill=[&e]{ return e.npix[0];       }, .axis_title="N_{Pixels} - FPix"});
#endif

#if PHASE == 0
  sh.AddNewFillParams("LayersDisks",      { .nbin=   7, .bins={    0.5,    7.5}, .fill=[&v]{ return v.layers_disks; }, .axis_title="", .def_range={}, .bin_labels={
					      {1, "Layer 1"}, {2, "Layer 2"}, {3, "Layer 3"}, {4, "Disk -2"},
					      {5, "Disk -1"}, {6, "Disk +1"}, {7, "Disk +2"}
					     }});
#else
  sh.AddNewFillParams("LayersDisks",      { .nbin=  10, .bins={    0.5,   10.5}, .fill=[&v]{ return v.layers_disks_phase1; }, .axis_title="", .def_range={}, .bin_labels={
					       {1, "Layer 1"}, {2, "Layer 2"}, { 3, "Layer 3"}, {4, "Layer 4"}, 
					       {5, "Disk -3"}, {6, "Disk -2"}, { 7, "Disk -1"}, 
					       {8, "Disk +1"}, {9, "Disk +2"}, {10, "Disk +3"}
					     }});
#endif
  sh.AddNewFillParams("LayersDisksInOut",   { .nbin=   7, .bins={    0.5,    7.5}, .fill=[&v]{ return v.layers_disks;  }, .axis_title=""});
  sh.AddNewFillParams("DisksInOut",         { .nbin=   4, .bins={    0.5,    4.5}, .fill=[&v]{ return v.disks_inout;   }, .axis_title=""});
  sh.AddNewFillParams("ROCInOut",         { .nbin=   8, .bins={    0.5,    8.5}, .fill=[&v]{ return v.fpix_roc_inout;   }, .axis_title=""});
  sh.AddNewFillParams("Ladders",            { .nbin=  45, .bins={  -22.5,   22.5}, .fill=[&v]{ return v.ladder;        }, .axis_title="Ladders"});
  sh.AddNewFillParams("Modules",            { .nbin=   9, .bins={   -4.5,    4.5}, .fill=[&v]{ return v.module;        }, .axis_title="Modules"});
  sh.AddNewFillParams("Pileup",             { .nbin=  50, .bins={      0,    100}, .fill=[&v]{ return v.pileup;        }, .axis_title="Pile-up"});
  sh.AddNewFillParams("InstLumi",           { .nbin=  80, .bins={      0,     20}, .fill=[&v]{ return v.instlumi;      }, .axis_title="Instantaneous luminosity (nb^{-1}s^{-1})"});
  sh.AddNewFillParams("InstLumi0p5",        { .nbin=  40, .bins={      0,     20}, .fill=[&v]{ return v.instlumi;      }, .axis_title="Instantaneous luminosity (nb^{-1}s^{-1})"});
  sh.AddNewFillParams("InstLumi1p0",        { .nbin=  21, .bins={   -0.5,   20.5}, .fill=[&v]{ return v.instlumi;      }, .axis_title="Instantaneous luminosity (nb^{-1}s^{-1})"});
  sh.AddNewFillParams("OnTrkCluSize",       { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.size;      }, .axis_title="On-Trk Cluster Size (pixel)",      .def_range={0,5}});
  sh.AddNewFillParams("OnTrkCluSizeX",      { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.sizeX;     }, .axis_title="On-Trk Cluster Size x (pixel)", .def_range={0,5}});
  sh.AddNewFillParams("OnTrkCluSizeY",      { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.sizeY;     }, .axis_title="On-Trk Cluster Size y (pixel)", .def_range={0,5}});
  sh.AddNewFillParams("OnTrkCluCharge",     { .nbin=  50, .bins={      0,    500}, .fill=[&v]{ return v.clu_charge;    }, .axis_title="On-Trk Cluster Charge (ke)",    .def_range={0,30}});
  sh.AddNewFillParams("NormOnTrkCluCharge", { .nbin=  50, .bins={      0,    200}, .fill=[&t]{ return t.norm_charge;   }, .axis_title="Norm. On-Trk Clu. Charge (ke)", .def_range={0,25} });
  sh.AddNewFillParams("CluSize",            { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&c]{ return c.size;          }, .axis_title="Cluster Size (pixel)",          .def_range={0,5}});
  sh.AddNewFillParams("CluCharge",          { .nbin=  50, .bins={      0,    500}, .fill=[&c]{ return c.charge/1e3;    }, .axis_title="Cluster Charge (ke)",           .def_range={0,60}});
  sh.AddNewFillParams("BunchCrossing12",    { .nbin= 300, .bins={      0,   3600}, .fill=[&e]{ return e.bx;            }, .axis_title="Bunch-crossing"});
  sh.AddNewFillParams("BunchCrossing60",    { .nbin=  60, .bins={      0,   3600}, .fill=[&e]{ return e.bx;            }, .axis_title="Bunch-crossing"});
  sh.AddNewFillParams("NBxPerTrig",         { .nbin=  80, .bins={      0,   2000}, .fill=[&v]{ return v.nbx_per_trig;  }, .axis_title="Avg. N_{Bunch-crossing} / Trigger latency"});
  sh.AddNewFillParams("NColPerTrig",        { .nbin= 200, .bins={      0, 100000}, .fill=[&v]{ return v.ncol_per_trig; }, .axis_title="Avg. N_{Collisions} / Trigger latency"});
  sh.AddNewFillParams("Runs",               { .nbin= 600, .bins={ 233800, 234400}, .fill=[&e]{ return e.run;           }, .axis_title="Runs"});
  sh.AddNewFillParams("TMuon",              { .nbin=  10, .bins={   -40,      60}, .fill=[&e]{ return e.tmuon;         }, .axis_title="t_{muon} @ Int. Point (ns)"});
  sh.AddNewFillParams("Delay",              { .nbin=  81, .bins={  -20.25,  20.25}, .fill=[&v]{ return v.delay;         }, .axis_title="Time Delay (ns)", .def_range={-10,10} });
  sh.AddNewFillParams("BiasVoltage",        { .nbin= 123, .bins={  -2.5,   612.5}, .fill=[&v]{ return v.bias_voltage;  }, .axis_title="Bias Voltage (V)"});
  sh.AddNewFillParams("NCluL1",             { .nbin=1000, .bins={  -0.5, 10000.5}, .fill=[&e]{ return e.nclu[1];       }, .axis_title="N_{cluster, L1}"});
  sh.AddNewFillParams("NCluL2",             { .nbin=1000, .bins={  -0.5, 10000.5}, .fill=[&e]{ return e.nclu[2];       }, .axis_title="N_{cluster, L2}"});
  sh.AddNewFillParams("NCluL3",             { .nbin=1000, .bins={  -0.5, 10000.5}, .fill=[&e]{ return e.nclu[3];       }, .axis_title="N_{cluster, L3}"});
  sh.AddNewFillParams("NCluFPix",           { .nbin=1000, .bins={  -0.5, 10000.5}, .fill=[&e]{ return e.nclu[0];       }, .axis_title="N_{cluster, FPix}"});
  sh.AddNewFillParams("NPixL1",             { .nbin=2000, .bins={  -0.5,  2000.5}, .fill=[&e]{ return e.npix[1];       }, .axis_title="N_{pixel, L1}"});
  sh.AddNewFillParams("NPixL2",             { .nbin=2000, .bins={  -0.5,  2000.5}, .fill=[&e]{ return e.npix[2];       }, .axis_title="N_{pixel, L2}"});
  sh.AddNewFillParams("NPixL3",             { .nbin=2000, .bins={  -0.5,  2000.5}, .fill=[&e]{ return e.npix[3];       }, .axis_title="N_{pixel, L3}"});
  sh.AddNewFillParams("NPixFPix",           { .nbin=2000, .bins={  -0.5,  2000.5}, .fill=[&e]{ return e.npix[0];       }, .axis_title="N_{pixel, FPix}"});
  sh.AddNewFillParams("LumiSection",        { .nbin=1000, .bins={   0.5,  1000.5}, .fill=[&e]{ return e.ls;            }, .axis_title="LumiSection"});
  sh.AddNewFillParams("LumiSectionCoarse",  { .nbin= 200, .bins={   0.5,  1000.5}, .fill=[&e]{ return e.ls;            }, .axis_title="LumiSection"});
  sh.AddNewFillParams("LumiSectionSpecial", { .nbin= 200, .bins={   0.5,  1000.5}, .fill=[&e]{ return e.ls + (e.run>246908)*175 + (e.run>246919)*50 + (e.run>246920)*10 + (e.run>246923)*25 + (e.run>246926)*250 + (e.run>246930)*40; }, .axis_title="LumiSection"});

  sh.AddNewFillParams("TrkPt",            { .nbin=   9, .bins={0, 0.2, 0.4, 0.6, 0.8, 1, 1.5, 2, 5, 20}, .fill=[&t]{ return t.trk.pt; }, .axis_title="Track p_{T} (GeV/c)"});
  sh.AddNewFillParams("TrkNStrip",        { .nbin=  18, .bins={0, 2, 4, 6, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 35, 50}, .fill=[&t]{ return t.trk.strip; }, .axis_title="N_{strip hits}"});
  sh.AddNewFillParams("TrkD0",            { .nbin=  11, .bins={0, 0.001, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 2, 20}, .fill=[&t]{ return fabs(t.trk.d0); }, .axis_title="Track Impact Parameter #Delta0 (cm)"});
  sh.AddNewFillParams("TrkDZ",            { .nbin=  10, .bins={0, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 2, 20}, .fill=[&t]{ return fabs(t.trk.dz); }, .axis_title="Track Impact Parameter #DeltaZ (cm)"});
  sh.AddNewFillParams("TrackPt",          { .nbin= 200, .bins={0, 20}, .fill=[&t]{ return t.trk.pt;      }, .axis_title="Track p_{T} (GeV)", .def_range={0,2} });
  sh.AddNewFillParams("TrackEta",         { .nbin=  52, .bins={-2.6, 2.6}, .fill=[&t]{ return t.trk.eta; }, .axis_title="Track #eta" });
  sh.AddNewFillParams("TrackNStrip",      { .nbin=  50, .bins={0, 50}, .fill=[&t]{ return t.trk.strip;   }, .axis_title="N_{strip hits}",    .def_range={0,30} });
  sh.AddNewFillParams("TrackD0",          { .nbin= 100, .bins={0, 1}, .fill=[&t]{ return fabs(t.trk.d0); }, .axis_title="Track Impact Parameter #Delta0 (cm)", .def_range={0, 0.5} });
  sh.AddNewFillParams("TrackDZ",          { .nbin= 200, .bins={0, 2}, .fill=[&t]{ return fabs(t.trk.dz); }, .axis_title="Track Impact Parameter #DeltaZ (cm)", .def_range={0, 1.0} });
  
  //sh.AddNewFillParams("ROCLadders",       { .nbin=  88, .bins={   -22,      22}, .fill=[&v]{ return v.roc_ladder;    }, .axis_title="Ladders"});
  //sh.AddNewFillParams("ROCModules",       { .nbin=  72, .bins={  -4.5,     4.5}, .fill=[&v]{ return v.roc_module;    }, .axis_title="Modules"});
  //sh.AddNewFillParams("ROCBladesInner",   { .nbin=  72, .bins={    0.5,   12.5}, .fill=[&v]{ return v.roc_blade;       }, .axis_title="Blades in Inner Halves"});
  //sh.AddNewFillParams("ROCBladesOuter",   { .nbin=  72, .bins={  -12.5,   -0.5}, .fill=[&v]{ return v.roc_blade;       }, .axis_title="Blades in Outer Halves"});
  //sh.AddNewFillParams("ROCSideDiskPanel", { .nbin=  72, .bins={  -4.5,     4.5}, .bin_labels={
  //      				      { 1, "Disk-2 Pnl2"}, { 9, "Disk-2 Pnl1"}, {19, "Disk-1 Pnl2"}, {27, "Disk-1 Pnl1"},
  //      				      {41, "Disk+1 Pnl1"}, {49, "Disk+1 Pnl2"}, {59, "Disk+2 Pnl1"}, {67, "Disk+2 Pnl2"}
  //      				    }, .fill=[&v]{ return v.roc_sdp;         }, .axis_title="" });

  sh.AddNewFillParams("ROC_L1_Ladder",        { .nbin=  26, .bins={  -6.5,     6.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 1 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L2_Ladder",        { .nbin=  58, .bins={ -14.5,    14.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 2 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L3_Ladder",        { .nbin=  90, .bins={ -22.5,    22.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 3 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L4_Ladder",        { .nbin= 130, .bins={ -32.5,    32.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 4 - ROC / Ladder"});
  sh.AddNewFillParams("Module",               { .nbin=  72, .bins={  -4.5,     4.5}, .fill=[&v]{ return v.module_coord;                  }, .axis_title="ROC / Module"});
  sh.AddNewFillParams("ROC_Ring1_BladePanel", { .nbin=  92, .bins={ -11.5,    11.5}, .fill=[&v]{ return v.blade_panel_coord-v.blade*0.5; }, .axis_title="Ring 1 - ROC / Blade"});
  sh.AddNewFillParams("ROC_Ring2_BladePanel", { .nbin= 140, .bins={ -17.5,    17.5}, .fill=[&v]{ return v.blade_panel_coord;             }, .axis_title="Ring 2 - ROC / Blade"});
  sh.AddNewFillParams("Disk",                 { .nbin=  56, .bins={  -3.5,     3.5}, .fill=[&v]{ return v.disk_coord;                    }, .axis_title="ROC / Disk"});

  // Special Y/Z axis parameters:
  sh.AddSpecial({ .name="HitEfficiency",   .name_plus_1d="ValidHit",  .axis="Hit Efficiency",  .axis_plus_1d="Valid Hit"});
  sh.AddSpecial({ .name="DColEfficiency",  .name_plus_1d="ColParity", .axis="Double Column Efficiency",  .axis_plus_1d="First Pixel Column Parity"});
#if PHASE == 0
  // Recover missing hits within 500 um
  sh.AddNewFillParams("HitEfficiency",    { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.clust_near : 1; }, .axis_title="Hit Efficiency", .def_range={0, 1} });
#else
  // Recover missing hits within 1 mm - Currently does not work
  sh.AddNewFillParams("HitEfficiency",    { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.d_cl>=0 && t.d_cl<DCL_MISSING : 1; }, .axis_title="Hit Efficiency", .def_range={0.5, 1} });
  sh.AddNewFillParams("DColEfficiency",   { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ if (t.clu.size!=2) return -1; if (((int)t.clu.pix[0][1])%52>=50||((int)t.clu.pix[0][1])%52<2) return -1; return (((int)t.clu.pix[0][1])%52)%2; }, .axis_title="Double Column Efficiency", .def_range={0, 1} });
#endif
  
  // Define Cuts here:
  sh.AddNewCut("Nvtx",              [&v]{ return v.cut_nvtx;     });
  sh.AddNewCut("ZeroBias",          [&v]{ return v.cut_zb;       });
  sh.AddNewCut("Random",            [&e]{ return (e.trig>>2)&1;  });
  sh.AddNewCut("FirstBX-1",         [&e]{ return e.bx==289||e.bx==1183||e.bx==2077; });
  sh.AddNewCut("EffCuts",           [&v]{ return v.effcut_all;   });
  sh.AddNewCut("EffCutsAllROC",     [&v]{ return v.effcut_allmod;});
  sh.AddNewCut("EffCutsScans",      [&v]{ return v.effcut_scans; });
  //sh.AddNewCut("EffCutsScans",      [&v]{ return v.effcut_startup; });
  sh.AddNewCut("DColEffCuts",       [&v]{ return v.dcol_effcut_all;    });
  sh.AddNewCut("DColEffCutsAllROC", [&v]{ return v.dcol_effcut_allmod; });
  sh.AddNewCut("DColEffCutsScans",  [&v]{ return v.dcol_effcut_scans;  });
  sh.AddNewCut("BPix",              [&v]{ return v.is_bpix;      });
  sh.AddNewCut("FPix",              [&v]{ return v.is_fpix;      });
  sh.AddNewCut("Lay1",              [&v]{ return v.layer==1;     });
  sh.AddNewCut("Lay2",              [&v]{ return v.layer==2;     });
  sh.AddNewCut("Lay3",              [&v]{ return v.layer==3;     });
  sh.AddNewCut("Lay4",              [&v]{ return v.layer==4;     });
  sh.AddNewCut("Ring1",             [&v]{ return v.ring==1;      });
  sh.AddNewCut("Ring2",             [&v]{ return v.ring==2;      });
  sh.AddNewCut("Data",              [&v]{ return v.is_data;      });
  sh.AddNewCut("MC",                [&v]{ return !v.is_data;     });
  sh.AddNewCut("Run203002",         [&v]{ return v.is_run203002; });
  sh.AddNewCut("NStrip>10",         [&v]{ return v.nstrip;       });
  sh.AddNewCut("Nbx>1300",          [&v]{ return v.main_filling_schemes; });
  sh.AddNewCut("HighPU",            [&v]{ return v.cut_highpu;   });
  sh.AddNewCut("GlobalMuon",        [&e]{ return e.tmuon!=-9999; });
  sh.AddNewCut("Lay3",              [&v]{ return v.pf_layers==2; });
  sh.AddNewCut("ValidHit",          [&t]{ return t.validhit==1; });
  sh.AddNewCut("HasLay2ValidHit",   [&t]{ return t.trk.validbpix[1]>0; });
  
  sh.AddNewCut("DelayScan",           [&v]{ return v.delay!=NOVAL_I; });
  sh.AddNewCut("OneHVGroupScan",      [&v]{ return v.is_one_hv_group_scan; });
  sh.AddNewCut("FullHVScan",          [&v]{ return v.is_full_hv_scan; });
  sh.AddNewCut("CluCharge>12",        [&c]{ return c.charge*1e3>12; });
  sh.AddNewCut("OnTrkCluCharge>12",   [&v]{ return v.clu_charge>12; });
  sh.AddNewCut("0TLay1HighEtaFix",    [&t,&e]{ return e.run>=246908 && e.run<250989 ? (t.mod_on.layer==1 ? fabs(t.trk.eta)<1.4 : 1) : 1; });
  sh.AddNewCut("OnTrkCluSize>0",      [&t]{ return t.clu.size>0; });
  sh.AddNewCut("FPixInner",           [&v]{ return v.is_fpix_inner; });
  sh.AddNewCut("FPixOuter",           [&v]{ return v.is_fpix_outer; });
  sh.AddNewCut("Delay==22",           [&v]{ return v.delay==22; });
  sh.AddNewCut("TrkPt>0.6&&ValidHit", [&t]{ return t.trk.pt>0.6&&t.validhit==1; });
  
  // --------------------------------------------------------------------------
  //                           Histogram Definitions
  
  // Layers/Disks
  sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",                         .pfs={"DelayScans"},          .cuts={"EffCutsScans","Delay==22"}, .draw="PE1", .opt="", .ranges={0,0, 0.95,1} });
  sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",                             .pfs={"Layers","DelayScans"}, .cuts={"EffCutsScans","Delay==22","BPix"}, .draw="PE1", .opt="", .ranges={0,0, 0,1} });
  sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",                             .pfs={"Layers","DelayScans"}, .cuts={"EffCutsScans","Delay==22","BPix"}, .draw="PE1", .opt="", .ranges={0,0, 0,1} });
  sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders_vs_Modules",                  .pfs={"Layers","DelayScans"}, .cuts={"EffCutsScans","Delay==22","BPix"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  
  // ROC Maps
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",            .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",            .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",            .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",            .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",       .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",       .pfs={"DelayScans"},            .cuts={"ZeroBias","EffCutsAllROC","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",            .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",            .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",            .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",            .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",       .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",       .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });

  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L1_Ladder_vs_Module",           .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L2_Ladder_vs_Module",           .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L3_Ladder_vs_Module",           .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L4_Ladder_vs_Module",           .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",      .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",      .pfs={"DelayScans"},            .cuts={"ZeroBias","DColEffCutsAllROC","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L1_Ladder_vs_Module",           .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L2_Ladder_vs_Module",           .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L3_Ladder_vs_Module",           .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L4_Ladder_vs_Module",           .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",      .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",      .pfs={"DelayScans","ExclMods"}, .cuts={"ZeroBias","DColEffCutsScans","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
  
  
#if CLUST_LOOP==1
  sh.AddHistos("clust", { .fill="ROC_L1_Ladder_vs_Module",                             .pfs={"DelayScans"},          .cuts={"ZeroBias","Lay1"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
  sh.AddHistos("clust", { .fill="ROC_L2_Ladder_vs_Module",                             .pfs={"DelayScans"},          .cuts={"ZeroBias","Lay2"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
  sh.AddHistos("clust", { .fill="ROC_L3_Ladder_vs_Module",                             .pfs={"DelayScans"},          .cuts={"ZeroBias","Lay3"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
  sh.AddHistos("clust", { .fill="ROC_L4_Ladder_vs_Module",                             .pfs={"DelayScans"},          .cuts={"ZeroBias","Lay4"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
  sh.AddHistos("clust", { .fill="ROC_Ring1_BladePanel_vs_Disk",                        .pfs={"DelayScans"},          .cuts={"ZeroBias","Ring1"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
  sh.AddHistos("clust", { .fill="ROC_Ring2_BladePanel_vs_Disk",                        .pfs={"DelayScans"},          .cuts={"ZeroBias","Ring2"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
#endif
  
  //__________________________________________________________________________________
  //                                Timing Scans
  
#if Timing_Scan == 1
  sh.SetHistoWeights({});

  // Timing
  //double sz1  =  2, sz2  = 7;
  //double osz1 =  2, osz2 = 7;
  //double ch1  = 30, ch2  = 100;
  //double och1 =  0, och2 = 100;
  //double onc1 = 10, onc2 = 50;
  //double mpv1 =  0, mpv2 = 50;
  // Other Scans
  double sz1  =  0, sz2  = 10;
  double osz1 =  0, osz2 = 10;
  double osx1 =  0, osx2 = 4;
  double ch1  =  0, ch2  = 100;
  double och1 =  0, och2 = 100;
  double onc1 =  0, onc2 = 50;
  double mpv1 =  0, mpv2 = 50;
  std::vector<std::string> plots = {"AvgCluSize","AvgCluCharge", "AvgOnTrkCluSize", "AvgOnTrkCluSizeX", "AvgOnTrkCluSizeY",
				    "AvgOnTrkCluCharge","AvgNormOnTrkCluCharge", "NormOnTrkCluChargeMPV", "HitEfficiency", "DColEfficiency"};
  std::vector<double> ymins = {sz1, ch1, osz1, osx1, osz1, och1, onc1, mpv1, 0.5, 0.0};
  std::vector<double> ymaxs = {sz2, ch2, osz2, osx2, osz2, och2, onc2, mpv2, 1.0, 1.0};

  for (std::string scan : {"Delay","ContrlReg","VcThrShift","ViBias"}) {
    for (size_t i=0, n=plots.size(); i<n; ++i) if (i>=2 || CLUST_LOOP>0) {
      std::string plot = plots[i];
      double ymin = ymins[i];
      double ymax = ymaxs[i];
      std::string tree = (i<2) ? "clust" : "traj";
      std::vector<std::string> cuts;
      cuts.push_back("ZeroBias");
      //if (i==0) cuts.push_back("CluCharge>12");
      //if (i>=2&&i<=4) cuts.push_back("OnTrkCluCharge>12");
      if      (i==8) cuts.push_back("EffCutsScans");
      else if (i==9) cuts.push_back("DColEffCutsScans");
      std::string main;
      if      (scan=="Delay")      main = "DelayScans";
      else if (scan=="ContrlReg")  main = "ContrlRegScans";
      else if (scan=="VcThrShift") main = "ThresholdScans";
      else if (scan=="ViBias")     main = "ViBiasScans";
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={main                                 }, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={main,        "BPixFPix"              }, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={main,        "LayersDisks"           }, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "BPixFPix",         main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "Layers",           main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"Mods",      "Layers",           main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"InnerOuter","Layers",           main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"InnerOuter","Layers","Mod12/34",main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"Shell",     "Layers",           main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "Layers","Shell",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"Mods",      "Layers","Shell",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"Sectors",   "Layers","Shell",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "Disks",            main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "Disks", "Rings",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"Shell",     "Disks",            main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={             "Disks", "Shell",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
      sh.AddHistos(tree,  { .fill=plot+"_vs_"+scan,       .pfs={"RingsROGs", "Disks", "Shell",   main}, .cuts=cuts, .draw="PE1", .opt="", .ranges={0,0, ymin,ymax} });
    }
  }

  // Plots for Viktor
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_Delay",  .pfs={"ROGRings","Layer12/34","Shell","Sectors","DelayScans"}, .cuts={"ZeroBias","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,0, 0,1} });

#if CLUST_LOOP==1
  sh.AddHistos("clust", { .fill="CluCharge",                            .pfs={"FineDelays","LayersDisks"}, .cuts={"DelayScan","ZeroBias"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("clust", { .fill="CluSize",                              .pfs={"FineDelays","LayersDisks"}, .cuts={"DelayScan","ZeroBias"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,0, 0,0} });
#endif
  sh.AddHistos("traj",  { .fill="NormOnTrkCluCharge",                   .pfs={"FineDelays","LayersDisks"}, .cuts={"DelayScan","ZeroBias"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluCharge",                       .pfs={"FineDelays","LayersDisks"}, .cuts={"DelayScan","ZeroBias"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluSize",                         .pfs={"FineDelays","LayersDisks"}, .cuts={"DelayScan","ZeroBias"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,0, 0,0} });  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_TrackEta",          .pfs={"Layers","DelayScans","11ns"}, .cuts={"DelayScan","ZeroBias"}, .draw="PE1", .opt="", .ranges={0,0, osz1,osz2} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_TrackEta",          .pfs={"DelayScans","Layers","11ns"}, .cuts={"DelayScan","ZeroBias"}, .draw="PE1", .opt="", .ranges={0,0, osz1,osz2} });
  // InstLumi
  sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",             .pfs={"Delays","LayersDisks"},  .cuts={"ZeroBias","EffCutsScans"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
  sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",            .pfs={"Delays","Layers"},       .cuts={"ZeroBias","DColEffCutsScans"},    .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });

#endif
  
  //__________________________________________________________________________________
  //                                  HV Scans
  
#if HV_Scan == 1
  // Full HV Scans"TrkPt>0.6&&ValidHit"
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
#endif
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,400, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,400, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","EffCutsScans","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,1} });

  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Mods","BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"LayersDisksInOut","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"LayersDisks","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
#endif
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"LayersDisksInOut","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"LayersDisks","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
#endif
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",       .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",       .pfs={"ROCInOut","Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"BPixLay1New","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"LayersDisksInOut","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  //sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"LayersDisks","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
#endif
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("traj",  { .fill="NormOnTrkCluCharge",                   .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluCharge",                       .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluSize",                         .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,10, 0,0} });
  
#if CLUST_LOOP==1
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  //sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"LayersDisksInOut","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  //sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"LayersDisks","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
#endif
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"HVBiasScans","LayersDisks"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Disks","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Mods","InnerOuter","Layers","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Disks","Rings","HVBiasScans"},                       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  //sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"LayersDisksInOut","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  //sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"LayersDisks","BPixFPix","HVBiasScans"},       .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"LayersDisks","NewModules","HVBiasScans"},          .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
#endif
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Sectors","Layers","Shell","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"RingsROGs","Disks","Shell","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"Mods","Layers","HVBiasScans"},                    .cuts={"FullHVScan","BPix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("clust", { .fill="NormOnTrkCluCharge",              .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="CluCharge",                       .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,400, 0,0} });
  sh.AddHistos("clust", { .fill="CluSize",                         .pfs={"Voltages","LayersDisks","HVBiasScans"}, .cuts={"FullHVScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,10, 0,0} });
#endif
  // One ROG HV Scans
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVBiasScans","HVGroupsScanned"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,300, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVGroupsScanned","HVBiasScans"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,300, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVBiasScans","BPixLay1New"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"BPixLay1New","HVBiasScans"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVBiasScans","Lay1HVScanned"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"Lay1HVScanned","HVBiasScans"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"DisksRings","HVBiasScans"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVBiasScans","DisksRings"},.cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,555, 0,1} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="HitEfficiency_vs_BiasVoltage",         .pfs={"HVGroupsScanned","NewModules","HVBiasScans"}, .cuts={"OneHVGroupScan","EffCutsScans"}, .draw="PE1", .opt="", .ranges={0,300, 0,1} });
#endif
  
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVBiasScans","HVGroupsScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVGroupsScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVBiasScans","BPixLay1New"},  .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"BPixLay1New","HVBiasScans"},  .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVBiasScans","Lay1HVScanned"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"Lay1HVScanned","HVBiasScans"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"HVBiasScans","HVGroupsScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"HVGroupsScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"DisksRings","HVBiasScans"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgNormOnTrkCluCharge_vs_BiasVoltage", .pfs={"HVBiasScans","DisksRings"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluCharge_vs_BiasVoltage",     .pfs={"HVGroupsScanned","NewModules","HVBiasScans"},  .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#endif
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"HVBiasScans","HVGroupsScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"HVGroupsScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"HVBiasScans","BPixLay1New"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"BPixLay1New","HVBiasScans"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"HVBiasScans","Lay1HVScanned"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"Lay1HVScanned","HVBiasScans"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"DisksRings","HVBiasScans"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage", .pfs={"HVBiasScans","DisksRings"},.cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,555, 0,0} });
#if PHASE == 0
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSize_vs_BiasVoltage",       .pfs={"HVGroupsScanned","NewModules","HVBiasScans"},  .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });   
#endif
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVGroupsScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,450, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVBiasScans","HVGroupsScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVBiasScans","BPixLay1New"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"BPixLay1New","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVBiasScans","Lay1HVScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"Lay1HVScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"DisksRings","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeX_vs_BiasVoltage",      .pfs={"HVBiasScans","DisksRings"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVGroupsScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,450, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVBiasScans","HVGroupsScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVBiasScans","BPixLay1New"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"BPixLay1New","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVBiasScans","Lay1HVScanned"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"Lay1HVScanned","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"DisksRings","HVBiasScans"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  sh.AddHistos("traj",  { .fill="AvgOnTrkCluSizeY_vs_BiasVoltage",      .pfs={"HVBiasScans","DisksRings"},               .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="PE1", .opt="", .ranges={0,400, 0,0} });
  
  sh.AddHistos("traj",  { .fill="NormOnTrkCluCharge",                   .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluCharge",                       .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("traj",  { .fill="OnTrkCluSize",                         .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan","TrkPt>0.6&&ValidHit","0TLay1HighEtaFix"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,10, 0,0} });
#if CLUST_LOOP==1
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"HVBiasScans","HVGroupsScanned"},              .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"HVGroupsScanned","HVBiasScans"},              .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("clust", { .fill="AvgCluCharge_vs_BiasVoltage",     .pfs={"HVGroupsScanned","NewModules","HVBiasScans"}, .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#endif
  
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"HVBiasScans","HVGroupsScanned"},              .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"HVGroupsScanned","HVBiasScans"},              .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#if PHASE == 0
  sh.AddHistos("clust", { .fill="AvgCluSize_vs_BiasVoltage",       .pfs={"HVGroupsScanned","NewModules","HVBiasScans"}, .cuts={"OneHVGroupScan"}, .draw="PE1", .opt="", .ranges={0,300, 0,0} });
#endif
  
  sh.AddHistos("clust", { .fill="NormOnTrkCluCharge",              .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("clust", { .fill="CluCharge",                       .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,100, 0,0} });
  sh.AddHistos("clust", { .fill="CluSize",                         .pfs={"Voltages","HVGroupsScanned","HVBiasScans"}, .cuts={"OneHVGroupScan"}, .draw="HISTE1", .opt="KeepNormSumw2", .ranges={0,10, 0,0} });
#endif
#endif

  
  
  sh.GetTotalNCells(); 
  std::function<void()> add_special_histos = [&sh]{};
  
  std::cout<<"-----------------------------------------------------------------\n";
  //std::cout<<"Creating the following plots:\n"; sh.PrintNames();
  //std::cout<<"-----------------------------------------------------------------\n";
  

  if (filelist.size()&&!is_a) {
    std::cout<<"Adding "<<filelist.size()<<" files from the shell arguments:\n";
    for (size_t i=0; i<filelist.size(); ++i) {
      std::cout<<filelist[i]<<std::endl;
      looper.AddFile(filelist[i]);
    }
  } else {
    //Add here hardcoded files to run on
    //looper.AddFile("/foo/bar/*.root");
  }
  
  // Load/Add Histos from a file
  if (!is_a) {
    //sh.Load("PHM_out/previous_scan.root");
    //sh.Add("PHM_out/previous_scan.root");
    
  } else {
    std::cout<<"Adding histograms from "<<filelist.size()<<" files from the shell arguments:\n";
    for (size_t i=0; i<filelist.size(); ++i) {
      std::cout<<filelist[i]<<std::endl;
      sh.Add(filelist[i]);
    }
  }
  
  // Loop on trees and fill histograms
  if (!is_a) looper.LoopOnTrees(&sh, add_special_histos, opt_n);
  
  // Write histograms and canvases in an output file
  TFile* f_out = new TFile(outputfile.size()?outputfile.c_str():"PHM_out/test.root","recreate"); 
  sh.DrawPlots();
  sh.Write();
  f_out->Close();
  std::cout<<"Writing plots to file: "<<f_out->GetName()<<" done.\n";
  
  return 1;
}
