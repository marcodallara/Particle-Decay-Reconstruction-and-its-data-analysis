#include <string>
#include <fstream>
#include <iostream>

#include "AnalysisFramework/EventReadFromFile.h"

using namespace std;

//read data from file "name"
EventReadFromFile::EventReadFromFile(const string& name){
  file= new ifstream(name );
}

EventReadFromFile::~EventReadFromFile() {
  delete file;
}

//return an event
const Event* EventReadFromFile::readFile(){
  Event* e;
  double evid;
  //if read the first then allocate and copy the event
  if( *file>>evid ) {
    
    double x;
    *file>>x;
    double y;
    *file>>y;
    double z;
    *file>>z;
    e=new Event(evid, x , y , z);
  } 
  else return nullptr;  // on failure return null pointer

  int np; // number of particles to control;
  *file>>np;
  int charge;
  double p_x, p_y, p_z;
  for(int i=0;i<np;i++){   //set particle's data
    
    *file>> charge;
    *file>> p_x;
    *file>> p_y;
    *file>> p_z;
    e->add(charge, p_x, p_y, p_z);
  }

  return e;
}


//get an event
const Event* EventReadFromFile::get(){
  return EventReadFromFile::readFile();
}

