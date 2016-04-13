/*
 * funciones.h
 *
 *  Created on: 12/4/2016
 *      Author: utnso
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct Archivo
{
	FILE* file;
} Archivo;

#endif /* FUNCIONES_H_ */

Archivo* abrirArchivoRead(char* ruta);
Archivo* abrirArchivoWrite(char* ruta);
Archivo* abrirArchivoAppend(char* ruta);
void cerrarArchivo(Archivo** archivo);
int finDeArchivo(Archivo* archivo);
char* leerLinea(Archivo* archivo);
