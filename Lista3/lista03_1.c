#include <stdio.h>

typedef struct {
	int hora;
	int minuto;
	int segundo;
} Horario;

int main() {
	Horario horaVar, horaVar2;
	int sec, sec2;
	
	scanf("%d %d %d", &horaVar.hora, &horaVar.minuto, &horaVar.segundo);
	scanf("%d %d %d", &horaVar2.hora, &horaVar2.minuto, &horaVar2.segundo);
	
	sec = (horaVar.hora * 3600) + (horaVar.minuto * 60) + horaVar.segundo;
	sec2 = (horaVar2.hora * 3600) + (horaVar2.minuto * 60) + horaVar2.segundo;
	
	
	if(sec == sec2) {
		printf("Horários Iguais\n");
	}
	
	else
		if(sec < sec2) {
		printf("%d:%d:%d\n", horaVar.hora, horaVar.minuto, horaVar.segundo);
		}
	else {
		printf("%d:%d:%d\n", horaVar2.hora, horaVar2.minuto, horaVar2.segundo);
	}
	
	return 0;
} 