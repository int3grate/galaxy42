#include "galaxy.h"
#include "ncurses_interface.h"
#include <csignal>
#include <iostream>
int do_quit = 0;
void quit(int param)
{
  do_quit = 1;
}

int main()
{
  Galaxy x;

  NcursesInterface interface(&x);
  signal(SIGINT, quit);

  while(1)
  {
    if(do_quit) interface.quit();
  }
}
