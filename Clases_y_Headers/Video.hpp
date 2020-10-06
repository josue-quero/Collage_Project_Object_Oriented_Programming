#ifndef VIDEOS_HPP
#define VIDEOS_HPP

#include <stdio.h>
#include <iostream>
using namespace std;

class Video{
public:
    //Constructor default
    Video();
    //Constructor con parámetros: iD, titulo, duracion, genero, calificacion
    Video(string, string, int, string, double);
    //Método que establece el iD
    void setId(string);
    //Método que establece el título del video
    void setTitulo(string);
    //Método que establece la duración del video
    void setDuracion(int);
    //Método que establece el género del video
    void setGenero(string);
    //Método que establece la calificación del video
    void setCalificacion(double);

    //Método que devuelve el Id del video
    string getId();
    //Método que devuelve el Título del video
    string getTitulo();
    //Método que devuelve la duración del video
    int getDuracion();
    //Método que devuelve el género del video
    string getGenero();
    //Método que devuelve la calificación del video
    double getCalificacion();
    //Método que devuelve todos los atributos en forma
    //de string
    string str();
protected:
    string iD, titulo, genero;
    int duracion; 
    double calificacionPromedio;

};
#endif /* VIDEOS_HPP */