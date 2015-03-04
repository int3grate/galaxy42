#include "engine.h"

Engine::Engine(Galaxy * g){
  galaxy = g;
}

void Engine::SelectSolarSystem(int x, int y)
{
  selected_solar_system = galaxy->galaxy_map[x][y];
}

