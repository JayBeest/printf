# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jcorneli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/06 23:29:14 by jcorneli      #+#    #+#                  #
#    Updated: 2021/03/22 22:39:42 by jcorneli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft
PRINTF_FILES =	ft_printf.c \
				ft_printf_utils.c \
				ft_printf_converters_part1.c \
				ft_printf_converters_part2.c \
				ft_printf_parsers.c
LIBFT = ./libft/libft.a
HEADER_FILES = ft_printf.h
SRC_PATH = ./src/
O_FILES = $(PRINTF_FILES:%.c=$(SRC_PATH)%.o)
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C ./libft
	cp $(LIBFT) $@
	$(AR) -r $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

test: $(NAME)
	clear
	$(CC) $(CFLAGS) $(NAME) main.c
	./a.out

clion: $(NAME)
	$(CC) $(CFLAGS) $(NAME) main.c

clean:
	rm -f $(O_FILES)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(O_FILES) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re test clion
