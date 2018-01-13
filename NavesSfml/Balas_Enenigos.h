#ifndef BALAS_ENENIGOS_H_INCLUDED
#define BALAS_ENENIGOS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class BalaEnemigo{
private:
    sf::RenderWindow* window;
    int x,y;
    sf::Texture tex;
    sf::Sprite spr;

public:
    BalaEnemigo(sf::RenderWindow* w,int x, int y);
    ~BalaEnemigo(){}
    void pintar();
    bool fuera() const;
};

#endif // BALAS_ENENIGOS_H_INCLUDED
