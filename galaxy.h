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

#define SS_EXISTS_PROB .03

class SolarSystem;

class Galaxy {
    std::vector<std::vector<SolarSystem *> > galaxy_map;
    int x_parsecs, y_parsecs;

    static const int x_default_width = 15;
    static const int y_default_width = 15;
 
    void setupNewGame (void);

    enum SS_TYPES {TYPE_SPARSE, TYPE_NORMAL, TYPE_DENSE};

    void configureWormholes(void);

  public:
    std::vector<Wormhole *> wormholes;
    Galaxy (int x_parsecs, int y_parsecs); 
    Galaxy (void);

    void DebugPrintGalaxy(void);
};

class SolarSystem {

    static const int debug_mode = 1;

    static const int object_types = 6;
    static const int num_ss_types = 3;

    static const int x_default_width = 20;
    static const int y_default_width = 20;
    
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
