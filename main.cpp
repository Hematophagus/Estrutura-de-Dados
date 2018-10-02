#include "queue.h"
#include "game_loop.h"
#include <iostream>

using namespace std;

int main(){

    int score, op;

   	do{
   		cout << "\n\n\n\n=========================\nSSSSSSSSSSSSNAKE K4BUL0SA\n=========================\n";
   		cout << "[1] NOVO JOGO\n[2] SAIR\n=========================\n";
   		
		cin >> op;
   		switch(op){
   			case 1:
   				score = loop() - 1;
   				
				if(score < 5)
					cout << "====================\nNOSSA, QUE PERDEDOR!\n====================\n";
				else if(score < 10)
					cout << "==================\nTA CAPENGA ISSO AI\n==================\n";
				else if(score <= 30)
					cout << "=============================\nBACANA, MAS PRECISA MELHORAR!\n=============================\n";
				else if(score <= 100)
					cout << "==============================\nAGORA TA FICANDO T O P Z E R A!\n==============================\n";
				else if(score <= 900)
					cout << "================\nQUE BELEZA HEIN!\n================\n";
				else 
					cout << "===============================\nAI SIM, PAPAI, TU ZEROU MESMO!!\n===============================\n";
				
				cout << score << " pontos\n";;
   				
   				break;
   	
   			case 2:
   				
   				break;
   			default:
   				
   				cout << "OPCAO INVALIDA\n\n";
		}
	}while( op != 2);
	
	cout << "\n\n\n\nGAME BY: Gabriel Bras\n\n\n";
	
    return 0;
}


