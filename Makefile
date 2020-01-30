# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilee <vilee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 12:00:04 by vilee             #+#    #+#              #
#    Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DIRHDER = ./includes/
DIRLIB = ./libft/
DIRSRC = ./srcs/

ft_printfSRCS = ./libft/ft_printf/includes/
ft_printfLIB = ./libft/ft_printf/srcs/

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) -Wall -Wextra -Werror
debug:
	gcc $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) -g3 -fsanitize=address
	#-Wall -Wextra -Werror
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
