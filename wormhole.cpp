#include "wormhole.h"

Wormhole::Wormhole(int x, int y) : CelestialObject(x, y)
{
  min_objects = 1;
  max_objects = 3;
  probability = .001;

  sister = NULL;
  type = SS_WORMHOLE;
}
