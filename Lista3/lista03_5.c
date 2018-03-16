#include <stdio.h>

typedef struct {
	int qtGols;
	int nc;
} Jogador;

typedef struct {
	int aTime;
	Jogador j[5];
} Equipe;

Jogador leJogador(void);
void leEquipe(Equipe *time);
void marcouGol(int nrCamisa, Equipe *time);
void escreveJogador(Jogador player);
Jogador obtemGoleador(Equipe time);


int main() {
	Equipe equip;
	int camisa;
	
	leEquipe(&equip);
 
	do {
		printf("Informe a camisa do jogador\n");
		scanf("%d", &camisa);
		
		if(camisa == 99) {
			break;
		}
		
		marcouGol(camisa, &equip);
		
	} while(camisa != 99);
	
	escreveJogador(obtemGoleador(equip));
	
	return 0;
}


void leEquipe(Equipe *time) {
	int i;
	
	printf("Ano de criaçao da Equipe\n");
	scanf("%d", &time->aTime);
	printf("Quantidade de gols e numero da camisa\n");
	for(i = 0; i < 5; i++) {
		time -> j[i] = leJogador();
	}
}

Jogador leJogador(void) {
	Jogador player;
	scanf("%d", &player.qtGols);
	scanf("%d", &player. nc);
	
	return player;
}

void marcouGol(int nr_Camisa, Equipe *time) {
	int i;
	
	for(i = 0; i < 5; i++) {
		if(nr_Camisa == time -> j[i].nc) {
			time ->j[i].qtGols++;
		}
	}
}


void escreveJogador(Jogador player) {
	printf("\nQuantidade de Gols:%d\nCamisa número:%d\n", player.qtGols, player.nc);
}

Jogador obtemGoleador(Equipe time) {
	int i, maior = 0;
	Jogador je;
	
	for(i = 0; i < 5; i++) {
		if(time.j[i].qtGols > maior) {
			maior = time.j[i].qtGols;
			je = time.j[i];
		}
	}
	
	return je;
}
