#ifndef LifetimeFit_h

#define LifetimeFit_h

#include <vector>

class Event;

class LifetimeFit {

 public:

  LifetimeFit( double Min_im, double Max_im, double Min_t, double Max_t, double Min_sr, double Max_sr, double Stepscan   ); // mass, time and scan range plus scanstep
  ~LifetimeFit();

  bool add( const Event& ev );      // add data from a new event
  void compute();                   // compute mean and rms
  
  int get_n_accev() const ;      // return number entries in the decay time vecor
  double lifeTime() const ;      //return mean lifetime
  double lifeTimeError() const;  //return lifetime error

 private:

  double min_im; // min mass
  double max_im; // max mass

  double min_T; //min time
  double max_T; //max time

  double min_sr; //min scan range
  double max_sr; //max scan range

  double scanstep;
  std::vector<double> decay_times; //container for all the decay times
  double plt_mean; //particle mean life time
  double plt_error; //particle error life time


};

#endif

