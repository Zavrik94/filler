# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/09/13 13:34:32 by azavrazh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := azavrazh.filler

SRC_D := src/
LIBFT_D := libft/
LIBFT := $(LIBFT_D)libft.a
INC_D := header/
OBJ_D := .obj/

CC := clang
CFLAGS := -g #-Wall -Wextra -Werror
IFLAGS := -I $(INC_D)

SRC := filler algo work_with_map cut_piece init_map can_put_it free
HFILES := $(INC_D)filler.h

SRCS := $(addprefix $(SRC_D), $(addsuffix .c, $(SRC)))
OBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))



VNAME := azavrazh.vis
VSRCS := visualizer.c vutils.c
VHFILES := $(INC_D)filler.h $(INC_D)visualaizer.h
VDIR := visualaizer/
VSRCS := $(addprefix $(VDIR), $(addsuffix .c, $(VIS)))
VOBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))


all: $(NAME)

vis: $(VNAME)

$(VNAME): $(LIBFT) $(OBJ_D) $(VOBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(VOBJS) $(LIBFT) -lncurses -o $(VNAME)

$(NAME): $(LIBFT) $(OBJ_D) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C $(LIBFT_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)$(SRC_D)
$(OBJ_D)%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 


clean: mclean
	make clean -C $(LIBFT_D)
fclean: mfclean
	make fclean -C $(LIBFT_D)
re: fclean all

mclean:
	rm -f $(OBJS)
mfclean:
	rm -f $(NAME)
	rm -f $(VNAME)
	rm -rf $(OBJ_D)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
