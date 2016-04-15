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
#include "node.h"
#include "list.h"

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

void parseFile(Archivo* file, void(*funcion)(char*)){
	while(!finDeArchivo(file)){
		char* linea = leerLinea(file);
		funcion(linea);
	}
}

void imprimirLinea(char* string){
	printf("%s\n",string);
}

void guardarRegistrosEnArchivo(Archivo* file, Lista* lista, char*(*getString)(void*)){
	int len = list_size(lista);
	int i;
	for(i=0;i<len;i++){
		char* string = getString(list_get(lista,i));
		grabarLineaEnArchivo(file,string);
	}
}

char* getNombreCompletoPersona(Persona* persona){
	char* p = (char*)malloc(sizeof(char)*(strlen(persona->nombre)+strlen(persona->apellido)+2));
	sprintf(p,"%s %s",persona->nombre,persona->apellido);
	return p;
}

void grabarLineaEnArchivo(Archivo* file, char* string){
	fprintf(file->file,"%s\n",string);
}

Persona *crearPersona(char *name, char *apellido){
	Persona *new = malloc(sizeof(Persona));
    new->nombre = strdup(name);
    new->apellido = strdup(apellido);
    return new;
}

void freePersona(Persona *self){
	free(self->nombre);
	free(self->apellido);
    free(self);
}


