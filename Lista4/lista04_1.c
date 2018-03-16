#include <stdio.h>
#define PI 3.14

typedef struct {
	int raio;
	int x, y;
} Circulo;

void criaCirculo(int x, int y, int raio, Circulo *c);
float areaCirculo(Circulo c); 
float perimetroCirculo(Circulo c);

int main() {
	
	Circulo c1, c2;
	int ray, ray2;
	float areaC1, areaC2;
	float per1, per2;
	
	printf("Raio um\n");
	scanf("%d", &ray);
	printf("Raio 2\n");
	scanf("%d", &ray2);
	
	criaCirculo(0, 0, ray, &c1);
	criaCirculo(10, 30, ray2, &c2);
	
	areaC1 = areaCirculo(c1);
	areaC2 = areaCirculo(c2);
	
	per1 = perimetroCirculo(c1);
	per2 = perimetroCirculo(c2);
	
	if(areaC1 > areaC2) {
		printf("Perimetro = %.2f\n", per1);
	}
	
	else {
		printf("Perimetro = %.2f\n", per2);
		
	}
	
	return 0;
}


void criaCirculo(int x, int y, int raio, Circulo *c) {
	c -> x = x;
	c -> y = y;
	c -> raio = raio;
}

float areaCirculo(Circulo c) {
	float area;
	
	area = PI * ((c.raio) * (c.raio));
	
	return area;
}

float perimetroCirculo(Circulo c) {
	float perimetro;
	
	perimetro = (2 * PI) * c.raio;
	return perimetro;
}

