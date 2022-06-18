#include <iostream>

#include "TH1F.h"
#include "TFile.h"

#include "MassMean.h"
#include "ParticleMass.h"

double mass( const Event& e );

//struct Particle;

ParticleMass::ParticleMass() {
}


ParticleMass::~ParticleMass() {
  for(auto c:pList) delete c;
}
//load two type of particles
void ParticleMass:: beginJob(){
  pCreate("K0", 0.495, 0.500);
  pCreate("Lamba0", 1.115, 1.116);

}

void ParticleMass:: endJob(){
  for(unsigned int i=0; i<pList.size();i++ ) {
    pList.at(i)->m->compute();
    // print number of selected events and results 
    std::cout<<"particle n: "<<i+1<<std::endl<<"selected events"<<pList.at(i)->m->get_n_accev()<<std::endl;
   std::cout<<" mean and rms"<<pList.at(i)->m->get_mean_im()<<"  "<<pList.at(i)->m->get_rms_im()<<std::endl;
  }
   
   TDirectory* currentDir= gDirectory;
   TFile* file= new TFile("hist" , "CREATE");
   for(auto c:pList) c->h->Write();
   file->Close();
   delete file;
   currentDir->cd();
   
   
   

}

void ParticleMass:: process( const Event& ev){
  for(auto c: pList ) if(c->m->add(ev)) c->h->Fill( mass(ev));
  
}

void ParticleMass:: pCreate (const string& name, float min , float max ){

  // create name for TH1F object
  const char* hName = name.c_str();

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
