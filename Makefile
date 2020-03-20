# compiler shit
CC = gcc
INCLUDE = -I. -I./src
LIBS = -lm
# obj shit
OBJS := src/main.o src/suwa_obj.o
NAME = pool.out

%.o: %.c
	$(CC) -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm $(OBJS)

