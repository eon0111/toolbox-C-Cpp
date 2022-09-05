/**
 * @author Noe Ruano Gutierrez
 * @date 08-2022
 */ 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>    // para la deteccion de tecla pulsada
#include <stdlib.h>

#define LONGITUD_LINEA 80

using namespace std;

/**
 * Funcion que retorna la longitud de una palabra contenida en una
 * cadena.
 * @param texto la cadena donde se encuentra la palabra a "medir"
 * @param comienzo la posicion de la primera letra de la palabra
 * dentro de la cadena
 * @returns la longitud de la palabra
 */ 
int longitudPalabra (string &texto, int comienzo) {
    char caracter = texto[comienzo];
    int longitud = 0;

    while (caracter != ' ' && caracter != '\0') {
        longitud++;
        caracter = texto[comienzo + longitud];
    }

    return longitud;
}

/**
 * Funcion que retorna el número de caracteres contenidos en una linea
 * con una longitud maxima de 80 caracteres, y en la que hay palabras
 * enteras.
 * @param texto el texto sobre el que trabajar
 * @param inicio el indice del caracter a partir del cual debe realizarse
 * el conteo
 * @returns el numero de caracteres contenidos en la linea
 */ 
int longitudLinea(string &texto, int inicio) {
    int i = 0;
    int ultimaLongitud;

    while (i <= LONGITUD_LINEA) {
        ultimaLongitud = longitudPalabra(texto, inicio + i);
        i += ultimaLongitud;

        if (texto[i + inicio] == '\0' || (texto[i + inicio] == ' ' && texto[i + inicio + 1] == '\0')) { // comprobacion para la ultima linea
            return i;
        }
        
        i++;    // para que no se quede pillado mirando la longitud de un espacio
    }

    return i - ultimaLongitud - 2;  // -2 para que no cuente el ultimo espacio, y el espacio de la ultima iteracion
}

void imprimeCadena(string &texto, int inicio, int longitud) {
    for (int i = inicio; i < inicio + longitud; i++) cout << texto[i];
}

void imprimeEspacios(int numEspacios) {
    for (int i = 0; i < numEspacios; i++) cout << ' ';
}

boolean contieneNulo(string &texto, int inicio, int fin) {
    for (int i = inicio; i <= fin; i++) {
        if (texto[i] == '\0') return true;
    }
    return false;
}

/**
 * Procedimiento que realiza el centrado del texto.
 * @param texto el texto a centrar en la salida del terminal
 */ 
void escribeCentrado(string &texto) {
    boolean fin = false;
    int longitud;
    int recorrido = 0;

    while (!fin) {
        longitud = longitudLinea(texto, recorrido);
        imprimeEspacios(LONGITUD_LINEA - longitud / 2);
        imprimeCadena(texto, recorrido, longitud);
        if (contieneNulo(texto, recorrido, recorrido + longitud)) fin = true;
        recorrido += longitud;
        cout << "\n";
    }
}

/**
 * Programa principal que genera un texto centrado.
 */ 
int main(int argc, char *argv[]) {
    string miString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis ultricies eros leo. Morbi vel mauris et justo scelerisque egestas. Donec vitae erat vitae odio egestas maximus. Nunc mattis mattis felis posuere tempor. Nam interdum nulla et sapien sollicitudin vehicula. Etiam ultricies tempor diam, id posuere magna feugiat quis. Curabitur dictum vitae velit sit amet blandit. Aenean justo libero, fermentum et purus eu, fermentum venenatis lacus. Morbi in diam vel neque sollicitudin commodo quis quis ex. Suspendisse lobortis et felis sit amet suscipit. Duis nec vulputate orci. Cras eget magna sit amet ligula vehicula sollicitudin venenatis nec elit. Fusce malesuada, eros nec ultricies commodo, erat eros elementum lacus, quis ultrices diam nulla vitae eros. Maecenas id dolor id eros varius tellus.";
    escribeCentrado(miString);
    return 0;
}