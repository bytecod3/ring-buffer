#include <stdio.h>

struct queue{
    unsigned int t; // current tail
    unsigned int h; // current head
    unsigned int s; // current number of items
    unsigned int c; // capacity of queue
    int* d; // pointer to array of data
};

// global def of queue_t
typedef struct queue queue_t;

queue_t* createQueue(unsigned int _c){
    // input: capacity of ring buffer
    // output: null on failure, pointer to created circular queue
    // this function determines if the queue is empty

    queue_t* my_q = (queue_t*)malloc(sizeof(queue_t));

    if (my_q == NULL){
        return NULL; // failed mem allocation
    } else{
        my_q->t = -1;
        my_q->h = 0;
        my_q->s = 0;
        my_q->c = _c;
        my_q->d = (int*)malloc(_c * sizeof(int));

        return my_q;
    }
    
}


int qEmpty(queue_t* q){
    // determine if queue is empty
    // return: -1 if NULL, 1 if empty, 0 if not empty

    if(q == NULL){
        return -1;
    }else if(q->s == 0){
        return 1;
    } else{
        return 0;
    }
}

int qFull(queue_t* q){
    // determine if the queue is full
    // return: -1 if NULL, 1 if full, 0 if not full

    if(q == NULL){
        return -1;
    } else if(q->s == q->c){
        return 1;
    } else{
        return 0;
    }
}


int qAdd(queue_t* q, int item){
    // add item to q
    // return: -1 if q is NULL, 1 if item addes succefully, 0 otherwise

    if(q == NULL){
        return -1;
    } else if(qFull(q) == 1){
        // make sure queue is not full
        return 0;
    } else{
        // move tail location up one level
        q->t = (q->t + 1) % q->c;
        q->d[q->t] = item; // add item to data array
        q->s++;
        return 1;

    }
}

int qRemove(queue_t* q){
    // return: -1 if q is NULL, 0 if empty, value of item at front of line

    if(q == NULL){
        return -1;
    } else if(qEmpty(q) == 1){
        return 0;
    } else{
        // get the item
        int item = q->d[q->h];
        q->h = (q->h + 1) % q->c;

        // decrease size by 1
        q->s--;

        return item;
    }

}

unsigned int qSize(queue_t* q){
    // return the size of q
    // return -1 if q is NULL

    if(q == NULL){
        return -1;
    }else{
        return q->s;
    }
}

void qFreeMem(queue_t* q){
    // free the array
    free(q->d);

    // free queue
    free(q);
}

int main(){
    queue_t* myq;

    myq->c = 4;
    int status;

    status = qEmpty(myq);

    printf("%d", status);

    return 0;
}