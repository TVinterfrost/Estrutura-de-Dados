#include <stdio.h>
typedef struct {
	int invoiceN, situation;
	float value;
} Cheque;


void criaCheque(Cheque *invoice, int nInvoice);
int obtemSituacao(Cheque invoice);
int obtemNumero(Cheque invoice);
void exibeCheque(Cheque invoice);
float obtemValor(Cheque invoice);
int compensaCheque(Cheque *invoice);
int emiteCheque(Cheque *invoice, float val);

int main() {
	Cheque c1, c2;
	int inv1, inv2;
	float val1, val2;
	
	printf("Ïnsira o numero dos dois cheques: ");
	scanf("%d %d", &inv1, &inv2); 
	criaCheque(&c1, inv1);
	criaCheque(&c2, inv2);
	
	printf("Ïnforme os valores dos cheques: ");
	scanf("%f %f", &val1, &val2);
	
	emiteCheque(&c1, val1);
	emiteCheque(&c2, val2);
	
	exibeCheque(c1);
	exibeCheque(c2);
	
	if(obtemValor(c1) > obtemValor(c2)) {
		compensaCheque(&c1);
	}
	
	else {
		compensaCheque(&c2);
	}
	
	printf("Situaaçao do Cheque 1: %d\nSituaçao do Cheque 2: %d\n", obtemSituacao(c1), obtemSituacao(c2));
	printf("Numero do Cheque 1: %d\nNumero do Cheque 2: %d\n", obtemNumero(c1), obtemNumero(c2));
	
	return 0;
}


void criaCheque(Cheque *invoice, int nInvoice) {
	invoice->invoiceN = nInvoice;
	invoice->situation = 0;
	invoice->value = 0;
}

int obtemSituacao(Cheque invoice) {
	return invoice.situation;
}

int obtemNumero(Cheque invoice) {
	return invoice.invoiceN;
}

void exibeCheque(Cheque invoice) {
	printf("Numero do Cheque: %d\nSituaçao do cheque: %d\nValor do cheque: %.2f\n", invoice.invoiceN, invoice.situation, invoice.value);
}

float obtemValor(Cheque invoice) {
	return invoice.value;
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
	if(invoice->situation == 0) {
		invoice->value = val;
		invoice->situation = 1;
		return 1;
	}
	
	else {
		return 0;
	}
}
