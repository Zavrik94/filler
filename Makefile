# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/09/03 19:50:06 by azavrazh         ###   ########.fr        #
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

SRC := filler input
HFILES := $(INC_D)filler.h

SRCS := $(addprefix $(SRC_D), $(addsuffix .c, $(SRC)))
OBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_D) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
$(LIB):
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
	rm -rf $(OBJ_D)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre