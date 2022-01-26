####### SOURCE FILES ######
FILES	=	draw_line.c		\
	  		draw_mesh.c		\
			pixel2buff.c	\
			projections.c	\
			vector2img.c	\
			vector_basic.c	\
			vector_basic.c	\
			fdf_center_offset.c	\
			vector_math.c

SRC	= $(addprefix src/, $(FILES))
OBJ	= $(addprefix obj/, $(FILES:.c=.o))
INC	= includes/

###### TARGETS ######
NAME	= fdf
LIBFT	= libft.a
MLX	= libmlx.a

###### COMPILER ######
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
DLIBS	= -framework OpenGL -framework AppKit

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(MLX) src/main.c
	$(CC) $(CFLAGS) $^ $(DLIBS) -I$(INC) -o $@

obj/%.o	: */%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(LIBFT) : 
	@make -C libft/
	@cp libft/$@ .

$(MLX)	: 
	@make -C mlx/
	@cp mlx/$@ .

clean	:
	$(RM) $(OBJ)
	@make fclean -C libft/
	@make clean -C mlx/

fclean	: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re	: fclean all	

.PHONY	: all clean fclean re
