# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 17:05:49 by ctirions          #+#    #+#              #
#    Updated: 2021/02/14 13:36:42 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
			  ft_isprint.c \
			  ft_lstlast.c \
			  ft_memcpy.c \
			  ft_split.c \
			  ft_strmapi.c \
			  ft_toupper.c \
			  ft_bzero.c \
			  ft_itoa.c \
			  ft_memmove.c \
			  ft_strchr.c \
			  ft_strncmp.c \
			  ft_calloc.c \
			  ft_memset.c \
			  ft_strdup.c \
			  ft_strnstr.c \
			  ft_isalnum.c \
			  ft_putchar_fd.c \
			  ft_strjoin.c \
			  ft_strrchr.c \
			  ft_isalpha.c \
			  ft_memccpy.c \
			  ft_putendl_fd.c \
			  ft_strlcat.c \
			  ft_strtrim.c \
			  ft_isascii.c \
			  ft_memchr.c \
			  ft_putnbr_fd.c \
			  ft_strlcpy.c \
			  ft_substr.c \
			  ft_isdigit.c \
			  ft_memcmp.c \
			  ft_putstr_fd.c \
			  ft_strlen.c \
			  ft_tolower.c

SRCS_BONUS	= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

.c.o:
			@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS_BONUS}
			@ar -rcs ${NAME} ${OBJS_BONUS}

full:		all	bonus

clean:
			@rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			@rm -f ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re bonus full
