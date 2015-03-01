#include "asteroid.h"

Asteroid::Asteroid(int x, int y, SolarSystem *s) : CelestialObject(x,y,s)
{
  min_objects = 5;
  max_objects = 40;
  probability = 0.008;
  type = SS_ASTEROID;
}
