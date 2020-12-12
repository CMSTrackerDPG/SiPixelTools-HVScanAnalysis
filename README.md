# SiPixelTools-HVScanAnalysis
This program is used to analyse Pixel HV scan data
Info on HV scans: https://twiki.cern.ch/twiki/bin/viewauth/CMS/PixelHVBiasScans

##### How to run the code?

First, you need CMSSW env (cmsenv) of a 80X version (somehow it doesn't work with newer c++ and/or root versions)

Input files: PhaseIPixelNtuplizer ntuple

Phase1ScanHistoMaker -- HV scan
Phase1PixelHistoMaker -- Hit efficiency analysis, only used for badROC exclusion
Compile:
```
make clean; make
```
Run:
```
Phase1ScanHistoMaker -o PHM_out/output.root /foo/bar/input*.root
```

##### How to analyse new HV scan data?
Need to implement HV data in PHM
1. download elog output (e.g.: http://cmsonline.cern.ch/cms-elog/1041847)
2. format txt
  a) ```cat filename.txt grep timestemp >newname.txt```
  b) delete all commas (search & replace)
3. AWK
   a) command.awk -> choose desired Layer/disk: whichDet=1 #Layers [1..4], Disks [5..7]
   b) ```awk -f command.awk Fullscan_example.txt >Lay1.h```
   ---better to check the results by eye, just to make sure
   c) d) ... repeat it for all relevant layers/disks
4. edit interface/scan_points.h
   a) number of HV scan: hv_scan_no function (line 837), fill new line with run number and give a number to the scan
   b) badroc filter. In function hv_scan_badroc_runnumber give the badroc runnumber
   c) copy the output of 3. (e.g. Lay1.h) to  function hv_l1
   d) e) ... Repeat for all relevant detector parts
   f) Full/Mini scan. If full scan, put HV scan number to is_full_hv_scan function. If mini scan then put HV scan number to is_one_hv_group_scan function (the same number as in 4/a)
5. make badroc list: (optional, only relevant for hit efficiency plots)
   a) ```make clean; make Phase1PixelHistoMaker```
   b) ```Phase1PixelHistoMaker -b /foo/bar/ntuple*.root```
6. Run ScanHistoMaker
```
make clean; make Phase1ScanHistoMaker
Phase1ScanHistoMaker -o PHM_out/output.root /foo/bar/input*.root
```
7. Open the output with root: root PHM_out/output.root, and see if it worked...

8. Append previous scans together:
```
Phase1ScanHistoMaker -o PHM_out/appended_scans.root -a PHM_out/scan1.root PHM_out/scan2.root PHM_out/scan3.root
```

Appendix for badROC exclusion:
What is a badROC? Inefficient ROC in terms of hit efficiency (it has too many missing hits).
(Exact definition: on hit efficiency distribution of ROCs: threshold = std::min(mean - 0.5*rms, 0.95))
If badROCs are present in the scan: would only effect negatively the hit efficiency plots. Since in cluster parameter plots, the values comes from clusters, a missing hit doesn't have a cluster (missing hit=hit expected by track, but there's no hit), so it wouldn't contribute at all to the cluster plots.
badROC exclusion can only affect cluster plots if by excluding a partly inefficient ROC, we also lose clusters from the good part of the ROC.

badROC exclusion only works if the scan run is different from the badROC run. It is because when you normally run PHM to analyse a scan, it creates a badROC list for the run in question (e.g. scan run). We don't want to identify badROCs in a scan, since low HV points could behave like inefficient ROCs, we'd unnecessary exclude ROCs. But there's a hack: run badROC exclusion for the scan run but outside of scan period. Put the same runnumber for badROC exclusion when analysing the data for the scan, and the exclusion will work properly. But beware, after the scan analysis complete, the badROC list is updated now including the scan data -> if you run again you might exclude too many ROCs.
