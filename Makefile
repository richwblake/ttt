ttt_game : main.o human.o game.o board.o
	clang++ -std=c++14 -Wall -Wextra human.o main.o game.o board.o -o ttt_game
	mv ttt_game bin/
	rm main.o game.o human.o board.o
main.o : main.cpp
	@echo "Creating"
	clang++ -std=c++14 -Ilib/players -c lib/main.cpp

human.o : human.cpp
	clang++ -std=c++14 -c lib/players/human.cpp

game.o : game.cpp
	clang++ -std=c++14 -c -Ilib/players lib/game.cpp

board.o : board.cpp
	clang++ -std=c++14 -c -Ilib/players lib/board.cpp

board.cpp:

game.cpp:

main.cpp:

human.cpp:
