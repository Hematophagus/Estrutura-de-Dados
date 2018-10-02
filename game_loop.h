/**
	@file game_loop.h
	@brief arquivo com as principais funcoes do jogo
	@author Gabriel Bras
*/

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "snake.h"

/**
	@fn cell **init(int side)
	@brief inicializa a tela do jogo
	@param side tamanho do largura e altura da tela 
	@return grid tela do jogo, se for inicializada
	@return NULL se a tela nao for inicializada
*/
cell **init(int side);

/**
	@fn int loop()
	@brief looping do jogo
	@return score pontuacao adquirida
*/
int loop();

/**
	@fn void print(cell **grid, int side)
	@brief imprime o símbolo de cada celula do jogo
	@param grid tela do jogo
	@param side tamalho do lado da tela
	@return nada
*/
void print(cell **grid, int side);

/**
	@fn void clear(cell **grid, int side)
	@brief remove o símbolo de cada celula do jogo
	@param grid tela do jogo
	@param side tamalho do lado da tela
	@return nada
*/
void clear(cell **grid, int side);

/**
	@fn bool _grow(cell **grid, int side)
	@brief verifica se a cobra pode ou nao crescer
	@param grid tela do jogo
	@param side tamalho do lado da tela
	@return true se a cobra puder crescer
	@return false se a cobra nao puder crescer
*/
bool _grow(cell **grid, int side);

/**
	@fn void insertFruit(cell **grid, bool grow, int side)
	@brief insere uma fruta na parte visivel da tela
	@param grid tela do jogo
	@param grow ja existe alguma fruta na tela?
	@param side tamalho do lado da tela
	@return true se a cobra puder crescer
	@return false se a cobra nao puder crescer
*/
void insertFruit(cell **grid, bool grow, int side);

#endif //GAME_LOOP_H
