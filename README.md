# Generic Circular/Ring Buffer Data Structure Library for Embedded Devices

## Library
**Static Lib** -> Uses memory and object pool for allocation of Circular Buffer objects

**Dynamic Lib** -> Uses dynamic memory only in initilization for allocation of Circular Buffer objects

## Examples
**STM32F4_DISCOVERY**

Data taken from ISR (UART Receive Completed Callback) is pushed to circular buffer. In superloop, produced data is comsumed by popping data from circular buffer and printing out to console directly. 

## APIs

![Circular_Buffer_API_List](https://user-images.githubusercontent.com/43597729/118403931-7da20400-b679-11eb-9364-aac6923e6732.png)

## Licencing
Licenced the under the MIT open source licence

## Contact
serbay_ozkan@hotmail.com 

https://www.linkedin.com/in/serbayozkan/
