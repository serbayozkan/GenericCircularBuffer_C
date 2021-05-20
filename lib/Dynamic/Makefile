# Circular Buffer Data Structure Dynamic Library Makefile

CC=gcc

CFLAGS=	-c

LINK_TARGET=test_cb_dynamic

OBJS= \
	test_cb_dynamic.o \
	circular_buffer.o

REBUILDABLES= $(OBJS) $(LINK_TARGET)

RM := rm -rf

all: dynamic

dynamic: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) $(OBJS) -o test_cb_dynamic
	@echo 'Finished building target: $@'
	@echo ' '
	./test_cb_dynamic

test_static.o: test_cb_dynamic.c
	$(CC) $(CFLAGS) test_cb_dynamic.c


circular_buffer.o: circular_buffer.c
	$(CC) $(CFLAGS) circular_buffer.c


clean: 
	$(RM) $(REBUILDABLES)

