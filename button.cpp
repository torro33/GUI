#include "graphics.hpp"
#include "button.hpp"
#include "string"
using namespace genv;
using namespace std;

Button::Button(int x, int y, int sx, int sy,string s) : Widget(x,y,sx,sy),txt(s){
    selected = false;
}
void Button::draw(){
    if(selected){
        gout << move_to(x, y) << color(150,150,150) << box(sx, sy);
        gout << move_to(x+4, y+4) << color(100,100,100) << box(sx-8,sy-8);
    }else{
        gout << move_to(x, y) << color(255,255,255) << box(sx, sy);
        gout << move_to(x+4, y+4) << color(100,100,100) << box(sx-8,sy-8);
    }
    gout << move_to(x + sx / 2 - gout.twidth(txt) / 2, y + sy / 2 - gout.cascent() / 2 - gout.cdescent() / 2) << color (0,0,0) << text(txt);
}

void Button::eventhandler(event ev){
    if(ev.type == ev_mouse && isselected(ev.pos_x, ev.pos_y) && ev.button == btn_left){
        selected = true;
    }
    if(ev.button==-btn_left || !isselected(ev.pos_x, ev.pos_y)){
        selected = false;
    }
}

bool Button::Getselected(){
    return selected;
}

bool Button::Setselected(bool b){
    selected = b;
    return selected;
}
