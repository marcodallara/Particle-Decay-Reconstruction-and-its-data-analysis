#ifndef LifetimeFit_h
#define LifetimeFit_h

class Event;

class LifetimeFit {

 public:

  LifetimeFit( float min, float max ); // mass range
  ~LifetimeFit();

  bool add( const Event& ev );      // add data from a new event
  void compute();                   // compute mean and rms
  
  int get_n_accev() const ;      // return number of accepted events

 private:

  double min_im; // min mass
  double max_im; // max mass

  int n_accev; // number of accepted events


};

#endif

