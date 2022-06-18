#include <iostream>
#include <fstream>
using namespace std;

#include "Event.h"

void dump(const Event& e){
  cout<< e.get_ev_id() << ' ' << endl;
  cout<< e.get_x() << ' ' << e.get_y() << ' ' << e.get_z() << endl;
  cout<< e.get_n_particle() << endl;
  for(int i=0;i<e.get_n_particle();i++)
    cout<<e.get_particle(i)->charge << ' ' << e.get_particle(i)->p_x << ' ' << e.get_particle(i)->p_y << ' ' << e.get_particle(i)->p_z << endl;
}
							      
  
  
