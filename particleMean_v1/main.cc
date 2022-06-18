#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

struct Event;
struct Partcile;

void dump(const Event& e);
const Event* read(std:: ifstream& in );
void clear(const Event* e);
double mass(const Event& e);
bool add(const Event& e, float min, float max, double& sum_im, double& sum_sqim );


int main( int argc, char* argv[] ){
  
  const char* name = argv[1];
  std::ifstream file( name ); //open input file
  const Event* e;
  //number of accepted events
  int n_accev = 0;
  //statistic variables
  double sum_im = 0;
  double sum_sqim = 0;
  double mean_im = 0;
  double rms_im = 0;
  while( ( e = read( file))  != nullptr ){ //looping file
    dump( *e );
    
    //update statistic variables
    if(add(*e, 0.490, 0.505, sum_im, sum_sqim ))  n_accev++;
    clear( e );
  }
  std::cout<<"numero di eventi accettati "<<n_accev<<std::endl;

  mean_im=(sum_im) / n_accev; 
  rms_im= sqrt( (sum_sqim/n_accev) - pow(mean_im,2));
  mean_im= mean_im +0.490;  //adding the min subtracted in "add(...)"
  std:: cout<< mean_im << ' ' << rms_im ;
  
  return 0;
}
