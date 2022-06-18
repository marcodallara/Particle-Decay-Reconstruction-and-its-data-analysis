#include "MassMean.h"
#include "Event.h"

#include <math.h>

double mass( const Event& e );


MassMean::MassMean( float min, float max ):
 // initializations
  min_im(min),
  max_im(max),
  n_accev(0),
  sum_im(0),
  sum_sqim(0) {
}


MassMean::~MassMean() {
}


// add data from a new event
void MassMean::add( const Event& e ) {

  // check for mass being in range
   double im = mass(e); 
  if(im < max_im && im > min_im ){
    im-=min_im; //to contrast limited precision;
    // update number of events and sums
    sum_im += im;
    sum_sqim += pow(im , 2);
    n_accev++;
    
  }




}


// compute mean and rms
void MassMean::compute() {
  mean_im=(sum_im) / n_accev;
  rms_im= sqrt( (sum_sqim/n_accev) - pow(mean_im,2));
  mean_im= mean_im +min_im;  //adding the min subtracted in "add(...)"
}


// return number of selected events
int MassMean::get_n_accev() const {
  return n_accev;
}


// return mean and rms

const double MassMean::get_mean_im() const  {
  return mean_im;
}

const double MassMean::get_rms_im() const {
  return rms_im;
}
