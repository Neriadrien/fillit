#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:05:01 by hthiessa          #+#    #+#              #
#    Updated: 2019/02/04 15:07:27 by hthiessa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = main.c solve.c print.c island.c

CFLAGS ?= -Werror -Wall -Wextra

INCL_PATH = . libft
CPPFLAGS += $(INCL_PATH:%=-I%) -MMD -MP

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft/
	$(LINK.o) -o $@ $^ libft/libft.a

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
