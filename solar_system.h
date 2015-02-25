#ifndef SOLAR_SYSTEM
#define SOLAR_SYSTEM

#include <iostream>
#include "celestial_object.h"
#include "sun.h"
/*
#include "nebula.h"
#include "drone.h"
#include "ship.h"
#include "planet.h"
#include "asteroid.h"
#include "wormhole.h"
*/

class SolarSystem {

  enum SPACE_OBJECTS {SUN};

  static const int num_types = 3;

  int x_pos, y_pos;

  public:
    int type;
    SolarSystem (int x, int y); 

};

#endif
