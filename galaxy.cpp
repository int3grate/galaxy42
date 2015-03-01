#include "galaxy.h"

// constructors
Galaxy::Galaxy()
{
  x_parsecs = x_default_width;
  y_parsecs = y_default_width;

  setupNewGame(); 
}

Galaxy::Galaxy(int x_size, int y_size)
{
  x_parsecs = x_size;
  y_parsecs = y_size;
  setupNewGame();
}

// create a new game map
void Galaxy::setupNewGame()
{
  std::default_random_engine generator;
  generator.seed(time(0));
  std::uniform_real_distribution<double> distribution(0.0,1.0);
  double r;

  for (int x=0; x<x_parsecs; x++)
  {
    std::vector<SolarSystem *> v_tmp;
    for (int y=0; y<y_parsecs; y++)
    {
      r = distribution(generator);
      if(r < SS_EXISTS_PROB)
        v_tmp.push_back(new SolarSystem(x, y, this));
      else
        v_tmp.push_back(NULL);
    }
    galaxy_map.push_back(v_tmp);
  }
  configureWormholes(); 
}

// print out map of galaxy for debugging
void Galaxy::DebugPrintGalaxy(void)
{
  std::cout << "Debug Galaxy Map : " << std::endl;
  for(int y=0; y<y_parsecs; y++)
  {
    for(int x=0; x<x_parsecs; x++)
    {
      if(galaxy_map[x][y] == NULL)
        std::cout << '.';
      else
      {
        if(galaxy_map[x][y]->type == TYPE_SPARSE)
          std::cout << 'S';
        else if(galaxy_map[x][y]->type == TYPE_NORMAL)
          std::cout << 'N'; 
        else if(galaxy_map[x][y]->type == TYPE_DENSE) 
          std::cout << 'D';
        else
          std::cout << "[ERROR]";
      }
    }
    std::cout << std::endl;
  } 
}

// TBD
void Galaxy::configureWormholes(void)
{
  Wormhole * wh;
  
  // make even number of wormholes
  if(wormholes.size() % 2 != 0)
  {
    // delete one wormhole to get an even number
    wh = wormholes.back();
    wormholes.pop_back();
    int x_coord = wh->solar_system->x_pos;
    int y_coord = wh->solar_system->y_pos;
    
    wh->solar_system->ss_map[x_coord][y_coord] = NULL;
    delete wh;
  }

  // randomly shuffle wormholes 
  std::random_device rd;
  std::mt19937 generator(rd());
  std::shuffle(wormholes.begin(), wormholes.end(), generator); 

  // select two at a time and link them
  for (int i=0; i<wormholes.size(); i+=2)
  {
    wormholes[i]->sister = wormholes[i+1];
    wormholes[i+1]->sister = wormholes[i];
  }
}
