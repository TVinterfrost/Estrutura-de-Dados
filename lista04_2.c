#include <stdio.h>
#include <math.h>

typedef struct {
	int x, y, raio;
} Circulo;


void criaCirculo(int x, int y, int raio, Circulo *c);
void exibeCirculo(Circulo c);
void moveCirculo(int xMove, int yMove, Circulo *c);
int comparaCirculos(Circulo c1, Circulo c2);
int estaDentroDoCirculo(Circulo c, int x, int y);


int main() {
	
	int x, y, comparison; 
	float raio1, raio2;
	Circulo c1, c2;
	
	printf("Circulo 1\n");
	printf("Raio: ");
	scanf("%f", &raio1);
	printf("X: ");
	scanf("%d", &x);
	printf("Ÿ: ");
	scanf("%d", &y);
	criaCirculo(x, y, raio1, &c1);
	
	printf("Circulo 2\n");
	printf("Raio: ");
	scanf("%f", &raio2);
	printf("X2: ");
	scanf("%d", &x);
	printf("Y2: ");
	scanf("%d", &y);
	criaCirculo(x, y, raio2, &c2);

	comparison = comparaCirculos(c1, c2);
	if(comparison == 0) {
		printf("Sao iguais\n");
	}
	
	if(comparison == 1) {
		printf("Ö primeiro circulo e maior\n");
	}
	
	else {
		printf("Ö segundo circulo e maior\n");
	}
	
	exibeCirculo(c1);
	exibeCirculo(c2);
	
	printf("Insira X: ");
	scanf("%d", &x);
	
	printf("Ïnsira Y: ");
	scanf("%d", &y);
	
	moveCirculo(x, y, &c2);
	exibeCirculo(c2);
return 0;
}

void criaCirculo(int x, int y, int raio, Circulo *c) {
	c->x = x;
	c->y = y;
	c->raio = raio;
}


void exibeCirculo(Circulo c) {
	printf("X = %d, Y = %d, Raio = %d\n", c.x, c.y, c.raio);
}

void moveCirculo(int xMove, int yMove, Circulo *c) {
	c->x = c->x + xMove;
	c->y = c->y + yMove;
}

int comparaCirculos(Circulo c1, Circulo c2) {
	if(c1.raio == c2.raio) {
		return 0;
	}
	
	if (c1.raio > c2.raio) {
		return 1;
	}
	
	else {
		return -1;
	}
}

int estaDentroDoCirculo(Circulo c, int x, int y) {
	
	if(pow((c.x - x), 2) + pow((c.y - y), 2) > pow(c.raio,2)) {
		return 0; 
	}
	
	else {
		return 0;
	}
}

