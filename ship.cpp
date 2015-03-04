#include "ship.h"

Ship::Ship(int x, int y, SolarSystem *s) : CelestialObject(x, y, s)
{
  refuel();
}


void Ship::refuel(void)
{
  fuel = DEFAULT_FUEL;
}
