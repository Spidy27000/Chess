compilerFlags := -Wall -Werror
includeFlags :=  -I/usr/local/include -I/usr/include 
linkerFlags := -L/usr/local/lib -L/usr/lib -lraylib -lm -lpthread -ldl -lrt 
ApiInculudeFlags := -Isrc/chessApi
MainInculudeFlags := -Isrc/MainGame
UtilsInculudeFlags := -Isrc/Utils

CC := g++

build: buildApi game.o main.o
	$(CC) -o Chess $(compilerFlags) $(linkerFlags)

buildApi: chessApi.o move.o peice.o board.o peices.o vec2.o
	$(CC) -fPIC -c obj/ChessApi.o obj/Move.o obj/Peice.o obj/Board.o obj/Peices.o obj/Vec2.o -o mainApi.so -shared $(linkerFlags)

chessApi.o: move.o peice.o board.o peices.o vec2.o
	$(CC) -c src/ChessApi/ChessApi.cpp -o obj/ChessApi.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
board.o:
	$(CC) -c src/ChessApi/Board.cpp -o obj/Board.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
move.o:
	$(CC) -c src/ChessApi/Move.cpp -o obj/Move.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
peice.o:
	$(CC) -c src/ChessApi/Peice.cpp -o obj/Peice.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
peices.o:
	$(CC) -c src/ChessApi/Peices.cpp -o obj/Peices.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
vec2.o:
	$(CC) -c src/ChessApi/Vec2.cpp -o obj/Vec2.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
game.o: 
	$(CC) -c src/MainGame/Game.cpp -o obj/Game.o $(compilerFlags) $(includeFlags) $(ApiInculudeFlags) $(UtilsInculudeFlags)
main.o:
	$(CC) -c src/MainGame/main.cpp -o obj/main.o $(compilerFlags) $(includeFlags) $(MainInculudeFlags) $(UtilsInculudeFlags)

clean:
	rm -rf obj/*.o
	rm -rf ./Chess