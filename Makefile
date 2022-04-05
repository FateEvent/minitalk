SRCC = client.c

SRCS = server.c

OBJC = $(SRCC:.c=.o)

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM =	rm -f

NAME = minitalk

CLIENT = client

SERVER = server

NONE='\033[0m'
PINK='\033[1;35m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJC) $(OBJS)
	@$(MAKE) -C ./libft
	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJC) libft.a -o $(CLIENT)
	@gcc $(FLAGS) $(OBJS) libft.a -o $(SERVER)
	@echo $(RED)Missi$(NONE)on accomp$(GREEN)lished!$(NONE);
	@rm $(OBJC) $(OBJS)

clean:
	@$(RM) $(OBJC) $(OBJS) libft.a
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all
