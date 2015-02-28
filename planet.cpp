#include "planet.h"

Planet::Planet(int x, int y) : CelestialObject(x,y)
{
  min_objects = 1;
  probability = .05;
  type = SS_PLANET;
}
