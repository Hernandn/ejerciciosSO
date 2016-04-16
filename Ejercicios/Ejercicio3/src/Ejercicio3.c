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
#include <commons/log.h>


int main(void) {
	//creo el log
	t_log* logger = log_create("pepe.log", "TEST",true, LOG_LEVEL_INFO);

	Lista* lista = levantarArchivoEnLista("archivo.txt");
	Lista* listaFiltrada = list_filter(lista,filtroMenorDeEdad);
	list_sort(listaFiltrada,criterioOrden);
	logSaldosMenores(listaFiltrada,logger);
	grabarNuevoArchivo(listaFiltrada);
	list_destroy_and_destroy_elements(lista,freePersona);
	list_destroy(listaFiltrada);

	log_destroy(logger);

	return EXIT_SUCCESS;
}
