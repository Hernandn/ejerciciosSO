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
#include "node.h"
#include "list.h"


int main(void) {

	Archivo* file = abrirArchivoRead("archivo.txt");
	parseFile(file,imprimirLinea);
	cerrarArchivo(&file);

	Archivo* file2 = abrirArchivoWrite("archivo2.txt");
	Lista* lista = list_create();
	Persona* p1 = crearPersona("Carlos","Perez");
	Persona* p2 = crearPersona("Jose","Fernandez");
	Persona* p3 = crearPersona("Luis","Perez");
	list_add(lista,p1);
	list_add(lista,p2);
	list_add(lista,p3);
	guardarRegistrosEnArchivo(file2,lista,getNombreCompletoPersona);
	cerrarArchivo(&file2);
	list_destroy_and_destroy_elements(lista,freePersona);

	return EXIT_SUCCESS;
}
