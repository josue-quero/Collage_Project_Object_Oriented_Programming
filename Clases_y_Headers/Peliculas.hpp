#ifndef PELICULAS_HPP
#define PELICULAS_HPP

#include <stdio.h>
#include "Pelicula.hpp"
#include <iostream>
using namespace std;

class Peliculas{
private:
    Pelicula *arrPtrPeliculas[100];
    int iCant; //Cantidad de Peliculas dadas de alta
public:
    //Constructor que inicializa el *arrPtrPeliculas[100] con nullptr
    Peliculas();
    //Lee las peliculas desde un archivo cvs y las carga en el arreglo -
    //*arrPtrPeliculas[100]
    void leerArchivo();
    //Reporte de todas las peliculas -
    //al final del mismo muestra la calificación promedio de todas las peliculas
    void str();
    //Reporte de las películas que tienen cierta calificación
    void reporteConCalificacion(double);
    //Reporte de las películas que tienen cierto género
    void reporteGenero(string);
    //Metodo para calcular únicamente el promedio de calificaciones de todas las películas
    double calculaCalPromedio();
    //Da de alta una nueva película
    //Sirve para cuando se ingresan los datos del teclado desde el main
    void setPtrPeliculas(Pelicula *ptr);
    //Retorna el objeto Pelicula que tiene el id
    //que recibió como parámetro de entrada
    Pelicula getPelicula(string);
    //Método para cambiar la cantidad de oscares
    void setCambioOscar(string, int);
    //Método para cambiar la calificación promedio
    double calificacionPromedio();
};

#endif /* PELICULAS_HPP */
