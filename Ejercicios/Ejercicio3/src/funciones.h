/*
 * funciones.h
 *
 *  Created on: 12/4/2016
 *      Author: utnso
 */
#include "node.h"
#include "list.h"
#include <commons/log.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct Archivo
{
	FILE* file;
} Archivo;

typedef struct Persona {
	char* region;
	char* nombreApellido;
	int edad;
	char* telefono;
	char* dni;
	int saldo;
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
Persona *crearPersona(char *);
void freePersona(Persona *self);
char* getNombreCompletoPersona(Persona* persona);
Lista* levantarArchivoEnLista(char* path);
bool criterioOrden(Persona* p1,Persona* p2);
void grabarNuevoArchivo(Lista* lista);
bool filtroMenorDeEdad(Persona* p);
char* getNuevoStringParaGrabar(Persona* p);
char* substring(char* s,int desde,int hasta);
void logSaldosMenores(Lista* list, t_log* logger);
void esSaldoMenor(Persona* p);
