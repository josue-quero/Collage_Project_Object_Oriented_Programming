#include "Episodio.hpp"

//Se inicializan los atributos con un episodio sin valores reales
Episodio::Episodio(){
    titulo = "N/A";
    temporada = 1;
    calificacion = 5;
}
//Se inicializan los atributos del episodio con los proporcionados
Episodio::Episodio(string tit, int temp, double cal){
    titulo = tit;
    temporada = temp;
    calificacion = cal;
}
//Se regresa un string con el valor de los atributos del episodio
string Episodio::str(){
    return titulo + ", " + to_string(temporada) + ", " + to_string(calificacion);
}
//Se establece el nombre del episodio según el string dado
void Episodio::setTitulo(string tit){
    titulo = tit;
}
//Se regresa el string del titiulo del episodio
string Episodio::getTitulo(){
    return titulo;
}
//Se establece la temporada a la que pertenece el episodio
void Episodio::setTemporada(int temp){
    temporada = temp;
}
//Se devuelve la temporada a la que pertenece el episodio
int Episodio::getTemporada(){
    return temporada;
}
//Se establece la calificación que tendrá el episodio
void Episodio::setCalificacion(double cal){
    calificacion = cal;
}
//Se devuelve la calificación que tiene el episodio
double Episodio::getCalificacion(){
    return calificacion;
}