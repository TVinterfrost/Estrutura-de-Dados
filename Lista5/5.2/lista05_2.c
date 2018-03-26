#include <stdio.h>

typedef struct {
	int invoiceN, situation;
	float value;
} Cheque;

typedef struct {
	int nrAccount;
	Cheque invoice[10];
} Talao;

void criaCheque(Cheque *invoice, int nInvoice);
void criaTalao(Talao *coupon, int nAccount, int nCoupon);
int compensaCheque(Cheque *invoice);
int emiteChequeDoTalao(Talao *coupon, int nInvoice, float nValue);
void exibeTalao(Talao *coupon);
void exibeCheque(Cheque invoice);
int compensaChequeDoTalao(Talao *coupon, int nInvoice);
float somaChequesDoTalao(Talao coupon, int cSituation);
int obtemNumero(Cheque invoice);
int emiteCheque(Cheque *invoice, float val);

int main() {
	int nAcc, nFC, op, situ;
	float val;
	Talao c1;
	
	scanf("%d %d", &nAcc, &nFC);
	criaTalao(&c1, nAcc, nFC);
	
	do{
		printf("\n");
		printf("Menu de opçoes\n");
		printf("0.Fim\n");
		printf("1.Exibe Talao\n");
		printf("2.Emite Cheque\n");
		printf("3. COmpensa Cheque\n");
		printf("4. Soma Cheques do Talao\n");
		printf("\n");
	
		scanf("%d", &op);
		printf("\n");
		switch(op) {
			case 1:
				exibeTalao(&c1);
			break;
			case 2:
				scanf("%d %f", &nFC, &val);
				int flag;  
				emiteChequeDoTalao(&c1, nFC, val);
				flag = emiteChequeDoTalao(&c1, nFC, val);
				if(flag == 0) {
					printf("SUCESSO\n");
				}
				else {
					printf("ERRO\n");
				}
			break;
			case 3:
				scanf("%d", &nFC);
				int flag2;
				compensaChequeDoTalao(&c1, nFC);
				flag2 = compensaChequeDoTalao(&c1, nFC);
				if (flag2 == 0) {
					printf("SUCESSO\n");
				}
				else {
					printf("ERRO\n");
				}
			break;
			case 4:
				scanf("%d", &situ);
				float sum = 0;
				sum = somaChequesDoTalao(c1, situ);
				printf("Soma dos cheques: %.2f\n", sum);
			break;
		}
	}while(op != 0);
	
	return 0;
}


void criaCheque(Cheque *invoice, int nInvoice) {
	invoice->invoiceN = nInvoice;
	invoice->situation = 0;
	invoice->value = 0;
}

void criaTalao(Talao *coupon, int nAccount, int nCoupon) {
	int i;
	Cheque c;
	coupon->nrAccount = nAccount;
	for(i = 0; i < 10; i++) {
		criaCheque(&c, nCoupon);
		coupon->invoice[i] = c;
		nCoupon++;
	}
}
	
void exibeTalao(Talao *coupon) {
	int i;
	printf("Numero da conta: %d\n", coupon->nrAccount);
	for(i = 0; i < 10; i++) {
		exibeCheque(coupon->invoice[i]);
	}
	
}

void exibeCheque(Cheque invoice) {
	printf("Numero do Cheque: %d\nSituaçao do cheque: %d\nValor do cheque: %.2f\n", invoice.invoiceN, invoice.situation, invoice.value);
}

int obtemNumero(Cheque invoice) {
	return invoice.invoiceN;
}
int compensaCheque(Cheque *invoice) {
	if(invoice->situation == 1) {
		invoice->situation = 2;
		return 0;
	}
	else {
		return 1;
	}
}

int emiteCheque(Cheque *invoice, float val) {
	invoice->value = val;
	if(invoice->situation == 0){
		invoice->value = val;
		invoice->situation = 1;
		return 1;
	}
	
	else {
		return 0;
	}
}

int emiteChequeDoTalao(Talao *coupon, int nInvoice, float nValue) {
	Cheque c;
	int i;
	for(i = 0; i < 10; i++) {
		c = coupon->invoice[i];
		if(obtemNumero(c) == nInvoice) {
			emiteCheque(&c, nValue);
			coupon->invoice[i] = c;
			return 0;
		}
	}
	
	return 1;
}

int compensaChequeDoTalao(Talao *coupon, int nInvoice) {
	Cheque c;
	int i;
	for(i = 0; i < 10; i++) {
		c = coupon->invoice[i];
		if(obtemNumero(c) == nInvoice) {
			compensaCheque(&c);
			coupon->invoice[i] = c;
			return 0;
		}
	}
	
	return 1;
}


float somaChequesDoTalao(Talao coupon, int cSituation) {
	int i;
	float val = 0;
	
	for(i = 0; i < 10; i++) {
		if(coupon.invoice[i].situation == cSituation) {
			val = val + coupon.invoice[i].value;
		}
	}
	
	return val;
}

	
	
