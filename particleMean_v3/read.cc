#include <iostream>
#include <fstream>

#include "Event.h"

const Event* read( std::ifstream& in){

  Event* e;
  double evid;
  //if read the first then allocate and copy the event
  if( in>>evid ) {
    
    double x;
    in>>x;
    double y;
    in>>y;
    double z;
    in>>z;
    e=new Event(evid, x , y , z);
  } 
  else return nullptr;  // on failure return null pointer

  int np; // number of particles to control;
  in>>np;
  int charge;
  double p_x, p_y, p_z;
  for(int i=0;i<np;i++){   //set particle's data
    
    in>> charge;
    in>> p_x;
    in>> p_y;
    in>> p_z;
    e->add(charge, p_x, p_y, p_z);
  }

  return e;

}
