# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 14:52:52 by ctirions          #+#    #+#              #
#    Updated: 2022/04/01 17:32:53 by ctirions         ###   ########.fr        #
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
			free/free.c					\
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
			utils/utils4.c

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(patsubst srcs%.c, objs%.o, $(SRCS))

CC		=	gcc -Wall -Wextra -Werror -g
MFLAGS	=	-lmlx -framework OpenGL -framework AppKit

NAME	=	cub3D
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@make full -C ./libft
			@$(CC) $(MFLAGS) -o $(NAME) $(OBJS) libft/libft.a
			@echo "\r[$(GREEN)✓$(RESET)] $(NAME) compiled                        "

bonus:		
			@make -C ./bonus
			@mv -f bonus/cub3D_bonus ./

objs/%.o:	srcs/%.c			
			@printf "\r[$(LIGHTPURPLE)✓$(RESET)] compilation of $<           \r"
			@$(CC) -Imlx -I ./includes -c $^ -o $@

clean:
			@$(RM) $(OBJS)
			@make clean -C ./libft
			@make clean -C ./bonus
			@echo "[$(RED)✓$(RESET)] clean done"

fclean:	
			@$(RM) $(OBJS)
			@$(RM) $(NAME)
			@make fclean -C ./libft
			@make fclean -C ./bonus
			@echo "[$(RED)✓$(RESET)] fclean done"

re:			fclean all

.PHONY:		all clean fclean re cub3d bonus
