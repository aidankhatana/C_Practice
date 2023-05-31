CC = gcc
CFLAGS = -Wall -Werror
SRCS = stackDemo.c intstack.c
TARGET = stackDemo


all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	@echo "Cleaning up..."
	rm -f $(TARGET)