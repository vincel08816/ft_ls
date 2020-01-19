NAME = ft_ls

DIRHDER = ./includes/
DIRLIB = ./libft/
DIRSRC = ./srcs/

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) 
	#-Wall -Wextra -Werror
debug:
	gcc $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) -g3 -fsanitize=address
	#-Wall -Wextra -Werror
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
