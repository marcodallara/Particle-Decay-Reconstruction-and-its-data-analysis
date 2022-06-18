#include "LifetimeFit.h"
#include "Event.h"
#include "ParticleReco.h"
#include <math.h>


//double mass( const Event& e );


LifetimeFit::LifetimeFit( float min, float max ):
 // initializations
  min_im(min),
  max_im(max),
  n_accev(0) {
}


LifetimeFit::~LifetimeFit() {
}


// add data from a new event
bool LifetimeFit::add( const Event& e ) {
  // check for mass being in range getting singleton particleReco
  static ParticleReco* pr = ParticleReco::instance();
  double im = pr->get_particleMass();
  if(im < max_im && im > min_im && pr->get_particleType() != ParticleReco::unknown){
    // update number of events and sums
    n_accev++;
    return true;
    
  }
  else  return false;




}


// compute mean and rms
void LifetimeFit::compute() {

  return;
  
}


// return number of selected events
int LifetimeFit::get_n_accev() const {
  return n_accev;
}


