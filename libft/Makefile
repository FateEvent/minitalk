SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c ft_strlen.c ft_memset.c ft_bzero.c ft_memalloc.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memdel.c ft_strnew.c ft_strclear.c ft_strdel.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strstr.c ft_strnstr.c ft_strequ.c ft_strnequ.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_spacetrim.c ft_split.c ft_itoa.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base.c get_next_line.c ft_printf.c ft_printf_utils.c ft_printf_basic.c

SRCSB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line_bonus.c

OBJS	= $(addprefix srcs/, ${SRCS:.c=.o})

OBJSB	= $(addprefix srcsb/, ${SRCSB:.c=.o})

NAME	= libft.a

.c.o:
		gcc -Wall -Wextra -Werror -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $@ $^

all:		${NAME}

bonus:		${NAME} ${OBJSB}
			ar -rcs ${NAME} ${OBJSB}

clean:		
			rm -f ${OBJS} ${OBJSB}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re