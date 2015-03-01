#ifndef SOLAR_SYSTEM
#define SOLAR_SYSTEM

#include <iostream>
#include <vector>
#include <random>
#include "celestial_object.h"

// Randomly created during map generation
#include "sun.h"
#include "planet.h"
#include "asteroid.h"
#include "nebula.h"
#include "stargate.h"
#include "wormhole.h"

/*
// Player created
#include "drone.h"
#include "ship.h"
*/
class Galaxy;

class SolarSystem {

    static const int debug_mode = 1;

    static const int object_types = 6;
    static const int num_ss_types = 3;

    static const int x_default_width = 20;
    static const int y_default_width = 20;
    
    int x_pos, y_pos;
    int x_au, y_au;

    void populateSolarSystem(void);
    std::vector<std::vector<CelestialObject *> > ss_map;

    Stargate * stargate;
    Galaxy * galaxy;

  public:
    int type;
    SolarSystem (int x, int y, Galaxy * g);
    void setSize(int x, int y); 
    void DebugPrintSolarSystem(void);
};

#endif
