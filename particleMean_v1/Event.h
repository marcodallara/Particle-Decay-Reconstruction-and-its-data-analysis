#ifndef Event_h
#define Event_h
#include "Particle.h"

struct Event{
  int ev_id;
  double x;
  double y;
  double z;
  int n_particle;
  Particle** pp;
};

#endif
