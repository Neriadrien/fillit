# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbode <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 19:31:39 by hbode             #+#    #+#              #
#    Updated: 2018/12/14 13:51:03 by hbode            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
FILES = ft_atoi \
	   ft_bzero \
	   ft_factorial \
	   ft_is_prime \
	   ft_isalnum \
	   ft_isalpha \
	   ft_isascii \
	   ft_isdigit \
	   ft_isprint \
	   ft_itoa \
	   ft_lstadd \
	   ft_lstdel \
	   ft_lstdelone \
	   ft_lstiter \
	   ft_lstmap \
	   ft_lstnew \
	   ft_max \
	   ft_memalloc \
	   ft_memccpy \
	   ft_memchr \
	   ft_memcmp \
	   ft_memcpy \
	   ft_memdel \
	   ft_memmove \
	   ft_memset \
	   ft_power \
	   ft_print_words_tables \
	   ft_putchar \
	   ft_putchar_fd \
	   ft_putendl \
	   ft_putendl_fd \
	   ft_putnbr \
	   ft_putnbr_fd \
	   ft_putstr \
	   ft_putstr_fd \
	   ft_range \
	   ft_sort_int_tab \
	   ft_split_whitespaces \
	   ft_sqrt \
	   ft_strcat \
	   ft_strchr \
	   ft_strchri \
	   ft_strclr \
	   ft_strcmp \
	   ft_strcpy \
	   ft_strdel \
	   ft_strdup \
	   ft_strequ \
	   ft_striter \
	   ft_striteri \
	   ft_strjoin \
	   ft_strjoin_free \
	   ft_strlcat \
	   ft_strlen \
	   ft_strmap \
	   ft_strmapi \
	   ft_strncat \
	   ft_strncmp \
	   ft_strncpy \
	   ft_strnequ \
	   ft_strnew \
	   ft_strnstr \
	   ft_strrchr \
	   ft_strrev \
	   ft_strsplit \
	   ft_strstr \
	   ft_strsub \
	   ft_strtrim \
	   ft_swap \
	   ft_tolower \
	   ft_toupper \

SRCS = $(patsubst %,%.c,$(FILES))
OBJS = $(patsubst %,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

@%.o : %.c
	gcc $(FLAGS) -c $(SRCS) -I.

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
