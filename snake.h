/**
    @file snake.h
    @author Gabriel Bras
    @brief Arquivo contendo especificacoes do game snake
*/
#include "queue.h"
#ifndef SNAKE_H
#define SNAKE_H

/**
    @typedef struct _cell_ cell
    @brief estrutura celula contendo as posicoes em x e y, a direcao e o caractere da celula
*/
typedef struct _cell_{
    int x;
    int y;
    int dir;
    char sym;
}cell;

/**
    @fn int input()
    @brief comandos do jogo
    @return 1 mover a cobra para cima
    @return 2 mover a cobra para a esquerda <3
    @return 3 mover a cobra para baixo
    @return 4 mover a cobra para a direita
    @return 0 mover a cobra para a direcao em que ela segue
    @return 8 interromper execucao
*/
int input();

/**
    @fn bool updateSnake(queue *snake, cell **grid, bool grow)
    @brief faz toda a movimentacao da cobra pela tela 
    @param snake fila contendo a cobra 
    @param grid tela do jogo
    @param grow a cobra pode crescer?
    @return true se a cobra puder fazer algum movimento 
    @return false se a cobra tiver tamanho menor ou igual a zero
*/
bool updateSnake(queue *snake, cell **grid, bool grow);

/**
    @fn void updateCell(cell *cel, int dir, int ant)
    @brief atualiza a posicao da celula e direcao a que vai seguir
    @param c celula a ser atualizada 
    @param dir nova direcao
    @param ant direcao anterior
    @return nada
*/
void updateCell(cell *c, int dir, int ant);

#endif // SNAKE_H
