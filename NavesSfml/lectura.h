#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void leer(){
    ifstream in;
    in.open("tmp.txt");
    char s[3];
    if(in.is_open()){
        in>>s;
        cout<<s<<endl;
    }else{
        cout<<"Error"<<endl;
    }
    in.close();

}


#endif // LECTURA_H_INCLUDED
