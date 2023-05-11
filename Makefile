# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 18:18:49 by fras          #+#    #+#                  #
#    Updated: 2023/05/11 15:14:15 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INCLUDE)
INCLUDE = -I include -I $(EXTLIB_DIR)/include
LIBRARIES = libftextended.a libft.a libftftprintf.a
LIB_DIR = lib
EXTLIB_DIR = $(LIB_DIR)/libft-extended
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

# Targets
.PHONY: all clean fclean re directories libsinit libsupdate libsmaster

all: $(NAME)

$(NAME): $(LIBRARIES) directories $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^	

# Libraries
$(LIBRARIES):
	$(MAKE) -C $(EXTLIB_DIR) $@
	cp $(EXTLIB_DIR)/$@ .

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) $(OBJECTS)
	$(RM) -r obj

fclean: clean
	$(MAKE) -C $(EXTLIB_DIR) $@ 
	$(RM) $(NAME)

re: fclean all

# Git
libsinit:
	git submodule update --init --recursive

libsupdate:
	git submodule update --remote --merge