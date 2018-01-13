#ifndef BALAS_ENEMIGOS_H_INCLUDED
#define BALAS_ENEMIGOS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class BalasEnemigo{
private:
    sf::RenderWindow* window;
    int x,y;
    sf::Texture tex;
    sf::Sprite spr;
public:
    BalasEnemigo(sf::RenderWindow* w,int _x,int _y);
    ~BalasEnemigo(){}
    void pintar();
    bool fuera();
    int X() const {return x;}
    int Y() const {return y;}

};

#endif // BALAS_ENEMIGOS_H_INCLUDED
