#include "../inc/geoarith.h"

/*Funcao que retorna se e um circulo ou nao
Parametros: Um vetor com os 3 pontos dados pelo usuario*/
BOOL is_circle(Point *point) {
	double *length= calloc(MAXCOOR, sizeof(double)), temp1, temp2;
	int i;


	/*Neste for sao feitos calculos de distancia de um ponto para o outro
	E ultilizado a formula de pitafuras a^2 + b^2 = h(hipotenusa)*/
	for (i = 0; i < MAXCOOR; ++i)
	{
		if(i != 2){
			temp1 = pow(point[i].point_x - point[i+1].point_x, 2);
			temp2 = pow(point[i].point_y - point[i+1].point_y, 2);
			length[i] = sqrt(temp1 + temp2);
		}else {
			temp1 = pow(point[2].point_x - point[0].point_x, 2);
			temp2 = pow(point[2].point_y - point[0].point_y, 2);
			length[2] = sqrt(temp1 + temp2);
		}
	}
	/*Compara todas as distancias e retorna falso se uma for maior ou igual a soma das outras duas*/
	if(length[0] + length[1] <= length[2] || length[0]+length[2] <= length[1] || length[1]+ length[2] <= length[0])
		return FALSE;

	return TRUE;
}

/*Funcao que retorna a linha/reta que equivale a mediatriz dos dos pontos
Parametro: Dois pontos*/
Line determinate_mediatriz(Point q, Point p) {
	Line mediatriz;
  mediatriz.a = 2*(q.point_x - p.point_x);
  mediatriz.b = 2*(q.point_y - p.point_y);
  mediatriz.c = (p.point_x * p.point_x + p.point_y * p.point_y) - (q.point_x * q.point_x + q.point_y * q.point_y);
  return mediatriz;
}

/*Funcao retorna um ponto que e o centro do circulo
Parametros: Os pontos lidos*/
Point find_center(Point *point) {
	Line mediatriz[MAXCOOR-1];
	int i;
	/*Sao encontradas duas mediatrizes, como aqui se tem a certeza que e um triangulo
	a interseccao entre as duas mediatrizes forma o centro do circulo*/
	for (i = 0; i < MAXCOOR-1; ++i)	
		mediatriz[i] = determinate_mediatriz(point[i], point[i+1]);
	
	return find_intersection(mediatriz[0], mediatriz[1]);
}


/*Funcao retorna o ponto de interserccao entre duas retas
Parametros: Duas linhas/retas*/
Point find_intersection(Line p, Line q) {
	double determinant = p.a * q.b - p.b * q.a;/*Determinante de uma matriz 2x2*/
	Point intersection;

	intersection.point_x = (-p.c * q.b + q.c * p.b) / determinant;
	intersection.point_y = (-q.c * p.a + p.c * q.a) / determinant;
	return intersection;
}
/*Funcao retorna o raio do circulo
Parametros: Um dos pontos informados, centro do circulo*/
double find_radius(Point point, Point center) {
	double temp1 = pow(point.point_x - center.point_x, 2);
	double temp2 = pow(point.point_y - center.point_y, 2);
	return sqrt(temp1+temp2);
}
