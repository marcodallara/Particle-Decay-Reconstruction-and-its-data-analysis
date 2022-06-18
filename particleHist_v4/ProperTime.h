#ifndef ProperTime_h
#define ProperTime_h

#include "Event.h"

#include "util/include/Singleton.h"
#include "util/include/LazyObserver.h"



class ProperTime: public Singleton<ProperTime>,
                    public LazyObserver<Event> {

  friend class Singleton<ProperTime>;


 public:

  // particle types
  enum ParticleType { K0, Lambda0, unknown };

  // recompute informations for new event
  void update( const Event& ev ) override;
  
  // return particle type
  ParticleType get_particleType();
  // return particle energy
  double get_particleEnergy();
  // return particle mass
  double get_particleMass();
  // return time
  double get_decayTime();
  

 private:

  // private constructor and destructor for singleton
  ProperTime();
  // deleted copy constructor and assignment to prevent unadvertent copy
  ProperTime           ( const ProperTime& x ) = delete;
  ProperTime& operator=( const ProperTime& x ) = delete;

  // destructor
  ~ProperTime() override;

  // particle type
  ParticleType type;
  // particle energy
  double particleEnergy;
  // particle mass
  double particleMass;
  // time
  double time;

};

#endif

