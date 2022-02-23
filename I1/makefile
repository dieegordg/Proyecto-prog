
OBJ = command.o game.o game_loop.o graphic_engine.o space.o game_reader.o object.o player.o

all: ejecutar clean

ejecutar: $(OBJ) libscreen.a 
	@gcc -o hormiguero $(OBJ) -L. -lscreen

start: hormiguero.dat
	@valgrind ./hormiguero hormiguero.dat

game_reader.o: game_reader.c game_reader.h
	@gcc -c -Wall -pedantic -g game_reader.c

command.o: command.c command.h 
	@gcc -c -Wall -pedantic -g command.c
	
game_loop.o: game_loop.c graphic_engine.h game.h command.h
	@gcc -c -Wall -pedantic -g game_loop.c

game.o: game.c game.h
	@gcc -c -Wall -pedantic -g game.c

graphic_engine.o: graphic_engine.c graphic_engine.h libscreen.h command.h types.h space.h
	@gcc -c -Wall -pedantic -g graphic_engine.c
	
space.o: space.c space.h
	@gcc -c -Wall -pedantic -g space.c

object.o : object.c object.h
	@gcc -c -Wall -pedantic -g object.c

player.o: player.c player.h
	@gcc -c -Wall -pedantic -g player.c

clean:
	@rm -f *.o 

	