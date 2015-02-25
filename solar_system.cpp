#include "solar_system.h"


SolarSystem::SolarSystem(int x, int y)
{
  // randomly select solar system type
  double r = ((double) std::rand() / (RAND_MAX));
  type =(int) (r * num_ss_types);

  x_pos = x;
  y_pos = y;
}

void SolarSystem::populateSolarSystem(void)
{


}

