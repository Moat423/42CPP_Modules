SHELL := /bin/bash
.ONESHELL:
MAKEFILES :=
MAKEFLAGS += --no-print-directory --warn-undefined-variables

NAME := mySed
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -pedantic -std=c++98 -fPIE -g

SRCS := main.cpp

OBJS := $(SRCS:.cpp=.o)

BOLD := $(shell printf '\033[1m')
RESET := $(shell printf '\033[0m')
RED := $(shell printf '\033[31;2m')
GREEN := $(shell printf '\033[32m')
YELLOW := $(shell printf '\033[33m')
CLEAR_LINE := $(shell printf '\033[2K')
CURSOR_UP := $(shell printf '\033[1A')
PHONY := all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(BOLD)Linking $(NAME)$(RESET)\n"
	$(CXX) $(CXXFLAGS) -o $@ $^ && \
	printf "\n$(GREEN)$(BOLD)Build successful!$(RESET)\n" || \
	printf "$(RED)$(BOLD)Build failed!$(RESET)\n"

%.o: %.cpp
	@printf "$(YELLOW)Compiling $(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: all
	./$(NAME)
	./$(NAME) testfile cats dogs toomanyargs
	./$(NAME) invalidfile cats dogs
	./$(NAME) testfile cats dogs

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
