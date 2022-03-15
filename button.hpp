#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "string"
#include "widget.hpp"

using namespace genv;
using namespace std;

class Button : public Widget{
protected:
    string txt = "";
    bool selected;
public:
    Button(int x,int y,int sx,int sy,string s);
    virtual void draw() override;
    virtual void eventhandler(event ev) override;
    bool Getselected();
    bool Setselected(bool b);
};

#endif // BUTTON_HPP_INCLUDED
