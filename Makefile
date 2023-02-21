NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -o $(NAME)

SCRS =	algo_more_5.c\
		algo_five_num.c\
		main.c\
		checkerr.c\
		rules.c\
		utils_libft.c\
		utils_algo_more_5.c\
		ft_atoi.c\

all : $(NAME)
$(NAME) :
	@$(CC) $(FLAGS) $(SCRS)

clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(NAME)

re : fclean all
