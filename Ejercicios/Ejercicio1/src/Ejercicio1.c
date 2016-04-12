/*
 ============================================================================
 Name        : Ejercicio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_concat(const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char*);


int main(void) {
	printf("string_concat:\n");
	char* nombre = "Ritchie";
	char* palabra = string_concat("Hola ",nombre);
	printf("%s",palabra);

	printf("\nstring_concat_dinamyc:\n");
	char* res;
	string_concat_dinamyc("Hola ",nombre,res);
	printf("%s",res);

	return EXIT_SUCCESS;
}

char* string_concat(const char* a, const char* b){
	char* p = (char*)malloc(sizeof(char)*(strlen(a)+strlen(b)+1));
	strcat(p,a);
	strcat(p,b);
	return p;
}

void string_concat_dinamyc(const char* a, const char* b, char* res){
	res = (char*)malloc(sizeof(char)*(strlen(a)+strlen(b)+1));
	strcpy(res,a);
	strcat(res,b);
}

