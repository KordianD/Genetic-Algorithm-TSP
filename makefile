CC = g++
CFLAGS = -g -Wall -Wextra -Wzero-as-null-pointer-constant 
SRCS = main.cpp Initializer.cpp Path.cpp
PROG = genetic_tsp

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
