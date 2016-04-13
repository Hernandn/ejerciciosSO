/*
 * funciones.c
 *
 *  Created on: 12/4/2016
 *      Author: utnso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

Archivo* abrirArchivoRead(char* ruta){
	Archivo* archivo = (Archivo*)malloc(sizeof(Archivo));
	archivo->file = fopen(ruta,"r+");
	return archivo;
}

Archivo* abrirArchivoWrite(char* ruta){
	Archivo* archivo = (Archivo*)malloc(sizeof(Archivo));
	archivo->file = fopen(ruta,"w+");
	return archivo;
}

Archivo* abrirArchivoAppend(char* ruta){
	Archivo* archivo = (Archivo*)malloc(sizeof(Archivo));
	archivo->file = fopen(ruta,"a+");
	return archivo;
}

void cerrarArchivo(Archivo** archivo){
	fclose((*archivo)->file);
}

int finDeArchivo(Archivo* archivo){
	return feof(archivo->file);
}

char* leerLinea(Archivo* archivo){
	char* p = (char*)malloc(sizeof(char)*100);
	fscanf(archivo->file,"%s",p);
	return p;
}
