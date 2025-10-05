CC = gcc

SRCS = main.c addition.c division.c multiplication.c subtraction.c apc_utils.c dll.c
HEADERS = apc.h

OBJS = $(SRCS:.c=.o)

EXEC = apc

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

cleanall: clean
	rm -f $(EXEC) $(OBJS)
