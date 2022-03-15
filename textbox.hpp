#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "string"
#include "widget.hpp"

using namespace std;


class Textbox : public Widget {
protected:
    string txt = "";
    bool checked;
public:
    Textbox(int x, int y,int sx, int sy, string b);
    virtual void draw() override;
    virtual void eventhandler(genv::event ev) override;
    string Gettxt();
    void Settxt(string s);
};

#endif // TEXTBOX_HPP_INCLUDED
