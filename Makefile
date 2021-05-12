NAME =			$(CHECKER) $(PUSH_SWAP)
PUSH_SWAP =		push_swap
CHECKER =		checker
FLAGS = -Wall -Wextra -Werror -I includes

CC = @gcc -I includes
LIBDIR = libft

SRCS_PS = srcs/push_swap.c\
			srcs/stack_utils.c\
			srcs/algo/a1.c\
			srcs/algo/a2.c\
			srcs/algo/a3.c\
			srcs/algo/a4.c\
			srcs/algo/a_2_3.c\
			srcs/algo/a_5_6.c

UTILS = srcs/operation/push.c\
		srcs/utils/ft_atoi.c\
		srcs/utils/ft_strlen.c\
		srcs/utils/ft_strncmp.c\
		srcs/utils/get_next_line.c\
		srcs/utils/ft_isdigit.c\
		srcs/utils/ft_split.c\
		srcs/utils/ft_strrep.c\
		srcs/operation/rotate.c\
		srcs/operation/rrotate.c\
		srcs/operation/swap.c\
		srcs/operation/exec_op.c\
		srcs/error.c

SRCS_CHECKER =	srcs/checker.c\
				srcs/stack_utils.c


O_CHECKER = $(SRCS_CHECKER:%.c=%.o)

O_PS = $(SRCS_PS:%.c=%.o)

O_FILES = $(UTILS:%.c=%.o)

O_CM =	$(O_FILES)\
		$(O_CHECKER)\
		$(O_PS)

all: $(NAME)

$(PUSH_SWAP): $(O_FILES) $(O_PS)
			$(CC) $(FLAGS) -o $(PUSH_SWAP) $(O_FILES) $(O_PS)
			@echo "\033[32mCOMPILATION PUSH_SWAP OK\033[0m"

$(CHECKER): $(O_FILES) $(O_CHECKER)
			$(CC) $(FLAGS) -o $(CHECKER) $(O_FILES) $(O_CHECKER)
			@echo "\033[32mCOMPILATION CHECKER OK\033[0m"


clean:
		@rm -rf $(O_CM) 
			@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
			@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIBDIR)


re: fclean all

.PHONY: all fclean clean re lib norm normlib