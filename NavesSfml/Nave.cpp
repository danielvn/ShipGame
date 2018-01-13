#include "Nave.h"

nave::nave(sf::RenderWindow* w){
    window=w;
    x=358;
    y=600;
    tex.loadFromFile("fig1.png");
    spr.setTexture(tex);
    font.loadFromFile("letra.ttf");
    text.setFont(font);
    text.setString("Salud");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setPosition(700,0);
    ss<<salud;
    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setString( ss.str().c_str() );
    text2.setPosition(750,0);
    ss.clear();
    ss.str("");
    ss<<vidas;
    text3.setFont(font);
    text3.setString("Vidas");
    text3.setCharacterSize(24);
    text3.setPosition(700,25);
    text4.setFont(font);
    text4.setString(ss.str().c_str());
    text4.setCharacterSize(24);
    text4.setPosition(750,25);
    text5.setFont(font);
    text5.setString("Puntos");
    text5.setCharacterSize(24);
    text5.setPosition(700,50);
    ss.clear();
    ss.str("");
    ss<<puntos;
    text6.setFont(font);
    text6.setString(ss.str().c_str());
    text6.setCharacterSize(24);
    text6.setPosition(750,50);
}

nave::~nave(){}

void nave::pintar(){

    window->draw(spr);
    window->draw(text);
    window->draw(text2);
    window->draw(text3);
    window->draw(text4);
    window->draw(text5);
    window->draw(text6);
}
void nave::mover(char c){

    spr.setPosition(x,y);
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){y-=10;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){x-=10;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){y+=10;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){x+=10;}*/
    switch (c){
        case 'W':
            y-=10;
            break;
        case 'A':
            x-=10;
            break;
        case 'S':
            y+=10;
            break;
        case 'D':
            x+=10;
            break;
        default:
            break;
    }
    if(!hayEscudo){
        if(x<=0){x=0;}
        if((x+94)>=800){x=800-94;}
        if(y<=0){y=0;}
        if((y+84)>=600){y=600-84;}
    }else{
        if(x<=0){x=0;}
        if((x+158)>=800){x=800-158;}
        if(y<=0){y=0;}
        if((y+158)>=600){y=600-158;}
    }
}

void nave::escudo(){
    if(!hayEscudo){
        tex.loadFromFile("fig5.png");
        spr.setTexture(tex,true);
        hayEscudo=true;
        x-=34;
        y-=40;
        clock.restart();
    }
}

void nave::liberarEscudo(){
    if(t1<=clock.getElapsedTime() && hayEscudo){
        tex.loadFromFile("fig1.png");
        spr.setTexture(tex,true);
        hayEscudo=false;
        x+=34;
        y+=40;
    }
}


void nave::puntosMarcianitos(){
    puntos+=50;
    cout<<"Los puntos acumulados son : "<<puntos<<endl;
    ss.clear();
    ss.str("");
    ss<<puntos;
    text6.setString( ss.str().c_str() );

}

void nave::golpeMarcianitos(){
    if(salud>0){
        salud-=10;
        ss.clear();
        ss.str("");
        ss<<salud;
        text2.setString( ss.str().c_str() );
    }
    if(salud<=0){
        salud=0;
    }
    if(salud==0 && vidas>0){
        salud=100;
        vidas--;
        ss.clear();
        ss.str("");
        ss<<vidas;
        text4.setString( ss.str().c_str() );
    }
    if(vidas==0 && salud==0){
        muerto=true;
        cout<<"Estas muerto"<<endl;
    }
    cout<<"Salud : "<<salud<<" Vidas : "<<vidas<<endl;
}

