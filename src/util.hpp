#pragma once

#include <iostream>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

namespace Util {
    void throwerr(const std::string err);
    void set_focus(xcb_connection_t *c,xcb_window_t win);
}

class WM {
public:
    static xcb_connection_t *dpy;
    static xcb_screen_t *scr;
    static xcb_window_t root;

    static xcb_generic_event_t *ev;

    void init_conn(xcb_connection_t **c);
    void close_conn(xcb_connection_t *c);
};

namespace Events {
    void handle_map_request(xcb_connection_t *c,xcb_generic_event_t *e);
}