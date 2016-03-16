/*
Project: Ocean
Author:  DEISS Olivier
License: This software is offered under the GPL license. See COPYING for more information.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Graphic/Window.hpp"
#include "Ocean/Ocean.hpp"

/* Ocean(lx, ly, nx, ny, windSpeed,  windAlignment, minWaveSize, A) */
Ocean* ocean;

/* handle for the window */
int mainwindow;

int main (int argc, char** argv) {

    /* random for gaussian numbers */
    srand(time(NULL));
    
    /* ocean parameters */
    const double lx             = 170;
    const double ly             = 350;
    const int    nx             = 64;
    const int    ny             = 128;
    const double wind_speed     = 50;
    const int    wind_alignment = 2;
    const double min_wave_size  = 0;
    const double A              = 0.000003;
    
    /* spectrum and ocean */
    Philipps philipps(lx, ly, nx, ny, wind_speed, wind_alignment, min_wave_size, A);  /* Philipps spectrum */
    Height   height(nx, ny);                                                          /* initial wave height field */
    ocean = new Ocean(lx, ly, nx, ny);
    
    height.generate_philipps(&philipps); /* Philipps spectrum */
    ocean->generate_height(&height);     /* initial ocean wave height field */
    
    /* rendering */
    Window::init(WIDTH, HEIGHT, "FFTOcean", argc, argv);
    Window::setFPS(35);
    Window::launch();
    
    /* free */
    Window::quit();
    delete ocean;
    
    return 0;
    
}
