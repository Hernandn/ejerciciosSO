/*
 ============================================================================
 Name        : Ejercicio2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	Archivo* file = abrirArchivoRead("archivo.txt");

	char* pepe = leerLinea(file);
	printf("%s",pepe);

	cerrarArchivo(&file);

	return EXIT_SUCCESS;
}
