#ifndef INTERFACE_H
#define INTERFACE_H

void menu () {
	printf("\n\t\t██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗");
	printf("\n\t\t██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗");
	printf("\n\t\t██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝");
	printf("\n\t\t██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝");
	printf("\n\t\t██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║");
	printf("\n\t\t╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝\n");

	printf("\t\t\t\t\t\t\t\t\tPor Edivânia Oliveira\n\n\n");
	
	printf("\t\t\t\t\t╔═══════════════════════╗\n");
	printf("\t\t\t\t\t║                       ║\n");
	printf("\t\t\t\t\t║\t1 - Começar\t║\n");
	printf("\t\t\t\t\t║                       ║\n");
	printf("\t\t\t\t\t║\t2 - Recordes\t║\n");
	printf("\t\t\t\t\t║                       ║\n");
	printf("\t\t\t\t\t║\t3 - Sair\t║\n");
	printf("\t\t\t\t\t║                       ║\n");
	printf("\t\t\t\t\t╚═══════════════════════╝\n\n");
}

void notification (int type) {
	switch(type){
		case 0:
			printf("\t\t\t\t+---------------------------------------+\n");
			printf("\t\t\t\t|\tInsira uma opção válida.\t|\n");
			printf("\t\t\t\t+---------------------------------------+\n\n");
			break;
		case 1:
			printf("\t\t\t\t+-------------------------------------------------+\n");
			printf("\t\t\t\t|\tCoordenada inválida. Tente novamente.\t  |\n");
			printf("\t\t\t\t+-------------------------------------------------+\n\n");
			break;
		case 2:
			printf("\t\t\t\t╔═══════════════════════╗\n");
			printf("\t\t\t\t║\tAté logo!\t║\n");
			printf("\t\t\t\t╚═══════════════════════╝\n\n");
			break;	
	}
}

/* inicializa tabuleiro */
void initBoard(char  board[LIN][COL]) {
    int i, j;
    for(i = 0; i < LIN; i++ ) {
    	for(j = 0; j < COL ; j++ ) {
        	board[i][j] = ' ';
    	}
    }
}

/* mostra tabuleiro */
void showBoard (char board[LIN][COL]) {
	int i, j;
	printf("\t\t\t\t\t  |0|1|2|3|4|5|6|7|8|9|\n");
	for(i = 0; i < LIN; i++ ) {
		printf("\t\t\t\t\t %i", i);
    	for(j = 0; j < COL ; j++ ) {
    		printf("|%c", board[i][j]);      
    	}
    	printf("|\n");
	}
}


/* tirar caracteres '-' da matriz */
void clearBoard (char board[LIN][COL]) {
	int i, j;
	for(i = 0; i < LIN; i++ ) {
    	for(j = 0; j < COL ; j++ ) {
    		if (board[i][j] == '-') {
    			board[i][j] = ' ';
    		}      
    	}
	}
}

/* imprime a interface da batalha */
void drawBattle () {
	int i, j, k;
	printf("\n\n");
	printf("\t\to = Navio\t\t\t\t╔═══════════════════════╗\n");
	printf("\t\ta = Navio atingido\t\t\t║\tPontos: %i\t║\n", points);
	printf("\t\t@ = Navio afundado\t\t\t║\tTiros: %i\t║\n", shoots);
	printf("\t\tx = Tiro perdido\t\t\t╚═══════════════════════╝\n\n\n");

	printf("\t\t\t           VOCÊ        \t\t\t           PC\n\n");
	printf("\t\t\t  |0|1|2|3|4|5|6|7|8|9|\t\t\t  |0|1|2|3|4|5|6|7|8|9|\n");
	for(i = 0; i < LIN; i++ ) {
		printf("\t\t\t %i", i);
    	for(j = 0; j < COL ; j++ ) {
    		printf("|%c", your_board[i][j]);      
    	}
    	printf("|\t\t\t %i", i);
    	for(k = 0; k < COL ; k++ ) {
    		//if(pcs_board[i][k] != 'o') {
    			printf("|%c", pcs_board[i][k]);
    //		} else {
    //			printf("| ");
    //		}
    	}
    	printf("|\n");
	}
}

#endif
