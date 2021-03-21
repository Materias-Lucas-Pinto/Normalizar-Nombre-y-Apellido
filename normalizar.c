#include"normalizar.h"
#include<stdio.h>
#include<string.h>

void ingresar_cadena(char *cad_anorm){

puts("cadena a normalizar:");
fflush(stdin);
gets(cad_anorm);

}

void normalizarcad(const char *cad_anorm,char *cad_norm){

t_palabra pal_orig,pal_dest;

char *cad_anorm_act=cad_anorm;
char *cad_norm_act=cad_norm;

cad_anorm_act=leer_palabra(cad_anorm_act,&pal_orig);

while(existe_palabra(&pal_orig)){

    cad_norm_act=escribir_palabra(cad_norm_act,&pal_orig,&pal_dest);

    *cad_norm_act= ' ';
    cad_norm_act++;

    a_titulo(&pal_dest);
    cad_anorm_act=leer_palabra(cad_anorm_act,&pal_orig);

}

*(cad_norm_act-1)='\0';

}

char *leer_palabra(char *cad_anorm_act, t_palabra *pal_orig){

while(*cad_anorm_act&& !es_letra(*cad_anorm_act))

    cad_anorm_act++;


if(*cad_anorm_act=='\0'){

    pal_orig->hay_pal=0;
    return cad_anorm_act;
}

pal_orig->hay_pal=1;
pal_orig->ini=cad_anorm_act;


while(*cad_anorm_act&& es_letra(*cad_anorm_act))

    cad_anorm_act++;

pal_orig->fin=cad_anorm_act-1;

return cad_anorm_act;

}

char *escribir_palabra(char *cad_norm, const t_palabra *pal_orig,t_palabra *pal_dest){

char *cad_norm_act =pal_orig->ini;

pal_dest->ini=cad_norm;

while(cad_norm_act<=pal_orig->fin){

    *cad_norm=*cad_norm_act;
    cad_norm++;
    cad_norm_act++;
}

pal_dest->fin=cad_norm-1;

return cad_norm;
}

int existe_palabra(const t_palabra *pal_orig)
{

if(pal_orig->hay_pal==1)

return  1;

else
    return 0;
}


int es_letra(char car){

if((car>='a'&&car<='z')||(car>='A'&&car<='Z'))
    return 1;

    else
        return 0;
}

 void a_titulo(const t_palabra *pal_dest){


char *pal_dest_act=pal_dest->ini+1;

*pal_dest->ini=a_mayuscula(*(pal_dest->ini));

while(pal_dest_act<=pal_dest->fin){

    *pal_dest_act=a_minuscula(*pal_dest_act);
    pal_dest_act++;
}

 }



char a_mayuscula(char car){

 if(car>='a'&&car<='z')

    return car-('a'-'A');

    else
        return car;

 }


 char a_minuscula(char car){

 if(car>='A'&&car<='Z')

    return car-('A'-'a');

    else
        return car;

 }
