.POSIX:
.SUFFIXES:
CC     = gcc
LIBS= x11
CFLAGS = -Wall $(shell pkg-config --cflags $(LIBS)) -lm -lstdc++ -pthread
LDLIBS = $(shell pkg-config --libs $(LIBS))
LDFLAGS = 
SRCS=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*.cc) $(wildcard src/*/*/*.cpp)
OBJS=$(SRCS:.cpp=.o)
NAME=trac

all: build
run: clean build
	./trac
run_lex: clean parser build
	./trac
	
	
parser:
	cd src/parser;bison -d -v Trac.yy
	cd src/parser;flex --outfile=Trac.yy.cc Trac.l
	rm src/parser/*.output

build: $(SRCS)
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LDLIBS)	-O3

debug: $(SRCS)
	$(CC) -o $(NAME) $^ $(CFLAGS) -g $(LDLIBS)

test:
	$(CC) $(LDFLAGS) -o $(NAME) $(wildcard *.o) $(LDLIBS)

clean:
	rm -f $(wildcard *.o) $(NAME)