# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 16:03:20 by viforget          #+#    #+#              #
#    Updated: 2021/04/28 16:49:18 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(CHECKER)
FLAGS = -Wall -Wextra -Werror -I includes

CC = @gcc -I includes
LIBDIR = libft

#SRCS_PS = srcs

SRCS_CHECKER = srcs_checker/push.c\
				srcs_checker/rotate.c\
				srcs_checker/rrotate.c\
				srcs_checker/swap.c\


O_FILES = $(SRCS_CHECKER:%.c=%.o)

#FLAGLIB = -L$(LIBDIR)

all: $(NAME)

$(NAME): $(O_FILES)
			#@make all -C $(LIBDIR)
			$(CC) $(FLAGS) -o $(NAME) $(O_FILES)
			@echo "\033[32mCOMPILATION OK\033[0m"

clean:
		@rm -rf $(O_FILES) $(LIBBIN)
			@make clean -C $(LIBDIR)
			@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
			@make fclean -C $(LIBDIR)
			@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIBDIR)


re: fclean all

.PHONY: all fclean clean re lib norm normlib