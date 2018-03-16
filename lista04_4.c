#include <stdio.h>

//Cria o tipo Conta
typedef struct {
	int nrConta;
	float saldo;
} Conta;

//Prototipos
void criaConta(int nrConta, Conta *acc);
void retiraDaconta(float retirada, Conta *acc);
void depositaNaConta(float deposito, Conta *acc);
float obtemSaldo(Conta acc);

int main() {
	/* nC = numero de conta e OP = operaçao para o Switch
	 * value = valor de resgate, resta = diferença entre value e saldo corrente
	 * sc e sp = variaveis que pegam saldos de ambas as contas
	 * cP e CC, sao as contas
	*/
	int nC, op;
	float value, resta = 0, sC, sP;
	Conta cP, cC;

	//Leitura dos dados
	printf("Ïnforme os dados das contas\n");
	printf("Numero da conta e saldo\n");
	scanf("%d %f", &nC, &value);
	criaConta(nC, &cP);
	criaConta(nC, &cC);

	printf("\n");
	
	//Estrutura para as opçoes, lendo valor e operaçao
	do {
		printf("Ïnforme a operaçao que deseja fazer\n");
		printf("1. Deposito conta corrente\n");
		printf("2. Deposito conta poupança\n");
		printf("3. Retirada conta corrente\n");
		printf("4. Retirada conta poupança\n");
		printf("5. Fim\n");
		scanf("%d", &op);
		
		//Para ler e forçar a parada sem ler a variavel value
		if(op == 5) {
			break;
		}
		
		//Le o valor que o usuario quer retirar ou depositar
		printf("Ïnforme o valor: ");
		scanf("%f", &value);
		
		//Estrutura para as opçoes
		switch(op) {
			case 1: //Auto-explicativo
				depositaNaConta(value, &cC);
				break;
			
			case 2: //Auto-explicativo
				depositaNaConta(value, &cP);
				break;
				
			/* Primeiro faz a diferença da conta corrente e o valor
			 * e armazena em uma variavel
			 * se o saldo da CC for menor ou igual que a retirada
			 * e se o saldo da CP for maior ou igual que a diferença
			 * o valor e passado para a conta corrente
			 * o valor da poupança e retirado, e por fim o da corrente
			 */
			 
			case 3:
				resta = value - obtemSaldo(cC);
				if(obtemSaldo(cC) <= value) {
					if(obtemSaldo(cP) >= resta ) {
						depositaNaConta(resta, &cC);
						retiraDaconta(resta,&cP);
						retiraDaconta(value, &cC);
					}
				
					else {
						printf("Saldo Insuficiente\n");
					}
				}
				
				else {
					retiraDaconta(value, &cC);
				}
				break;
			
			/* Se o saldo da poupança for menor ou igual a 0
			 * aparece o saldo é insuficiente, do contrario...
			 * é feita a retirada da conta poupança
			 */
			 
			case 4:
				if(obtemSaldo(cP) <= 0) {
					printf("Saldo insuficiente\n");
				}
				
				else {
					retiraDaconta(value, &cP);
				}
				break;
			default:
				printf("Öperaçao Inválida\n");
		}
		
		//Variaveis com os saldos para exibiçao na tela
		sC = obtemSaldo(cC);
		sP = obtemSaldo(cP);
		printf("Saldo Conta Poupança: %.2f \n", sP);
				
		printf("Saldo Conta Corrente: %.2f \n", sC);
		
		printf("\n");	
		
	} while(op != 5);

	return 0;
}



void criaConta(int conta, Conta *acc) {
	acc->nrConta = conta;
	acc->saldo = 0;
}

void retiraDaconta(float retirada, Conta *acc) {
	if(retirada > acc->saldo) {
		printf("O saldo é insuficiente\n");
	}
	
	else {
		acc->saldo = acc->saldo -retirada;
	}
}

void depositaNaConta(float deposito, Conta *acc) {
	acc->saldo = acc->saldo + deposito;
}

float obtemSaldo(Conta acc) {
	return acc.saldo;
}
