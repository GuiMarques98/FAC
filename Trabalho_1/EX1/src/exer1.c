#include "../inc/exer1.h"


/*Funcao retorna a leitura dos pontos*/
Point* read_point() {
  Point *point = malloc(MAXCOOR * sizeof(point));/*Aloca dinamicamente 2 pontos*/

  for (int i = 0; i < MAXCOOR; ++i) {
	  scanf("%lf", &point[i].point_x);
	  scanf("%lf", &point[i].point_y);
  }
  return point;
}

/*Funcao escreve na tela o centro do circulo e o raio
Parametros: Centro do circulo, raio do circulo*/
void print_answer(Point center, double radius) {
	printf("Radius: %.3lf\n",radius);
	printf("Centro: %.3lf, %.3lf\n",center.point_x, center.point_y);
}


