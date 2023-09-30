#include <iostream>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

#include "util.hpp"

// WM {
xcb_connection_t *WM::dpy;
xcb_screen_t *WM::scr;
xcb_window_t WM::root;

void WM::init_conn(xcb_connection_t **c){
    *c = xcb_connect(NULL,NULL);
    if (xcb_connection_has_error(*c)){
        std::cout << "unable to access display\n";
        std::exit(1);
    }
}

void WM::close_conn(xcb_connection_t *c){
    if (c != NULL){
        xcb_disconnect(c);
        std::exit(1);
    }
    std::exit(0);
}
// }