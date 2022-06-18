#include "LifetimeFit.h"
#include "Event.h"
#include "ProperTime.h"
#include <math.h>
#include "QuadraticFitter.h"



LifetimeFit::LifetimeFit( double Min_im, double Max_im, double Min_t, double Max_t, double Min_sr, double Max_sr, double Stepscan ):
 // initializations
  min_im(Min_im),
  max_im(Max_im),
  min_T(Min_t),
  max_T(Max_t),
  min_sr(Min_sr),
  max_sr(Max_sr),
  scanstep(Stepscan) {
}


LifetimeFit::~LifetimeFit() {
}


// add data from a new event
bool LifetimeFit::add( const Event& e ) {
  // check for time and mass  being in range getting singleton ProperTIme
  static ProperTime* pt = ProperTime::instance();
  double dt = pt->get_decayTime();
  double im = pt->get_particleMass();
  if(im < max_im && im > min_im && dt < max_T &&dt > min_T && pt->get_particleType() != ProperTime::unknown){
    decay_times.push_back(dt);
    return true;
  }  
  
  else  return false;

}


// compute mean and rms
void LifetimeFit::compute() {
  QuadraticFitter qf;
  double L;
  //make a quadratic fit of max likelihood
  for(double t=min_sr; t<max_sr; t=t+scanstep){
    L=0;
    for(auto c: decay_times){
      
      L=L+(c/t)+log(t)+log(exp(-min_T/t)-exp(-max_T/t));
      
    }
    qf.add(t, L);
  }
  plt_mean=-qf.b()/(2*qf.c());
  plt_error=1/sqrt(2*qf.c());
 
  
  return;
  
}

// return number of selected events
int LifetimeFit::get_n_accev() const {
  return decay_times.size();
}

// return lifetime mean
double LifetimeFit::lifeTime() const {
  return plt_mean;
}

// return lifetime error
double LifetimeFit::lifeTimeError() const {
  return plt_error;
}


