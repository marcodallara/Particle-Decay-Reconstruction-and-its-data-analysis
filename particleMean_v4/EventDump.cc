#include "EventDump.h"
#include "Event.h"

#include <iostream>

#include "Event.h"

using namespace std;

EventDump::EventDump() {
}


EventDump::~EventDump() {
}


// function to be called at execution start
void EventDump::beginJob() {
  return;
}


// function to be called at execution end
void EventDump::endJob() {
  return;
}


// function to be called for each event
void EventDump::process( const Event& ev ) {
  cout<< ev.get_ev_id() << ' ' << endl;
  cout<< ev.get_x() << ' ' << ev.get_y() << ' ' << ev.get_z() << endl;
  cout<< ev.get_n_particle() << endl;
  for(int i=0;i<ev.get_n_particle();i++)
    cout<<ev.get_particle(i)->charge << ' ' << ev.get_particle(i)->p_x << ' ' << ev.get_particle(i)->p_y << ' ' << ev.get_particle(i)->p_z << endl;

}

