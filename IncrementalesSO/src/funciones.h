/*
 * funciones.h
 *
 *  Created on: 8/4/2016
 *      Author: utnso
 */

#ifndef SRC_FUNCIONES_H_
#define SRC_FUNCIONES_H_

typedef struct Libro
{
   char nombre[20]; // valor que contiene el nodo
   char isbn[14];
   float precio;
   int stock;

   struct Libro* sig; // referencia al siguiente nodo
} Libro;

#endif /* SRC_FUNCIONES_H_ */

void cargarLibro(Libro** p, char* nombre, char* isbn, float precio, int stock);
void listarLibros(Libro* p);
void liberar(Libro** p);
void quitarLibro(Libro** p, char* nombre);
int aumentarStock(Libro* p, char* nombre,int stock);
int disminuirStock(Libro* p, char* nombre,int stock);
int getTiempoGeneracionLibros();
int getValorFromRegistro(char reg[]);
void hiloImprenta();
void gestionLibros();
void delay(int seconds);
