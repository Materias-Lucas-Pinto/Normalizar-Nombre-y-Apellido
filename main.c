#include <stdio.h>
#include <stdlib.h>
#include"normalizar.h"
#include<string.h>
int main()
{

char cad_anorm[201];
char cad_norm[201];

ingresar_cadena(cad_anorm);

normalizarcad(cad_anorm,cad_norm);

puts(cad_norm);
    return 0;
}
