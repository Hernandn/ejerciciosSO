/*
 ============================================================================
 Name        : IncrementalesSO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funciones.h"



int main(void) {

	pthread_t hilo1;
	pthread_create(&hilo1,NULL,(void*)hiloImprenta,NULL);
	pthread_t hilo2;
	pthread_create(&hilo2,NULL,(void*)gestionLibros,NULL);

	while(1){

	}






	return EXIT_SUCCESS;
}


