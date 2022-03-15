#include "graphics.hpp"
#include "selector.hpp"
#include "string"
#include <iostream>
using namespace genv;
using namespace std;

Selector::Selector(int x, int y, int sx, int sy,vector<string>options,int cell):Widget(x,y,sx,sy),options(options),cell(cell){
    active = "";
    fixrow = 0;
    selected = false;

}

void Selector::draw(){
//    if(btn->Getselected()){//megjelenik egy 2 opciós tábla
//        gout << move_to(x, y) << color(0,0,255) << box(sx,sy*3);
//        gout << move_to(x+10,y+sy*1+sy/3) << color(0,0,0) << text(options[fixrow]);
//        gout << move_to(x+10,y+sy*2+sy/3) << color(0,0,0) << text(options[fixrow+1]);
//    }else{
//        gout << move_to(x,y) << color(0,0,0) << box(sx,sy*3);
//        gout << move_to(x, y) << color(255,255,255) << box(sx, sy);
//        gout << move_to(x+4, y+4) << color(0,0,255) << box(sx-8,sy-8);
//    }
//    gout << move_to(x+10, y+15) << color (0,0,0) << text(active);

        gout << move_to(x, y) << color(100,100,100) << box(sx,sy*3);
//        for(int i = 0;i<cell;i++){
//            //if(options[fixrow+(i-1)] == active){gout << move_to(x+10,y+sy*i+sy/3) << color(255,255,255) << text(options[fixrow+(i-1)]);}else{}
//                //if()ha nincs annyi a vektorban akkor ""
//            gout << move_to(x+10,y+sy*i+sy/3) << color(0,0,0) << text(options[fixrow+i]);
//
//        }
//        gout << move_to(x+10,y+sy*1+sy/3) << color(0,0,0) << text(options[fixrow]);
//        gout << move_to(x+10,y+sy*2+sy/3) << color(0,0,0) << text(options[fixrow+1]);
if(options.size() >= 3){
        if(active != ""){
        if(activeindex == fixrow){
                gout << move_to(x+10,y+sy*0+sy/3) << color(255,255,255) << text(options[fixrow]);
        }else{
        gout << move_to(x+10,y+sy*0+sy/3) << color(0,0,0) << text(options[fixrow]);
        }
        if(activeindex == fixrow+1){
            gout << move_to(x+10,y+sy*1+sy/3) << color(255,255,255) << text(options[fixrow+1]);
        }else{
        gout << move_to(x+10,y+sy*1+sy/3) << color(0,0,0) << text(options[fixrow+1]);
        }
        if(activeindex == fixrow+2){
            gout << move_to(x+10,y+sy*2+sy/3) << color(255,255,255) << text(options[fixrow+2]);
        }else{
        gout << move_to(x+10,y+sy*2+sy/3) << color(0,0,0) << text(options[fixrow+2]);
        }
        }else{
        gout << move_to(x+10,y+sy*0+sy/3) << color(0,0,0) << text(options[fixrow]);
        gout << move_to(x+10,y+sy*1+sy/3) << color(0,0,0) << text(options[fixrow+1]);
        gout << move_to(x+10,y+sy*2+sy/3) << color(0,0,0) << text(options[fixrow+2]);
        }
}else{
    for(int i = 0;i<options.size();i++){
        if(active != ""){
            if(activeindex == fixrow+i){
                gout << move_to(x+10,y+sy*i+sy/3) << color(255,255,255) << text(options[fixrow+i]);
            }else{
                gout << move_to(x+10,y+sy*i+sy/3) << color(0,0,0) << text(options[fixrow+i]);
            }
        }else{
            gout << move_to(x+10,y+sy*i+sy/3) << color(0,0,0) << text(options[fixrow+i]);
        }
    }
}
}

void Selector::eventhandler(event ev)
{
    bool modifyList = false;
    int rowNumber = 0;

    //if(isselected(ev.pos_x, ev.pos_y)){
        if (ev.type == ev_key)
        {
            modifyList = true;
//            cout << ev.pos_x << "x"  << endl;
//            cout << ev.pos_y << endl;
        }
        if(modifyList == true){
            if(ev.keycode == key_up  && options.size() > 3)
                {
                    if(fixrow < options.size() - 3)
                    {
                        fixrow++;
                    }
                }
            else if(ev.keycode == key_down  && options.size() > 3)
                {
                    if(fixrow > 0)
                    {
                        fixrow--;
                    }
                }
        }
    //}

    if(isselected(ev.pos_x, ev.pos_y))//(ev.type == ev_mouse || ev.type == ev_key) &&
    {
        if(options.size() <= 3){fixrow = 0;}
        if (ev.type == ev_mouse)
        {
//            for(int i = 0;i<cell;i++){
//                if(x < ev.pos_x && ev.pos_x < x+sx && y+sy*i < ev.pos_y && ev.pos_y < y+sy*i){
//                    rowNumber = i;
//                    modifyList = true;
//                }
//            }
            if (x < ev.pos_x && ev.pos_x < x+sx && y+sy*0 < ev.pos_y && ev.pos_y < y+sy*1)
            {
                rowNumber = 0;
                modifyList = true;
            }
            if (x+10 < ev.pos_x && ev.pos_x < x+sx && y+10+sy*1 < ev.pos_y && ev.pos_y < y+sy*2)
            {
                rowNumber = 1;
                modifyList = true;
            }
            if (x+20 < ev.pos_x && ev.pos_x < x+sx && y+20+sy*2 < ev.pos_y && ev.pos_y < y+sy*3)
            {
                rowNumber = 2;
                modifyList = true;
            }
        }
        else if (ev.type == ev_key)
        {
            modifyList = true;
        }

        if (modifyList == true)
        {
            if(ev.button == btn_wheelup && options.size() > 3)
            {
                if(fixrow < options.size() - 3)
                {
                    fixrow++;
                }
            }
            else if(ev.button == btn_wheeldown && options.size() > 3)
            {
                if(fixrow > 0)
                {
                    fixrow--;
                }
            }
            else if (ev.button == btn_left)
            {
                if (rowNumber == 0 && options.size() >= 1)
                {
                    active = options[fixrow];
                    activeindex = fixrow;
                }
                else if(rowNumber == 1 && options.size() >= 2)
                {
                    active = options[fixrow + 1];
                    activeindex = fixrow+1;
                }
                else if(rowNumber == 2 && options.size() >= 3)
                {
                    active = options[fixrow + 2];
                    activeindex = fixrow+2;
                }
            }
        }
    }//if
}//eventhandler

bool Selector::isselected(int mousex,int mousey)
{
    return mousex > x && mousex < x+sx && mousey > y && mousey < y+sy*cell;
}

string Selector::Getactive(){
    return active;
}

void Selector::Setactive(string s){
    active = s;
}

void Selector::Setoptions(vector<string> s){
    options = s;
}
