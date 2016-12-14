#include <stdio.h>
#include <string.h>
#include "fifo.h"

#define VALUE_LENGTH    (10)
#define ARRAY_SIZE      (10)

typedef struct
{
    int index;
    char value[VALUE_LENGTH];
} data_t;


void additem(fifo_t *pfifo)
{
    static int idx = 0;

    data_t newData;

    newData.index = idx;
    memset(newData.value, 'a'+idx, VALUE_LENGTH);
    idx++;

    if(0 < FIFO_AddItem(pfifo, &newData))
    {
        printf("WRITE: item added to fifo %d:%.10s\n", newData.index, newData.value);
    }
    else
    {
        printf("WRITE: FAILED\n");
    }
    printf("Free space %d\n", FIFO_FreeSpace(pfifo));
}


void getitem(fifo_t *pfifo)
{
    data_t newData;
    if(0 < FIFO_GetItem(pfifo, &newData))
    {
        printf("READ: %d::%.10s\n", newData.index, newData.value);
    }
    else
    {
        printf("READ: EMPTY\n");
    }
    printf("Free space %d\n", FIFO_FreeSpace(pfifo));
}

int main()
{
    fifo_t myFifo;
    data_t myData[10];
    
    //init
    FIFO_Init(&myFifo, myData, sizeof(myData[0]), sizeof(myData)/sizeof(myData[0]));
    printf("Free space %d\n", FIFO_FreeSpace(&myFifo));
/*
    additem(&myFifo);
    additem(&myFifo);
    additem(&myFifo);

    getitem(&myFifo);
    getitem(&myFifo);
    getitem(&myFifo);
    getitem(&myFifo);
*/
    int idx;
    for(idx=0; idx<ARRAY_SIZE+1; idx++)
    {
        additem(&myFifo);
    }        

    for(idx=0; idx<ARRAY_SIZE+1; idx++)
    {
        getitem(&myFifo);
    }        
    
    return 0;
}