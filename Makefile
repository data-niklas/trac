.POSIX:
.SUFFIXES:
CC     = gcc
LIBS= x11
CFLAGS = -Wall $(shell pkg-config --cflags $(LIBS)) -lm -lstdc++ -pthread
LDLIBS = $(shell pkg-config --libs $(LIBS))
LDFLAGS = 
SRCS=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS=$(SRCS:.cpp=.o)
NAME=trac

all: build
run: clean build
	./trac
	
	

build: $(SRCS)
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LDLIBS)	

debug: $(SRCS)
	$(CC) -o $(NAME) $^ $(CFLAGS) -g $(LDLIBS)

test:
	$(CC) $(LDFLAGS) -o $(NAME) $(wildcard *.o) $(LDLIBS)

clean:
	rm -f $(wildcard *.o) $(NAME)