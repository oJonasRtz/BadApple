NAME = player
LIBS = $(shell pkg-config --cflags --libs opencv4)
SRC = player.cpp
COMPILER = g++ -std=c++20

all: $(NAME)

$(NAME):
	@$(COMPILER) -I. $(SRC) -o $(NAME) $(LIBS)

run: all
	./$(NAME) BadApple.mp4

clear:
	rm -f $(NAME)

re: clear all run

.PHONY: all run clear re