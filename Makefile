#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:05:01 by hthiessa          #+#    #+#              #
#    Updated: 2019/02/18 17:36:01 by hthiessa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIB = libft/libft.a

SRC = main.c solve.c print.c check_file.c check_adjacent.c set_left.c type.c island.c

CFLAGS ?= -Werror -Wall -Wextra

INCL_PATH = . libft
CPPFLAGS += $(INCL_PATH:%=-I%) -MMD -MP

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(LINK.o) -o $@ $^

$(LIB):
	$(MAKE) -C libft/

clean:
	$(RM) $(OBJ) $(DEP)
	$(MAKE) -C libft/ $@

fclean:
	$(RM) $(OBJ) $(DEP) $(NAME)
	$(MAKE) -C libft/ $@

re: fclean
	$(MAKE)

norm:
	norminette *.h *.c libft/*.c libft/*.h

-include $(DEP)
