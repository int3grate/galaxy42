#include "stargate.h"

Stargate::Stargate(int x, int y, SolarSystem *s) : CelestialObject(x,y,s)
{
  min_objects = 1;
  max_objects = 1;
  probability = 0.001;
  type = SS_STARGATE;
}
