#ifndef SUN
#define SUN

#include "celestial_object.h"
#include <random>

class Sun : public CelestialObject {

  int mass;

  public:
    Sun (int x, int y, SolarSystem *s);
    int getMass(void);
    
};

#endif
