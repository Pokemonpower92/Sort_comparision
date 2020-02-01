CC = g++
CFLAGS = -std=c++11

# Directories
ODIR = obj
SDIR = src
IDIR = include
IODIR = io
BDIR = benchmarking

# Files
PROGRAMS = bin/sort_tester
SRCS = sort_tester.cpp

# Paths

SOURCES= $(patsubst %, $(SDIR)/%, $(SRCS))
OBJECTS= $(patsubst %, $(ODIR)/%, $(SRCS:.cpp=.o))
BENCHMARKING= $(patsubst %, $(BDIR)/%, *.txt)
IO= $(patsubst %, $(IODIR)/%, *.txt)

# Make everything
all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS) $(BENCHMARKING) $(IO)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(IDIR) -o $@ -c $^

bin/sort_tester: $(OBJECTS)
	$(CC) $(CFLAGS) -I$(IDIR) -o $(PROGRAMS) $(OBJECTS)

files:
	python scripts/gen.py
	./bin/sort_tester
