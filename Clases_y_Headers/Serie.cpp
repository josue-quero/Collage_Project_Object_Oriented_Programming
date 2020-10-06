#include "Serie.hpp"    
    
    
Serie::Serie(){
    cant = 0;
    for (int i = 0; i < 5; i++)
        episodios[i] = nullptr;
}

    //Método constructor con parámetros, inicializa todos los espacios en el arreglo con nullptr
Serie::Serie(std::string id,  std::string titulo, int duracion, std::string genero, double calificacion, int cantidad): Video(id, titulo, duracion, genero, calificacion){
    cant = 0;
    for (int i = 0; i < 5; i++)
        episodios[i] = nullptr;                
}

//Destructor
Serie::~Serie(){
}

//Métdo que sirve para mostrar la serie
string Serie::str(){
    return "Serie: " + Video::str();
}
//Se calcula la calificación promedio de la serie
//utilizando sobrecarga de operadores
double Serie::calPromedio(){
    double promedio = 0;
    for (int i = 0; i < cant; i++){
        promedio = *episodios[i] + promedio;
    }
    //Se valida si hay o no episodios en la serie
    if (cant > 0){
        return promedio/cant;
    }
    else{
        return -1;
    }
}

//Se añade un episodio en el lugar que se indica y se incrementa
//el valor de la cantidad de episodios 
void Serie::setEpisodio(int epi, Episodio *nuevo){
    episodios[epi] = nuevo;
    cant++;
}

//Se devuelve el episodio que se encuentra en cierta posición
//del arreglo
Episodio Serie::getEpisodio(int epi){
    return *episodios[epi];
}
//Se establecen la cantidad de episodios que tiene una serie
void Serie::setCantidadEpisodios(int cantidad){
    cant = cantidad;
}
//Se devuelve la cantidad de episodios que tiene una serie
int Serie::getCantidadEpisodios(){
    return cant;
}
//Se devuelve la cantidad de temporadas que tiene una serie
int Serie::getCantidadTemporadas(){
    int temporada[cant], contador = 0, contador_2 = 1;
    //Si no tiene episodios la serie, se devuelve cero
    if (cant == 0){
        return 0;
    }
    else{
        for (int i = 0; i < cant; i++){
            if(episodios[i]->getTemporada() >= contador){
                temporada[i] = episodios[i]->getTemporada();
                contador = episodios[i]->getTemporada();
            }
            else{
                temporada[i] = contador;
                temporada[i-1] = episodios[i]->getTemporada();
            }
        }
        for (int iR = 1; iR < cant; iR++){
            if (temporada[iR] > temporada[iR-1]){
                contador_2++;
            }
        }
        return contador_2;
    }

}

