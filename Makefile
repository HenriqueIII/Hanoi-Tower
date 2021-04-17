CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
_SRCOBJ = #All cpp to debug
SRCOBJ = $(patsubst %,$(SRC)/%,$(_SRCOBJ))
INCLUDE := include/

#Creates list of Objects to make
ODIR 	:= obj
_OBJ = #All objects to be included
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
	$(CXX) $(CXX_FLAGS) $(SRC)/$(EXECUTABLE).cpp $(SRCOBJ) $(OBJ) -I$(INCLUDE) -L$(LIBRARIES) -Wl,-rpath='$$ORIGIN' -o $(BIN)/$(EXECUTABLE) -lUtil -lncursesw
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
	
