#ifndef PELICULA_HPP
#define PELICULA_HPP

#include <stdio.h>
#include <string>
#include "Video.hpp"


class Pelicula: public Video{
protected:
    int iOscares;
public:
    //Constructor default
    Pelicula();
    //Constructor con parámetros que inicializará también el constructor
    //con parámetros de la clase video.
    Pelicula(string, string, int, string, double, int);
    //Desctructor
    ~Pelicula();
    //Método que devuelve todos los atributos de una película:
    //ID, Título, duración, género, calificación y cantidad de oscares
    string str();
    //Se devuelve la calificación de la película 
    double calPromedio();
    //Se establece la cantidad de oscares que tiene la película
    void setOscares(int);
    //Método que devuelve la cantidad de oscares que tiene la película
    int getOscares();
};

#endif /* PELICULA_HPP */