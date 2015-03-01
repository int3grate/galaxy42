#include "wormhole.h"

Wormhole::Wormhole(int x, int y, SolarSystem *s) : CelestialObject(x,y,s)
{
  min_objects = 2;
  max_objects = 10;
  probability = .001;

  sister = NULL;
  type = SS_WORMHOLE;
}
