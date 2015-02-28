#include "planet.h"

Planet::Planet(int x, int y) : CelestialObject(x,y)
{
  min_objects = 5;
  max_objects = 30;
  probability = 0.006;
  type = SS_PLANET;
}
