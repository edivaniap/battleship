#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define LIN 10
#define COL 10
#define FALSE 0
#define TRUE 1

int points;
int shoots;

#include "interface.h"
#include "position.h"
#include "battle.h"

int main() {
	char your_board[LIN][COL];
	char pcs_board[LIN][COL];

	int option; // variavel para opção
	int contin; // variavel para informar se devo continuar mostrando o menu ou não

    do {
    	contin = FALSE; // de inicio, o while não deve continuar, a não ser que a opção digitada não seja válida
        menu(); // mostrar tela inicial/menu
        printf("\t\t\t\tOpção: ");
        scanf("%i", &option); // ler opção
        system("clear"); // limpar tela

        switch(option) {
            case 1:
            	initBoard(your_board); // inicializando tabuleiro
				initBoard(pcs_board);
				wayPosition(your_board);
				//start();
				printf("começar batalha!\n");
				randomPosition(pcs_board, FALSE);
                battle(your_board, pcs_board);
                break;

            case 2:
                //records()
                break;

            case 3:
                notification(2);
                return 0;
                break;

            default:
            	notification(0); // mensagem de opção inválida
            	contin = TRUE; // o while deve continuar
        }
    } while(contin);
	return 0;
}
