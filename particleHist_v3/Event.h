#ifndef Event_h
#define Event_h

#include <vector>
#include <memory>



class Event {

 public:

  Event( int n, float x, float y, float z ); // create an event with number "n"
                                             // and coordinates x, y, z
  ~Event();

  // composite object Particle to hold all information for each particle
  // ( electric charge and x,y,z momentum components )
  struct Particle {
    int charge;
    double p_x;
    double p_y;
    double p_z;
  };
  typedef const Particle* part_ptr;

  // add a particle to the event
  void add( int charge, float px, float py, float pz );

  // get event id.
  int get_ev_id() const;
  // get decay point coordinates
  double  get_x() const;
  double  get_y() const;
  double  get_z() const;
  // get number of particles
  int get_n_particle() const;
  // get particle
  part_ptr get_particle( unsigned int i ) const;

 private:

  // event-specific informations:
   int ev_id;
   double x;
   double y;
   double z;
   std::vector <const Particle* > pp;

};

#endif

