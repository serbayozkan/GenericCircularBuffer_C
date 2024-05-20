/**
  ******************************************************************
  * @file    circular_buffer.c
  * @author  Serbay Ozkan
  * @date    12 May 2021
  * @brief   Circular Buffer Data Structure Source File
  ******************************************************************
  */

/* Standard Library Header Files */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* User Defined Header Files */
#include "circular_buffer.h"

/* Circular Buffer Data Structure */
struct circularBuffer{
    /* Manages the whether circular buffer in use (true) or not (false) */
    bool inUse;

    /* Tracks the pop operation */
    int head;
    
    /* Tracks the push operation */
    int tail;

    /* Buffer item size */
    size_t itemSize;

    /* Total capacity of buffer items */
    int capacity;

    /* Byte Array */
    uint8_t data[CB_MAX_BUFFER_POOL_SIZE];
};

/* Private Variables */
static int instanceNumber = 0;
static circularBuffer_t circularBufferPool[CB_MAX_INSTANCE_POOL_SIZE];

/* Private Function Declerations */
static circularBuffer_t *circular_buffer_find_unused_instance(void);

/* Private Function Definitions */
static circularBuffer_t *circular_buffer_find_unused_instance(void)
{
    for (int i = 0; i < CB_MAX_INSTANCE_POOL_SIZE; i++){
        if (circularBufferPool[i].inUse == false)
            return &circularBufferPool[i];
    }
}

/* Creates and inits new circular buffer object */
circularBuffer_t *circular_buffer_init(size_t itemSize)
{
    if (instanceNumber == CB_MAX_INSTANCE_POOL_SIZE - 1)
        return NULL;

    circularBuffer_t *newCircularBuffer = circular_buffer_find_unused_instance();
    newCircularBuffer->itemSize = itemSize;
    newCircularBuffer->capacity = CB_MAX_BUFFER_POOL_SIZE / itemSize;

    /* We could not create item in Circular Buffer Pool */
    /* Item Size is too big to create item in Circular Buffer Pool */
    if (newCircularBuffer->capacity == 0)
        return NULL;

    newCircularBuffer->head = 0;
    newCircularBuffer->tail = 0;
    newCircularBuffer->inUse = true;
    (void) memset(newCircularBuffer->data, 0, CB_MAX_BUFFER_POOL_SIZE);
    instanceNumber++;

    return newCircularBuffer;
}

/* Deletes the circular buffer object */
void circular_buffer_destroy(circularBuffer_t *circularBuffer)
{
    if (!circularBuffer || instanceNumber == 0)
        return;

    (void) memset(circularBuffer->data, 0, CB_MAX_BUFFER_POOL_SIZE);
    circularBuffer->inUse = false;
    instanceNumber--;
}

/* Pushes new data to buffer and moves tail to next position */
bool circular_buffer_push(circularBuffer_t *const circularBuffer, const void *data)
{
    if (circular_buffer_full(circularBuffer))
        return false;
    
    int index = (circularBuffer->tail + 1) % (circularBuffer->capacity * circularBuffer->itemSize);
    (void) memcpy((void *)&circularBuffer->data[index], data, circularBuffer->itemSize);
    circularBuffer->tail = (circularBuffer->tail + circularBuffer->itemSize) % (circularBuffer->capacity * circularBuffer->itemSize);
 
    return true;
}

/* Poppes data from buffer and moves head to next position */
bool circular_buffer_pop(circularBuffer_t *const circularBuffer, void *data)
{
    if (circular_buffer_empty(circularBuffer))
        return false;
    
    int index = (circularBuffer->head + 1) % (circularBuffer->capacity * circularBuffer->itemSize);
    (void) memcpy(data, (void *)&circularBuffer->data[index], circularBuffer->itemSize);
    circularBuffer->data[circularBuffer->head] = 0;
    circularBuffer->head = (circularBuffer->head + circularBuffer->itemSize) % (circularBuffer->capacity * circularBuffer->itemSize);

    if (circular_buffer_empty(circularBuffer)){
        circularBuffer->head = 0;
        circularBuffer->tail = 0;
    }
 
    return true;
}

/* Checks whether the circular buffer empty (true) or not (false) */
bool circular_buffer_empty(const circularBuffer_t *const circularBuffer)
{
    /* If the tail and head pointers are equal, it means that circlar buffer is empty.
        Because of that reason, the one more space is used in circular buffer design */
    return (circularBuffer->tail == circularBuffer->head) ? true : false;
}

/* Checks whether the circular buffer full (true) or not (false) */
bool circular_buffer_full(const circularBuffer_t *const circularBuffer)
{
    /*  If the next move of tail equals to head, it means that circular buffer is full.
        Since the buffer is circular, we should take the mode of tail with capacity
        to calculate the next position of tail pointer */
    return (((circularBuffer->tail + circularBuffer->itemSize) % (circularBuffer->capacity * circularBuffer->itemSize)) 
                 == circularBuffer->head) ? true : false;
}

/* Gets the free available space in circular buffer */
int circular_buffer_free_space(const circularBuffer_t *const circularBuffer)
{
    int freeSpace = 0;

    if (circularBuffer->head > circularBuffer->tail)
        freeSpace = ((circularBuffer->head - circularBuffer->tail) / circularBuffer->itemSize) - 1;
    else 
        freeSpace = circularBuffer->capacity - ((circularBuffer->tail - circularBuffer->head) / circularBuffer->itemSize) - 1;
    
    return freeSpace;
}

/* Gets the capacity of circular buffer */
int circular_buffer_capacity(const circularBuffer_t *const circularBuffer)
{
    return circularBuffer->capacity;
}
