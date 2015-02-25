#ifndef CELESTIAL_OBJECT
#define CELESTIAL_OBJECT

class CelestialObect {

  protected:
    SolarSystem * solarSystem;
    int x_parsec_loc, y_parsec_loc;

  public:
    int * getCoords (void); 
    SolarSystem * getSolarSystem (void);
  
    virtual std:string getObjectName(void);  


};

#endif
