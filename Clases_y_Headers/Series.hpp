#ifndef SERIES_HPP
#define SERIES_HPP
#include "Serie.hpp"

class Series{
private:
    Serie *arrPtrSeries[100];
    int cant;
public:
    //Constructor default
    Series();
    //Método que lee los datos del archivo csv.
    void leerArchivo();
    //Método que imprime los datos de todas las series
    //que se han leído o creado
    void str();
    //Método que imprime los las series que tienen
    //una cierta calificación con sus episodios
    void reporteConCalificacion(double);

    //Método que devuelve las series y sus episodios
    //que sean de cierto género
    void reporteGenero(string);
    //Método que ingerta un objeto de la clase serie en
    //el arreglo de series
    void setPtrSerie(Serie *ptr);
    //Método que devuelve una serie según la posición que se de  
    Serie getPtrSerie(int);
    //Método que imprime los episodios de una serie específica
    //que tengan cierta calificación 
    void consultaEpisodiosCalificacion(string, double);
    //Método que calcula el promedio por serie, según la
    //calificaión de los episodios
    void calcularPromedioXSerie();
    //Según sea el Id que se de, se imprimirán los episodios 
    //de la serie que tenga dicho ID
    void reporteId(string);
    //Según sea la cantidad de temporadas que se den,
    //se validará si hay una serie que tenga dicha cantidad de
    //temporadas y se imprimirá la serie
    void reportePorTemporadas(int);
    //Se devuelve la cantidad de series que hay.
    int getCantidad();
    //Se da de alta un episodio de la serie que tenga el ID
    //proporcionado
    void darAltaEpisodio(string);
};

#endif /* Series.hpp */