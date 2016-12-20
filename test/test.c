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


int8_t additem(fifo_t *pfifo)
{
    static int idx = 0;

    data_t newData;

    newData.index = idx;
    memset(newData.value, 'a'+idx, VALUE_LENGTH);
    idx++;

    printf("Add item %d\n", 'a'+idx);
    return FIFO_AddItem(pfifo, &newData);
}


int8_t getitem(fifo_t *pfifo)
{
    data_t newData;
    return FIFO_GetItem(pfifo, &newData);
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
        ck_assert(additem(&myFifo) >= 0);
    }        
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), 1);

    // get the last free space in the fifo
    ck_assert(additem(&myFifo) >= 0);
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), 0);

    // try to get one, more item from the queue, should fail
    ck_assert_int_eq(additem(&myFifo), -1);
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), 0);

    

    //Loop till there is one item left in the fifo
    for(idx=0; idx<ARRAY_SIZE-1; idx++)
    {
        ck_assert(getitem(&myFifo) >= 0);
    }
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), ARRAY_SIZE-1);

    //Get last item
    ck_assert(getitem(&myFifo) >= 0);
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), ARRAY_SIZE);

    //Fifo empty, try to get one more item
    ck_assert_int_eq(getitem(&myFifo), -1);
    ck_assert_int_eq(FIFO_FreeSpace(&myFifo), ARRAY_SIZE);
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

    suite_add_tcase(suite, tcase);      //TODO: move aboud tcase_add_test!!!

    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_VERBOSE);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
