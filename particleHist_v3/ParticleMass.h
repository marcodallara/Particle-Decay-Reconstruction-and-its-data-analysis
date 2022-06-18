#ifndef ParticleMass_h
#define ParticleMass_h

#include <string>
#include <vector>
#include "AnalysisSteering.h"

#include "TH1F.h"
#include "TFile.h"

using namespace std;

class Event;
class MassMean;

class ParticleMass : public AnalysisSteering {

 public:

  ParticleMass( const AnalysisInfo* info );
  // deleted copy constructor and assignment to prevent unadvertent copy
  ParticleMass           ( const ParticleMass& x ) = delete;
  ParticleMass& operator=( const ParticleMass& x ) = delete;

   ~ParticleMass() override;

  // function to be called at execution start
  void beginJob()  override; 
  // function to be called at execution end
  void   endJob()  override;
  // function to be called for each event
  void process( const Event& ev )  override;
  // create objects for a hist
  void pCreate(const std:: string& name, float min, float max);
  
 private:
  struct Particle {
    string name;
    MassMean* m;
    TH1F* h;
  };
  vector <Particle*> pList;
    

};

#endif

