CC= g++ -g
CFLAGS= -Wall
OBJ= obj/main.o obj/Game.o
COMP= -I/usr/include/SDL2
LIB= -lSDL2 
LINKEDIT= -L/usr/bin/sdl2-config
EXEC= bin/Prog
all: $(EXEC)
$(EXEC): $(OBJ) 
	$(CC) $(OBJ) -o $(EXEC) $(LINKEDIT) $(LIB) 
obj/main.o: src/main.cpp 
	$(CC) $(CFLAGS) src/main.cpp -c -o obj/main.o $(COMP) $(LIB)
obj/Game.o: src/Game.cpp 
	$(CC) $(CFLAGS) src/Game.cpp -c -o obj/Game.o $(COMP) $(LIB)			

cleanO:
	rm obj/*

veryclean:
	rm bin/*	