# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:11:49 by gabsanch          #+#    #+#              #
#    Updated: 2023/07/16 18:32:26 by gabsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= library/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I $(dir $(LIBFT))
AR			= ar -rcs
RM			= rm -rf

SRCS		= ft_printf.c ft_print_types.c ft_pointer.c ft_unsigned.c 
OBJS		= $(SRCS:.c=.o)

all:		
			$(MAKE) -C $(dir $(LIBFT))
			$(MAKE) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			cp $(LIBFT) $(NAME)
			$(AR)	$(NAME) $(OBJS)

.c.o: 		
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(dir $(LIBFT))
			cp $(LIBFT) $(NAME)

clean:
			make clean -C $(dir $(LIBFT))
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(dir $(LIBFT))
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
