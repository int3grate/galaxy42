#ifndef GALAXY
#define GALAXY

#include <vector>
#include <string>
#include <iostream>
#include <random>
#include "solar_system.h"

#define SS_EXISTS_PROB .03

class Galaxy {
    std::vector<std::vector<SolarSystem *> > galaxy_map;
    int x_parsecs, y_parsecs;
    static const int x_default_width = 20;
    static const int y_default_width = 20;
 
    void setupNewGame (void);

    enum SS_TYPES {TYPE_SPARSE, TYPE_NORMAL, TYPE_DENSE};

  public:
    Galaxy (int x_parsecs, int y_parsecs); 
    Galaxy (void);

    void DebugPrintGalaxy(void);
};

#endif
