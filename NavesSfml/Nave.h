#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
using namespace std;

class nave{

private:
    sf::RenderWindow* window;
    int x,y;
    sf::Texture tex;
    sf::Sprite spr;
    sf::Time t1=sf::seconds(3);
    sf::Clock clock;
    sf::Text text,text2,text3,text4,text5,text6;
    sf::Font font;
    stringstream ss;


    bool hayEscudo=false;
    unsigned int puntos=0;
    int salud = 100, vidas=3;
    bool muerto = false;
public:

    nave(sf::RenderWindow* w);
    ~nave();
    void mover(char c);
    void pintar();
    int X() const {return x;}
    int Y() const {return y;}
    void escudo();
    void liberarEscudo();
    bool esc() const {return hayEscudo;}
    void puntosMarcianitos();
    void golpeMarcianitos();
    void puntuacion();

};

#endif // NAVE_H_INCLUDED
