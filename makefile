all: video object player rabbit
	g++						\
	./src/main.cpp				\
	./obj/video.o				\
	./obj/player.o				\
	./obj/rabbit.o				\
	./obj/object.o				\
	-o main.e				\
	../gorgon_core/static/libgorgon.a	\
	`allegro-config --libs`			\

video: ./include/video.hpp ./src/video.cpp
	g++ -c ./src/video.cpp
	mv video.o ./obj/video.o
	
object: ./include/object.hpp ./src/object.cpp
	g++ -c ./src/object.cpp
	mv object.o ./obj/object.o

player: ./include/player.hpp ./src/player.cpp
	g++ -c ./src/player.cpp
	mv player.o ./obj/player.o

rabbit: ./include/rabbit.hpp ./src/rabbit.cpp
	g++ -c ./src/rabbit.cpp
	mv rabbit.o ./obj/rabbit.o

clean:
	@rm -rdf ./include/*~
	@rm -rdf ./src/*~
	@rm -rdf ./*~
