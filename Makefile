NAME	= libftprintf.a
SRC		= 	ft_printf_c.c \
			ft_printf_di.c \
			ft_printf_main.c \
			ft_printf_p.c \
			ft_printf_pct.c \
			ft_printf_s.c \
			ft_printf_u.c \
			ft_printf_utils_1.c \
			ft_printf_x.c
B_SRC	= 	ft_printf_bonus_c.c \
			ft_printf_bonus_di.c \
			ft_printf_bonus_flags.c \
			ft_printf_bonus_main.c \
			ft_printf_bonus_p.c \
			ft_printf_bonus_pct.c \
			ft_printf_bonus_s.c \
			ft_printf_bonus_u.c \
			ft_printf_bonus_utils_1.c \
			ft_printf_bonus_utils_2.c \
			ft_printf_bonus_utils_3.c \
			ft_printf_bonus_x.c
SRCDIR	= srcs
B_SRCDIR = srcs_bonus
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
B_SRCS  = $(addprefix $(B_SRCDIR)/, $(B_SRC))
OBJS	= $(SRCS:%.c=%.o)
B_OBJS	= $(B_SRCS:%.c=%.o)
INCLUDE	= -I./includes/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(B_OBJS)
	rm -f $(NAME)
	ar rc $(NAME) $(B_OBJS)

test: bonus
	$(CC) $(CFLAGS) test.c -L. -lftprintf -o test
	./test

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re bonus