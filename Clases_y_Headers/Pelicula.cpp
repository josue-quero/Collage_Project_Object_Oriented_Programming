#include "Pelicula.hpp"

//Método constructor default
Pelicula::Pelicula(): Video(){
    iOscares = 0;
}

//Método constructor con parámetros
Pelicula::Pelicula(string id, string titulo, int duracion, string genero, double calificacion,
int oscares): Video(id, titulo, duracion, genero, calificacion){
    iOscares = oscares;
}
//Destructor
Pelicula::~Pelicula(){
}

//Retorna un string con la información de la película
string Pelicula::str(){
    return Video::str() + ", " + to_string(iOscares);
}

double Pelicula::calPromedio(){
    return getCalificacion();
}

//Cambia el atributo Oscars
void Pelicula::setOscares(int oscares){
    iOscares = oscares;
}

//Retorna el atributo iOscares
int Pelicula::getOscares(){
    return iOscares;
}
