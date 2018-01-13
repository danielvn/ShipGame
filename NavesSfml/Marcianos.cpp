#include "Marcianos.h"


Marcianitos::Marcianitos(sf::RenderWindow* w,int _x, int _y,int p){

    window=w;
    x=_x;
    y=_y;
    patron=p;
    tex.loadFromFile("fig6.png");
    spr.setTexture(tex);
}

void Marcianitos::pintar(){
    if(patron==0){
        if(control==0){
            x+=14;
            y+=2;
            if(x>=700){
                control=1;
            }
        }
        if(control==1){
            x-=12;
            y+=2;
            if(x<=100){
                control=2;
            }
        }
        if(control==2){
            x+=12;
            y+=2;
            if(x>=700){
                control=3;
            }
        }
        if(control==3){
            x-=12;
            y+=2;
            if(x<=100){
                control=4;
            }
        }
        if(control==4){
            x+=10;
            y+=4;
            if(x>=500){
                control=5;
                acaba=true;
            }
        }
    }else if(patron==1){

        if(control==0){
            y+=10;
            if(y>200)
                control=1;

        }else if(control==1){
            x+=5;
            if(x>=450){
                control = 2;
            }
        }else if(control == 2){
            y+=10;
            if(y>=400)
                control = 3;

        }else if(control == 3){
            x-=10;
            if(x<=350)
                control=4;
        }else if(control == 4){
            y+=10;
            if(y>=600){
                control = 5;
            }
        }else if(control == 5){
            x+=10;
            if(x>=450){
                control=6;
            }
        }else if(control==6){
            y+=10;
            if(y>=600){
                control=7;
                acaba=true;
            }
        }
    }
    spr.setPosition(x,y);
    window->draw(spr);
}
