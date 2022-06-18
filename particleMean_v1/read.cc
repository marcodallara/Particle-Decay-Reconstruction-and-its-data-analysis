#include <iostream>
#include <fstream>

#include "Event.h"
#include "Particle.h"

const Event* read( std::ifstream& in){

  Event* e;
  double i;
  if( in>>i ) e = new Event; 
  else return nullptr;  // on failure return null pointer
  //read the event id and coordinates
  e->ev_id = i; 
  
  in>>i;
  e->x = i;
   
  in>>i;
  e->y = i;
   
  in>>i;
  e->z = i;

  int n;
  in>>n;
  e->n_particle = n;

  e->pp = new Particle*[n];
  
  for(int i=0;i<n;i++){   //set particle's data
    (e->pp[i]) = new Particle;
    in>> (e->pp[i])->charge;
    in>> (e->pp[i])->p_x;
    in>> (e->pp[i])->p_y;
    in>> (e->pp[i])->p_z;
  }

  return e;

}
