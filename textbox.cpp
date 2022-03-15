#include "textbox.hpp"
#include "graphics.hpp"
#include "string"
using namespace genv;

Textbox::Textbox(int x, int y, int sx, int sy, std::string b)
    : Widget(x,y,sx,sy), txt(b)
{
    checked=false;
    txt = b;
}

void Textbox::draw()
{
    gout << color(255,255,255) << move_to(10, 10) << text("elem neve");
     gout << color(255,255,255) << move_to(250, 10) << text("prioritas");
    gout << color(100,100,100) << move_to(x, y) << box(sx, sy);
//    gout << color(0,0,0) << move_to(x+2, y+2) << box(sx-4, sy-4);
//    gout << move_to(x+2, y+14) << color(0,0,0) << text(txt);
    gout << move_to(x, y + sy / 2 - gout.cascent() / 2 - gout.cdescent() / 2) << color(0,0,0) << text(txt);
}
void Textbox::eventhandler(event ev){
        if (ev.keycode>0 and ev.keycode<256 and (ev.keycode != key_backspace)){
            txt += ev.keycode;
        }else if((ev.keycode == key_backspace) && (txt.size() != 0)){
            txt.pop_back();
        }
}

string Textbox::Gettxt(){
    return txt;
}

void Textbox::Settxt(string s){
    txt = s;
}
