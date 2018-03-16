#include <stdio.h>

typedef struct {
	int qtdGols;
	int nrCamisa;
} Jogador;

Jogador leJogador(void);
void escreveJogador(Jogador player);
int ehGoleador(Jogador player);

int main() {
	Jogador p1;
	
	printf("Informe o número de gols e o número da camisa do jogador:\n");
	p1 = leJogador();
	
	if(ehGoleador(p1) == 1) {
		printf("\nÉ goleador\n");
	}
	
	
	escreveJogador(p1);
	
	return 0;
}


Jogador leJogador(void) {
	Jogador player;
	scanf("%d", &player.qtdGols);
	scanf("%d", &player. nrCamisa);
	
	return player;
}

void escreveJogador(Jogador player) {
	printf("\nQuantidade de Gols:%d\nCamisa número:%d\n", player.qtdGols, player.nrCamisa);
}

int ehGoleador(Jogador player) {
	if(player.qtdGols > 5) {
		return 1;
	}
	
	else {
		return 0;
	}
}
