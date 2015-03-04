#include "ncurses_interface.h"

NcursesInterface::NcursesInterface(Galaxy * g)
{
  galaxy = g;
  initialize();
}

void NcursesInterface::quit(void)
{
  std::cout << "Caught Ctrl+C, exiting..." << std::endl;
  endwin();
  exit(0);
}

void NcursesInterface::initialize(void)
{
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  getmaxyx(stdscr, max_y, max_x); 

  createWindows();
  
  refresh();
}

void NcursesInterface::createWindows(void)
{
  int total_width = 0;
  int total_height = 0;
  int a_x, b_x, a_y, b_y;

  int a_y_t, a_x_t;

  a_x = galaxy->x_parsecs;
  a_y = galaxy->y_parsecs;

  b_x = galaxy->x_ss_au;
  b_y = galaxy->y_ss_au;
 
  total_width += a_x;
  total_height += a_y;

  if(total_width > max_x || total_height > max_y)
  {
  // tell user to resize window here
  }
  else
  {
    galaxy_win = newwin(a_y, a_x, 0, 0);
    wborder(galaxy_win, '|', '|', '-', '-', '+', '+', '+', '+');
  
    ss_win = newwin(b_y, b_x, 0, a_x + 1);
    wborder(ss_win, '|', '|', '-', '-', '+', '+', '+', '+');
  }
}

void NcursesInterface::refresh(void)
{
  wrefresh(galaxy_win);
  wrefresh(ss_win);
  //wrefresh(menu_win);
}
