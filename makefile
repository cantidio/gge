INCLUDEDIR= "./src/"
all: 
	g++						\
	./src/main.cpp			\
	./obj/video.o			\
	./obj/background.o		\
	./obj/object.o			\
	./obj/player.o			\
	./obj/item.o			\
	./obj/itens.o			\
	./obj/gui.o				\
	./obj/enemy.o			\
	./obj/caterpie.o		\
	./obj/mush.o			\
	./obj/rabbit.o			\
	-o main.e				\
	`gorgon-config --libs`	\
	`allegro-config --libs`	\

video: ./include/video.hpp ./src/video.cpp
	g++ -c ./src/video.cpp
	mv video.o ./obj/video.o

background: ./include/background.hpp ./src/background.cpp
	g++ -c ./src/background.cpp
	mv background.o ./obj/background.o
	
object: ./include/object.hpp ./src/object.cpp
	g++ -c ./src/object.cpp
	mv object.o ./obj/object.o

clean:
	@rm -rf main.e
	@rm -rf ./include/*~
	@rm -rf ./src/*~
	@rm -rf ./*~

createbg:
	g++ ./bg_make/main.c -o a.out	../gorgon_core/static/libgorgon.a `allegro-config --libs`
	g++ ./bg_make/maine.c -o a2.out ../gorgon_core/static/libgorgon.a `allegro-config --libs`
	mv a.out ./bg_make/a.out
	mv a2.out ./bg_make/a2.out
	
