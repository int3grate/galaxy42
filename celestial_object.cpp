#include "celestial_object.h"

CelestialObject::CelestialObject(int x, int y, SolarSystem *s)
{
  x_parsec_loc = x;
  y_parsec_loc = y;
  solar_system = s;
}

int CelestialObject::getMaxObjects(void)
{
  return max_objects;
}

int CelestialObject::getMinObjects(void)
{
  return min_objects;
}

double CelestialObject::getProbability(void)
{
  return probability;
}
 
std::string CelestialObject::getObjectName(void)
{
  return object_name;
}
