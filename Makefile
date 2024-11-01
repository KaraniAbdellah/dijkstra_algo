CC=gcc
CFLAGS = -Wall -Wextra
EXEC=main
FILIES=fun.c main.c

build:
	$(CC) $(CFALGS) $(FILIES) -o $(EXEC)


clean:
	rm $(EXEC)



