
all: engine tools

engine:
	g++ -c src/animation_manager.cpp
	g++ -c src/input.cpp
	g++ -c src/text_window.cpp
	g++ -c src/console_window.cpp
	g++ -c src/tile.cpp
	g++ -c src/game.cpp
	g++ -c src/object.cpp
	g++ -c src/sprite_manager.cpp
	
	g++ -c src/object_lua.cpp
	g++ -c src/text_window_lua.cpp
	g++ -c src/input_lua.cpp
	g++ -c src/tile_lua.cpp
	g++ -c src/game_lua.cpp
	mv *.o obj/
	g++ src/main.cpp obj/*.o -o gge.exe  `gorgon-config --libs --addons --addon_sdl --addon_magick` -lguichan -lguichan_allegro -fopenmp

clean:
	@rm -rf main.e
	@rm -rf ./include/*~
	@rm -rf ./src/*~
	@rm -rf ./*~

tools: bgGen

bgGen:
	g++ tools/background_generator.cpp -o tools/background_generator.exe `gorgon-config --libs --addons --addon_sdl --addon_magick` 
