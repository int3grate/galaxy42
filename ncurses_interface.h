#ifndef NCURSES_INTERFACE
#define NCURSES_INTERFACE

#include "galaxy.h"
#include <ncurses.h>

class NcursesInterface {
    void initialize(void);

    int max_x, max_y;

    int ss_x_off;
    int ss_y_off;

    int galaxy_x_off;
    int galaxy_y_off;

    int menu_x_off;
    int menu_y_off;

    WINDOW * ss_win;
    WINDOW * galaxy_win;
    WINDOW * menu_win;

    Galaxy * galaxy;

  public:
    NcursesInterface(Galaxy *g);
    void refresh(void);
    void createWindows(void);
    void quit(void);
    // Todo - add resize handler

};

#endif
