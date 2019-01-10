#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 15:05:01 by hthiessa          #+#    #+#              #
#    Updated: 2019/01/10 15:52:39 by hthiessa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC_NAME =

CFLAGS += -Werror -Wall -Wextra

INCL_PATH = . libft
CPPFLAGS += $(INCL_PATH:%=-I%) -MMD -MP

SRC = $(SRC_NAME)
OBJ = $(SRC_NAME:.c=.o)
DEP = $(SRC_NAME:.c=.d)

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
