/*
 ============================================================================
 Name        : Prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
   int valor; // valor que contiene el nodo
   struct Nodo* sig; // referencia al siguiente nodo
} Nodo;

void agregar(Nodo**, int);
void mostrar(Nodo*);
void liberar(Nodo**);
Nodo* buscar(Nodo*,int);
void eliminar(Nodo**, int);
Nodo* insertarOrdenado(Nodo** p, int v);
Nodo* buscarEInsertarOrdenado(Nodo** p, int v, int* enc);
void push(Nodo** p, int v);
int pop(Nodo** p);
int pilaVacia(Nodo* p);
void encolar(Nodo** p, int v);
int desencolar(Nodo** p);
int colaVacia(Nodo* p);


int main(void)
{
   Nodo* p = NULL;

   agregar(&p,5);
   agregar(&p,8);
   agregar(&p,7);
   agregar(&p,7);
   eliminar(&p,7);
   agregar(&p,3);
   agregar(&p,9);

   Nodo* n = buscar(p,3);
   if(n==NULL){
      printf("No esta %d\n",3);
   } else {
      printf("Esta %d\n",n->valor);
   }
   mostrar(p);
   liberar(&p);
   Nodo* m = buscar(p,3);
   if(m==NULL){
      printf("No esta %d\n",3);
   } else {
      printf("Esta %d\n",m->valor);
   }
   //ARCHIVOS
   printf("ARCHIVOS\n\n");

   //escribir lineas
   FILE* f1=fopen("archivo.txt","w+");
   char linea[100];
   printf("-->");
   gets(linea);
   while( strcmp(linea,"FIN") )
   {
      fprintf(f1,"%s\n",linea);

      printf("-->");
      gets(linea);
   }
   fclose(f1);

   //leer lineas
   FILE* f2=fopen("archivo.txt","r+");
   char linea2[100];
   // leo una linea
   fgets(linea2,100,f2);
   while( !feof(f2) )
   {
      printf("--> %s",linea2);
      // leo la siguiente linea
      fgets(linea2,100,f2);
   }
   fclose(f2);

   //leer registro con formato (comas)
   FILE* arch=fopen("archivo.txt","r+");
   char nombre[11];
   float altura;
   int edad;
   fscanf(arch,"%s,%f,%d",nombre,&altura,&edad);
   while( !feof(arch) )
   {
      printf("%s, %.2f, %d\n",nombre,altura,edad);
      fscanf(arch,"%s,%f,%d",nombre,&altura,&edad);
   }
   fclose(arch);

   return 0;
}

void agregar(Nodo** p, int v){
// creamos el nuevo nodo
   Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
   nuevo->valor = v;
   nuevo->sig = NULL;
// si la lista esta vacia entonces hacemos que p apunte al nuevo nodo
   if(*p==NULL )
   {
      *p = nuevo;
   }
   else
   {
      Nodo* aux = *p;
// recorremos la lista hasta llegar al ultimo nodo
      while(aux->sig!=NULL )
      {
// avanzamos a aux al proximo nodo
         aux = aux->sig;
      }
// como aux apunta al ultimo entonces su siguiente sera el nuevo nodo
      aux->sig = nuevo;
   }
}

void mostrar(Nodo* p){
   Nodo* aux = p;
   while(aux!=NULL )
   {
      printf("Nodo valor: %d\n",aux->valor);
      aux = aux->sig;
   }
}

void liberar(Nodo** p)
{
   while( *p!=NULL )
   {
      Nodo* prox=(*p)->sig;
      free(*p);
      *p=prox;
   }
}

Nodo* buscar(Nodo* p,int v)
{
   Nodo* aux=p;
   while( (aux!=NULL) && (aux->valor!=v) )
   {
      aux=aux->sig;
   }
   return aux;
}

void eliminar(Nodo** p, int v)
{
   Nodo* aux = *p;
   Nodo* ant = NULL;
   while((aux!=NULL )&& (aux->valor!=v) ){
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

Nodo* insertarOrdenado(Nodo** p, int v)
{
   Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
   nuevo->valor = v;
   nuevo->sig = NULL;
   Nodo* aux = *p;
   Nodo* ant = NULL;
   while((aux!=NULL )&& (aux->valor <= v) ){
   ant = aux;
   aux = aux->sig;
}
   if(ant==NULL )
   {
      *p = nuevo;
   }
   else
   {
      ant->sig = nuevo;
   }
   nuevo->sig = aux;
   return nuevo;
}

Nodo* buscarEInsertarOrdenado(Nodo** p, int v, int* enc)
{
   Nodo* r = buscar(*p,v);
   *enc = r!=NULL;
   if(!*enc)
   {
      r = insertarOrdenado(p,v);
   }
   return r;
}

//PILAS
void push(Nodo** p, int v)
{
   Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
   nuevo->valor = v;
   nuevo->sig = *p;
   *p = nuevo;
}
int pop(Nodo** p)
{
   Nodo* aux = *p;
   int ret = aux->valor;
   *p = aux->sig;
   free(aux);
   return ret;
}
int pilaVacia(Nodo* p)
{
   return p==NULL;
}


//COLAS
void encolar(Nodo** p, int v)
{
   Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
   nuevo->valor = v;
   if(*p==NULL )
   {
      nuevo->sig = nuevo;
   }
   else
   {
      nuevo->sig = (*p)->sig;
      (*p)->sig = nuevo;
   }
   *p = nuevo;
}
int desencolar(Nodo** p)
{
   int ret = (*p)->sig->valor;
   if(*p==(*p)->sig)
   {
      free(*p);
      *p = NULL;
   }
   else
   {
      Nodo* aux = (*p)->sig;
      (*p)->sig = aux->sig;
      free(aux);
   }
   return ret;
}
int colaVacia(Nodo* p)
{
   return p==NULL;
}
