#include "solar_system.h"

SolarSystem::SolarSystem(void)
{
  // randomly select solar system type
  double r = ((double) std::rand() / (RAND_MAX));
  type =(int) (r * num_types); 
}
