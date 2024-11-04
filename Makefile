CC=gcc
CFLAGS = -Wall -Wextra
EXEC=main
FILES=src/fun.c main.c

build: vis
	$(CC) $(CFLAGS) $(FILES) -o $(EXEC)

clean:
	rm $(EXEC) dot/g.dot dot/g.png  # Clean up the generated files

vis:
	make -Bnd | make2graph | dot -Tpng dot/g.dot -o dot/g.png  # Generate the PNG from g.dot


