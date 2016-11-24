#ifndef POSITION_H
#define POSITION_H

void  manualPosition (char board[LIN][COL]);
void randomPosition (char board[LIN][COL], int human_player);

/* posiona navio dada as coordenadas das suas extremidades */
int positionShips (char board[LIN][COL], int x1, int y1, int x2, int y2) { 
	int i, aux;

	if(y2 < y1){ // definindo y2 como maior que y1
		aux = y1;
		y1 = y2;
		y2 = aux;
	}
	
	if(x2 < x1){ // definindo x2 como maior que x1
		aux = x1;
		x1 = x2;
		x2 = aux;
	}
	
	
	if (x1 == x2) {
		/* primeiro verificando se tem algum navio impedindo que seja colocado este navio */
		for (i = y1; i <= y2; ++i) {
			if (board[x1][i] == 'o') {
				printf("\t++ problema: colisão de navios ++\n");
				return TRUE; // true: vai ter que pedir outra coordenada
			}

			if (board[x1][i] == '-') {
				printf("\t++ problema: navios adjacentes ++\n");
				return TRUE; // true: vai ter que pedir outra coordenada
			}
		}

		/* após verificar que ta ok, preencher navio no tabuleiro */
		if(y1 != 0 && board[x1][y1-1] != 'o') { //preencher lateral
			board[x1][y1-1] = '-';
			if(x1 != 0) {
				board[x1-1][y1-1] = '-'; //preencher lateral
			}
			if(x1 != LIN-1) {            //preencher lateral
				board[x1+1][y1-1] = '-';
			}
		}
		
		for (i = y1; i <= y2; ++i) {
			board[x1][i] = 'o';
			
			if (x1 != 0)             //preencher lateral
				board[x1-1][i] = '-';
			if(x1 != LIN - 1)         //preencher lateral
				board[x1+1][i] = '-';
		}

		if(y2 != COL-1 && board[x1][y2+1] != 'o') {
			board[x1][y2+1] = '-';
			if(x1 != 0) {
				board[x1-1][y2+1] = '-';
			}
			if(x1 != LIN-1) {
				board[x1+1][y2+1] = '-';
			}
		}
		//---------------------------------------//
	} else if (y1 == y2) {
		/* primeiro verificando se tem algum navio impedindo que seja colocado este navio */
		for (i = x1; i <= x2; ++i) {
			if (board[i][y1] == 'o'){
				printf("\t++ problema: colisão de navios ++\n");
				return TRUE; // true: vai ter que pedir outra coordenada
			}
			if (board[i][y1] == '-') {
				printf("\t++ problema: navios adjacentes ++\n");
				return TRUE; // true: vai ter que pedir outra coordenada
			}
		}

		/* após verificar que ta ok, preencher navio no tabuleiro */
		if(x1 != 0 && board[x1-1][y1] != 'o') {
			board[x1-1][y1] = '-';
			if(y1 != 0) {
				board[x1-1][y1-1] = '-';
			}
			if(y1 != COL-1) {
				board[x1-1][y1+1] = '-';
			}
		}

		for (i = x1; i <= x2; ++i) {
			board[i][y1] = 'o';

			if (y1 != 0)
				board[i][y1-1] = '-';
			if(y1 != COL - 1)
				board[i][y1+1] = '-';
		}

		if(x2 != LIN-1 && board[x2+1][y1] != 'o') {
			board[x2+1][y1] = '-';
			if(y1 != 0) {
				board[x2+1][y1-1] = '-';
			}
			if(y1 != COL-1) {
				board[x2+1][y1+1] = '-';
			}
		} 
	}
	
	return FALSE;
}

void ask(char board[LIN][COL]) {
		int option;
		int contin;

	    do {
	    	contin = FALSE;
	    	printf("\n\t\t\t\t\t╔══════════════════════════╗\n");
			printf("\t\t\t\t\t║\tSEU TABULEIRO\t   ║\n");
			printf("\t\t\t\t\t╚══════════════════════════╝\n\n");
			
			showBoard(board);

			printf("\n\n");
			printf("\t\tInsira a opção: 0 - Iniciar batalha \t 1 - Novo posicionamento manual \t 2 - Novo posicionamento aleatório\n\n\t\t\t");
	        scanf("%i", &option); // ler opção
	        system("clear"); // limpar tela

	        switch(option) {
	            case 0:
	                break;

	            case 1:
	            	initBoard(board);
	            	manualPosition(board);	            	
	                break;

	            case 2:
	            	initBoard(board);
	            	randomPosition(board, TRUE);
	                break;

	            default:
	            	notification(0); // mensagem de opção inválida
	            	contin = TRUE; // o while deve continuar
	        }
	    } while(contin); 
}

/* posiciona navios aleatoriamente */
void randomPosition (char board[LIN][COL], int human_player) {	
	srand( (unsigned)time(NULL) );
	
 	int num = 1; // numero de navios
	int size = 4; // tamanho do navio
	int x1, y1, x2, y2; // variaveis para coordenada de cada extremidade do navio 
	int i, j;
	/* laço para cada tipo de navio */
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= num; j++) {
			int contin; // vai informar se o usuário deve continuar informando a coordenada se ele tiver informado uma invalida 

			do {
				contin = FALSE;
				
				short int orientation = rand() % 2; //gerando aleatorio que vai informar se o navio vai ser alocado na vertical ou horizontal
 										//0 - horizontal, 1 - vertical
				short int way = rand() % 2; //gerando aleatorio que vai informar se o sentido do navio
											//0 ou 1 - frente para tras ou tras para frente

				x1 = rand() % 10;
 				y1 = rand() % 10;

				if(size != 1) { // se não for submarino precisa de 2 coordenadas diferentes
					if(way == 0) { //tratando o sentido
						way = -1;
					}

					if (orientation == 0){ 
				 		x2 = x1;
				 		y2 = y1 + (way * (size-1));
				 	}

					if (orientation == 1){ 
				 		y2 = y1;
				 		x2 = x1 + (way * (size-1));
				 	}
				} else { // se for submarino
					x2 = x1;
					y2 = y1;
				}


				/* condições para continuar a pedir as coord certas */
				if (x1 < 0 || x1 > LIN-1 || y1 < 0 || y1 > COL-1 || x2 < 0 || x2 > LIN-1 || y2 < 0 || y2 > COL-1) {
					printf("\t ++problema: fora do limite++\n\n");
					contin = TRUE; // se as coordenadas estiverem fora do limite da matriz
				} else if (x1 != x2 && y1 != y2) {
					printf("\t ++problema: nao esta na mesma linha nem na mesma coluna++\n\n");
					contin = TRUE; // nao esta na mesma linha nem na mesma coluna
				}

				if (x1 == x2 && abs(y1 - y2) != size - 1) { //se não condizer com o tamanho do navio
					contin = TRUE; 
					 printf("\t ++problema: tamanho do navio x++\n\n");
				} else if (y1 == y2 && abs(x1 - x2) != size - 1) {
					contin = TRUE;
					printf("\t ++problema: tamanho do navio y++\n\n");
				}

				if(contin == FALSE){
					contin = positionShips(board, x1, y1, x2, y2);
				}				

				system("clear");

				if(contin){
					notification(1);
				}
			} while (contin);
		}

		num++; // muda o tipo do navio
		size--; // muda o tamanho do navio
	}

	clearBoard(board);

	if (human_player) {
		ask(board);
	}
}

/* posiciona navios manualmente */
void  manualPosition (char board[LIN][COL]) {
	int num = 1; // numero de navios
	int size = 4; // tamanho do navio
	int x1, y1, x2, y2; // variaveis para coordenada de cada extremidade do navio 
	int i, j;
	/* laço para cada tipo de navio */
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= num; j++) {
			int contin; // vai informar se o usuário deve continuar informando a coordenada se ele tiver informado uma invalida
			char * name; //nome do navio

			if(size == 4) {
				name = "Porta-avião";
			} else if(size == 3) {
				name = "Encouraçado";
			} else if(size == 2) {
				name = "Cruzador";
			} else if(size == 1) {
				name = "Submarino";
			} 

			do {
				contin = FALSE;

				printf("\n\t\tVocê deve posicionar os navios de forma que eles não sejam adjacentes. Os navios são:\n\n");
				printf("\tQuantidade -  Aparência  -     nome\n\n");
				printf("\t    1      -  |o|o|o|o|  -  porta-avião\n");
				printf("\t    2      -  |o|o|o|    -  encouraçados                 o = Navio alocado\n");
				printf("\t    3      -  |o|o|      -  cruzadores                   - = Área adjacente ao navio\n");
				printf("\t    4      -  |o|        -  submarinos\n\n");
				
				showBoard(board);

				printf("\n\n\n");
				printf("\t\t\t\t╔═══════════════════════════════╗\n");
				printf("\t\t\t\t║\t%i° %s\t\t║\n", j, name);
				printf("\t\t\t\t╚═══════════════════════════════╝\n\n");

				printf("\tInforme as coordenadas da extremidade do navio\n");
				printf("\t\tLin Col: ");
				scanf("%i %i", &x1, &y1);

				if(size != 1) { // se não for submarino precisa de 2 coordenadas diferentes
					printf("\tInforme as coordenadas da outra extremidade do navio\n");
					printf("\t\tLin Col: ");
					scanf("%i %i", &x2, &y2);
				} else { // se for submarino
					x2 = x1;
					y2 = y1;
				}


				/* condições para continuar a pedir as coord certas */
				if (x1 < 0 || x1 > LIN-1 || y1 < 0 || y1 > COL-1 || x2 < 0 || x2 > LIN-1 || y2 < 0 || y2 > COL-1) {
				printf("\t ++problema: fora do limite++\n\n");	contin = TRUE; // se as coordenadas estiverem fora do limite da matriz
				} else if (x1 != x2 && y1 != y2) {
					printf("\t ++problema: nao esta na mesma linha nem na mesma coluna++\n\n");
					contin = TRUE; // nao esta na mesma linha nem na mesma coluna
				}

				if (x1 == x2 && abs(y1 - y2) != size - 1) { //se não condizer com o tamanho do navio
					contin = TRUE; 
					 printf("\t ++problema: tamanho do navio x++\n\n");
				} else if (y1 == y2 && abs(x1 - x2) != size - 1) {
					contin = TRUE;
					printf("\t ++problema: tamanho do navio y++\n\n");
				}

				if(contin == FALSE){
					contin = positionShips(board, x1, y1, x2, y2);
				}				

				system("clear");

				if(contin){
					notification(1);
				}
			} while (contin);
		}

		num++; // muda o tipo do navio
		size--; // muda o tamanho do navio
	}
	
	clearBoard(board);
	ask(board);
}

/* decidir qual como o jogador quer posicionar seus navios */
void wayPosition () { 
	int option;
	int contin;

    do {
    	contin = FALSE;
    	printf("\n\tVocê deseja posicionar seus navios ou deseja um posicionamento aleatório?\n\n");
    	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
		printf("\t\t\t\t║\t1 - Posicionar      2 - Aleatório\t║\n");
		printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n\n");
        printf("\t\t\t\tOpção: ");
        scanf("%i", &option); // ler opção
        system("clear"); // limpar tela

        switch(option) {
            case 1:
            	manualPosition(your_board);
                break;

            case 2:
            	randomPosition(your_board, TRUE);
                break;

            default:
            	notification(0); // mensagem de opção inválida
            	contin = TRUE; // o while deve continuar
        }
    } while(contin); 
}

#endif
