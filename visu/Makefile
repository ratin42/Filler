# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/05/01 17:18:51 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := includes
LIB_PATH := ../libft

SRC_NAME :=	main.c \
			start_mlx.c \
			get_game.c \
			handle_game.c \
			get_info.c \
			pixel.c \
			bresenham.c \
			board.c \
			print_ath.c \
			get_score.c \
			free_prog.c \

OBJECT_NAME := $(SRC_NAME:.c=.o)
INC_NAME := visu.h

LIB := $(LIB_PATH)/libft.a
LIB_LINK := -L $(LIB_PATH) -lft

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

INCS := -I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)
INC := -I /usr/local/include
X := -I /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

CC := gcc
CFLAGS := -Wall -Wextra -Werror
MLX := -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(FLAGS) -o $@ $^ $(MLX) $(LIB_LINK) -lm

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC_NAME)
	$(CC) $(CFLAGS) $(INC) $(X) -o $@ -c $<

obj:
	mkdir -p obj

clean:
	rm -rf $(OBJ) $(LIB_PATH)/*.o
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/$(NAME).h
	norminette libft/includes/libft.h

.PHONY: all fclean clean re norme
