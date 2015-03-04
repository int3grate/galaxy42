#ifndef ENGINE
#define ENGINE

#include "galaxy.h"
#include "player.h"
#include <vector>

class Engine {
  int turn;
  int cur_player;
  std::vector<Player *> players;  

  Galaxy * galaxy;

  public:
    SolarSystem * selected_solar_system;
   
    Engine(Galaxy * g);    

    void SelectSolarSystem(int x, int y); 
};

#endif
