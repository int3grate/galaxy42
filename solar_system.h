#ifndef SOLAR_SYSTEM
#define SOLAR_SYSTEM

#include <iostream>
#include <vector>
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

    static const int object_types = 1;
    static const int num_ss_types = 3;
    
    enum SS_OBJECTS {SS_SUN};

    int x_pos, y_pos;
    int x_au, y_au;

    void populateSolarSystem(void);
    std::vector<std::vector<CelestialObject *> > ss_map;

  public:
    int type;
    SolarSystem (int x, int y);
    void setSize(int x, int y); 
};

#endif
