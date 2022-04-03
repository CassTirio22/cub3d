# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliens <aliens@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:16:15 by aliens            #+#    #+#              #
#    Updated: 2022/04/03 19:23:20 by aliens           ###   ########.fr        #
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

SRCSDIR	=	srcs/
OBJSDIR	=	objs/

FILES	=	cub3d.c						\
			draw/draw.c					\
			draw/draw_map_2d.c			\
			draw/draw_player_2d.c		\
			free/free.c					\
			free/error_msg.c			\
			hook/hook.c					\
			hook/move.c					\
			hook/rotate.c				\
			init/init_var.c				\
			init/init_cub.c				\
			init/init_textures.c		\
			parsing/parse.c				\
			parsing/parse_map.c			\
			parsing/parse_map_utils.c	\
			raycasting/dist_to_wall.c	\
			utils/utils.c				\
			utils/utils2.c				\
			utils/utils3.c				\
			utils/utils4.c				\
			utils/utils5.c

SRCS	=	$(addprefix srcs_bonus/, $(FILES))
OBJS	=	$(patsubst srcs_bonus%.c, objs_bonus%.o, $(SRCS))

CC		=	gcc -Wall -Wextra -Werror -g
MFLAGS	=	-lmlx -framework OpenGL -framework AppKit

NAME	=	cub3D_bonus
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@make full -C ../libft
			@$(CC) $(MFLAGS) -o $(NAME) $(OBJS) ../libft/libft.a
			@echo "\r[$(GREEN)✓$(RESET)] $(NAME) compiled                        "

objs_bonus/%.o:	srcs_bonus/%.c			
			@printf "\r[$(LIGHTPURPLE)✓$(RESET)] compilation of $<           \r"
			@$(CC) -Imlx -I ../includes -c $^ -o $@

clean:
			@$(RM) $(OBJS)
			@make clean -C ../libft

fclean:	
			@$(RM) $(OBJS)
			@$(RM) ../$(NAME)
			@make fclean -C ../libft

re:			fclean all

.PHONY:		all clean fclean re
