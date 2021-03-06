#ifndef CELESTIAL_OBJECT
#define CELESTIAL_OBJECT

#include <string>

enum SS_OBJECTS {SS_SUN, SS_PLANET, SS_ASTEROID, SS_NEBULA, SS_STARGATE, SS_WORMHOLE};

class SolarSystem;

class CelestialObject {

  protected:
    int max_objects;
    int min_objects;
    double probability;
    std::string object_name;

  public:
    int x_parsec_loc, y_parsec_loc;
    int type;
    virtual std::string getObjectName(void);  
    int getMaxObjects(void);
    int getMinObjects(void);
    double getProbability(void);
    CelestialObject(int x, int y, SolarSystem * s);
    SolarSystem * solar_system;
};

#endif
