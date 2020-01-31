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

# Make everything
all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(IDIR) -o $@ -c $^

bin/sort_tester: $(OBJECTS)
	$(CC) $(CFLAGS) -I$(IDIR) -o $(PROGRAMS) $(OBJECTS)

numbers:
	python scripts/gen.py
