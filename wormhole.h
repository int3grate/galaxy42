#ifndef WORMHOLE
#define WORMHOLE

#include "celestial_object.h"

class Wormhole : public CelestialObject {

  public:
    Wormhole(int x, int y);
    Wormhole * sister;

};

#endif
