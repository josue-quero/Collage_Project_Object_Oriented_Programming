#ifndef EPISODIO_HPP
#define EPISODIO_HPP

#include <stdio.h>
#include <string>
using namespace std;

class Episodio{
protected:

    std::string titulo;
    int temporada;
    double calificacion;

public:
    //Constructor default
    Episodio();

    //Constructor con parámetros: titulo, temporada, calificacion
    Episodio(std::string, int, double);

    //Método que devuelve los atributos del episodio en forma de
    //string
    std::string str();
    //Método que establece el título de un episodio
    void setTitulo(std::string);
    
    //Método que devuelve el título del episodio
    std::string getTitulo();

    //Método que establece la temporada del episodio
    void setTemporada(int);

    //Método que devuelve la temporada del episodio
    int getTemporada();

    //Método que establece la calificación del episodio
    void setCalificacion(double);

    //Método que devuelve la calificación del episodio
    double getCalificacion();

    //Sobrecarga de operador + para obtener el promedio
    double operator + (double puntuacion){
        return puntuacion + calificacion;
    }
};

#endif /* Episodio_hpp */