EXE = Tanks.app
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
SYSTEM = windows

ifeq ($(SYSTEM),linux)
LIBS = -lSDL2 -lSDL2_image -lSDL2_net
else
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_net
endif

SDL_INCLUDE_DIR = C:\tools\mingw64\include
SDL_LIBRARY_DIR = C:\tools\mingw64\lib

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = g++

IFLAGS = -I$(INC_DIR) -I$(SDL_INCLUDE_DIR)
LFLAGS = -L$(SDL_LIBRARY_DIR)
OBJ_NAME = Tanks

.PHONY : all clean

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $^ $(IFLAGS) $(LFLAGS) $(LIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $< $(IFLAGS) $(LFLAGS) $(LIBS) -o $@

clean :
	rm -rf $(OBJ)
