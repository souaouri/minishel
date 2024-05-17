# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:34:57 by souaouri          #+#    #+#              #
#    Updated: 2024/05/17 01:11:54 by souaouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	cc -fsanitize=address -g
CC				+=	-Wall -Wextra -Werror
NAME 			=	minishell
HEADER 			=	minishell.h
DIR				=	.object_files

SRC_FILES		=	minishell.c
BUILTS_FILES	=	cd.c			echo.c			pwd.c		\
					env.c			export.c
UTILS_FILES		=	utils_1.c 		utils_2.c 		utils_3.c 	\
					utils_4.c 		utils_5.c 		utils_6.c
VUR_FILES		=	list.c

SRC_SRC			=	$(addprefix src/,$(SRC_FILES))
BUILTS_SRC		=	$(addprefix builtins/,$(BUILTS_FILES))
UTILS_SRC		=	$(addprefix utils/,$(UTILS_FILES))
VUR_SRC			=	$(addprefix virtual/,$(VUR_FILES))

SRC_OBJ			=	$(SRC_SRC:.c=.o)
BUILTS_OBJ		=	$(BUILTS_SRC:.c=.o)
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)
VUR_OBJ			=	$(VUR_SRC:.c=.o)

OBJ_FILES		=	$(SRC_OBJ)	$(BUILTS_OBJ)	$(UTILS_OBJ)	\
					$(VUR_OBJ)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) -lreadline -o $@ $^

$(DIR)/src/%.o : src/%.c
	@mkdir -p $@
	@$(CC) -c $< -o $@

$(DIR)/builtins/%.o : builtins/%.c
	@mkdir -p $@
	@$(CC) -c $< -o $@

$(DIR)/utils/%.o : utils/%.c
	@mkdir -p $@
	@$(CC) -c $< -o $@

$(DIR)/virtual/%.o : virtual/%.c
	@mkdir -p $@
	@$(CC) -c $< -o $@

clean :
	rm -rf $(DIR)
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all