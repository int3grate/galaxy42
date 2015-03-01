#include "planet.h"

Planet::Planet(int x, int y, SolarSystem *s) : CelestialObject(x,y,s)
{
  min_objects = 5;
  max_objects = 30;
  probability = 0.006;
  type = SS_PLANET;
}
