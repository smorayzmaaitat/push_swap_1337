# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imaaitat <imaaitat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 22:57:08 by imaaitat          #+#    #+#              #
#    Updated: 2022/12/26 19:45:58 by imaaitat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

OBJS =  utils/index.o src/push.o src/main.o src/simple.o  src/sort_3_3.o utils/initstack.o       src/radix.o         src/reverseRotate.o src/rotate.o    src/swap.o utils/check_args.o  utils/printlist.o  utils/t_list.o     utils/utils.o
CHECK_OBJS = checker.o  utils/index.o src/push.o   utils/initstack.o       src/radix.o         src/reverseRotate.o  src/rotate.o    src/swap.o   utils/check_args.o  utils/printlist.o  utils/t_list.o     utils/utils.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make 
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	
bonus:$(CHECK)

$(CHECK): $(CHECK_OBJS)
	@cd libft && make 
	@$(CC) $(CFLAGS) $(CHECK_OBJS) ./libft/libft.a -o $(CHECK)
	
$(OBJS): ./includes/push_swap.h
$(CHECK_OBJS): ./includes/push_swap.h
clean: 
	@cd libft && make clean
	@$(RM) $(OBJS)
	@$(RM) $(CHECK_OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(CHECK)

re: fclean all

