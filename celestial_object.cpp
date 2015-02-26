#include "celestial_object.h"

CelestialObject::CelestialObject(int x, int y)
{
  x_parsec_loc = x;
  y_parsec_loc = y;
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
