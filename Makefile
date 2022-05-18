CC = clang++
CFLAGS = -Wall -Wextra -std=c++14
TARGET = bin/ttt_game
DEPS = main.o board.o human.o game.o
INCLUDES = -Ilib/players

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPS)

main.o: lib/main.cpp
	$(CC) $(INCLUDES) -c $(CFLAGS) lib/main.cpp

board.o: lib/board.cpp
	$(CC) $(INCLUDES) -c $(CFLAGS) lib/board.cpp

game.o: lib/game.cpp
	$(CC) $(INCLUDES) -c $(CFLAGS) lib/game.cpp

human.o: lib/players/human.cpp
	$(CC) -c $(CFLAGS) lib/players/human.cpp

clean:
	rm $(DEPS) $(TARGET)

	
