#include <iostream>
#include <fstream>

#include "Event.h"
#include "Particle.h"

//clear memor
void clear(const Event* e){
  for(int i=0;i<e->n_particle;i++)  delete e->pp[i];
  delete[] e->pp;
  delete e;

}

