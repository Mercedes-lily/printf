NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_puthexnbr_fd.c \
		ft_puthexxnbr_fd.c \
		ft_putaddinhex_fd.c \
		ft_putchar_fd_return.c \
		ft_putstr_fd_return.c \
		ft_putnbr_fd_return.c \
		ft_putunsignbr_fd.c 

OBJS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re