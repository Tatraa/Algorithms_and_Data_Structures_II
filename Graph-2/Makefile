CC = g++
CFLAGS = -Wall -std=c++11

OBJECTS1 = main.o

TARGET1 = main.out

.PHONY: all
all:$(TARGET1)

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET1) : $(OBJECTS1)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS1) -o $(TARGET1)

.PHONY: all
all:$(TARGET1)

.PHONY : clean

clean :
	$(RM) *.o *.out core