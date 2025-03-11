SHELL := /bin/bash
.ONESHELL:
MAKEFILES :=
MAKEFLAGS += --no-print-directory --warn-undefined-variables

CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -pedantic -std=c++98

SRCS := Harl.cpp main.cpp

OBJS := $(SRCS:.cpp=.o)

CPLUS_INCLUDE_PATH := .

BOLD := $(shell printf '\033[1m')
RESET := $(shell printf '\033[0m')
RED := $(shell printf '\033[31;2m')
GREEN := $(shell printf '\033[32m')
YELLOW := $(shell printf '\033[33m')
CLEAR_LINE := $(shell printf '\033[2K')
CURSOR_UP := $(shell printf '\033[1A')

NAME := harlFilter

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(BOLD)Linking $(NAME)$(RESET)\n"
	$(CPP) $(CPPFLAGS) -o $@ $^ && \
	printf "\n$(GREEN)$(BOLD)Build successful!$(RESET)\n" || \
	printf "$(RED)$(BOLD)Build failed!$(RESET)\n"

%.o: %.cpp
	@printf "$(YELLOW)Compiling $(RESET)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

test: all
	./$(NAME) "WARNING"
	./$(NAME) "I am not sure how tired I am today..."
	./$(NAME) "DEBUG"

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
