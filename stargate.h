#ifndef STARGATE
#define STARGATE

#include "celestial_object.h"

class Stargate : public CelestialObject  {

  public:
    Stargate(int x, int y, SolarSystem *s);
};

#endif
