#ifndef SHIP
#define SHIP

#include "galaxy.h"

#define DEFAULT_FUEL 3

struct engine_upgrades {
  int warp;
  int impulse;
};

struct weapons_upgrades {
  int laser;
  int kinetic_energy;
  int nuclear;
};

struct sensor_upgrades {
  int long_range;
  int short_range;
  int tactical;
  int navigation;
};

struct ship_upgrades {
  engine_upgrades engine;
  weapons_upgrades weapons;
  sensor_upgrades sensor;
};

class Ship : public CelestialObject {
    int x_pos;
    int y_pos;

    int fuel;
        
  public:
    ship_upgrades upgrades;

    bool canMoveWarp(int new_x_pos, int new_y_pos);
    bool canMoveImpulse(int new_x_pos, int new_y_pos);

    bool moveWarp(int new_x_pos, int new_y_pos);
    bool moveImpulse(int new_x_pos, int new_y_pos);

    void refuel(void);
 
    Ship(int x, int y, SolarSystem *s); 
};

#endif
