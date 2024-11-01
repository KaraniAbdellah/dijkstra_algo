CC=gcc
CFLAGS = -Wall -Wextra
EXEC=main
FILES=fun.c main.c

build: vis
	$(CC) $(CFLAGS) $(FILES) -o $(EXEC)

clean:
	rm $(EXEC) g.dot g.png  # Clean up the generated files

vis:
	make -Bnd | make2graph | dot -Tpng g.dot -o g.png  # Generate the PNG from g.dot


