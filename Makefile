# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 18:18:49 by fras          #+#    #+#                  #
#    Updated: 2023/05/11 16:24:56 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INCLUDE)
INCLUDE = -I include -I $(EXTLIB_DIR)/include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f
# Libraries
LIB_DIR = lib
LIBRARIES = libftextended.a libft.a libftftprintf.a
EXTLIB_DIR = $(LIB_DIR)/libft-extended


# Targets
.PHONY: all clean fclean re directories libsinit libsupdate

all: $(NAME)

echo:
	echo $(LIBRARIES)

$(NAME): $(LIBRARIES) directories $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIB_DIR)/$(LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^	

# Libraries
$(LIBRARIES):
	$(MAKE) -C $(EXTLIB_DIR) $@
	cp $(EXTLIB_DIR)/$@ $(LIB_DIR)/$@

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