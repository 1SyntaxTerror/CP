CC = clang
CFLAGS = -Wall

TARGET = main
HEADERS = functii.h
OBJ = main.o functii.o
LIBS = -lm


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o
	rm $(TARGET)
