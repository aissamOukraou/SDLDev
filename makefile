CC= g++ -g
CFLAGS= -Wall
OBJ= obj/main.o obj/Game.o obj/TextureManager.o obj/GameObject.o obj/Player.o
COMP= -I/usr/include/SDL2
LIB= -lSDL2 -lSDL2_image 
LINKEDIT= -L/usr/bin/sdl2-config
EXEC= bin/Prog
all: $(EXEC)
$(EXEC): $(OBJ) 
	$(CC) $(OBJ) -o $(EXEC) $(LINKEDIT) $(LIB) 
obj/main.o: src/main.cpp 
	$(CC) $(CFLAGS) src/main.cpp -c -o obj/main.o $(COMP) $(LIB)
obj/Game.o: src/Game.cpp 
	$(CC) $(CFLAGS) src/Game.cpp -c -o obj/Game.o $(COMP) $(LIB)		
obj/TextureManager.o: src/TextureManager.cpp 
	$(CC) $(CFLAGS) src/TextureManager.cpp -c -o obj/TextureManager.o $(COMP) $(LIB)	
obj/GameObject.o: src/GameObject.cpp
	$(CC) $(CFLAGS) src/GameObject.cpp -c -o obj/GameObject.o $(COMP) $(LIB)
obj/Player.o: src/Player.cpp		
	$(CC) $(CFLAGS) src/Player.cpp -c -o obj/Player.o $(COMP) $(LIB)	

cleanO:
	rm obj/*

veryclean:
	rm bin/*	