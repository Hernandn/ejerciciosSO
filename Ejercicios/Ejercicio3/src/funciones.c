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
	//fscanf(archivo->file,"%s",p);
	fgets(p,100,archivo->file);
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
/*
char* getNombreCompletoPersona(Persona* persona){
	char* p = (char*)malloc(sizeof(char)*(strlen(persona->nombre)+strlen(persona->apellido)+2));
	sprintf(p,"%s %s",persona->nombre,persona->apellido);
	return p;
}*/

void grabarLineaEnArchivo(Archivo* file, char* string){
	fprintf(file->file,"%s\n",string);
}

Persona* crearPersona(char *registro){
	Persona *new = malloc(sizeof(Persona));
	char** strings = string_split(registro,";");
    new->region = strdup(strings[0]);
    new->nombreApellido = strdup(strings[1]);
    new->edad = atoi(strings[2]);
    new->telefono = strdup(strings[3]);
    new->dni = strdup(strings[4]);
    new->saldo = atoi(strings[5]);
    return new;
}

void freePersona(Persona *self){
	free(self->region);
	free(self->nombreApellido);
	free(self->telefono);
	free(self->dni);
    free(self);
}

Lista* levantarArchivoEnLista(char* path){
	Archivo* file = abrirArchivoRead(path);
	Lista* lista = list_create();
	while(!finDeArchivo(file)){
		char* registro = leerLinea(file);
		Persona* p = crearPersona(registro);
		list_add(lista,p);
	}
	cerrarArchivo(&file);
	return lista;
}

bool criterioOrden(Persona* p1,Persona* p2){
	return string_equals_ignore_case(p1->region,p2->region)?(p1->edad<p2->edad):strcmp(p1->region,p2->region);
}

void grabarNuevoArchivo(Lista* lista){
	Archivo* file = abrirArchivoWrite("archivoOrdenado.txt");
	int size = list_size(lista);
	int i;
	for(i=0;i<size;i++){
		char* string = string_new();
		Persona* p = list_get(lista,i);
		grabarLineaEnArchivo(file,getNuevoStringParaGrabar(p));
	}
	cerrarArchivo(&file);
}

bool filtroMenorDeEdad(Persona* p){
	return p->edad>=18;
}

char* getNuevoStringParaGrabar(Persona* p){
	char* nombreCortado;
	if(strlen(p->nombreApellido)>30){
		nombreCortado = substring(p->nombreApellido,0,30);
	} else {
		nombreCortado = p->nombreApellido;
	}
	char* punt = (char*)malloc(sizeof(char)*120);
	sprintf(punt,"%s | %d | %s | %s | %s",p->region,p->edad,p->dni,nombreCortado,p->telefono);
	return punt;
}

char* substring(char* s,int desde,int hasta)
{
	int n = hasta-desde;
	char* ret = (char*) malloc(sizeof(char)*(n+1));
	int j=0;
	int i;
	for(i=desde; i<hasta; i++){
		ret[j]=s[i];
		j=j+1;
	}
	ret[j]='\0';
	return ret;
}


