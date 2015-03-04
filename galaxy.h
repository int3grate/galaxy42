#ifndef GALAXY
#define GALAXY

#include <vector>
#include <string>
#include <iostream>
#include <random>

#include "celestial_object.h"

// Randomly created during map generation
#include "wormhole.h"
#include "sun.h"
#include "planet.h"
#include "asteroid.h"
#include "nebula.h"
#include "stargate.h"
#include "wormhole.h"

#include "ship.h"

#define SS_EXISTS_PROB .03

class SolarSystem;

class Galaxy {

    static const int x_galaxy_width = 15;
    static const int y_galaxy_width = 15;

    void setupNewGame (void);

    enum SS_TYPES {TYPE_SPARSE, TYPE_NORMAL, TYPE_DENSE};

    void configureWormholes(void);

  public:
    std::vector<std::vector<SolarSystem *> > galaxy_map;

    static const int x_ss_width = 20;
    static const int y_ss_width = 20;

    int x_parsecs, y_parsecs;
    int x_ss_au, y_ss_au;
    std::vector<Wormhole *> wormholes;
    Galaxy (int x_parsecs, int y_parsecs); 
    Galaxy (void);

    void DebugPrintGalaxy(void);
};

class SolarSystem {
    static const int debug_mode = 0;

    static const int object_types = 6;
    static const int num_ss_types = 3;
 
    int x_au, y_au;

    void populateSolarSystem(void);

    Stargate * stargate;
    Galaxy * galaxy;

  public:

    std::vector<std::vector<CelestialObject *> > ss_map;
    int x_pos, y_pos;
    int type;
    SolarSystem (int x, int y, Galaxy * g);
    void setSize(int x, int y); 
    void DebugPrintSolarSystem(void);
};

#endif
