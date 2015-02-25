#include "sun.h"

Sun::Sun(void)
{
  max_objects = 2;
  object_name = "sun";

  // generate random mass for sun
  std::srand(std::time(nullptr));
  mass = std::rand() % 10 + 1;
}

// returns mass, int 1-10
int Sun::getMass(void)
{
  return mass;
}
