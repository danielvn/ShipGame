#include "Balas_Enemigos.h"

BalasEnemigo::BalasEnemigo(sf::RenderWindow* w,int _x,int _y){
    window=w;
    x=_x+17;
    y=_y+44;
    tex.loadFromFile("fig7.png");
    spr.setTexture(tex);


}

void BalasEnemigo::pintar(){
    if(y<600)
        y+=15;
    spr.setPosition(x,y);
    window->draw(spr);

}

bool BalasEnemigo::fuera(){
    if(y>=600){
        return true;
    }
    return false;
}
