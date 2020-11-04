.PHONY:clean
CC = g++

OBJS = main.o \
	   chessboard.o
main: $(OBJS)
	$(CC) $(OBJS) -o main -g

%.o : %.c
	$(CC) -c $^ -o $@ -g

clean:
	-rm -rf $(OBJS)
