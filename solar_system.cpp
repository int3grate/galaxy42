#include "solar_system.h"


SolarSystem::SolarSystem(int x, int y)
{
	// randomly select solar system type
  double r = ((double) std::rand() / (RAND_MAX));
  type =(int) (r * num_ss_types);

  x_pos = x;
  y_pos = y;

  setSize(40,40);

  populateSolarSystem();
}

void SolarSystem::setSize(int x, int y)
{
  x_au = x;
  y_au = y;
}

void SolarSystem::populateSolarSystem(void)
{
  // initialize empty map 
  for (int y=0; y<x_au; y++)
  {
    std::vector<CelestialObject *> v_tmp;
    for (int x=0; x<x_au; x++)
      v_tmp.push_back(NULL);
    ss_map.push_back(v_tmp);
  }

  for (int i=0; i<object_types; i++)
  {
    CelestialObject * celestial_object;

    if(i == SS_SUN)
    {
      Sun sun(0,0);
      celestial_object = &sun;
    // TBD - more objects here
    }

    int max_objects = celestial_object->getMaxObjects();
    int min_objects = celestial_object->getMinObjects();

    double prob = celestial_object->getProbability(); 

    int num_objects = 0;

    while(num_objects < min_objects)
    {
      for (int y=0; y<y_au; y++)
      {
        for (int x=0; x<x_au; x++)
        {
          if(ss_map[x][y] != NULL) continue;

          double r = ((double) std::rand() / (RAND_MAX));
          if(r < prob)
          {
            if(i == SS_SUN)
              ss_map[x][y] = new Sun(x, y);
            // TBD - more objects here
            num_objects++;
            if(num_objects > max_objects) break;
          }
        }
        if(num_objects > max_objects) break;
      }
      if(num_objects > max_objects) break;
    }
  }
}

