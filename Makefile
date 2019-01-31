## Makefile ##

#
# notes:
#
#

CXX           = g++
CXXDEPEND     = -MM
CXXFLAGS      = -g -Wall -fPIC -O0

UNAME := $(shell uname)

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs) 
ROOTGLIBS    := $(shell root-config --glibs)

CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTLIBS) $(SYSLIBS)
GLIBS         = $(ROOTGLIBS) $(SYSLIBS)

INCDIR = ./include
SRCDIR = ./src
TMPDIR = ./tmp
LIBDIR = ./lib
BINDIR = ./bin

INCLUDES = -I$(INCDIR)

.PHONY: 
	all

all: clean rootcint shared

ROOTSO := $(LIBDIR)/libRATEvent.so

ROOTDICT := $(SRCDIR)/RATEventRootDict.cc

ROOTSRC := $(INCDIR)/PosFit.hh $(SRCDIR)/DSReader.cc $(INCDIR)/DSReader.hh $(SRCDIR)/MCLAPPD.cc $(INCDIR)/MCLAPPD.hh $(SRCDIR)/MCPMT.cc $(INCDIR)/MCPMT.hh $(SRCDIR)/RunStore.cc $(INCDIR)/RunStore.hh $(INCDIR)/Centroid.hh $(INCDIR)/Calib.hh $(INCDIR)/EV.hh $(INCDIR)/LAPPD.hh $(INCDIR)/LAPPDHit.hh $(INCDIR)/LAPPDInfo.hh $(INCDIR)/MC.hh $(INCDIR)/MCParticle.hh $(INCDIR)/MCPhoton.hh $(INCDIR)/MCSummary.hh $(INCDIR)/MCTrack.hh $(INCDIR)/MCTrackStep.hh $(INCDIR)/PathFit.hh $(INCDIR)/PMT.hh $(INCDIR)/PMTInfo.hh $(INCDIR)/Run.hh $(INCDIR)/RunStore.hh $(INCDIR)/RATEventLinkDef.h
ROOTOBJS := $(TMPDIR)/MCLAPPD.o $(TMPDIR)/MCPMT.o $(TMPDIR)/RunStore.o $(TMPDIR)/Centroid.o $(TMPDIR)/Calib.o $(TMPDIR)/EV.o $(TMPDIR)/LAPPD.o $(TMPDIR)/LAPPDHit.o $(TMPDIR)/LAPPDInfo.o $(TMPDIR)/MC.o $(TMPDIR)/MCParticle.o $(TMPDIR)/MCPhoton.o $(TMPDIR)/MCSummary.o $(TMPDIR)/MCTrack.o $(TMPDIR)/MCTrackStep.o $(TMPDIR)/PathFit.o $(TMPDIR)/PMT.o $(TMPDIR)/PMTInfo.o $(TMPDIR)/PosFit.o $(TMPDIR)/Run.o $(TMPDIR)/RunStore.o $(TMPDIR)/EvtDisplayRootDict.o

$(TMPDIR)/%.o : $(SRCDIR)/%.cc
	@echo "<**Compiling $@**>"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TMPDIR)/%.d: $(SRCDIR)/%.cc
	@echo "<**Depend $@**>"
	set -e; $(CXX) $(CXXDEPEND) $(CXXFLAGS) $(INCLUDES) $< \
	| sed 's!$*\.o!& $@!' >$@;\
	[ -s $@ ] || rm -f $@

$(ROOTDICT) : $(ROOTSRC)

rootcint : $(ROOTSRC)
	@echo "<**Rootcint**>"
	rootcint -f $(ROOTDICT) -c -I$(INCDIR) -I$(shell root-config --incdir) MCLAPPD.hh MCPMT.hh RunStore.hh Centroid.hh Calib.hh EV.hh LAPPD.hh LAPPDHit.hh LAPPDInfo.hh MC.hh MCParticle.hh MCPhoton.hh MCSummary.hh MCTrack.hh MCTrackStep.hh PathFit.hh PMT.hh PMTInfo.hh PosFit.hh Run.hh RunStore.hh

shared: $(ROOTDICT) $(ROOTSRC) $(ROOTOBJS)
	@echo "<**Shared**>"
ifeq ($(UNAME), Darwin) 
	g++ -dynamiclib $(ROOTLIBS) $(ROOTGLIBS) -O $(ROOTOBJS) -o $(ROOTSO)
endif
ifeq ($(UNAME), Linux) 
	g++ -shared $(ROOTLIBS) $(ROOTGLIBS) -O $(ROOTOBJS) -o $(ROOTSO) 
endif

clean :
	@echo "<**Clean**>"
	rm -f $(SRCDIR)/*~ $(INCDIR)/*~ $(TMPDIR)/*.o $(TMPDIR)/*.d $(TMPDIR)/*.a $(LIBDIR)/*.so $(SRCDIR)/RATEventRootDict.*

DEPS = $(ROOTOBJS:$(TMPDIR)/%.o=$(TMPDIR)/%.d)

ifeq ($(MAKECMDGOALS),all)
 include $(DEPS)
endif

ifeq ($(MAKECMDGOALS),shared)
 include $(DEPS)
endif
