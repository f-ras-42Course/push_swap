# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 18:18:49 by fras          #+#    #+#                  #
#    Updated: 2023/05/19 19:08:24 by fras          ########   odam.nl          #
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
LIBRARIES = libftextended.a libft.a libftprintf.a
EXTLIB_DIR = $(LIB_DIR)/libft-extended
LIBRARY_PATHS = $(foreach lib, $(LIBRARIES), $(LIB_DIR)/$(lib))

ifdef DEBUG
CFLAGS+=-g
endif

ifdef FSAN
CFLAGS+=-fsanitize=address -g
endif

# Targets
.PHONY: all clean fclean re directories libsinit libsupdate debug rebug fsan resan

all: $(NAME)

$(NAME): $(LIBRARIES) directories $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBRARY_PATHS)

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
	$(RM) $(LIBRARY_PATHS)
	$(RM) $(NAME)

re: fclean all

debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Git
libsinit:
	git submodule update --init --recursive

libsupdate:
	git submodule update --remote --merge