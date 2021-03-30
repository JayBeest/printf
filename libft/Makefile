# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jcorneli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/22 22:40:35 by jcorneli      #+#    #+#                  #
#    Updated: 2021/03/29 10:19:28 by jcorneli      ########   odam.nl          #
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
		ft_toupper.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoba.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strtolower.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c

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
