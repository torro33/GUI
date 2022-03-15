#ifndef SELECTOR_HPP_INCLUDED
#define SELECTOR_HPP_INCLUDED

#include "string"
#include "widget.hpp"
#include "button.hpp"

using namespace genv;
using namespace std;

class Selector : public Widget{
protected:
    string active;
    vector<string> options;
    int cell;
    bool selected;
    int fixrow;
    int activeindex;
    Button * btn1;
    Button * btn2;
public:
    Selector(int x,int y,int sx,int sy,vector<string> s,int cell);
    virtual bool isselected(int,int)override;
    virtual void draw() override;
    virtual void eventhandler(event ev) override;
    string Getactive();
    void Setactive(string s);
    void Setoptions(vector<string> s);
};

#endif // SELECTOR_HPP_INCLUDED
