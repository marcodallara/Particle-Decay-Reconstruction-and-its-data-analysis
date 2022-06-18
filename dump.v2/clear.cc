#include <iostream>
#include <fstream>

#include "Event.h"
#include "Particle.h"

void clear(const Event* e){
  //delete particels
  for(int i=0;i<e->n_particle;i++)  delete e->p[i];
  //delete array of pointer to particle
  delete[] e->p;
  //delete event
  delete e;

}
