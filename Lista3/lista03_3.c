#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} Aluno;

typedef struct {
	int dia, mes, ano;
} Data;

int main() {
	
	Aluno v1[5];
	Data hoje, v2[5];
	int i, c = 0;
	
	for(i = 0; i < 5; i++) {
		scanf("%d %d %d", &v1[i].dia, &v1[i].mes, &v1[i].ano);
	}
	
	printf("\nInforme a data\n");
	scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
	
	for(i = 0; i < 5; i++) {
		if(hoje.mes == v1[i].mes) {
			c++;
			v2[c].dia = v1[i].dia;
			v2[c].mes = v1[i].mes;
			v2[c].ano = v1[i].ano;
			printf("\n%02d/%02d/%02d\n", v2[c].dia, v2[c].mes, v2[c].ano);
		}
	}
	
	return 0;
}



	/*for(i = 0; i < 5; i++) {
		printf("%02d %02d %02d\n", v1[i].dia, v1[i].mes, v1[i].ano);
	}*/