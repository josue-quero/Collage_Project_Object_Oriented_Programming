//Nombre: David Josué Marcial Quero
//Matrícula: A00828702

#include <iostream>
#include "Peliculas.hpp"
#include "Series.hpp"
#include <fstream>
#include <sstream>

void leerDatosPelicula(Pelicula &datosPelicula){
    //Se crean las variables que ayudarán a almacenar los
    //datos que el usuario ingrese
    int iOscares;
    string sId;
    string sTitulo;
    int iDuracion;
    string sGenero;
    double dCalificacion;

    
    //Se le irá solicitando al usuario ingresar cada uno de los
    //datos pertinentes a la clase
    cout << "**** Ingresa los datos de la Pelicula ****\n";
    cout << "Ingresa el Título:";
    getline(cin, sTitulo);
    cin.ignore();
    datosPelicula.setTitulo(sTitulo);
    
    cout << "Ingresa el iD";
    cin >> sId;
    cin.ignore();
    datosPelicula.setId(sId);

    cout << "Ingresa Duracion(min):";
    cin >> iDuracion;
    datosPelicula.setDuracion(iDuracion);

    cout << "Ingresa Genero:";
    cin >> sGenero;
    datosPelicula.setGenero(sGenero);

    cout << "Ingresa Calificacion(double):";
    cin >> dCalificacion;
    datosPelicula.setCalificacion(dCalificacion);

    cout << "Ingresa Oscares que ha ganado:";
    cin >> iOscares;
    datosPelicula.setOscares(iOscares);
    cin.ignore();
}

void leerDatosSerie(Serie &datosSerie){
    //Se crean las variables que servirán para leer los datos
    //que el usuario ingrese
    Episodio *temporal[5];
    string id, tituloSerie, tituloEpisodio, genero;
    int temporada, duracion;
    double calificacionSerie, calificacionEpisodio;

    //Se le irá solicitando al usuario ingresar cada uno de los
    //datos pertinentes a la clase
    cout << "**** Ingresa los datos de la Serie ****\n";
    cout << "Ingresa el Título de la Serie:";
    getline(cin, tituloSerie);
    datosSerie.setTitulo(tituloSerie);
    
    cout << "Ingresa el iD: ";
    cin >> id;
    cin.ignore();
    datosSerie.setId(id);

    cout << "Ingresa Duracion(min):";
    cin >> duracion;
    datosSerie.setDuracion(duracion);

    cout << "Ingrese el Género(Drama, Acción, Comedia):";
    cin >> genero;
    datosSerie.setGenero(genero);

    cout << "Ingrese la Calificación(double):";
    cin >> calificacionSerie;
    datosSerie.setCalificacion(calificacionSerie);

    //Loop para ingresar los datos de los episodios
    for (int i = 0; i < 5; i++){
        temporal[i] = new Episodio;
        cout << "Ingrese el Título del episodio de la serie:";
        getline(cin, tituloEpisodio);
        temporal[i]->setTitulo(tituloEpisodio);
        cout << "Ingrese el número de la temporada:";
        cin >> temporada;
        temporal[i]->setTemporada(temporada);
        cout << "Ingrese la calificación del episodio:";
        cin >> calificacionEpisodio;
        temporal[i]->setCalificacion(calificacionEpisodio);
        datosSerie.setEpisodio(i, temporal[i]);
    }
}

int menuPeliculas(){
    // Se le permite al usuario elegir la opción que más desea.
    // Se despliega todas las posibles acciones que el usuario puede tomar
    int iOpcion;
    cout << "\n**Películas" <<
    "\n1. Leer información de películas desde Archivo" <<
    "\n2. Dar de alta una película" <<
    "\n3. Reporte de todas las películas" <<
    "\n4. Reporte con Calificación de películas" <<
    "\n5. Reporte por género de película" <<
    "\n6. Cambiar Oscares de la Película(cantOscares):" <<
    "\n** Series" <<
    "\n10. Leer información de series desde Archivo" <<
    "\n11. Dar de alta una Serie de cinco episodios" <<
    "\n12. Reporte de todas las series" <<
    "\n13. Reporte de Series con calificación" <<
    "\n14. Reporte de Series por genero" <<
    "\n15. Añadir un episodio de una serie(idSerie)" <<
    "\n16. Calcular calificacion de Series con base a la calificacion de los episodios-sobrecarga+" <<
    "\n17. Reporte de series por cantidad de temporadas(temporadas)"
    "\n** Episodios" <<
    "\n30. Consulta todos los episodios de una serie(iDSerie):" <<
    "\n31. Consulta todos los episodios de una serie con una calificación (idSerie, calificacion):" <<
    "\nTeclea la opción:";
    cin >> iOpcion;
    return iOpcion;
}

int main() {
    // Se inicializan las variables que se irán ocupando
    // según la acción que se desee llevar a cabo
    Peliculas peliculas;
    Pelicula *ptrPelicula;
    Pelicula hola;
    Series series;
    Serie *ptrSerie;
    int iOpcion, iCal, oscares, temporada;
    string sGenero, id;
    string regresa;

    peliculas.leerArchivo();
    series.leerArchivo();
    //Se inicializa el menú con las opciones antes del ciclo centinela
    iOpcion = menuPeliculas();
    //A menos de que el usuario presione 0, el ciclo centinela continuará
    while(iOpcion != 0){
        cout << "A00828702 -> David Josue Marcial Quero" << endl;
        switch (iOpcion) {
            case 1:
                //Se leen todas las películas que están dentro del archivo csv
                peliculas.leerArchivo();
                break;
            case 2:
                //Se puede dar de alta, una película a la vez con input
                //directo del usuario
                ptrPelicula = new Pelicula();
                leerDatosPelicula(*ptrPelicula);
                peliculas.setPtrPeliculas(ptrPelicula);
                cout << ptrPelicula->str() << endl; //borrar
                break;
            case 3:
                //Se muestran todas las películas
                peliculas.str();
                break;
            case 4:
                //Se mostrarán solo las películas que tengan una determinada
                //calificación
                cout << "Ingresa la calificación:";
                cin >> iCal;
                peliculas.reporteConCalificacion(iCal);
                break;
            case 5:
                //Se ingresa el género y se busca las películas que coincidan
                cout << "Ingresa el Genero:";
                cin >> sGenero;
                peliculas.reporteGenero(sGenero);
                break;
            case 6:
                //Cambiar la cantidad de Oscares de una película, primero se da el id
                int caliTemp;
                cout << "Ingrese el iD de la película:";
                cin >> id;
                cin.ignore();
                cout << "Ingrese la cantidad de oscares:";
                cin >> oscares;
                peliculas.setCambioOscar(id, oscares);
                hola = peliculas.getPelicula(id);
                cout << hola.str();
                break;
            case 10:
                //Se lee el archivo csv que contiene todas las series
                series.leerArchivo();
                break;
            case 11:
                //Se le permiete al usuario crear una serie con
                //el input directo del mismo
                ptrSerie = new Serie();
                leerDatosSerie(*ptrSerie);
                series.setPtrSerie(ptrSerie);
                cout << ptrSerie->str() << endl;
                break;
            case 12:
                //Se muestran todas las series(sin sus episodios)
                series.str();
                break;
            case 13:
                //Se mostrarán solo las series que coincidan
                //exactamente con la calificación dada y sus episodios
                cout << "Ingresa la calificación:";
                cin >> iCal;
                series.reporteConCalificacion(iCal);
                break;
            case 14:
                //Se mostrarán solo las series que coincidan
                //con el genero indicado por el usuario
                cout << "Ingresa el Genero:";
                cin >> sGenero;
                series.reporteGenero(sGenero);
                break;
            case 15:
                //Se da la posibilidad de dar de alta un episodio
                //de una serie ya existente
                cout << "Ingrese el iD de la serie:";
                cin >> id;
                cin.ignore();
                series.darAltaEpisodio(id);
                break;
            case 16:
                //Se calcula el promedio total de una serie,
                //con base en las calificaciones independientes de los
                //episodios.
                series.calcularPromedioXSerie();
                series.str();
                break;
            case 17:
                // Según lo entendí, esta opción te deja ver solo las 
                //series que tienen cierta cantidad de temporadas.
                cout << "Ingrese la cantidad de temporadas que la serie debe tener:";
                cin >> temporada;
                series.reportePorTemporadas(temporada);
                break;
            case 30:
                //Se muestran todos los episodios de una serie en 
                //concreto
                cout << "Ingrese el ID de la serie:";
                cin >> id;
                cin.ignore();
                series.reporteId(id);
                break;
            case 31:
                //Se muestran todos los episodios de una serie en
                //concreto, si tienen una cierta calificación
                cout << "Ingrese el ID de la serie:";
                cin >> id;
                cin.ignore();
                cout << "Ingrese la calificacion:";
                cin >> iCal;
                series.consultaEpisodiosCalificacion(id, iCal);
                break;
            default:
                //Se cierra el ciclo
                cout << "Opcion invalida" << endl;
                break;
        }
        iOpcion = menuPeliculas();
    }
    cout << "Gracias por su visita";
    return 0;
}
