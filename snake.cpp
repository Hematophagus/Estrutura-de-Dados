#include <cmath>
#include <conio.h>
#include <iostream>
#include "queue.h"
#include "snake.h"
#include "game_loop.h"

#ifdef LINUX
	#include <unistd.h>
#else
	#include <windows.h>
	#include <dos.h>
#endif

using namespace std;

int input(){
    char c;
    
    if(kbhit()){
        c = getch();
        switch(c){
        case 'W':
        case 'w':
            return 1;
        case 'A':
        case 'a':
            return 2;
		case 'S':
        case 's':
            return 3;
        case 'D':
		case 'd':
            return 4;
        case 'Q':
		case 'q':
        	return 8;
        }
    }
    return 0;
}

void updateCell(cell *c, int dir, int ant){
    switch(dir){
    case 1:
        if(ant != 3){
            c -> y--;
            c -> dir = dir;
        }else{
            c -> y++;
            c -> dir = ant;
        }
        return ;
    case 2:
        if(ant != 4){
            c -> x--;
            c -> dir = dir;
        }else{
            c -> x++;
            c -> dir = ant;
        }
        return ;
    case 3:
        if(ant != 1){
            c -> y++;
            c -> dir = dir;
        }else{
            c -> y--;
            c -> dir = ant;
        }

        return ;
    case 4:
        if(ant != 2){
            c -> x++;
            c -> dir = dir;
        }else{
            c -> x--;
            c -> dir = ant;
        };
        return ;
    }
}

bool updateSnake(queue *snake, cell **grid, bool grow){
    int a, ant, prev = 0;
    int side = sqrt(snake -> max_data);
    cell *newCell, *_front, *tail = new cell [1];
    a = input();
    	
    	
	_front = (cell *)front(snake);
   	
	newCell = (cell *)dequeue(snake);
    ant = newCell -> dir;
   
    if(newCell -> y >= 0 && newCell -> y < side && newCell -> x >= 0 && newCell -> x < side)
    	grid[newCell -> y][newCell -> x].sym = ' ';
	
	if(a != 0)
    	updateCell(newCell, a, ant);
	else
		updateCell(newCell, ant, 0);
	
	if(newCell -> y >= 0 && newCell -> y < side && newCell -> x >= 0 && newCell -> x < side)
		grid[newCell -> y][newCell -> x].sym = newCell -> sym;
	enqueue(snake, (void *)newCell);
	
	
    while(front(snake) != ((void *)_front)){
    	prev = ant;
        newCell = (cell *)dequeue(snake);
        
        if(newCell -> y >= 0 && newCell -> y < side && newCell -> x >= 0 && newCell -> x < side)
       	 	grid[newCell -> y][newCell -> x].sym = ' ';
        
        ant = newCell -> dir;
        
		*tail = *newCell;
		
		updateCell(newCell, prev, 0);
        
		if(newCell -> y >= 0 && newCell -> y < side && newCell -> x >= 0 && newCell -> x < side)
			grid[newCell -> y][newCell -> x].sym = newCell -> sym;	
        
		enqueue(snake, (void *)newCell);
    }
	
	if(grow){
		grid[tail -> y][tail -> x].sym = tail -> sym;
		enqueue(snake, (void *)tail);
	}
	
	newCell = (cell *)front(snake);
	
	if(isFull(snake))
		return false;
	
	if(newCell -> x < 0 || newCell -> y < 0 || newCell -> x >= side || newCell -> y >= side)
		for(int i = 0; i < 5; i++){
			dequeue(snake);
			if(isEmpty(snake))
        		return false;
		}

    return true;
}

