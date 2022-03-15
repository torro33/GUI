#include "graphics.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "textbox.hpp"
#include "selector.hpp"
#include "scrollbutton.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace genv;


Window::Window(int x,int y):X(x), Y(y){
    gout << font("LiberationSans-Regular.ttf",20);
    gout.open(X,Y);
    limited = false;
    btn1 = new Button(10,130,100,50,"Torol");
    btn2 = new Button(250,130,100,50,"Uj elem");
    btn3 = new Button(10,370,200,50,"Rendez:Prior");
    btn4 = new Button(10,430,200,50,"Rendez:Letrehoz");
    widgetpush(btn1);
    widgetpush(btn2);
    widgetpush(btn3);
    widgetpush(btn4);
    btn5 = new Button(330,230,150,50,"Limit On");
    btn6 = new Button(330,310,150,50,"Limit Off");
    widgetpush(btn5);
    widgetpush(btn6);
}

void Window::event_loop(){
    event ev;
    int focus = -1;
    while(gin >> ev) {
            if (ev.type == ev_mouse) {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->isselected(ev.pos_x, ev.pos_y)) {
                            focus = i;
                    }
                }
            }
        if (focus!=-1) {
            widgets[focus]->eventhandler(ev);
        }
        for(Widget * wg : widgets){
            wg->draw();
        }
        del();
        ins();
        prior();
        create();
        limiton();
        limitoff();
        //if( ((Scrollbutton*)widgets[9])->Getselected()) || ((Scrollbutton*)widgets[10])->Getselected()) ){makevs();}
        gout << refresh;
    }//while
}

void Window::widgetpush(Widget *w){
    widgets.push_back(w);
}

vector<string> Window::Getvs(){
    return vs;
}

void Window::Setvs(){//?????????????????????????????????????????????????????????????

}

void Window::del(){
        if(btn1->Getselected() && ((Selector*)widgets[8])->Getactive() != ""){//delete item
//                cout << "del" << endl;
//                for(int j = 0;j<vs.size();j++){cout << vs[j] << endl;}
        for(int i = 0;i<itemvs.size();i++){
            if(itemvs[i].name == ((Selector*)widgets[8])->Getactive()){//
                itemvs.erase(itemvs.begin()+i);
                ((Selector*)widgets[8])->Setactive("");
                makevs();
                ((Selector*)widgets[8])->Setoptions(vs);
                break;
            }
        }
    }

}

void Window::ins(){
    if(btn2->Getselected()){//insert item

        if(((Textbox*)widgets[7])->Gettxt() != ""){
            it.name = ((Textbox*)widgets[7])->Gettxt();
            it.value = ((Scrollbutton*)widgets[6])->Getscore();
            //it.createdvalue = itemvs.size()+1;
            int maximum = 0;
            if(itemvs.size() > 1){
                for(int i = 1;i<itemvs.size();i++){
                    if(itemvs[i].createdvalue > itemvs[maximum].createdvalue){
                        maximum = i;
                    }
                }
                it.createdvalue = itemvs[maximum].createdvalue + 1;
            }else{it.createdvalue = 1;}
            //it.createdvalue = itemvs[maximum].createdvalue + 1;
            itemvs.push_back(it);
            ((Textbox*)widgets[7])->Settxt("");
        }
        makevs();
        ((Selector*)widgets[8])->Setoptions(vs);
    }
}

void Window::prior(){
    if(btn3->Getselected() && vs.size() != 0){
        int minimum;
        Item seged;
        for(int i = 1;i<itemvs.size()-1;i++){
            minimum = i;
            for(int j = i+1;j<itemvs.size();j++){
                if(itemvs[minimum].value > itemvs[j].value){
                    minimum = j;
                }
            }
            seged = itemvs[i];
            itemvs[i] = itemvs[minimum];
            itemvs[minimum] = seged;

        }
        makevs();
//        cout << "belep" << endl<<endl;
//            for(int j = 0;j<itemvs.size();j++){
//                cout << itemvs[j].name << endl;
//        }
    }
}

void Window::create(){
    if(btn4->Getselected() && itemvs.size() != 0){
        int minimum;
        Item seged;
        for(int i = 1;i<itemvs.size()-1;i++){
            minimum = i;
            for(int j = i+1;j<itemvs.size();j++){
                if(itemvs[minimum].createdvalue > itemvs[j].createdvalue){
                    minimum = j;
                }
            }
            seged = itemvs[i];
            itemvs[i] = itemvs[minimum];
            itemvs[minimum] = seged;

        }
       makevs();
    }
}

void Window::makevs(){
    vs.clear();
    if(limited){
        for(int i = 0;i<itemvs.size();i++){
            if((itemvs[i].value > ((Scrollbutton*)widgets[9])->Getscore()) && (itemvs[i].value < ((Scrollbutton*)widgets[10])->Getscore())){
                vs.push_back(itemvs[i].name);
            }
        }
        ((Selector*)widgets[8])->Setoptions(vs);
    }else if(!limited){
        for(int i = 0;i<itemvs.size();i++){
            vs.push_back(itemvs[i].name);
        }
        ((Selector*)widgets[8])->Setoptions(vs);
    }
}


void Window::limiton(){
    if(btn5->Getselected()){
        limited = true;
    }
    makevs();
}

void Window::limitoff(){
    if(btn6->Getselected()){
        limited = false;
    }
    makevs();
}

//void Window::del(){
//
//        if(btn1->Getselected() && ((Selector*)widgets[6])->Getactive() != ""){//delete item
////                cout << "del" << endl;
////                for(int j = 0;j<vs.size();j++){cout << vs[j] << endl;}
//        for(int i = 0;i<vs.size();i++){
//            if(vs[i] == ((Selector*)widgets[6])->Getactive()){
//                vs.erase(vs.begin()+i);
//                vsoriginal.erase(vsoriginal.begin()+i);//
//                vsoriginalnumber.erase(vsoriginalnumber.begin()+i);//
//                ((Selector*)widgets[6])->Setactive("");
//                ((Selector*)widgets[6])->Setoptions(vs);
//                break;
//            }
//        }
//    }
//
//}
//
//void Window::ins(){
//    if(btn2->Getselected()){//insert item
//        if(((Textbox*)widgets[5])->Gettxt() != ""){
//            vs.push_back(((Textbox*)widgets[5])->Gettxt());
//            vsoriginal.push_back(((Textbox*)widgets[5])->Gettxt());
//            vsoriginalnumber.push_back(((Scrollbutton*)widgets[4])->Getscore());
//            ((Textbox*)widgets[5])->Settxt("");
//        }
//        ((Selector*)widgets[6])->Setoptions(vs);
//    }
//}
//
//void Window::prior(){
//    if(btn3->Getselected() && vs.size() != 0){
//        vsnumber = vsoriginalnumber;
//        int minimum;
//        int seged;
//        for(int i = 1;i<vsnumber.size()-1;i++){
//            minimum = i;
//            for(int j = i+1;j<vsnumber.size();j++){
//                if(vsnumber[minimum] > vsnumber[j]){
//                    minimum = j;
//                }
//            }
//            seged = vsnumber[i];
//            string seged2 = vs[i];
//            vsnumber[i] = vsnumber[minimum];
//            vs[i] = vs[minimum];
//            vsnumber[minimum] = seged;
//            vs[minimum] = seged2;
//        }
//    }
//}
//
//void Window::create(){
//    if(btn4->Getselected() && vs.size() != 0){
//        vs = vsoriginal;
//    }
//}
