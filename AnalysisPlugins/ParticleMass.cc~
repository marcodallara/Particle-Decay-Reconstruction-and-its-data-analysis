#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "TFileProxy.h"

#include "MassMean.h"
#include "ParticleMass.h"
#include "AnalysisFactory.h"
#include "AnalysisInfo.h"
#include "ParticleReco.h"

// concrete factory to create an EventDump analyzer
class ParticleMassFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "particlemass" as name for this analyzer and factory
  ParticleMassFactory(): AnalysisFactory::AbsFactory( "particlemass" ) {}
  // create an particleMass  when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleMass( info );
  }
};
// create a global EventDumpFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EventDumpFactory will be available with name "dump".
static ParticleMassFactory pm;


ParticleMass::ParticleMass( const AnalysisInfo* info ):
  AnalysisSteering( info ) {
}


ParticleMass::~ParticleMass() {
  for(auto c:pList) delete c;
}
//load two type of particles
void ParticleMass:: beginJob(){
  if(aInfo->contains("ParticleMassRanges")){
    ifstream fin(aInfo->value("ParticleMassRanges"));
    string a;
    double b,c;
    //read names and datas and call pcreate
    while(fin>>a>>b>>c){
      pCreate(a, b, c);
    }
  }

  else{ pCreate("K0", 0.495, 0.500);   pCreate("Lamba0", 1.115, 1.116);}
}



void ParticleMass:: endJob(){
  for(unsigned int i=0; i<pList.size();i++ ) {
    pList.at(i)->m->compute();
    // print number of selected events and results 
    std::cout<<"particle n: "<<i+1<<std::endl<<"selected events"<<pList.at(i)->m->get_n_accev()<<std::endl;
   std::cout<<"inv mass  mean and rms"<<pList.at(i)->m->get_mean_im()<<"  "<<pList.at(i)->m->get_rms_im()<<std::endl;
  }


   TDirectory* currentDir= gDirectory;
   TFileProxy* file= new TFileProxy( "hists" , "CREATE");
   for(auto c:pList) c->h->Write();
   file->Close();
   delete file;
   currentDir->cd();
   
   
   

}

void ParticleMass:: update( const Event& ev){
  //fill histogram with the mass getting singleton particleReco
  static ParticleReco* pr = ParticleReco::instance();
  for(auto c: pList ) if(c->m->add(ev)) c->h->Fill( pr->get_particleMass());
  
}

void ParticleMass:: pCreate (const string& name, float min , float max ){

  // create name for TH1F object
  const string n = "mass_" + name; 
  const char* hName = n.c_str();

  // bin number equal to point number
  int nBinD = 50;

  // create TH1F and statistic objects and store their pointers
  Particle* pa = new Particle;
  pa-> name = name;
  pa->m = new MassMean( min, max );
  pa->h = new TH1F( hName, hName, nBinD , min, max );
  pList.push_back(pa);
  
  return;


}
