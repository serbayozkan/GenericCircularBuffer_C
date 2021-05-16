/**
  ******************************************************************
  * @file    circular_buffer.h
  * @author  Serbay Ozkan
  * @date    12 May 2021
  * @brief   Circular Buffer Data Structure Header File
  ******************************************************************
  */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

/* Standard Library Header Files */
#include <stdbool.h>
#include <stdlib.h>

/* Forward decleration of circularBuffer struct */
typedef struct circularBuffer circularBuffer_t;

/* Creates and inits new circular buffer object */
circularBuffer_t *circular_buffer_init(size_t itemSize, int capacity);

/* Deletes the circular buffer object and frees the allocated space */
void circular_buffer_destroy(circularBuffer_t **circularBuffer);

/* Pushes new data to buffer and moves tail to next position */
bool circular_buffer_push(circularBuffer_t *const circularBuffer, const void *data);

/* Poppes data from buffer and moves head to next position */
bool circular_buffer_pop(circularBuffer_t *const circularBuffer, void *data);

/* Checks whether the circular buffer empty (true) or not (false) */
bool circular_buffer_empty(const circularBuffer_t *const circularBuffer);

/* Checks whether the circular buffer full (true) or not (false) */
bool circular_buffer_full(const circularBuffer_t *const circularBuffer);

/* Gets the free available space in circular buffer */
int circular_buffer_free_space(const circularBuffer_t *const circularBuffer);

/* Gets the capacity of circular buffer */
int circular_buffer_capacity(const circularBuffer_t *const circularBuffer);

#endif /* CIRCULAR_BUFFER_H_ */
