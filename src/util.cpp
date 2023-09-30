#include <iostream>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

#include "util.hpp"

// Util {
void Util::throwerr(const std::string err){
    std::cout << "\033[031merror:\033[037m" << err << std::endl;
    return;
}

void Util::set_focus(xcb_connection_t *c, xcb_window_t win){
    if (win)
        xcb_set_input_focus(c,XCB_INPUT_FOCUS_POINTER_ROOT,win,XCB_CURRENT_TIME);
    else Util::throwerr("window does not exist");
}
// }

// WM {
xcb_connection_t *WM::dpy;
xcb_screen_t *WM::scr;
xcb_window_t WM::root;

xcb_generic_event_t *WM::ev;

void WM::init_conn(xcb_connection_t **c){
    *c = xcb_connect(NULL,NULL);
    if (xcb_connection_has_error(*c)){
        Util::throwerr("unable to access display");
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

// Events {
void Events::handle_map_request(xcb_connection_t *c,xcb_generic_event_t *ev){
    xcb_map_request_event_t *e = (xcb_map_request_event_t *)ev;
    xcb_window_t win = e->window;

    uint32_t vals[1];
    vals[0] = XCB_EVENT_MASK_FOCUS_CHANGE | XCB_EVENT_MASK_ENTER_WINDOW;

    xcb_map_window(c,win);

    xcb_change_window_attributes_checked(c,win,XCB_CW_EVENT_MASK,vals);
    Util::set_focus(c,win);
}
// }