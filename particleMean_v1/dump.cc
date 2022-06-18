#include <iostream>
#include <fstream>
using namespace std;

#include "Event.h"
#include "Particle.h"

void dump(const Event& e){
  cout<< e.ev_id << ' ' << endl;
  cout<< e. x << ' ' << e.y << ' ' << e.z << endl;
  cout<< e.n_particle << endl;
  for(int i=0;i<e.n_particle;i++)
    cout<<e.pp[i]->charge << ' ' << e.pp[i]->p_x << ' ' << e.pp[i]->p_y << ' ' << e.pp[i]->p_z << endl;
}
							      
  
  
