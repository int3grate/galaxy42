#include "wormhole.h"

Wormhole::Wormhole(int x, int y) : CelestialObject(x, y)
{
  min_objects = 2;
  max_objects = 10;
  probability = .001;

  sister = NULL;
  type = SS_WORMHOLE;
}
