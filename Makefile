NAME	= fractol

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

MLX_NAME	= libmlx.a
MLX_PATH	= minilibx-linux/
MLX		= $(MLX_PATH)$(MLX_NAME)

LIBFT_NAME	= libft.a
LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC		= -I ./includes/\
		  -I ./libft/\
		  -I ./minilibx-linux/

SRC_PATH	= src/
SRC		= \
		  fractol.c \
		  initialization.c \
		  utils.c \
		  events.c \
		  render.c \
		  color.c \
		  parse_args.c \
		  help_msg.c \
		  set_gradation.c \
		  fractal_sets/mandelbrot.c \
		  fractal_sets/julia.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

HEADERS		= $(wildcard includes/*.h)

all: $(MLX) $(LIBFT) $(OBJ_PATH) $(OBJS) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)fractal_sets/

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm

clean:
	@rm -rf $(OBJ_PATH)
	@if [ -f "$(MLX_PATH)/Makefile.gen" ]; then make clean -C $(MLX_PATH); fi
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
