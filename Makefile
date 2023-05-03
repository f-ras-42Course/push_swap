# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 18:18:49 by fras          #+#    #+#                  #
#    Updated: 2023/05/03 22:37:05 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INCLUDE)
INCLUDE = -I include $(EXT_INCLUDES)
EXT_INCLUDES = $(foreach lib,$(LIBRARY_NAMES),-I lib/$(lib)/include)
LIBRARY_NAMES = libft
LIBRARIES = $(foreach lib,$(LIBRARY_NAMES),lib/$(lib)/$(lib).a)
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

# Targets
.PHONY: all clean fclean re directories updatelibs

all: $(NAME)

$(NAME): $(LIBRARIES) directories $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^	

# Libraries
$(LIBRARIES):
	$(MAKE) -C lib/$(basename $(notdir $@)) all

updatelibs:
	git submodule update --init

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) $(OBJECTS)
	$(RM) -r obj

fclean: clean
	@for lib in $(LIBRARY_NAMES); do \
		$(MAKE) -C lib/$$lib fclean; \
	done
	$(RM) $(NAME)

re: fclean all