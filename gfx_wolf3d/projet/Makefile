##
## Makefile for wolf in /home/menett_a/Modules/infographie/gfx_wolf3d
## 
## Made by Nicolas Menettrier
## Login   <menett_a@epitech.net>
## 
## Started on  Tue Dec 22 12:13:51 2015 Nicolas Menettrier
## Last update Wed Jan  6 14:57:03 2016 Nicolas Menettrier
##

NAME		=	wolf3d

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

CFLAGS		+=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/

SRC		=	my_getnbr.c	\
			init.c		\
			tekpixel.c	\
			noise_color.c	\
			my_putstr.c	\
			raycasting.c	\
			read_map.c	\
			main.c

OBJ		=	$(SRC:.c=.o)

INCLUDE		=	include/struct.h

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o $(NAME) $(INCLUDE)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
