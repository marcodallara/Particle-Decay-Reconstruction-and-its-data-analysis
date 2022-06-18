#include <iostream>

#include "TFileProxy.h"

#include "MassMean.h"
#include "ParticleLifetime.h"
#include "AnalysisFactory.h"
#include "ParticleReco.h"
#include "AnalysisInfo.h"
#include "ProperTime.h"

// concrete factory to create an EventDump analyzer
class ParticleLifetimeFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "particlelifetime" as name for this analyzer and factory
  ParticleLifetimeFactory(): AnalysisFactory::AbsFactory( "particlelifetime" ) {}
  // create an particleMass  when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleLifetime( info );
  }
};
// create a global EventDumpFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EventDumpFactory will be available with name "dump".
static ParticleLifetimeFactory pm;


ParticleLifetime::ParticleLifetime( const AnalysisInfo* info ):
  AnalysisSteering( info ) {
}


ParticleLifetime::~ParticleLifetime() {
  for(auto c:pList) delete c;
}
//load two type of particles
void ParticleLifetime:: beginJob(){
  pCreate("K0", 0.495, 0.500, 10.0, 500.0);
  pCreate("Lamba0", 1.115, 1.116, 10.0, 1000.0);
}

void ParticleLifetime:: endJob(){
  for(unsigned int i=0; i<pList.size();i++ ) {
    pList.at(i)->m->compute();
    // print number of selected events 
    std::cout<<"particle n: "<<i+1<<std::endl<<"selected events"<<pList.at(i)->m->get_n_accev()<<std::endl;
   
  }


   TDirectory* currentDir= gDirectory;
   TFileProxy* file= new TFileProxy( "hists" , "CREATE");
   for(auto c:pList) c->h->Write();
   file->Close();
   delete file; 
   currentDir->cd();
   

}

void ParticleLifetime:: update( const Event& ev){
  //fill histogram with the mass getting singleton particleReco
  static ProperTime* pr = ProperTime::instance();
  for(auto c: pList ) if(c->m->add(ev)) c->h->Fill( pr->get_decayTime());
  
}

void ParticleLifetime:: pCreate (const string& name, float min , float max, float timeMin, float timeMax){

  // create name for TH1F object
  const string n = "time_" + name; 
  const char* hName = n.c_str();

  // bin number equal to point number
  int nBinD = 50;

  // create TH1F and statistic objects and store their pointers
  Particle* pa = new Particle;
  pa-> name = name;
  pa->m = new LifetimeFit( min, max );
  pa->h = new TH1F( hName, hName, nBinD , timeMin, timeMax );
  pList.push_back(pa);
  
  return;


}
