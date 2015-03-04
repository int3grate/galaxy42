#ifndef PLAYER
#define PLAYER

#include "galaxy.h"
#include <vector>
#include <string>

class Player {
  
  public:
    std::string name;    
    Player();
    std::vector<Ship *> ships;

};

#endif
