#ifndef SCROLLBUTTON_HPP_INCLUDED
#define SCROLLBUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <sstream>
#include "string"

using namespace genv;
using namespace std;

class Scrollbutton : public Widget{
protected:
    int lowerinterval;
    int upperinterval;
    int score;
    bool selected;
    bool setupscreen;

public:
    Scrollbutton(int x,int y,int sx,int sy,int lowerinterval,int upperinterval);
    virtual void draw() override;
    virtual void eventhandler(event ev) override;
    void indicate();
    void startdisplay();
    int Getscore();
    bool Getselected();
};

#endif // SCROLLBUTTON_HPP_INCLUDED
