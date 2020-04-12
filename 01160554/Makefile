# Project:
# Makefile created by Dev-C++ 4.9.9.2

CPP = g++.exe
CC  = gcc.exe
WINDRES = windres.exe
RES =
OBJ = main.o $(RES)
LINKOBJ = main.o $(RES)
LIBS = -L"C:/MinGW/lib" -L"C:/Dev-Cpp/lib" -mwindows -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32
INCS = -I"C:/MinGW/include" -I"C:/Dev-Cpp/include"
CXXINCS = -I"C:/MinGW/include" -I"C:/MinGW/lib/gcc/mingw32/4.6.2/include" -I"C:/MinGW/lib/gcc/mingw32/4.6.2/include/c++" -I"C:/MinGW/lib/gcc/mingw32/4.6.2" -I"C:/MinGW/lib/gcc/mingw32/4.6.2/include/c++/backward" -I"C:/MinGW/lib/gcc/mingw32/4.6.2/include/c++/bits" -I"C:/MinGW/lib/gcc/mingw32/4.6.2/include/c++/mingw32/bits" -I"C:/Dev-Cpp/include" -I"C:/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"
BIN = Project.exe
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before Project.exe all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o "Project.exe" $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)
