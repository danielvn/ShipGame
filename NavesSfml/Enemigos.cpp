#include "Enemigos.h"

Enemigo::Enemigo(sf::RenderWindow* w){
    window=w;
    x=348;
    y=0;
    tex.loadFromFile("fig4.png");
    spr.setTexture(tex);
}

void Enemigo::mover(){
    spr.setPosition(x,y);

}

void Enemigo::pintar(){
    window->draw(spr);
}

bool Enemigo::golpe(int a, int b){

    if((a>=x) && ((a+5)<=(x+104))){

        if((b>=y)&&((b)<=(y+92)))
            return true;
    }

    return false;

}

void Enemigo::vida(){
    if(salud>0){
        salud--;
    }
    if(salud==0 && vidas>0){
        salud=100;
        vidas--;
    }
    if(vidas==0 && salud==0){
        cout<<"muere"<<endl;
    }
    cout << salud << "  " << vidas  << endl;
}
