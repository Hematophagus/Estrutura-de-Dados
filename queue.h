/**
	@file queue.h
	@author Gabriel Bras
	@brief Arquivo com as especificacoes do TAD Queue para a disciplina Estrutura de dados
*/

#ifndef QUEUE_H
#define QUEUE_H

/**
	@typedef void (*Remove)(void *a)
	@brief funcao de remocao de um elemento
*/
typedef void (*Remove)(void *a);

/**
	@typedef queue
	@brief Estrutura fila
*/
typedef struct _queue_{
    void **data;
    int front;
    int rear;
    int max_data;
    int num_data;
    Remove rem;
}queue;

/**
	@fn queue *createQueue(int max_data, Remove rem)
	@brief Aloca memoria para o tad fila
	@param max_data tamanho maximo da fila
	@param rem funcao de desalocar um elemento da fila
	@return q, se a fila for alocada
	@return NULL, se a fila nao for alocada
*/
queue *createQueue(int max_data, Remove rem);

/**
	@fn int enqueue(queue *q, void *data)
	@brief insere um dado no final da fila
	@param q fila previamente alocada
	@param data dado a ser enfileirado
	@return 1, se o dado for enfileirado
	@return 0, se o dado nao for enfileirado
*/
int enqueue(queue *q, void *data);

/**
	@fn void *dequeue(queue *q)
	@brief remove o dado no inicio da fila
	@param q fila previamente alocada
	@return O dado que foi desenfilado
	@return 0, se nao houver dados na fila
*/
void *dequeue(queue *q);

/**
	@fn void *front(queue *q)
	@brief retorna o dado no inicio da fila
	@param q fila previamente alocada
	@return O dado que no inicio da fila
	@return NULL, se nao houver dados na fila
*/
void *front(queue *q);

/**
	@fn bool isEmpty(queue *q)
	@brief verifica se a fila esta vazia
	@param q fila previamente alocada
	@return true, se a fila estiver vazia
	@return false, se a fila nao estiver vazia
*/
bool isEmpty(queue *q);

bool isFull(queue *q);

/**
	@fn void destroyQueue(queue **q)
	@brief desaloca toda memoria no tad fila
	@param q fila previamente alocada
	@return nada
*/
void destroyQueue(queue **q);

#endif // QUEUE_H
