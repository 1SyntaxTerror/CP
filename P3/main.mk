
main: main.o
	clang -Wall main.o -o main

main.o: main.c
	clang -c -Wall main.c

.PHONY: clean

clean:
	rm main
	rm -f *.o
