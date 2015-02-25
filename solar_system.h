#ifndef SOLAR_SYSTEM
#define SOLAR_SYSTEM

#include <iostream>
#include "celestial_object.h"

// Randomly created during map generation
#include "sun.h"
/*
#include "nebula.h"
#include "planet.h"
#include "asteroid.h"
#include "wormhole.h"
*/

/*
// Player created
#include "drone.h"
#include "ship.h"
*/

class SolarSystem {

    enum SPACE_OBJECTS {SUN};
    static const int object_types = 1;
    static const int num_ss_types = 3;

    int x_pos, y_pos;

    void populateSolarSystem(void);

  public:
    int type;
    SolarSystem (int x, int y);

};

#endif
