####### SOURCE FILES ######
FILES	=	draw_line.c			\
			pixel2buff.c		\
			vector2img.c		\
			vector.c			\
			hooks.c				\
			utils.c				\
	  		fdf_drawmesh.c		\
	  		fdf_drawutils.c		\
			fdf_center_offset.c	\
			fdf_zoom.c			\
			fdf_move.c			\
			fdf_files.c			\
			fdf_clean.c			\
			fdf_exit.c

SRC		= $(addprefix ., $(FILES))
OBJ		= $(addprefix obj/, $(FILES:.c=.o))
INC		= .

###### TARGETS ######
NAME	= fdf
LIBFT	= libft.a
MLX		= libmlx.a

###### COMPILER ######
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
DLIBS	= -lmlx -framework OpenGL -framework AppKit

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) main.c
	$(CC) $(CFLAGS) $^ $(DLIBS) -I$(INC) -o $@

obj/%.o	: %.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(LIBFT) : 
	@make -C libft/
	@cp libft/$@ .

clean	:
	$(RM) $(OBJ)
	@make fclean -C libft/

fclean	: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re		: fclean all	

.PHONY	: all clean fclean re linux
