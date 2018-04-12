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
OBJS = $(addprefix $(objdir)/,utils.o )

# Phony targets
.PHONY: clean cleanobj cleanbin 
.PHONY: all run main build utils 


# Use "make" to execute everything
all: build main

# Use "make run" to compile and execute everything
run: build main conway

# Use "make main" to compile the main
main: conway 

# Use "make build" to build all the modules
build: utils

# Use "make <name>" to build only the <name> module
utils: $(objdir)/utils.o

# Compiles the main
conway: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $(bindir)/$@
	@ln -sFv $(bindir)/$@ $@
	@echo "Symlink created with sucess! To execute just type ./$@"


# Builds only the utils module
$(objdir)/utils.o: $(srcdir)/utils.cpp $(incdir)/utils.hpp
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj: 
	$(RM) $(objdir)/*.o

# Clean all executables
cleanbin:
	$(RM) -rf $(bindir)/*


clean: cleanobj cleanbin 
