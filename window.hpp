#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "button.hpp"
#include <vector>
#include "string"
#include <sstream>
using namespace std;
using namespace genv;

struct Item{
public:
    string name;
    int value;
    int createdvalue;
};

class Window{
protected:
    vector <Widget*> widgets;
    vector <Item> itemvs;
    vector <string> vs;
//    vector <string> vs;// = {"A:0::B:0"};//= {"A:0::B:0", "A:0::B:1","A:0::B:2","A:0::B:3","A:0::B:4","A:0::B:5","A:0::B:6"};
//    vector <string> vsoriginal;
//    vector <int> vsnumber;
//    vector <int> vsoriginalnumber;
    const int X;
    const int Y;
    Button * btn1;
    Button * btn2;
    Button * btn3;
    Button * btn4;
    Button * btn5;
    Button * btn6;
    Item it;
    bool limited;
public:
    Window(int x, int y);
    void widgetpush(Widget *w);
    void event_loop();
    bool Getsave();
    vector<string>Getvs();
    void Setvs();
    void del();
    void ins();
    void prior();
    void create();
    void makevs();
    void limiton();
    void limitoff();
};

#endif // WINDOW_HPP_INCLUDED
