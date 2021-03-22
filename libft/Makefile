# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jcorneli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/22 22:40:35 by jcorneli      #+#    #+#                  #
#    Updated: 2021/03/22 22:40:39 by jcorneli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	ft_atoi.c \
		ft_isdigit.c \
		ft_itoba_nomalloc.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strtoupper.c \
		ft_toupper.c

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
HEADER_FILES = libft.h
CC = clang

O_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) -r $@ $^

%.o: %.c $(HEADER_FILES)
	@echo Compiling $@
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
