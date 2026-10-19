NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
       ft_isdigit.c \
       ft_itoa.c \
       ft_printf_decimal.c \
       ft_printf_str.c \
       parser.c \
       ft_strncmp.c \
       push_swap.c \
       stack_push.c \
       stack_reverse_rotate.c \
       stack_rotate.c \
       stack_swap.c \
       simple.c \
       ft_strlen.c \
       ft_split.c \
       disorder.c \
       medium.c \
       adaptive.c \
       ft_printf_float.c





OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
