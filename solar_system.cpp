#include "galaxy.h"

SolarSystem::SolarSystem(int x, int y, Galaxy * g)
{
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(0,num_ss_types-1);

  type = distribution(generator);
  x_pos = x;
  y_pos = y;
  galaxy = g;

  setSize(galaxy->x_ss_width, galaxy->y_ss_width);

  populateSolarSystem();

  if(debug_mode) DebugPrintSolarSystem();
}

void SolarSystem::setSize(int x, int y)
{
  x_au = x;
  y_au = y;
}

void SolarSystem::populateSolarSystem(void)
{
  std::default_random_engine generator;
  generator.seed(time(0));
  std::uniform_real_distribution<double> distribution(0.0,1.0);

  // initialize empty map 
  for (int x=0; x<x_au; x++)
  {
    std::vector<CelestialObject *> v_tmp;
    for (int y=0; y<y_au; y++)
      v_tmp.push_back(NULL);
    ss_map.push_back(v_tmp);
  }

  for (int i=0; i<object_types; i++)
  {
    CelestialObject * celestial_object;

    if(i == SS_SUN)
    {
      Sun sun(0,0,this);
      celestial_object = &sun;
    }
    else if(i == SS_PLANET)
    {
      Planet planet(0,0,this);
      celestial_object = &planet;
    }
    else if(i == SS_ASTEROID)
    {
      Asteroid asteroid(0,0,this);
      celestial_object = &asteroid;
    }
    else if(i == SS_NEBULA)
    {
      Nebula nebula(0,0,this);
      celestial_object = &nebula;
    }
    else if(i == SS_STARGATE)
    {
      Stargate stargate(0,0,this);
      celestial_object = &stargate;
    }
    else if(i == SS_WORMHOLE)
    {
      Wormhole wormhole(0,0,this);
      celestial_object = &wormhole;
    }
    int max_objects = celestial_object->getMaxObjects();
    int min_objects = celestial_object->getMinObjects();

    double prob = celestial_object->getProbability(); 
    int num_objects = 0;

    double r;

    while(num_objects < min_objects)
    {
     // density loop
     for (int j=0; j<=type; j++)
      {
        for (int x=0; x<x_au; x++)
        {
          for (int y=0; y<y_au; y++)
          {
            if(ss_map[x][y] != NULL) continue;

            r = distribution(generator);
            if(r < prob)
            {
              if(i == SS_SUN)
                ss_map[x][y] = new Sun(x, y, this);
              else if(i == SS_PLANET)
                ss_map[x][y] = new Planet(x, y, this);
              else if(i == SS_ASTEROID)
                ss_map[x][y] = new Asteroid(x, y, this);
              else if(i == SS_NEBULA)
                ss_map[x][y] = new Nebula(x, y, this);
              else if(i == SS_WORMHOLE)
              {
                ss_map[x][y] = new Wormhole(x, y, this);
                galaxy->wormholes.push_back((Wormhole *)ss_map[x][y]);
              }
              else if(i == SS_STARGATE)
              {
                ss_map[x][y] = new Stargate(x, y, this);
                stargate = (Stargate *) ss_map[x][y];
              }
              num_objects++;
              if(num_objects >= max_objects) break;
            }
          }
          if(num_objects >= max_objects) break;
        }
        if(num_objects >= max_objects) break;
      }
      if(num_objects >= max_objects) break;
    }
  }
}

void SolarSystem::DebugPrintSolarSystem(void)
{
  std::cout << "Debug Solar System Map (" <<
  x_pos << "," << y_pos <<
  ") Density : " << type << std::endl;

  for(int y=0; y<y_au; y++)
  {
    for(int x=0; x<x_au; x++)
    {
      if(ss_map[x][y] == NULL)
        std::cout << '.';
      else
      {
        if(ss_map[x][y]->type == SS_SUN)
          std::cout << '*';
        else if(ss_map[x][y]->type == SS_PLANET)
          std::cout << '@';
        else if(ss_map[x][y]->type == SS_ASTEROID)
          std::cout << '~';
        else if(ss_map[x][y]->type == SS_NEBULA)
          std::cout << '#';
        else if(ss_map[x][y]->type == SS_STARGATE)
          std::cout << "%";  
        else if(ss_map[x][y]->type == SS_WORMHOLE)
          std::cout << "&";  
      else
          std::cout << "[ERROR]";
      }
    }
    std::cout << std::endl;
  } 
  std::cout << std::endl;
}
