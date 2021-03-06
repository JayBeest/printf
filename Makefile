NAME = libftprintf.a
LIB = libft
PRINTF_FILES = ft_printf.c ft_printf_utils.c ft_printf_converters.c ft_printf_checks.c #main.c
LIBFT = ./libft/libft.a
HEADER_FILES = ft_printf.h
SRC_PATH = ./src/
O_FILES = $(PRINTF_FILES:%.c=$(SRC_PATH)%.o)
CFLAGS =  -g #-Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

#$(NAME): $(O_FILES)
#	$(MAKE) -C ./libft
#	cp $(LIBS) $@
#	ar -r $@ $^

$(NAME): $(O_FILES)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
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