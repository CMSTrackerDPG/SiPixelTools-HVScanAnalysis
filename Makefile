include Makefile.arch

#------------------------------------------------------------------------------
P1SHMO      = Phase1ScanHistoMaker.$(ObjSuf)
P1SHMS      = Phase1ScanHistoMaker.$(SrcSuf)
P1SHM       = Phase1ScanHistoMaker$(ExeSuf)

OBJS          += $(P1SHMO)
PROGRAMS      += $(P1SHM)

#------------------------------------------------------------------------------
P1PHMO      = Phase1PixelHistoMaker.$(ObjSuf)
P1PHMS      = Phase1PixelHistoMaker.$(SrcSuf)
P1PHM       = Phase1PixelHistoMaker$(ExeSuf)

OBJS          += $(P1PHMO)
PROGRAMS      += $(P1PHM)

#------------------------------------------------------------------------------


.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

all:            $(PROGRAMS)

$(P1SHM):     $(P1SHMO)
		$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
		$(MT_EXE)
		@echo "$@ done"

$(P1PHM):     $(P1PHMO)
		$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
		$(MT_EXE)
		@echo "$@ done"

clean:
		@rm -f $(OBJS) core


distclean:      clean
		@rm -f $(PROGRAMS) *Dict.* *.def *.exp \
		   *.root *.ps *.so *.lib *.dll *.d *.log .def so_locations
		@rm -rf cxx_repository

.SUFFIXES: .$(SrcSuf)

###

.$(SrcSuf).$(ObjSuf):
	$(CXX) $(CXXFLAGS) -c $<

