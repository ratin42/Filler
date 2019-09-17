# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/04/30 19:02:36 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ratin.filler

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := includes
LIB_PATH := libft
VIS_PATH := visu

SRC_NAME :=	main.c \
			free_tab.c \
			get_env.c \
			get_piece.c \
			env.c \
			direction.c \
			place_piece.c \
			scan_territory.c \
			get_pion.c \
			closest.c \
			get_piece_cordo.c \
			sort_closest.c \
			sort_pion_tab.c \
			found_place.c \
			get_player.c \
			calc_coef.c \
			sertif_map.c \

OBJECT_NAME := $(SRC_NAME:.c=.o)
INC_NAME := filler.h

LIB := $(LIB_PATH)/libft.a
LIB_LINK := -L $(LIB_PATH) -lft
VIS := $(VIS_PATH)/visu

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

INCS := -I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME) $(VIS)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(FLAGS) -o $@ $^ -lm

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC_NAME)
	$(MAKE) obj
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB):
	make -C $(LIB_PATH)

$(VIS):
	make -C $(VIS_PATH) all

obj:
	mkdir -p obj

clean:
	rm -rf $(OBJ) $(LIB_PATH)/*.o
	rm -rf obj
	rm -f filler.trace

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean
	make -C $(VIS_PATH) fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/$(NAME).h
	norminette libft/includes/libft.h

.PHONY: all fclean clean re norme