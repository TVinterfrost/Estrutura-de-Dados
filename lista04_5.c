#include <stdio.h>

typedef struct {
	int x, y;
} Ponto;

typedef struct {
	Ponto pSE, pID;
} Retangulo;

void criaRetangulo(Retangulo *rectangle, int x1, int y1, int x2, int y2);
int areaRetangulo(Retangulo rectangle);

int main() {
	Retangulo rect;
	int x1, x2, y1, y2, area;
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	criaRetangulo(&rect, x1, x2, y1, y2);
	areaRetangulo(rect);
	
	area = areaRetangulo(rect);
	
	printf("Ä área do retangulo é: %d\n", area);
	
	return 0;
	
}

void criaRetangulo(Retangulo *rectangle, int x1, int y1, int x2, int y2) {
	rectangle->pSE.x = x1;
	rectangle->pSE.y = y1;
	rectangle->pID.x = x2;
	rectangle->pID.y = y2;
}

int areaRetangulo(Retangulo rectangle) {
	return (2*(rectangle.pID.x - rectangle.pSE.x)) + (2*(rectangle.pSE.y - rectangle.pID.y));
}
