#include "Series.hpp"
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

//Se crea el objeto series con los espacios
//en su arreglo igual a nullptr
Series::Series(){
    for (int i = 0; i < 5; i++){
        arrPtrSeries[i] = nullptr;
    }
    cant = 0;
}

//Método que lee de un archivo csv los episodios y las series
void Series::leerArchivo(){
    fstream fin;

    int episodio = 0;

    int arrIdSerie[150];

    Episodio *arrPtrEpisodio[150];

    Episodio *arrPtrEpi[5];

    fin.open("Episodios.csv", ios::in);

    string row[6];
    string line, word;

    while (getline(fin, line)){
        stringstream s(line);

        int i = 0;

        while (getline(s, word, ',')){
            row[i++] = word;
        }

        arrPtrEpisodio[episodio] = new Episodio();
        arrIdSerie[episodio] = stoi(row[0]);

        arrPtrEpisodio[episodio]->setTitulo(row[1]);
        arrPtrEpisodio[episodio]->setTemporada(stoi(row[2]));
        arrPtrEpisodio[episodio]->setCalificacion(stoi(row[3]));

        episodio++;
    }

    fin.close();

    fin.open("ArchivoSerie.csv", ios::in);
    cant = 0;
    while (getline(fin, line)){

        stringstream s(line);

        int i = 0;

        while (getline(s, word, ',')){
            row[i++] = word;
        }
        arrPtrSeries[cant] = new Serie(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]));

        int e = 0;
        for (int epi = 0; (epi < episodio) && (e < 5); epi++){
            if (arrIdSerie[epi] == stoi(row[0])){
                arrPtrSeries[cant]->setEpisodio(e, arrPtrEpisodio[epi]);
                e++;
            }
        }

        cant = cant + 1;
    }

    cout << "Se terminó de leer las series" << endl;
    fin.close();
}

//Método que sirve para mostrar todas las series y episodios correspondientes
//almacenados en el proveedor del servicio de streaming
void Series::str(){
    int contador = 1;
    for (int i = 0; i < cant; i++){
        cout << arrPtrSeries[i]->str() << endl; 
        for(int iR = 0; iR < arrPtrSeries[i]->getCantidadEpisodios(); iR++){
            cout << "Episodio: " << contador << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
            contador++;
        }
        contador = 1;
        cout << endl;
    }
}

//Método que muestra todas las series y sus episodios
//si esta tiene una calificación igual a la proporcionada
void Series::reporteConCalificacion(double cal){
    bool validar = false;
    int contador = 1;
    for (int i = 0; i < cant; i++){
        if (arrPtrSeries[i]->getCalificacion() == cal){
            cout << arrPtrSeries[i]->str() << endl;
            for (int iR = 0; iR < arrPtrSeries[i]->getCantidadEpisodios(); iR++){
                cout << "Episodio: " << contador << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
                contador++;
            }
            contador = 1;
            validar = true;
            cout << endl;
        }
    }
    //Si no hay una serie con una calificación igual a la proporcionada
    //se le deja saber al usuario con un mensaje
    if (validar == false){
        cout << "No hay serie con dicha calificacion!" << endl;
    }

}

//Método que r
void Series::reporteGenero(string genero){
    bool validar = false;
    int contador = 1;
    string temporal1;
    for (int i = 0; i < cant; i++){
        temporal1 = arrPtrSeries[i]->getGenero();
        for_each(temporal1.begin(), temporal1.end(), [](char & c){
	        c = ::tolower(c);
        });
        for_each(genero.begin(), genero.end(), [](char & c){
	        c = ::tolower(c);
        });
        if (temporal1  == genero){
            cout << arrPtrSeries[i]->str() << endl;
            for(int iR = 0; iR < arrPtrSeries[i]->getCantidadEpisodios(); iR++){
                cout << "Episodio: " << contador << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
                contador++;
            }
            contador = 1;
            validar = true;
            cout << endl;
        }
    }
    //Si no hay una película con el genero proporcionado
    //se le deja saber al usuario.
    if (validar == false){
        cout << "No hay series con ese genero!" << endl;
    }
}

//Método que guarda una serie en el arreglo de series
void Series::setPtrSerie(Serie *ptr){
    arrPtrSeries[cant++] = ptr;
}
//Método que devuelve la serie en la posición dada
Serie Series::getPtrSerie(int ser){
    Serie temporal = *arrPtrSeries[ser];
    return temporal;
}
//Método que imprime los episodios de una serie, dado el id de la serie
//y la calificación específica que deben tener los episodios
void Series::consultaEpisodiosCalificacion(string id, double cal){
    Episodio temporal;
    int contador = 1;
    bool validar1 = false, validar2 = false;
    for (int i = 0; i < cant; i++){
        if(arrPtrSeries[i]->getId() == id){
            validar1 = true;
            cout << arrPtrSeries[i]->str() << endl;
            for (int iR= 0; iR < arrPtrSeries[i]->getCantidadEpisodios(); iR++){
                if(arrPtrSeries[i]->getEpisodio(iR).getCalificacion() == cal){
                    validar2 = true;
                    cout << "Episodio: " << contador << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
                    contador++;
                }
            }
        }
    }
    //Se valida si es que hay un ID de una serie igual a la que se proporcionó
    //De igual forma, si no hay episodios con esa calificación, se le hace
    //saber al usuario
    if(validar1 == false){
        cout << "No hay serie con ese ID!" << endl;
    }
    else if(validar2 == false){
        cout << "No hay episodios de esta serie con esa calificacion!" << endl;
    }
}

//Se calcula la calificación de las series por serie
//Cada serie tendrá la calificación promedio de sus
//episodios
void Series::calcularPromedioXSerie(){
    double promedio;
    for (int i = 0; i < cant; i++){
        promedio = arrPtrSeries[i]->calPromedio();
        arrPtrSeries[i]->setCalificacion(promedio);
    }
}

//Se imprime la serie y sus episodios que tenga un iD
//igual al proporcionado por el usuario
void Series::reporteId(string iD){
    int contador, contador2 = 1;
    bool validar1 = false;
    for (int i = 0; i < cant; i++){
        contador = arrPtrSeries[i]->getCantidadEpisodios();
        if(arrPtrSeries[i]->getId() == iD){
            validar1 = true;
            cout << arrPtrSeries[i]->str() << endl;
            for(int iR = 0; iR < contador; iR++){
                cout << "Episodio: " << contador2 << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
                contador2++;
            }           
        }
    }
    //Si no hay una serie con ese ID, se le hace saber al usuario
    if(validar1 == false){
        cout << "No hay serie con ese ID!" << endl;
    }
}
//Se imprimen las series y episodios de dichas series
//que contengan una cierta cantidad de temporadas
void Series::reportePorTemporadas(int cantidad){
    bool validar = false;
    int contador;
    for (int i = 0; i < cant; i++){
        if(arrPtrSeries[i]->getCantidadTemporadas() == cantidad){
            cout << arrPtrSeries[i]->str() << endl;
            validar = true;
            for (int iR = 0; iR < arrPtrSeries[i]->getCantidadEpisodios(); iR++){
                cout << "Episodio: " << contador << " " << arrPtrSeries[i]->getEpisodio(iR).str() << endl;
                contador++;
            }
            contador = 1;
            cout << endl;
       
        }
    }
    //Si no se tiene una serie con esa cantidad de temporadas, solo
    //se muestra un mensaje al usuario indicándole esto mismo
    if(validar == false){
        cout << "No hay series con esa cantidad de temporadas!" << endl;
    }
}

//Se devuelve la cantidad de series
int Series::getCantidad(){
    return cant;
}
//Método para dar de alta un episodio de una serie determinada
void Series::darAltaEpisodio(string id){
    Episodio *epi;
    int temporada, cantidad;
    double calificacion;
    string titulo;
    bool validar = false;
    for (int i = 0; i < cant; i++){
        epi = new Episodio;
        cantidad = arrPtrSeries[i]->getCantidadEpisodios();
        if (arrPtrSeries[i]->getId() == id && cantidad < 5){
            cout << "Ingrese el Título del episodio:";
            getline(cin, titulo);
            cout << "Ingrese la temporada a la que pertenece:";
            cin >> temporada;
            cout << "Ingrese la calificación del episodio:";
            cin >> calificacion;
            epi->setTitulo(titulo);
            epi->setTemporada(temporada);
            epi->setCalificacion(calificacion);
            arrPtrSeries[i]->setEpisodio(cantidad, epi);
            validar = true;
            cout << arrPtrSeries[i]->str() << endl;
            cout << arrPtrSeries[i]->getEpisodio(cantidad).str() << endl;
        }
    }
    //Si la serie indicada ya tiene la cantidad límite de episoidos
    //o no existe una serie con ese ID, se le deja saber al usuario
    if (validar == false){
        cout << "Ya tiene el limite de episodios o el ID no es correcto!";
    }
}