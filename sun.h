#ifndef SUN
#define SUN

#include "celestial_object.h"
#include <cstdlib>
#include <ctime>

class Sun : public CelestialObject {

  int mass;

  public:
    Sun (void);
    int getMass(void);
    
};

#endif
