#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Enemigo{

private:
    sf::RenderWindow* window;
    int x,y;
    sf::Texture tex;
    sf::Sprite spr;
    int salud=100;
    int vidas=3;
public:
    Enemigo(sf::RenderWindow* w);
    ~Enemigo(){}
    void pintar();
    void mover();
    bool golpe(int a, int b);
    void vida();
};

#endif // ENEMIGOS_H_INCLUDED
