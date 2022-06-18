#ifndef ParticleLifetime_h
#define ParticleLifetime_h

#include <string>
#include <vector>
#include "AnalysisFramework/AnalysisSteering.h"
#include "util/include/ActiveObserver.h"
#include "TH1F.h"
#include "TFile.h"
#include "AnalysisObjects/LifetimeFit.h"

using namespace std;

class Event;
class MassMean;

class ParticleLifetime : public AnalysisSteering, public ActiveObserver<Event> {

 public:

  ParticleLifetime( const AnalysisInfo* info );
  // deleted copy constructor and assignment to prevent unadvertent copy
  ParticleLifetime           ( const ParticleLifetime& x ) = delete;
  ParticleLifetime& operator=( const ParticleLifetime& x ) = delete;

   ~ParticleLifetime() override;

  // function to be called at execution start
  void beginJob()  override; 
  // function to be called at execution end
  void   endJob()  override;
  // function to be called for each event
  void update( const Event& ev )  override;
  // create objects for a hist
  void pCreate(const string& name, float minm , float maxm, double timeMin, double timeMax, double minsr, double maxsr, double step);
  
 private:
  struct Particle {
    string name;
    LifetimeFit* m;
    TH1F* h;
  };
  
  vector <Particle*> pList;
    

};

#endif

