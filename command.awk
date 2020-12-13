#This program gets the necessery info for HV scan points from the automatic elog outputs and saves it in c++ format
#please change the original input txt so that 1) grep timestamp 2) delete all commas
BEGIN {
FS="[: ]"
Run=0
begin=-1
whichDet=1 #Which detector part you want to get? Layers [1..4], Disks [5..7]
print "//Detector part " whichDet;
}
{
printrun=0;
run=$9; if (Run!=run) {Run=run;printrun=1;}
whichHV=14+whichDet*2;
hv=$whichHV;
orbit1=$13;
getline;
orbit2=$13;
if (begin!=-1 && printrun==1) print "\t      : NOVAL_I;";
if (printrun==1) print "\tcase " run ":\n\t  return";
if (printrun==1) print "\t    orbit>= " orbit1 " && orbit<= " orbit2 " ? " hv;
if (printrun==0) print "\t    : orbit>= " orbit1 " && orbit<= " orbit2 " ? " hv;
begin=1;
}
END {
print "\t      : NOVAL_I;";
}
