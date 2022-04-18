# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 11:44:58 by faventur          #+#    #+#              #
#    Updated: 2022/04/18 17:27:13 by faventur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = client.c

SRCS_S = server.c

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM =	rm -f

NAME = minitalk

CLIENT = client

SERVER = server

NONE = \033[0m
RED	 = \033[31m
GREEN =	\033[32m

all: $(NAME)

$(NAME): $(OBJS_C) $(OBJS_S)
	@$(MAKE) -C ./libft
	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJS_C) libft.a -o $(CLIENT)
	@gcc $(FLAGS) $(OBJS_S) libft.a -o $(SERVER)
	@echo "$(RED)Missi$(NONE)on accomp$(GREEN)lished!$(NONE)";
	@rm $(OBJS_C) $(OBJS_S)

.c.o:
	gcc -Wall -Wextra -Werror -c -I./libft/includes $< -o ${<:.c=.o}

clean:
	@$(RM) $(OBJS_C) $(OBJS_S) libft.a
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C ./libft

re: fclean all
