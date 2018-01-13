#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Nave.h"
#include <list>
#include "balas.h"
#include "Enemigos.h"
#include "Marcianos.h"
#define marcianos_max 25
using namespace std;
char s[3];
void leer(){
    ifstream in;
    in.open("tmp.txt");
    if(in.is_open()){
        in>>s;
        cout<<s<<endl;
    }else{
        cout<<"Error"<<endl;
    }
    in.close();
}
int main()
{
    //Ventana
    sf::RenderWindow window(sf::VideoMode(800,600),"Space retards");
    window.setFramerateLimit(15);
    sf::Texture image;
    sf::Sprite background;
    sf::Sprite background2;
    sf::Event evento;
    if(!image.loadFromFile("fig2.jpg"))
        cout<<"No se cargo la imagen"<<endl;
    background.setTexture(image);
    background2.setTexture(image);
    bool isPlay = true, font =false;
    background.setPosition(0,0);
    int y=-254, y2=-1108;
    //Objetos
    nave n(&window);
    list<Balas*> B;
    list<Balas*>::iterator it;
    list<Marcianitos*> M;
    list<Marcianitos*>::iterator it2;
    int marcianos=0;
    sf::Clock clock;
    sf::Time t1=sf::seconds(0.2f);
    Enemigo *E;
    bool colMarcianos=false;

    int controlNivel=0;

    while(isPlay){
    //Movimiento del fondo
    leer();
    y+=4;
    y2+=4;
    background.setPosition(0,y);
    background2.setPosition(0,y2);
    if(y>=0 && (!font)){
        font=true;
    }
    if(y>=600 && (font)){
        y=-1108;
    }
    if(y2>=600 && (font)){
        y2=-1108;
    }
    //Deteccion de eventos
    while(window.pollEvent(evento)){
        if(evento.type==sf::Event::Closed){
            window.close();
            isPlay=false;
        }
        if(evento.type==sf::Event::KeyPressed){

            if(evento.key.code==sf::Keyboard::K){
                B.push_back(new Balas(n.X(),n.Y(),&window,n.esc()));
            }
            if(evento.key.code==sf::Keyboard::L){
                n.escudo();
            }
        }
    }


        if(t1<clock.getElapsedTime() && controlNivel==0){
            M.push_back(new Marcianitos(&window,0,0,0));
            M.push_back(new Marcianitos(&window,350,0,1));
            clock.restart();
            marcianos++;
            if(marcianos>marcianos_max){
                controlNivel=1;
                marcianos=0;
            }
        }
        if(controlNivel==1){
            E=new Enemigo(&window);
            controlNivel=2;
            cout<<"Nuevo Enemigo"<<endl;

        }

        n.liberarEscudo();
        n.mover(s[0]);

        for(it2=M.begin();it2!=M.end();it2++){
            colMarcianos=false;
            for(it=B.begin();it!=B.end();it++){
                    if(((*it)->X())>=((*it2)->X())&&((*it)->X()+5)<=((*it2)->X()+50)){
                        if(((*it)->Y()-44)<=((*it2)->Y()) && ((*it)->Y())>=((*it2)->Y())){
                            colMarcianos=true;
                            delete *it;
                            it=B.erase(it);
                        }
                    }

                }
                if(colMarcianos){
                    n.puntosMarcianitos();
                    delete *it2;
                    it2=M.erase(it2);
                }
            }

        for(it2=M.begin();it2!=M.end();it2++){
            if(((((*it2)->X()+50)<=(n.X()+94))&&(((*it2)->X())<=(n.X()+94))&&(((*it2)->X()+50)>=(n.X()))) ||
            ((((*it2)->X())>n.X())&&(((*it2)->X())<(n.X()+94))&&(((*it2)->X()+50)>(n.X()+94)))){
                if((((*it2)->Y()+44)>=n.Y())&&(((*it2)->Y())<=n.Y()+84)){
                    delete *it2;
                    it2=M.erase(it2);
                    if(!n.esc())
                        n.golpeMarcianitos();
                }
            }

        }

//Dibujar
        window.draw(background);
        window.draw(background2);
        n.pintar();
        for(it2=M.begin();it2!=M.end();it2++){
            (*it2)->pintar();
            if((*it2)->Acaba()){
                delete (*it2);
                it2=M.erase(it2);
            }
        }

        for(it=B.begin();it!=B.end();it++){
            (*it)->pintar();
            if((*it)->fuera()){
                delete(*it);
                it=B.erase(it);
            }
        }
        window.display();
    }

    window.close();
    return 0;
}
