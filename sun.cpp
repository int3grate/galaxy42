#include "sun.h"

Sun::Sun(int x, int y) : CelestialObject(x, y)
{
  min_objects = 1;
  max_objects = 2;
  object_name = "SUN";
  probability = .001;

  type = SS_SUN;
  
  // generate random mass for sun
  mass = std::rand() % 10 + 1;
}

// returns mass, int 1-10
int Sun::getMass(void)
{
  return mass;
}
