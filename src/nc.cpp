#include <cstdlib>
#include <iostream>
#include <string.h>

#include "util.hpp"

int main(int argc,char *argv[]){
    WM nc;

    nc.init_conn(&nc.dpy);

    nc.scr = xcb_setup_roots_iterator(xcb_get_setup(nc.dpy)).data;
    nc.root = nc.scr->root;
    
    switch(argc){
        case 1:
            util::annoy(error,"no command specified");
            nc.close_conn(nc.dpy);
            std::exit(1);
        case 2:
            break;
    }

    if (strncmp(argv[1],"mv",2)==0){
        if (!(argv[2] && argv[3])){
            util::annoy(error,"invalid args");
            nc.close_conn(nc.dpy);
            std::exit(1);
        }

        if (!argv[4]){
            util::annoy(error,"invalid args");
            nc.close_conn(nc.dpy);
            std::exit(1);
        }

        unsigned int newX = atoi(argv[2]);
        unsigned int newY = atoi(argv[3]);

        util::move_window(nc.dpy,strtoul(argv[4],NULL,16),newX,newY);
    }

    if (strncmp(argv[1],"fc",2)==0){
        if (!argv[2]){
            util::annoy(error,"invalid args");
            nc.close_conn(nc.dpy);
            std::exit(1);
        }

        util::set_focus(nc.dpy,strtoul(argv[2],NULL,16));
    }

    nc.close_conn(nc.dpy);
}
