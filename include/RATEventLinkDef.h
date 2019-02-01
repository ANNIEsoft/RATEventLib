#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

//#pragma link C++ nestedtypedef;
//#pragma link C++ nestedclass;

#pragma link C++ class PMTInfo+;
#pragma link C++ class LAPPDInfo+;

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


#pragma link C++ class RAT::Log+;
#pragma link C++ class RAT::DBFieldCallback+;

#endif // __CINT__

#ifdef __MAKECINT__

#pragma link C++ class pair<string,string>+;
#pragma link C++ class map<int, int>+;
#pragma link C++ class map<int, vector<int> >+;
#pragma link C++ class vector<TVector3>;
#pragma link C++ class vector<TLorentzVector>; 
#pragma link C++ class vector<RAT::DS::Root>;
#pragma link C++ class vector<PMTInfo>;
#pragma link C++ class vector<LAPPDInfo>;

#pragma link C++ class vector<RAT::DS::MC>;
#pragma link C++ class vector<RAT::DS::MCParticle>;
#pragma link C++ class vector<RAT::DS::MCTrack>;
#pragma link C++ class vector<RAT::DS::MCTrackStep>;
#pragma link C++ class vector<RAT::DS::MCPMT>;
#pragma link C++ class vector<RAT::DS::MCLAPPD>;
#pragma link C++ class vector<RAT::DS::MCPhoton>;
#pragma link C++ class vector<RAT::DS::Calib>;
#pragma link C++ class vector<RAT::DS::EV>;
#pragma link C++ class vector<RAT::DS::PMT>;
#pragma link C++ class vector<RAT::DS::LAPPD>;
#pragma link C++ class vector<RAT::DS::LAPPDHit>;
#pragma link C++ class vector< pair<string, int> >;
#pragma link C++ class vector<RAT::DBTable*>;

#pragma link C++ class vector<RAT::TrackNode*>;
#pragma link C++ class vector<RAT::DS::EV*>;
#pragma link C++ class vector<RAT::DS::PMT*>;
#pragma link C++ class vector<RAT::DS::LAPPD*>;
#pragma link C++ class vector<RAT::DS::LAPPDHit*>;
#pragma link C++ class vector<RAT::DS::MCParticle*>;
#pragma link C++ class vector<RAT::DS::MCTrack*>;
#pragma link C++ class vector<RAT::DS::MCPMT*>;
#pragma link C++ class vector<RAT::DS::MCLAPPD*>;
#pragma link C++ class vector<RAT::DS::MCPhoton*>;
#pragma link C++ class vector<RAT::DS::MCTrackStep*>;

#endif

