# compiler shit
CC = gcc
INCLUDE = -I. -I./src
LIBS = -lm -lSDL
# obj shit
OBJS := src/main.o src/kanako.o
NAME = pool.out

%.o: %.c
	$(CC) -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm $(OBJS)

