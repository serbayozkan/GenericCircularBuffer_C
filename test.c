/**
  ******************************************************************
  * @file    test.c
  * @author  Serbay Ozkan
  * @date    12 May 2021
  * @brief   Tests the Circular Buffer Data Structure APIs 
  ******************************************************************
  */

/* Private Macro Definitions */

#define CB_STATIC
// #define CB_DYNAMIC

#if defined CB_STATIC && defined CB_DYNAMIC
#error "Please choose only static or dynamic circular buffer design"
#endif

#define CB_TEST_CIRC_BUFFER_ITEM_SIZE                ( 16 )

/* Standard Library Header Files */
#include <stdio.h>

/* User Defined Header Files */
#include "circular_buffer.h"

int main(int argc, char *argv[])
{
    #ifdef CB_DYNAMIC
    circularBuffer_t *circBuffer = circular_buffer_init(sizeof(int), CB_TEST_CIRC_BUFFER_ITEM_SIZE);
    #endif

    #ifdef CB_STATIC
    circularBuffer_t *circBuffer = circular_buffer_init(sizeof(int));
    #endif

    int data = 0;

    printf("Circular Buffer test starts...\n\n");
    printf("Circular Buffer Capacity: %d\n", circular_buffer_capacity(circBuffer));
    printf("Circular Buffer Available Space: %d\n", circular_buffer_free_space(circBuffer));

    for (int i = 0; i < CB_TEST_CIRC_BUFFER_ITEM_SIZE; i++){
        if (circular_buffer_push(circBuffer, &data)){
            data += 10;
        }
        else{
            printf("Push Operation to Empty Circular Buffer!\n");
        }
    }

    if (circular_buffer_full(circBuffer))
        printf("Circular Buffer is full!\n");
    
    printf("Available space in circular buffer: %d\n", circular_buffer_free_space(circBuffer));
    
    for (int i = 0; i < CB_TEST_CIRC_BUFFER_ITEM_SIZE; i++){
        if (circular_buffer_pop(circBuffer, &data)){
            printf("Popped Data[%d]: %d\n", i, data);
        }
        else{
            printf("Pop Operation to Empty Circular Buffer!\n");
        }
    }

    if (circular_buffer_empty(circBuffer))
        printf("Circular Buffer is empty!\n");

    printf("Available space in circular buffer: %d\n", circular_buffer_free_space(circBuffer));

    #ifdef CB_DYNAMIC
    circular_buffer_destroy(&circBuffer);

    if (circBuffer == NULL)
        printf("Circular Buffer is destroyed!\n");
    #endif

    #ifdef CB_STATIC
    circular_buffer_destroy(circBuffer);
    #endif
    
    return EXIT_SUCCESS;
}
