/*
 ============================================================================
 Name        : Ejercicio3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
#include "list.h"
#include "node.h"

int main(void) {
	Lista* lista = levantarArchivoEnLista("archivo.txt");
	list_sort(lista,criterioOrden);
	Lista* listaFiltrada = list_filter(lista,filtroMenorDeEdad);
	grabarNuevoArchivo(listaFiltrada);
	list_destroy_and_destroy_elements(listaFiltrada,freePersona);
	list_destroy_and_destroy_elements(lista,freePersona);
	return EXIT_SUCCESS;
}
