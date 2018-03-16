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
	
	int x, y, i, inOut;
	Circulo c1;
	
	criaCirculo(10, 5, 5, &c1);
	
	for(i = 0; i < 5; i++) {
		printf("X: ");
		scanf("%d", &x);
		printf("Ÿ: ");
		scanf("%d", &y);
		
		inOut = estaDentroDoCirculo(c1, x, y);
		
		if(inOut == 1) {
			printf("Dentro do circulo\n");
		}
		
		else {
			printf("Fora do circulo\n");
		}
		
	}
	
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
