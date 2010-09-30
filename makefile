
all: 
	g++ -c src/animation_manager.cpp
	g++ -c src/input.cpp
	g++ -c src/object_lua.cpp
	g++ -c src/text_window.cpp
	g++ -c src/tile.cpp
	g++ -c src/game.cpp
	g++ -c src/input_lua.cpp
	g++ -c src/object.cpp
	g++ -c src/sprite_manager.cpp
	g++ -c src/text_window_lua.cpp
	g++ -c src/tile_lua.cpp
	mv *.o obj/
	g++ src/main.cpp obj/*.o  `gorgon-config --libs` `allegro-config --libs`

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
	
