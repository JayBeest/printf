NAME = libft.a
EX = libft
OBJ_F = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
 ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c\
  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c\
   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
   ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strlcat.c
OBJ_F_PT2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
 ft_strmapi.c ft_split.c ft_itoba.c ft_itoba_nomalloc.c\
 ft_strtoupper.c ft_strtolower.c
OBJ_F_BONUS = ft_lstnew.c ft_lstadd_front.c\
 ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
  ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
  ft_lstmap.c
OBJ_F_T = main.c ftt_memset.c ftt_strnstr.c ftt_isalpha.c\
 ftt_isdigit.c ftt_isalnum.c ftt_isascii.c ftt_isprint.c\
  ftt_toupper.c ftt_tolower.c ftt_atoi.c ftt_strlcat.c ftt_memcpy.c\
  ftt_strlcpy.c
OBJ_F_T_PT2 = ftt_substr.c ftt_strjoin.c ftt_strtrim.c\
 ftt_itoa.c ftt_putchar_fd.c ftt_putstr_fd.c ftt_putendl_fd.c\
 ftt_putnbr_fd.c ftt_strmapi.c ftt_split.c ftt_itoba.c ftt_itoba_nomalloc.c\
 ftt_strtolower.c
OBJ_F_BONUS_T = ftt_lstnew.c ftt_lstsize.c ftt_lstlast.c\
ftt_lstadd_back.c ftt_lstdelone.c ftt_lstclear.c ftt_lstmap.c
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
TEST_PATH = ./.tests/
HEADER_FILES = libft.h $(TEST_PATH)test.h
CC = clang

TEST = $(OBJ_F_T:%.c=$(TEST_PATH)%.o) $(OBJ_F_T_PT2:%.c=$(TEST_PATH)%.o) $(OBJ_F_BONUS_T:%.c=$(TEST_PATH)%.o)
OBJ = $(OBJ_F:.c=.o) $(OBJ_F_PT2:.c=.o)
OBJ_BONUS = $(OBJ_F_BONUS:.c=.o)

OBJ_TEST = $(OBJ) $(OBJ_BONUS) $(TEST)

ifdef WITH_BONUS
O_FILES = $(OBJ) $(OBJ_BONUS)
else
O_FILES = $(OBJ)
endif

ifdef WITH_TEST
O_FILES = $(OBJ_TEST)
NAME = libft
endif

all: $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

test: re
	$(MAKE) WITH_TEST=1 all
	./libft

so: libft.so

$(NAME): $(O_FILES)
	ar -rc $@ $^

$(EX): $(NAME) $(O_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER_FILES)
	@echo Compiling $@
	$(CC) -c $(CFLAGS) -o $@ $<

%.so: $(O_FILES)
	$(CC) -shared -o $@ $^ -L.

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_TEST)

fclean: clean
	rm -f $(NAME) $(EX) libft.so

re: fclean all

.PHONY: all clean fclean re test
