CC=gcc
CFLAGS=-Wall -Wextra -O2
TARGET=passgen

all: $(TARGET)

$(TARGET): main.c generator.c generator.h
	$(CC) $(CFLAGS) -o $(TARGET) main.c generator.c

clean:
	rm -f $(TARGET)
