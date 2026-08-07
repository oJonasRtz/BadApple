NAME = badApple
LIBS = $(shell pkg-config --cflags --libs opencv4)
SRC = badApple.cpp
COMPILER = g++ -std=c++20

all: $(NAME)

$(NAME):
	@$(COMPILER) -I. $(SRC) -o $(NAME) $(LIBS)

clear:
	rm -f $(NAME)

re: clear all