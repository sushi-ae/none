#pragma once

#include <xcb/xcb.h>
#include <xcb/xproto.h>

class WM {
public:
    static xcb_connection_t *dpy;
    static xcb_screen_t *scr;
    static xcb_window_t root;

    void init_conn(xcb_connection_t **c);
    void close_conn(xcb_connection_t *c);
};