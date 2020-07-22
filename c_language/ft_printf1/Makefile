# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nofloren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 18:32:04 by nofloren          #+#    #+#              #
#    Updated: 2020/07/22 23:52:38 by nofloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_create_mod.c srcs/ft_print_h.c srcs/ft_print_u.c\
	   srcs/ft_putnbr.c srcs/ft_check_specifier.c srcs/ft_print_let.c\
	   srcs/ft_printaddr.c srcs/ft_putstr.c srcs/ft_print_c.c\
	   srcs/ft_print_s.c srcs/ft_printf.c srcs/ft_strlen.c srcs/ft_print_d.c\
	   srcs/ft_specifier.c srcs/ft_putchar.c

SRCL = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c\
	   libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c\
	   libft/ft_isprint.c libft/ft_itoa.c libft/ft_memccpy.c libft/ft_memchr.c\
	   libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c\
	   libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
	   libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c\
	   libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c\
	   libft/ft_strlen.c libft/ft_strmapi.c	libft/ft_strncmp.c\
	   libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c\
	   libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c\
	   libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c\
	   libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c\
	   libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c

OBJS = ft_create_mod.o ft_print_h.o ft_print_u.o ft_putnbr.o\
	   ft_check_specifier.o ft_print_let.o ft_printaddr.o ft_putstr.o ft_print_c.o\
	   ft_print_s.o ft_printf.o ft_strlen.o ft_print_d.o ft_specifier.o\
	   ft_putchar.o

OBJL = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
      ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o\
      ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o\
      ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o\
      ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o\
	  ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o\
	  ft_tolower.o ft_toupper.o ft_lstadd_back.o ft_lstadd_front.o\
	  ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o\
	  ft_lstnew.o ft_lstsize.o

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	@gcc -c ${FLAGS} ${SRCS} ${SRCL} -I ${INCLUDES}
	@ar rc ${NAME} ${OBJS} ${OBJL}
	@ranlib ${NAME}
	@rm -f ${OBJS} ${OBJL}

clean:
	@rm -f ${OBJS} ${OBJL}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
