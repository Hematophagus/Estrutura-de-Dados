#include <iostream>
#include "queue.h"

using namespace std;

queue *createQueue(int max_data, Remove rem){
    queue *q;

    if(max_data > 0){

        q = new queue[1];
        if(q != NULL){

            q -> data = new void*[max_data];

            if(q -> data != NULL){

                q -> front = 0;
                q -> max_data = max_data;
                q -> num_data = 0;
                q -> rear = 0;
                q -> rem = rem;

            }else{

                delete []q;
                q = NULL;

            }
        }
    }

    return q;
}

int enqueue(queue *q, void *data){

    if(q != NULL && q -> data != NULL && q -> num_data < q -> max_data){

        q -> data[q -> rear] = data;
        q -> rear++;
        q -> num_data++;

        return 1;
    }

    return 0;
}

void *dequeue(queue *q){

    void *aux = NULL;

    if(q != NULL && q -> data != NULL && !isEmpty(q)){

        aux = q -> data[q -> front];

        for(int i = q -> front; i < q -> rear - 1; i++){

            q -> data[i] = q -> data[i + 1];

        }
        q -> rear--;
        q -> num_data--;
    }

    return aux;
}


void *front(queue *q){

    if(q != NULL && q -> data != NULL && !isEmpty(q))
        return q -> data[q -> front];

    return NULL;
}

bool isEmpty(queue *q){

    if(q -> front == q -> rear)
        return true;
    
    return false;
}

bool isFull(queue *q){

    if(q -> num_data == q -> max_data)
        return true;
    
    return false;
}

void destroyQueue(queue **q){
    queue *tmp =  *q;

    delete []tmp -> data;
    delete []tmp;

    *q = NULL;
}
