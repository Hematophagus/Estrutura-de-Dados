#include "game_loop.h"
#include <iostream>
#include "queue.h"
#include "snake.h"
#include <cmath>
#include <conio.h>
#include <cstdlib>
#include <ctime>

//#define LINUX

#ifdef LINUX
	#include <unistd.h>
#else
	#include <windows.h>
	#include <dos.h>
#endif

using namespace std;

void rem(void *a){
    cell *a1 = (cell *)a;

    delete []a1;
}

cell **init(int side){
    cell **grid = new cell *[side];

    for(int i = 0; i < side; i++){

        grid[i] = new cell[side];

        for(int j = 0; j < side; j++){

            grid[i][j].y = i;
            grid[i][j].x = j;
            grid[i][j].dir = 0;
            grid[i][j].sym = ' ';

        }

    }
    srand(time(NULL));
    return grid;
}

int loop(){
	const int side = 30;
	cell **grid = init(side);
    queue *snake = createQueue(side*side, rem);
    
    for(int i = 0; i < 2; i++){
        cell *b = new cell[1];
        b -> sym = '*';
        b -> x = 5 - i;
        b -> y = 5;
        b -> dir = 4;
        enqueue(snake, (void *)b);
    }
    
	int score = 3;
    bool grow = true;
	
	do{
        #ifdef LINUX
            system("clear");
        #else
            system("cls");
        #endif
		clear(grid, side);
			
        grow = _grow(grid, side);

        if (!updateSnake(snake, grid, grow))
            break;
        
        if(grow)
            score++;
		
		//system("pause");
        insertFruit(grid, grow, side);

        grow = false;

        print(grid, side);
		
        #ifdef LINUX
            usleep(1000000); // dorme por 1 s: 1 0000 0000 de milisegundos
        #else
            Sleep(100);
        #endif
    }while(input() != 8);
    
    destroyQueue(&snake);
    for(int i = 0; i < side; i++)
    	delete []grid[i];
    delete []grid;
	return score;
}

void print(cell **grid, int side){
    for(int i = -1; i < side+1; i++){
        for(int j = -1; j < side+1; j++){
            if (i < 0 || j < 0 || i >= side || j >= side)
                cout << "# " ;
            else
                cout << grid[i][j].sym<< " ";
        }
        cout << "\n";
    }
}

void clear(cell **grid, int side){
    for(int i = 0; i < side; i++)
        for(int j =0; j < side; j++)    
            if(grid[i][j].sym != 'o')
				grid[i][j].sym = ' ';
        
    
}

bool _grow(cell **grid, int side){
	for(int i = 0; i < side; i++)
        for(int j = 0; j < side; j++){
            if(grid[i][j].sym == 'o')
                return false;
     	}
    return true;
}

void insertFruit(cell **grid, bool grow, int side){
	cell fruit;

	fruit.x = rand()%side;
    fruit.y = rand()%side;
    fruit.dir = 0;
    fruit.sym = 'o';

 	if(grid[fruit.y][fruit.x].sym != '*' && grow)
    	grid[fruit.y][fruit.x] = fruit;
}
