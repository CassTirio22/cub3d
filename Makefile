# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 14:52:52 by ctirions          #+#    #+#              #
#    Updated: 2021/02/19 15:55:18 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)


SRCS		=	cub3d.c\
				ft_hook.c\
				ft_utils.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				ft_draw/ft_draw.c\
				ft_move/ft_move.c\
				ft_move/ft_move2.c\
				init_data/init_data.c\
				init_data/init_data2.c\

OBJS		=	${SRCS:.c=.o}

NAME		=	cub3d.a

CFLAGS		= 	-Wall -Wextra -Werror

LIBFT		=	./libft

.c.o:			
				@gcc ${CFLAGS} -c -I ./ $< -o ${<:.c=.o}
				@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):		${OBJS}
				@make full -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}
				@ranlib ${NAME}
				@echo "${GREEN}Library done !${RESET}"
				@gcc -lmlx -framework OpenGL -framework AppKit $(NAME)

all:			${NAME}

clean:
				@rm -f ${OBJS}
				@make clean -C $(LIBFT)
				@echo "${RED}Clean done !${RESET}"

fclean:			clean
				@rm -f ${NAME}
				@make fclean -C $(LIBFT)
				@echo "${RED}Fclean done !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re
