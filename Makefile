# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/09/17 23:49:06 by azavrazh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := azavrazh.filler
VIS := visualizer

SRC_D := src/
VIS_D := $(SRC_D)visualizer/
LIBFT_D := libft/
LIBFT := $(LIBFT_D)libft.a
INC_D := header/
OBJ_D := .obj/

CC := clang
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I $(INC_D)

SRC := filler algo work_with_map cut_piece init_map can_put_it free
HFILES := $(INC_D)filler.h

SRCS := $(addprefix $(SRC_D), $(addsuffix .c, $(SRC)))
OBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))


all: $(NAME)
	make -C $(VIS_D)
	cp $(VIS_D)$(VIS) .

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
	rm -rf $(OBJ_D)
	rm -rf $(VIS_D)$(OBJ_D)
mfclean: mclean
	rm -f $(NAME)
	rm -f $(VIS)
	rm -f $(VIS_D)$(VIS)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
