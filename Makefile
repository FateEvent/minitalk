SRCC = client.c

SRCS = server.c

OBJC = $(SRCC:.c=.o)

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM =	rm -f

NAME = minitalk

CLIENT = client

SERVER = server

NONE = \033[0m
RED	 = \033[31m
GREEN =	\033[32m

all: $(NAME)

$(NAME): $(OBJC) $(OBJS)
	@$(MAKE) -C ./libft
	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJC) libft.a -o $(CLIENT)
	@gcc $(FLAGS) $(OBJS) libft.a -o $(SERVER)
	@echo "$(RED)Missi$(NONE)on accomp$(GREEN)lished!$(NONE)";
	@rm $(OBJC) $(OBJS)

clean:
	@$(RM) $(OBJC) $(OBJS) libft.a
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C ./libft

re: fclean all
