/*
 * funciones.c
 *
 *  Created on: 8/4/2016
 *      Author: utnso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

void cargarLibro(Libro** p, char* nombre, char* isbn, float precio, int stock){
	Libro *nuevo = (Libro*)malloc(sizeof(Libro));
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->isbn, isbn);
	nuevo->precio = precio;
	nuevo->stock = stock;
	nuevo->sig = NULL;
	if(*p==NULL )
	{
		*p = nuevo;
	}
	else
	{
		Libro* aux = *p;
		while(aux->sig!=NULL ){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void listarLibros(Libro* p){
	Libro* aux = p;
	printf("Libro: Nombre\tISBN\tPrecio\tStock\n");
	while(aux!=NULL )
	{
		printf("Libro: %s\t%s\t%.2f\t%d\n",aux->nombre,aux->isbn,aux->precio,aux->stock);
		aux = aux->sig;
	}
}

void liberar(Libro** p)
{
   while( *p!=NULL )
   {
	   Libro* prox=(*p)->sig;
      free(*p);
      *p=prox;
   }
}

void quitarLibro(Libro** p, char* nombre)
{
	Libro* aux = *p;
	Libro* ant = NULL;
	while((aux!=NULL)&&(strcmp(aux->nombre,nombre)!=0)){
		ant=aux;
		aux=aux->sig;
	}
	if(aux!=NULL )
	{
		if(ant!=NULL )
		{
			ant->sig = aux->sig;
		}
		else
		{
			*p = aux->sig;
		}
		free(aux);
	}
}

int aumentarStock(Libro* p, char* nombre,int stock)
{
	Libro* aux=p;
	while( (aux!=NULL) && (strcmp(aux->nombre,nombre)!=0) )
	{
		aux=aux->sig;
	}
	if(aux!=NULL){
		aux->stock += stock;
	}
	return aux->stock;
}

int disminuirStock(Libro* p, char* nombre,int stock)
{
	Libro* aux=p;
	while( (aux!=NULL) && (strcmp(aux->nombre,nombre)!=0) )
	{
		aux=aux->sig;
	}
	if(aux!=NULL){
		aux->stock -= stock;
	}
	return aux->stock;
}

int getTiempoGeneracionLibros(){
	FILE* f2=fopen("biblio.conf","r+");
	char linea[50];
	fgets(linea,50,f2);
	int t = getValorFromRegistro(linea);
	fclose(f2);
	return t;
}

int getValorFromRegistro(char reg[]){
	int i = 0;
	char num[10];
	int numlen = 0;
	int len = strlen(reg);
	while(reg[i]!='='){
		i++;
	}
	i++;
	while(i<len){
		num[numlen]=reg[i];
		numlen++;
		i++;
	}
	return atoi(num);

}

void hiloImprenta(){
	int t = getTiempoGeneracionLibros();
	while(1){

		printf("Generando libros...\n");
		delay(t);
	}
}

#include <time.h>


void delay(int seconds)
{
    long pause;
    clock_t now,then;

    pause = seconds*(CLOCKS_PER_SEC/1000)*1000;
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void gestionLibros(){
	Libro* p = NULL;
	cargarLibro(&p,"Libro1","0000000000001",200.00,10);
	cargarLibro(&p,"Libro2","0000000000002",50.50,15);
	cargarLibro(&p,"Libro3","0000000000003",30.2,2);
	listarLibros(p);

	quitarLibro(&p,"Libro2");
	listarLibros(p);

	aumentarStock(p,"Libro3",20);
	disminuirStock(p,"Libro1",5);
	listarLibros(p);

	liberar(&p);
}
