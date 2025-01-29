NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

MLX_NAME	= libmlx.a
MLX_PATH	= minilibx-linux/
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_NAME	= libft.a
LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/

SRC_PATH	=	src/
SRC			=	fractol.c \
				initialization.c \
				utils.c \
				events.c \
				render.c \
				color.c \
				parse_args.c \
				help_msg.c \
				fractal_sets/mandelbrot.c \
				fractal_sets/julia.c \
				color_sets/color_interpolated.c \
				color_sets/color_special.c \
				color_sets/color_striped.c
SRCS		=$(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH),  $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_sets/

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
