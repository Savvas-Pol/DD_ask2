CC=gcc
CFLAGS=-Wall


askisi2: main.o Menu.o TyposStoixeiouMenu.o
	$(CC) $(CFLAGS) -o askisi2 main.o Menu.o TyposStoixeiouMenu.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

Menu.o: Menu.c
	$(CC) $(CFLAGS) -c Menu.c

TyposStoixeiouMenu.o: TyposStoixeiouMenu.c
	$(CC) $(CFLAGS) -c TyposStoixeiouMenu.c

.PHONY: clean

clean:
	rm -f askisi2 main.o Menu.o TyposStoixeiouMenu.o
