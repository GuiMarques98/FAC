#include "../inc/tipes.h"
#include "../inc/geoarith.h"
#include "../inc/exer1.h"
#include <math.h>

int main(int argc, char const *argv[]) {
	Point *point = read_point(), center;
  double radius;

  if(is_circle(point)){
  	center = find_center(point);
    radius = find_radius(point[0], center);
  	print_answer(center, radius);	
  }else{
  	printf("Circulo nao viavel.\n");
  }
  
	return 0;
}
