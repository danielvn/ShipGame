#include "balas.h"
Balas::Balas(int _x, int _y,sf::RenderWindow* w,bool e){
    window=w;
    if(!e){
        x=_x+45;
        y=_y;
    }else{
        x=_x+77;
        y=_y;
    }
    tex.loadFromFile("fig3.png");
    spr.setTexture(tex);
}

void Balas::pintar(){
    if(y>0)
        y-=30;
    spr.setPosition(x,y);
    window->draw(spr);
}

bool Balas::fuera(){
    if(y<=0){
        return true;
    }
    return false;
}
Balas::~Balas(){
}
