#include "graphics.hpp"
#include "scrollbutton.hpp"
#include "window.hpp"
#include "textbox.hpp"
#include "selector.hpp"
using namespace genv;


int main()
{
    Window * win = new Window(700,700);
    Scrollbutton * scb = new Scrollbutton(250,80,50,35,1,20);
    win->widgetpush(scb);
    Textbox * tb = new Textbox(10,50,200,30,"elem");
    win->widgetpush(tb);
    Selector * sr = new Selector(10,200,100,50,win->Getvs(),3);
    win->widgetpush(sr);
    Scrollbutton * scb2 = new Scrollbutton(250,250,50,35,0,20);
    win->widgetpush(scb2);
    Scrollbutton * scb3 = new Scrollbutton(250,330,50,35,0,20);
    win->widgetpush(scb3);
    win->event_loop();
    return 0;
}


