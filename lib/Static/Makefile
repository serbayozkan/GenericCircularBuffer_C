# Circular Buffer Data Structure Static Library Makefile

CC=gcc

CFLAGS=	-c

LINK_TARGET=test_cb_static

OBJS= \
	test_cb_static.o \
	circular_buffer.o

REBUILDABLES= $(OBJS) $(LINK_TARGET)

RM := rm -rf

all: static

static: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) $(OBJS) -o test_cb_static
	@echo 'Finished building target: $@'
	@echo ' '
	./test_cb_static 

test_static.o: test_cb_static.c
	$(CC) $(CFLAGS) test_cb_static.c


circular_buffer.o: circular_buffer.c
	$(CC) $(CFLAGS) circular_buffer.c


clean: 
	$(RM) $(REBUILDABLES)

