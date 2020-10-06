#include "Video.hpp"

//Método constructor con una de mis películas favoritas
Video::Video()
{
    iD = "000";
    titulo = "Blade Runner";
    genero = "Drama";
    duracion = 132;
    calificacionPromedio = 4.9;
}
//Método constructor con parámetros: ID, título, duración, género y calificación
Video::Video(string id, string tit, int dur, string gen, double calif)
{
    iD = id;
    titulo = tit;
    genero = gen;
    duracion = dur;
    calificacionPromedio = calif;
}
//Se establece el ID de un video
void Video::setId(string id)
{
    iD = id;
}
//Se establece el título de un video
void Video::setTitulo(string tit)
{
    titulo = tit;
}
//Se establece la duración del video
void Video::setDuracion(int dur)
{
    duracion = dur;
}
//Se establece el género del video
void Video::setGenero(string gen)
{
    genero = gen;
}
//Se establece la calificación del video
void Video::setCalificacion(double calif)
{
    calificacionPromedio = calif;
}
//Se duevelve el Id del video
string Video::getId()
{
    return iD;
}
//Se devuelve el título del video
string Video::getTitulo()
{
    return titulo;
}
//Se devuélve la duración del video
int Video::getDuracion()
{
    return duracion;
}
//Se devuelve el género del video
string Video::getGenero()
{
    return genero;
}
//Se devuelve la calificación del video
double Video::getCalificacion()
{
    return calificacionPromedio;
}
//Se devuelven todos los atributos en un string
string Video::str()
{
    return iD + ", " + titulo + ", " + to_string(duracion) +
    ", " + genero + ", " + to_string(calificacionPromedio);
}