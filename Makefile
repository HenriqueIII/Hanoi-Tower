CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
_SRCOBJ = Game.cpp Arena.cpp Status.cpp Obstacle.cpp Snake.cpp Mouse.cpp
SRCOBJ = $(patsubst %,$(SRC)/%,$(_SRCOBJ))
INCLUDE := include/

#Creates list of Objects to make
ODIR 	:= obj
_OBJ = Game.o Status.o Obstacle.o Arena.o Mouse.o Snake.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

LIBRARIES   := lib

EXECUTABLE  := main

ifeq ($(OS),Windows_NT)
	TOBUILD := win32
else
	TOBUILD := linux
endif

all: $(TOBUILD)

win32: $(OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC)/$(EXECUTABLE).cpp $(OBJ) -o$(BIN)/$(EXECUTABLE).exe -L lib -I include -I include/curses lib/libUtil.a -lstdc++
	copy $(LIBRARIES)\libUtil.dll bin
	copy pdcurses.dll bin

linux: $(OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC)/$(EXECUTABLE).cpp $(OBJ) -I$(INCLUDE) -L$(LIBRARIES) -Wl,-rpath='$$ORIGIN' -o $(BIN)/$(EXECUTABLE) -lUtil -lncurses
	cp $(LIBRARIES)/libUtil.so $(BIN)

$(OBJ): $(ODIR)/%.o: $(SRC)/%.cpp
ifeq ($(OS),Windows_NT)
	$(CXX) -c $< -o $@ -I$(INCLUDE) -I$(INCLUDE)curses -L$(LIBRARIES)
else
	$(CXX) -c $< -o $@ -I$(INCLUDE)
endif

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
ifeq ($(OS),Windows_NT)
	del /F /s /q $(BIN)\* $(ODIR)\*
else
	-rm $(BIN)/* $(ODIR)/*
endif
	
