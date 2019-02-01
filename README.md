Libraries for reading out RAT-PAC ROOT files.  This library is a 
direct port of all classes in the /DS/ directory of RAT-PAC, along
with the DSReader.  

Although the ideal way to implement these libraries in ToolAnalysis
would be to perform a full install of RAT-PAC and link the libraries,
this approach is more lightweight.  A full installation of RAT-PAC
requires GEANT4, which would make the docker image bulky.  
Additionally, ToolAnalysis only needs to read
the RATDS structure.

A small note: This library is basically a copy and paste of the ds
files within RAT-PAC, with some subtle changes:
  - The header includes no longer point to locations in a /RAT/DS/
    subdirectory.
  - DSReader.hh has the lines "using namespace RAT" and "using namespace
    RAT::DS" following the includes.  For some reason, if at least
    one of the files didn't just make a call to using the namespace,
    rootcint wouldn't link the libraries properly.

