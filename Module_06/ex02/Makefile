SHELL := /bin/bash
.ONESHELL:
MAKEFILES :=
MAKEFLAGS += --no-print-directory --warn-undefined-variables

NAME := a.out
CXX := c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

HDRS := Debug.hpp Base.hpp A.hpp B.hpp C.hpp

SRCS := main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJS := $(SRCS:.cpp=.o)

BOLD := $(shell printf '\033[1m')
RESET := $(shell printf '\033[0m')
RED := $(shell printf '\033[31;2m')
GREEN := $(shell printf '\033[32m')
YELLOW := $(shell printf '\033[33m')
CLEAR_LINE := $(shell printf '\033[2K')
CURSOR_UP := $(shell printf '\033[1A')
PHONY := all clean fclean re

all: $(NAME) $(HDRS)

$(NAME): $(OBJS)
	@printf "\n$(BOLD)Linking $(NAME)$(RESET)\n"
	$(CXX) $(CXXFLAGS) -o $@ $^ && \
	printf "\n$(GREEN)$(BOLD)Build successful!$(RESET)\n" || \
	printf "$(RED)$(BOLD)Build failed!$(RESET)\n"

%.o: %.cpp
	@printf "$(YELLOW)Compiling $(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

debug: CXXFLAGS += -DDEBUG -g3
debug: re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
