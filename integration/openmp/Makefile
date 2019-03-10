
###############################################################################
CC = gcc
CCFLAGS = -Wall -I $(INCLUDE) -std=gnu99 -lm -fopenmp
LDFLAGS = -lm -fopenmp
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = openmp

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

###############################################################################

clean:
	rm -f *.o $(TARGET)
	rm -f $(SRC)/*.o
