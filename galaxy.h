#ifndef GALAXY
#define GALAXY

#include <vector>

class Galaxy {

    std::vector<vector<SolarSystem>> galaxy_map;
    int x_parsecs, y_parsecs;

    void setupNewGame (void);
 
  public:
    Galaxy (int x_parsecs = 30, int y_parsecs = 30); 
};

#endif
