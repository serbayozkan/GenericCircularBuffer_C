# Generic Circular/Ring Buffer Data Structure Library for Embedded Devices

## Library
**Static Lib** -> Uses memory and object pool for allocation of Circular Buffer objects

**Dynamic Lib** -> Uses dynamic memory only in initilization for allocation of Circular Buffer objects

## Examples
**STM32F4_DISCOVERY**

Data taken from ISR (UART Receive Completed Callback) is pushed to circular buffer. In superloop, produced data is comsumed by popping data from circular buffer and printing out to console directly. 

## APIs

| API Name                        | Definition                                                          |
| --------------------------------|---------------------------------------------------------------------| 
| **circular_buffer_init**        | Creates and inits new circular buffer object                        |    
| **circular_buffer_destroy**     | Deletes the circular buffer object and frees the allocated space    | 
| **circular_buffer_push**        | Pushes new data to buffer and moves tail to next position           | 
| **circular_buffer_pop**         | Poppes data from buffer and moves head to next position             | 
| **circular_buffer_empty**       | Checks whether the circular buffer empty (true) or not (false)      | 
| **circular_buffer_full**        | Checks whether the circular buffer full (true) or not (false)       | 
| **circular_buffer_free_space**  | Gets the free available space in circular buffer                    | 
| **circular_buffer_capacity**    | Gets the capacity of circular buffer                                | 

## Licencing
Licenced the under the MIT open source licence

## Contact
serbay_ozkan@hotmail.com 

https://www.linkedin.com/in/serbayozkan/




