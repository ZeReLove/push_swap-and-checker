# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 14:01:17 by mrolfe            #+#    #+#              #
#    Updated: 2019/06/21 16:34:57 by mrolfe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
    ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c \
    ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
    ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
    ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
    ft_memalloc.c ft_memdel.c ft_memdel.c ft_strdel.c ft_strclr.c \
    ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
    ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
    ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c ft_strnew.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
    get_next_line.c 
INCLUDES = ./includes
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -g -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all