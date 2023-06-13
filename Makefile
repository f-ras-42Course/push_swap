# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 18:18:49 by fras          #+#    #+#                  #
#    Updated: 2023/06/13 16:10:44 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan

all: $(NAME) $(BONUS)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS)
	@echo "\033[92m$@ is ready for usage!\033[0m"

$(BONUS): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS)
	@echo "\033[92m$@ is ready for usage!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

mandatory: $(NAME)

bonus: $(BONUS)

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) $(OBJECTS)
	$(RM) -r obj

fclean: clean
	$(RM) $(NAME)
	$(RM) checker

re: fclean all

debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Leaks

leakscheck: $(NAME)
	leaks --atExit -- ./$< "3 2 1"

leaksinfo: $(NAME)
	export MallocStackLogging=1 && \
	./$< && \
	leaks -atExit -quiet -list -- ./$< "3 2 1"