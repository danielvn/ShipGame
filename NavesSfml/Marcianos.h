#ifndef MARCIANOS_H_INCLUDED
#define MARCIANOS_H_INCLUDED
#include <SFML/Graphics.hpp>
class Marcianitos{
private:
    sf::RenderWindow* window;
    int x,y;
    sf::Texture tex;
    sf::Sprite spr;
    unsigned int control=0;
    int patron;
    bool acaba=false;
public:
    Marcianitos(sf::RenderWindow* w,int _x,int _y, int p);
    ~Marcianitos(){}
    void pintar();
    unsigned int Control(){return control;}
    int X() const {return x;}
    int Y() const {return y;}
    int Acaba() const {return acaba;}
};

#endif // MARCIANOS_H_INCLUDED
