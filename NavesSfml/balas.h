#ifndef BALAS_H_INCLUDED
#define BALAS_H_INCLUDED

#include <SFML/Graphics.hpp>

class Balas{

private:
sf::RenderWindow* window;
int x,y;
sf::Texture tex;
sf::Sprite spr;
public:
Balas(int _x, int _y,sf::RenderWindow* w,bool e);
~Balas();
void pintar();
bool fuera();
int X() const {return x;}
int Y() const {return y;}
};

#endif // BALAS_H_INCLUDED
