#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    Display *dpy;
    Window win;
    int screen;
    int width, height;
    int x, y;
    int border_width;
    int depth;

    dpy = XOpenDisplay(NULL);
    if (dpy == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
    screen = DefaultScreen(dpy);
    width = DisplayWidth(dpy, screen);
    height = DisplayHeight(dpy, screen);
    x = 0;
    y = 0;
    border_width = 4;
    depth = DefaultDepth(dpy, screen);

    win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen), x, y, width, height, border_width, BlackPixel(dpy, screen), BlackPixel(dpy, screen));
    XSelectInput(dpy, win, ExposureMask | KeyPressMask | ButtonPressMask);
    XMapWindow(dpy, win);
    XFlush(dpy);
    while (1) {
        XEvent event;
        XNextEvent(dpy, &event);
        switch(event.type) {
            case Expose:
                break;
            case KeyPress:
                break;
            case ButtonPress:
                break;
        }
    }

    XCloseDisplay(dpy);
    return 0;
}
