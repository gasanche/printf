# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:11:49 by gabsanch          #+#    #+#              #
#    Updated: 2023/06/08 13:32:44 by gabsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	 ft_isprint.c ft_strlen.c ft_toupper.c ft_toupper.c \
	 ft_tolower.c ft_atoi.c ft_strlcat.c ft_strlcpy.c \
	 ft_strchr.c ft_memset.c ft_bzero.c ft_strnstr.c \
	 ft_memcpy.c ft_strncmp.c ft_memmove.c ft_memchr.c \
	 ft_strrchr.c ft_memcmp.c ft_strdup.c ft_calloc.c \
	 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	 ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS= ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJ= $(SRC:.c=.o) 
	#cambio los nombres de los archivos .c a .o
BNS= $(BONUS:.c=.o)
HDR=libft.h

GCC=cc
FLAGS=-Wall -Werror -Wextra -I .
#el -I . es para que busque en el directorio actual el libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BNS) $(OBJ)
	ar rc $(NAME) $(OBJ) $(BNS)
%.o: %.c $(HDR)
	$(GCC) $(FLAGS) -c -o $@ $<
# $@ = %.o
# $< = %.c Compilo los .c para crear los .o
clean:
	rm -fv *.o

fclean: clean
	rm -fv $(NAME)

re: fclean all
.PHONY: all clean re fclean bonus
