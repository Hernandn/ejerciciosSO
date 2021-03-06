/*
 * funciones.h
 *
 *  Created on: 12/4/2016
 *      Author: utnso
 */
#include "node.h"
#include "list.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct Archivo
{
	FILE* file;
} Archivo;

typedef struct Persona {
	char* nombre;
	char* apellido;
} Persona;

#endif /* FUNCIONES_H_ */

Archivo* abrirArchivoRead(char* ruta);
Archivo* abrirArchivoWrite(char* ruta);
Archivo* abrirArchivoAppend(char* ruta);
void cerrarArchivo(Archivo** archivo);
int finDeArchivo(Archivo* archivo);
char* leerLinea(Archivo* archivo);
void parseFile(Archivo* file, void(*funcion)(char*));
void imprimirLinea(char* string);
void guardarRegistrosEnArchivo(Archivo* file, Lista* lista, char*(*getString)(void*));
void grabarLineaEnArchivo(Archivo* file, char* string);
Persona *crearPersona(char *name, char *apellido);
void freePersona(Persona *self);
char* getNombreCompletoPersona(Persona* persona);
