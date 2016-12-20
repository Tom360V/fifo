#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "fifo.h"

#define VALUE_LENGTH    (10)
#define ARRAY_SIZE      (10)
#define printf

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

START_TEST(test_fifo_test1)
{
    fifo_t myFifo;
    data_t myData[10];

    //init
    FIFO_Init(&myFifo, myData, sizeof(myData[0]), sizeof(myData)/sizeof(myData[0]));
    printf("Free space %d\n", FIFO_FreeSpace(&myFifo));

    int idx;
    //Loop till there is only one space left in the fifo
    for(idx=0; idx<ARRAY_SIZE-1; idx++)
    {
        additem(&myFifo);
    }        
    ck_assert(FIFO_FreeSpace(&myFifo) == 1);

    // get the last free space in the fifo
//    ck_assert(additem(&myFifo >= 0);
    additem(&myFifo);
    ck_assert(FIFO_FreeSpace(&myFifo) == 0);

    // try to get one, more item from the queue, should fail
    additem(&myFifo);
    ck_assert(FIFO_FreeSpace(&myFifo) == 0);

    for(idx=0; idx<ARRAY_SIZE+1; idx++)
    {
        getitem(&myFifo);
    }
   ck_assert(1 == 1);
}
END_TEST

START_TEST(test_fifo_test2)
{
   ck_assert(1 == 1);
}
END_TEST


int main(void)
{
	int number_failed;
	Suite *suite   = suite_create("FIFO");
    TCase *tcase   = tcase_create("Case1");

	/* ADD TESTS HERE*/
    tcase_add_test(tcase, test_fifo_test1);
    tcase_add_test(tcase, test_fifo_test2);

	suite_add_tcase(suite, tcase);		//TODO: move aboud tcase_add_test!!!

	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_VERBOSE);
	number_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
