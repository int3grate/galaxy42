#ifndef SHIP
#define SHIP

#include "galaxy.h"

class Ship : public CelestialObject {
    int x_pos;
    int y_pos;

  public:
    bool canMoveWarp(int new_x_pos, int new_y_pos);
    bool canMoveImpulse(int new_x_pos, int new_y_pos);

    bool moveWarp(int new_x_pos, int new_y_pos);
    bool moveImpulse(int new_x_pos, int new_y_pos);
 
    Ship(int x, int y, SolarSystem *s); 
};

#endif
