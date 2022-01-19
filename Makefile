####### SOURCE FILES ######
FILES =	draw_line.c	\
	draw_mesh.c	\
	pixel2buff.c	\
	projections.c	\
	vector2img.c	\
	vector_basic.c	\
	vector_math.c

SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix obj/, $(FILES:.c=.o))
INC = includes/

###### TARGETS ######
NAME = fdf
LIBFT = libft.a
MLX = libmlx.a

###### COMPILER ######
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
DLIBS = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ src/main.c $(DLIBS) -I$(INC) -o $@

obj/%.o : */%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(LIBFT) : 
	@make -C libft/
	@cp $@ ../

$(MLX) : 
	@make -C mlx/
	@cp $@ ../

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all	

.PHONY : all clean fclean re