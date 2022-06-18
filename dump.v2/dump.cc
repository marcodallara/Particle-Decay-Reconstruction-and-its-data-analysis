#include <iostream>
#include <fstream>
using namespace std;

#include "Event.h"
#include "Particle.h"

void dump(const Event& e){
  //dump event number, coordinates
  cout<< e.ev_id << ' ' << endl;
  cout<< e. x << ' ' << e.y << ' ' << e.z << endl;
  //dump data of each particle
  cout<< e.n_particle << endl;
  for(int i=0;i<e.n_particle;i++)
    cout<<e.p[i]->charge << ' ' << e.p[i]->p_x << ' ' << e.p[i]->p_y << ' ' << e.p[i]->p_z << endl;
}
							      
  
  
