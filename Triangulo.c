#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float altura, base, area;
  printf("Programa para resolver el area de un triangulo \n");
  printf("Introduzca la base: \n");
  scanf("%f", &base);
  printf("Introduzca la altura: \n");
  scanf("%f", &altura);
  area = (base * altura)/2;
  printf("El area del triangulo es %f", area);
  return 0;

}
