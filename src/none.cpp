#include <iostream>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

#include "util.hpp"

int main(void){
    WM none;

    none.init_conn(&none.dpy);

    none.scr = xcb_setup_roots_iterator(xcb_get_setup(none.dpy)).data;
    none.root = none.scr->root;

    uint32_t vals[4];
    
    vals[0] = XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT;
    xcb_change_window_attributes_checked(none.dpy,none.root,XCB_CW_EVENT_MASK,vals);

    none.close_conn(none.dpy);
}