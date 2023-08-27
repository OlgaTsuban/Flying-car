CC = clang
EXECUTABLE = endgame


CFLAGS = `sdl2-config --libs --cflags` -std=c11 -Werror -Wpedantic -Wno-unused-command-line-argument -Wno-unused-variable -Wno-unused-function -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm -g

SOURCES := $(wildcard src/*.c)
OBJECTS = $(addprefix obj/,$(notdir $(SOURCES:.c=.o)))

all: objdir $(SOURCES) $(EXECUTABLE)

objdir:
	mkdir -p obj

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

obj/%.o: src/%.c
	clang -std=c11 -Wall -Wextra -Wpedantic -I/usr/include/SDL2 -Wno-unused-command-line-argument -Wno-unused-variable -Wno-unused-function -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -g -c -o $@ $<

uninstall: clean
	rm -rf $(EXECUTABLE)

clean:

reinstall: uninstall all



NAME = endgame

