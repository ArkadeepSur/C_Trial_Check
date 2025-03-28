CC=gcc
CFLAGS=-Wall
TARGET=main.exe

all: $(TARGET)

$(TARGET): /main.c
	$(CC) $(CFLAGS) -o $(TARGET) /main.c

clean:
	del $(TARGET)
