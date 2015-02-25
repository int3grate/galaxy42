#ifndef CELESTIAL_OBJECT
#define CELESTIAL_OBJECT

#include <string>

class CelestialObject {

  protected:
    int x_parsec_loc, y_parsec_loc;
    int max_objects;
    std::string object_name;

  public:
    int * getCoords (void); 
    virtual std::string getObjectName(void);  
    int getMaxObjects(void);
};

#endif
