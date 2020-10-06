#ifndef SERIE_HPP
#define SERIE_HPP

#include "Video.hpp"
#include "Episodio.hpp"

class Serie: public Video{
protected:
    Episodio *episodios[5];
    int cant;

public:

    // Constructor default
    Serie();

    //Método constructor con parámetros
    Serie(std::string, std::string, int, std::string, double, int);

    //Método destructor
    ~Serie();

    //Método que devuelve todos los atributos de la serie
    std::string str();

    //Método que calcula el promedio de los episodios de la serie
    double calPromedio();

    //Método que establece un nuevo episodio
    void setEpisodio(int, Episodio *ptrEpisodio);

    //Método que devuelve el episodio según su id
    Episodio getEpisodio(int);

    //Método que establece la cantidad de episodios de una serie
    void setCantidadEpisodios(int);

    //Método que devuelve la cantidad de episodios de una serie
    int getCantidadEpisodios();

    //Método que devuelve la cantidad de temporadas que tiene una serie
    int getCantidadTemporadas();

};

#endif /* Serie_hpp */