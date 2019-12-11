NAME= libftprintf.a
CFLAGS= -Wall -Werror -Wextra
CC= gcc
SRC=	ft_printf.c\
		flags_fill_in.c\
		is_int.c\
		is_string.c\
		is_char.c\
		is_hexa.c\
		convert_to_hexa.c\
		is_pointer.c\
		is_unsigned.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_strchr.c\
	ft_strjoin.c\
	ft_strlen.c\
	ft_strrev.c\
	ft_strdup.c\
		ft_printf.h\


all: $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
