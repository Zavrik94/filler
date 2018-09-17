# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/09/17 15:59:31 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre
.SUFFIXES:
.SUFFIXES: .c .o .h


NAME := azavrazh.vis

LIBFT_D := ../../libft/
LIBFT := $(LIBFT_D)libft.a
INC_D := ../../header/
OBJ_D := .obj/

CC := clang
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I $(INC_D)

HFILES := $(INC_D)filler.h $(INC_D)visualizer.h
SRCS := visualizer.c vutils.c
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

mclean:
	rm -rf $(OBJ_D)
mfclean: mclean
	rm -f $(NAME)
mre: mfclean all

