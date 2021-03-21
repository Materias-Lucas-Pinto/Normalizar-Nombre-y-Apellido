#ifndef NORMALIZAR_H_INCLUDED
#define NORMALIZAR_H_INCLUDED
#include<stdio.h>
#include<string.h>
typedef struct{

char*ini;
char*fin;
int hay_pal;

}t_palabra;


void ingresar_cadena(char* cad_anorm);
void normalizarcad(const char *cad_anorm,char *cad_norm);
char *leer_palabra(char *cad_anorm_act, t_palabra *pal_orig);
char *escribir_palabra(char *cad_norm, const t_palabra *pal_orig,t_palabra *pal_dest);
int existe_palabra(const t_palabra *pal_orig);
int es_letra(char car);
 void a_titulo(const t_palabra *pal_dest);
 char a_mayuscula(char car);
 char a_minuscula(char car);

#endif // NORMALIZAR_H_INCLUDED
