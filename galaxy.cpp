#include "galaxy.h"


// constructors
Galaxy::Galaxy()
{
  x_parsecs = 30;
  y_parsecs = 30;
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
  std::srand(std::time(nullptr));
  for (int x=0; x<x_parsecs; x++)
  {
    std::vector<SolarSystem *> v_tmp;
    for (int y=0; y<y_parsecs; y++)
    {
      SolarSystem * s_tmp;
      double r = ((double) std::rand() / (RAND_MAX));
      if(r < SS_EXISTS_PROB)
        v_tmp.push_back(new SolarSystem);
      else
        v_tmp.push_back(NULL);

    }
    galaxy_map.push_back(v_tmp);
  }
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
        //std::cout << galaxy_map[x][y]->type << std::endl;
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
