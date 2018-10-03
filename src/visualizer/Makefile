# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/10/03 19:57:37 by azavrazh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := azavrazh.vis

LIBFT_D := ../../libft/
LIBFT := $(LIBFT_D)libft.a
INC_D := ../../header/
OBJ_D := .obj/

CC := clang
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I $(INC_D)

SRCS := visualizer.c vutils.c
HFILES := $(INC_D)filler.h $(INC_D)visualizer.h

OBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_D) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT) -lncurses -o $(NAME)
$(LIBFT):
	make -C $(LIBFT_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)
$(OBJ_D)%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 


clean: mclean
	make clean -C $(LIBFT_D)
fclean: mfclean
	make fclean -C $(LIBFT_D)
re: fclean all

.PHONY: all clean fclean re mclean mfclean mre
