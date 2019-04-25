#if defined(__CLING__) || defined(__CINT__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedtypedef;
#pragma link C++ nestedclass;

#pragma line C++ namespace RAT;
#pragma line C++ namespace DS;
#pragma line C++ namespace RAT::DS;
//
#pragma line C++ defined_in namespace RAT;
#pragma line C++ defined_in namespace DS;
#pragma line C++ defined_in namespace RAT::DS;

#pragma link C++ class PMTInfo+;
#pragma link C++ class LAPPDInfo+;

#pragma link C++ class RAT::DS::Root+;
#pragma link C++ class RAT::DS::MC+;
#pragma link C++ class RAT::DS::MCParticle+;
#pragma link C++ class RAT::DS::MCTrack+;
#pragma link C++ class RAT::DS::MCTrackStep+;
#pragma link C++ class RAT::DS::MCPMT+;
#pragma link C++ class RAT::DS::MCLAPPD+;
#pragma link C++ class RAT::DS::MCPhoton+;
#pragma link C++ class RAT::DS::MCSummary+;
#pragma link C++ class RAT::DS::Calib+;

#pragma link C++ class RAT::DS::EV+;
#pragma link C++ class RAT::DS::PMT+;
#pragma link C++ class RAT::DS::LAPPD+;
#pragma link C++ class RAT::DS::LAPPDHit+;

#pragma link C++ class RAT::DS::PosFit+;
#pragma link C++ class RAT::DS::Centroid+;
#pragma link C++ class RAT::DS::PathFit+;

#pragma link C++ class RAT::DS::RunStore+;
#pragma link C++ class RAT::DS::Run+;

#pragma link C++ class RAT::DSReader;
//#pragma link C++ class json::Value+; 

#pragma link C++ class RAT::ObjInt+;
#pragma link C++ class RAT::ObjDbl+;
#pragma link C++ class RAT::Log+;
#pragma link C++ class RAT::DBFieldCallback+;
#pragma link C++ class RAT::TrackCursor+;
#pragma link C++ class RAT::TrackNode+;
#pragma link C++ class RAT::TrackNav+;

#endif // __CINT__


