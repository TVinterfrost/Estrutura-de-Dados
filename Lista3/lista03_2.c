#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	int matricula;
	Data data;
}Aluno;

int main() {
	
	Data dataHoje;
	Aluno alunoDados;
	
	
	dataHoje.dia = 10;
	dataHoje.mes = 3;
	dataHoje.ano = 2018;
	
	

	do {
		scanf("%d", &alunoDados.matricula);
		if (alunoDados.matricula < 0) {
			break;
		}
		
		scanf("%d %d %d", &alunoDados.data.dia, &alunoDados.data.mes, &alunoDados.data.ano);
		
		if(dataHoje.ano - alunoDados.data.ano == 18) {
			if((dataHoje.dia > alunoDados.data.dia) || (dataHoje.mes == alunoDados.data.mes)) {
				printf("O aluno de matricula: %d, nascido em: %d/%d/%d é maior de 18 anos\n", alunoDados.matricula, alunoDados.data.dia, alunoDados.data.mes, alunoDados.data.ano);
			}
			else {
			printf("O aluno de matricula: %d, nascido em: %d/%d/%d é menor de 18 anos\n", alunoDados.matricula, alunoDados.data.dia, alunoDados.data.mes, alunoDados.data.ano);
			}
		}
		
	} while(alunoDados.matricula > 0);
	
	
	return 0;
}