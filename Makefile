CC = clang++
CFLAGS = -Wall -Wextra -std=c++14
TARGET = bin/ttt_game
DEPS = main.o board.o human.o computer.o player.o game.o
INCLUDES = -Ilib/players
LIBDIR = -Ilib

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPS)

main.o: lib/main.cpp
	$(CC) $(INCLUDES) $(LIBDIR) -c $(CFLAGS) lib/main.cpp

board.o: lib/board.cpp
	$(CC) $(INCLUDES) -c $(CFLAGS) lib/board.cpp

game.o: lib/game.cpp
	$(CC) $(INCLUDES) $(LIBDIR) -c $(CFLAGS) lib/game.cpp

human.o: lib/players/human.cpp
	$(CC) -c $(CFLAGS) $(LIBDIR) lib/players/human.cpp

computer.o: lib/players/computer.cpp
	$(CC) -c $(CFLAGS) $(LIBDIR) lib/players/computer.cpp

player.o: lib/players/player.cpp
	$(CC) $(LIBDIR) -c $(CFLAGS) lib/players/player.cpp

clean:
	rm $(DEPS) $(TARGET)

	
