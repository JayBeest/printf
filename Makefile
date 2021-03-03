CFLAGS = -g #-fsanitize=address

all: ft_printf_utils.c ft_printf.c ft_printf_converters.c  ft_printf_checks.c libft.a main.c
	clang $(CFLAGS) $^

clean:
	rm a.out a.out.dSYM
