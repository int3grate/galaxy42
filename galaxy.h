#ifndef GALAXY
#define GALAXY

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "solar_system.h"

#define SS_EXISTS_PROB .03

class Galaxy {
    std::vector<std::vector<SolarSystem *> > galaxy_map;
    int x_parsecs, y_parsecs;
 
    void setupNewGame (void);

    static const int TYPE_SPARSE = 0;
    static const int TYPE_NORMAL = 1;
    static const int TYPE_DENSE = 2;

//    static double SS_EXISTS_PROB () { return .03; } 

  public:
    Galaxy (int x_parsecs, int y_parsecs); 
    Galaxy (void);

    void DebugPrintGalaxy(void);
};

#endif
