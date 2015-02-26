#ifndef CELESTIAL_OBJECT
#define CELESTIAL_OBJECT

#include <string>

class CelestialObject {

  protected:
    int x_parsec_loc, y_parsec_loc;
    int max_objects;
    int min_objects;
    double probability;
    std::string object_name;

  public:
    int * getCoords (void); 
    virtual std::string getObjectName(void);  
    int getMaxObjects(void);
    int getMinObjects(void);
    double getProbability(void);
    CelestialObject(int x, int y);
};

#endif
