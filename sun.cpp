#include "sun.h"

Sun::Sun(int x, int y, SolarSystem *s) : CelestialObject(x, y,s)
{
  min_objects = 1;
  max_objects = 2;
  object_name = "SUN";
  probability = .001;

  type = SS_SUN;
  
  // generate random mass for sun
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(0,10);
  mass = distribution(generator);
}

// returns mass, int 1-10
int Sun::getMass(void)
{
  return mass;
}
