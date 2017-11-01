#ifndef TYPES_H
#define TYPES_H

/*Sao definidos aqui algumas constantes booleanas e o o tipo BOOL com o define*/
#define TRUE 1
#define FALSE 0
#define BOOL int
/*Constante da quantidade de pontos*/
#define MAXCOOR 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Defini um ponto no plano cartesiano (x,y)*/
typedef struct {
  double point_x;
  double point_y;
}Point;

/*Define uma linha/reta como sua equacao geral ax+bx+c=0*/
typedef struct
{
	double a, b, c;
}Line;

#endif
