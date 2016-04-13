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
void string_concat_dinamyc(const char*, const char*, char**);
void mail_split(const char* mail, char** user, char** dominio);
char* substring(char* s,int desde,int hasta);


int main(void) {
	printf("string_concat:\n");
		char* nombre = "Ritchie";
		char* palabra = string_concat("Hola ",nombre);
		printf("%s",palabra);

	printf("\nstring_concat_dinamyc:\n");
		char* res;
		string_concat_dinamyc("Hola ",nombre,&res);
		printf("%s",res);

	printf("\nmail_split:\n");
		char* mail = "ritchie@ansic.com.ar";
		char* user, dominio;
		printf("Mail: %s",mail);
		mail_split(mail, &user, &dominio);

		//printf("%s",dominio);
		//printf("Mail: %s , Usuario: %s , Dominio: %s",mail,user,dominio);

	return EXIT_SUCCESS;
}

char* string_concat(const char* a, const char* b){
	char* p = (char*)malloc(sizeof(char)*(strlen(a)+strlen(b)+1));
	strcat(p,a);
	strcat(p,b);
	return p;
}

void string_concat_dinamyc(const char* a, const char* b, char** res){
	*res = (char*)malloc(sizeof(char)*(strlen(a)+strlen(b)+1));
	strcat(*res,a);
	strcat(*res,b);
}

void mail_split(const char* mail, char** user, char** dominio){
	char* aux = mail;
	int i = 0;
	while(*aux!='@'){
		aux++;
		i++;
	}
	*user = substring(mail,0,i);
	printf("\nUser: %s",*user);
	*dominio = substring(mail,i+1,strlen(mail));
	printf("\nDominio: %s",*dominio);
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

