all: video object background player gui enemy caterpie coguns rabbit
	g++						\
	./src/main.cpp				\
	./obj/video.o				\
	./obj/background.o			\
	./obj/object.o				\
	./obj/player.o				\
	./obj/gui.o				\
	./obj/enemy.o				\
	./obj/caterpie.o			\
	./obj/mush.o				\
	./obj/rabbit.o				\
	-o main.e				\
	../gorgon_core/static/libgorgon.a	\
	`allegro-config --libs`			\

video: ./include/video.hpp ./src/video.cpp
	g++ -c ./src/video.cpp
	mv video.o ./obj/video.o
background: ./include/background.hpp ./src/background.cpp
	g++ -c ./src/background.cpp
	mv background.o ./obj/background.o
	
object: ./include/object.hpp ./src/object.cpp
	g++ -c ./src/object.cpp
	mv object.o ./obj/object.o

player: ./include/player.hpp ./src/player.cpp
	g++ -c ./src/player.cpp
	mv player.o ./obj/player.o

gui: ./include/gui.hpp ./src/gui.cpp
	g++ -c ./src/gui.cpp
	mv gui.o ./obj/gui.o

enemy: ./include/enemy.hpp ./src/enemy.cpp
	g++ -c ./src/enemy.cpp
	mv enemy.o ./obj/enemy.o

caterpie: ./include/caterpie.hpp ./src/caterpie.cpp
	g++ -c ./src/caterpie.cpp
	mv caterpie.o ./obj/caterpie.o


coguns:	./include/mush.hpp ./src/mush.cpp
	g++ -c ./src/mush.cpp
	mv mush.o ./obj/mush.o
	
	
rabbit: ./include/rabbit.hpp ./src/rabbit.cpp
	g++ -c ./src/rabbit.cpp
	mv rabbit.o ./obj/rabbit.o

clean:
	@rm -rdf ./include/*~
	@rm -rdf ./src/*~
	@rm -rdf ./*~

createbg:
	g++ ./bg_make/main.c -o a.out	../gorgon_core/static/libgorgon.a `allegro-config --libs`
	g++ ./bg_make/maine.c -o a2.out ../gorgon_core/static/libgorgon.a `allegro-config --libs`
	mv a.out ./bg_make/a.out
	mv a2.out ./bg_make/a2.out
	
