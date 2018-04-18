# Makefile for the LPI Project "Conway`s Simulator"

# Creators:
# 	- Felipe Ramos

# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin
# datadir = ./data

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -I$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,cell.o generation.o canvas.o io.o)

# Phony targets
.PHONY: clean cleanobj cleanbin cleansym
.PHONY: all run main build cell generation canvas io


# Use "make" to execute everything
all: build main

# Use "make run" to compile and execute everything
run: build main conway

# Use "make main" to compile the main
main: conway

# Use "make build" to build all the modules
build: cell generation canvas io

# Use "make <name>" to build only the <name> module
cell: $(objdir)/cell.o
generation: $(objdir)/generation.o
canvas: $(objdir)/canvas.o
io: $(objdir)/io.o

# Compiles the main
conway: $(srcdir)/main.cpp $(OBJS)
	@mkdir -p $(bindir)
	@$(CC) $(CFLAGS) $^ -o $(bindir)/$@
	@ln -sFv $(bindir)/$@ $@
	@echo "Symlink created with sucess! To execute just type ./$@\n\n"


# Builds only the cell module
$(objdir)/cell.o: $(srcdir)/cell.cpp $(incdir)/cell.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the generation module
$(objdir)/generation.o: $(srcdir)/generation.cpp $(incdir)/generation.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the canvas module
$(objdir)/canvas.o: $(srcdir)/canvas.cpp $(incdir)/canvas.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the io module
$(objdir)/io.o: $(srcdir)/io.cpp $(incdir)/io.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(objdir)/*.o

# Clean all executables
cleanbin:
	$(RM) -rf $(bindir)/*

cleansym:
	$(RM) -rf conway

clean: cleanobj cleanbin cleansym
