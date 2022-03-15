#include "graphics.hpp"
#include "scrollbutton.hpp"
#include "string"
#include <sstream>

Scrollbutton::Scrollbutton(int x, int y, int sx, int sy,int lowerinterval,int upperinterval):Widget(x,y,sx,sy),lowerinterval(lowerinterval),upperinterval(upperinterval){
    selected = false;
    setupscreen = true;
    score = 1;
}

void Scrollbutton::draw(){
    stringstream ss;
    if(selected){
        gout << move_to(x, y) << color(150,150,150) << box(sx, sy);//zöldgombkijelolvekeret
        gout << move_to(x+4, y+4) << color(100,100,100) << box(sx-8,sy-8);//kékgomb
    }else{
        gout << move_to(x, y) << color(255,255,255) << box(sx, sy);//fehérgombnincskijelolvekeret
        gout << move_to(x+4, y+4) << color(100,100,100) << box(sx-8,sy-8);//kékgomb
    }
    gout << move_to(x+sx/2-1,y) << color(255,255,255) << box(2,sy);//2 gomb közti választék
    //gout << move_to(x+5, y+5) << color (0,0,0) << text("<");
    gout << move_to(x + sx / 4 - gout.twidth("<") / 2, y + sy / 2 - gout.cascent() / 2 - gout.cdescent() / 2) << color (0,0,0) << text("<");
    //gout << move_to(x+5+sx/2, y+5) << color (0,0,0) << text(">");
    gout << move_to(x + sx*3 / 4 - gout.twidth(">") / 2, y + sy / 2 - gout.cascent() / 2 - gout.cdescent() / 2) << color (0,0,0) << text(">");
    gout << move_to(x,y) << color(100,100,100) << box(50,-33);
    ss << score;
    //gout << move_to(x+(sx-20)/2, y+(-sy-20)/2) << color (0,0,0) << text(ss.str());
    gout << move_to(x + sx / 2 - gout.twidth(ss.str()) / 2, y - sy / 2 - gout.cascent() / 2 - gout.cdescent() / 2) << color (0,0,0) << text(ss.str());
}

void Scrollbutton::eventhandler(event ev){
    if(ev.type == ev_mouse && isselected(ev.pos_x, ev.pos_y) && ev.button == btn_left){
        selected = true;
        if(x < ev.pos_x && ev.pos_x < x+sx/2 && y < ev.pos_y && ev.pos_y < y+sy){
            if(score != lowerinterval)score--;
        }
        if(x+sx/2 < ev.pos_x && ev.pos_x < x+sx && y < ev.pos_y && ev.pos_y < y+sy){
            if(score != upperinterval)score++;
        }
    }
    if(ev.button==-btn_left || !isselected(ev.pos_x, ev.pos_y)){
        selected = false;
    }
    if(ev.type == ev_key){
        if(ev.keycode == key_pgup || ev.keycode == key_up)
            if(score != upperinterval){score++;}
        if(ev.keycode == key_pgdn ||ev.keycode == key_down)
            if(score != lowerinterval){score--;}
    }
}

int Scrollbutton::Getscore(){return score;}
bool Scrollbutton::Getselected(){return selected;}
