#include "nebula.h"

Nebula::Nebula(int x, int y, SolarSystem *s) : CelestialObject(x,y,s)
{
  min_objects = 5;
  max_objects = 40;
  probability = 0.007;
  type = SS_NEBULA;
}
