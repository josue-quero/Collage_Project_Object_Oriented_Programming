#include "Peliculas.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <bits/stdc++.h>

Peliculas::Peliculas(){
    iCant = 0;
    for (int i = 0; i < 100; i++)
        arrPtrPeliculas[i] = nullptr;
}

void Peliculas::leerArchivo(){
    //File pointer
    fstream fin;

    fin.open("Peliculas.csv", ios::in);

    //Read the Data from the file as String array
    string row[6];
    string line, word;

    while(getline(fin, line)){
        //Read a row and store it in a string variable
        
        //Used for breaking words
        stringstream s(line);

        //Read every column data of a row and store it in a string variable
        int i = 0;
        //Extracts characters of  s and stores them in word until finding ','
        while(getline(s, word, ',')){
            //Add all the column data of a row to a vector
            row[i++] = word;
        }

        //Creates an object of type movie - Dinamyc memory -
        arrPtrPeliculas[iCant] = new Pelicula();

        arrPtrPeliculas[iCant]->setId(row[0]);
        arrPtrPeliculas[iCant]->setTitulo(row[1]);
        arrPtrPeliculas[iCant]->setDuracion(stoi(row[2]));
        arrPtrPeliculas[iCant]->setCalificacion(stoi(row[4]));
        arrPtrPeliculas[iCant]->setGenero(row[3]);
        arrPtrPeliculas[iCant]->setOscares(stoi(row[5]));

        iCant++;
    }
    cout << "Se termino de leer las peliculas" << endl;
    fin.close();
}

//Método que agregará una película al arreglo de peliculas
void Peliculas::setPtrPeliculas(Pelicula *ptr){
    arrPtrPeliculas[iCant++] = ptr;
}

//Se devuelve la película que corresponda con el ID
Pelicula Peliculas::getPelicula(string iPel){
    Pelicula peli;
    for (int i = 0; i < iCant; i++){
        if (arrPtrPeliculas[i]->getId() == iPel){
            return(*arrPtrPeliculas[i]);
        }
    }
    //Si no hay ninguna película que tenga el id correspondiente
    //se devuelve un mensaje de error y un objeto película predeterminado
    cout << "ID invalido";
    return peli;    
}

//Método utilizado para desplegar todas las películas en el arreglo.
void Peliculas::str()
{   
    int contador = 1;
    cout << "# id    Titulo   Duracion   Genero   Calificacion   Oscares" << endl;
    for (int i = 0; i < iCant; i++)
    {
        cout << "Pelicula: " << contador << " " << arrPtrPeliculas[i]->str() << endl;
        contador++;
    }

    cout << "Calificacion Promedio: " << calificacionPromedio();
}

//Método que imprime las películas que tienen cierta calificación
void Peliculas::reporteConCalificacion(double cali)
{
    bool validar = false;
    for (int i = 0; i < iCant; i++){
        if (arrPtrPeliculas[i]->getCalificacion() == cali)
        {
            cout << arrPtrPeliculas[i]->str() << endl;
            validar = true;
        }
    } 
    //Si no hay una película con la calificación proporcionada
    //se le deja saber al usuario
    if (validar == false){
        cout << "No hay una pelicula con dicha calificacion!" << endl;
    }
}
//Método que imprime las películas que pertenezcan a cierto género
void Peliculas::reporteGenero(string gen)
{
    bool validar = false;
    string temporal1;
    for (int i = 0; i < iCant; i++){
        temporal1 = arrPtrPeliculas[i]->getGenero();
        //Se convierten los strings a uppercase, para que
        //aunque el usuario haya escrito en mayúsculas o minúsculas
        //sea posible encontrar las películas con el género correspondiente
        for_each(temporal1.begin(), temporal1.end(), [](char & c){
	        c = ::tolower(c);
        });
        for_each(gen.begin(), gen.end(), [](char & c){
	        c = ::tolower(c);
        });
        if (temporal1  == gen){
            cout << arrPtrPeliculas[i]->str() << endl;
            validar = true;
        }
    }
    //Si no hay una película con el genero proporcionado
    //se le deja saber al usuario.
    if (validar == false){
        cout << "No hay series con ese genero!" << endl;
    }
}

//Métdo que obtiene el promedio de todas las películas
double Peliculas::calificacionPromedio(){
    double promedio = 0;
    for (int i = 0; i < iCant; i++){
        promedio = promedio + arrPtrPeliculas[i]->getCalificacion();
    }
    return promedio/iCant;
}

//Método específico para cambiar la cantidad de oscares de una 
//película, dándole el id y la cantidad de oscares
void Peliculas::setCambioOscar(string id, int cantidad){
    double calif = 0;
    for (int i = 0; i < iCant; i++){
        if (arrPtrPeliculas[i]->getId() == id){
            if (cantidad > 10){
                calif = 5;
            }
            else{
                calif = 0.5*cantidad;
            }
            arrPtrPeliculas[i]->setOscares(cantidad);
            arrPtrPeliculas[i]->setCalificacion(calif);

        }
    }
    //Si no hay una película con el id indicado, se le deja
    //saber al usuario
    if (calif == 0){
        cout << "ID invalida" << endl;
    }
}
//Note: You can use overload to add grade or calculate their average
