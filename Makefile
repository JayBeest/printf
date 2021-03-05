NAME = libftprintf.a
LIB = libft
PRINTF_FILES = ft_printf.c ft_printf_utils.c ft_printf_converters.c ft_printf_checks.c #main.c
LIBS = ./libft/libft.a
HEADER_FILES = ./src/ft_printf.h
SRC_PATH = ./src/
O_FILES = $(PRINTF_FILES:%.c=$(SRC_PATH)%.o)
CFLAGS =  -g #-Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C ./libft
	ar -rc $@ $(LIBS) $^

%.o: %.c $(HEADER_FILES) 
	clang -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(O_FILES)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(O_FILES) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all
