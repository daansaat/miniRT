# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaat <dsaat@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/16 16:43:18 by dsaat         #+#    #+#                  #
#    Updated: 2022/11/04 10:07:18 by daansaat      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;33m
PURPLE = \033[0;35m
GREEN = \033[0;32m
RESET = \033[0m

NAME = raymini
SRCS_DIR = ./src/
SRCS_LIST = \
	main.c \
	vec3f.c \
	ray.c \
	render.c \
	parser.c \
	intersect.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:$(SRCS_DIR)%.c=obj/%.o)
LIBS = -L ./minilibx -lmlx -L ./Libft -l ft
CFLAGS = -Wall -Werror -Wextra
FRAMEWORK = -framework OpenGl -framework AppKit
INCLUDES = -I ./minilibx -I ./Libft -I ./inc
HEAD = inc/miniRT.h inc/vec3f.h inc/ray.h inc/render.h inc/intersect.h inc/parser.h

all: $(NAME)

$(NAME): $(OBJS) minilibx/libmlx.a libft/libft.a $(HEAD)
	@echo "$(PURPLE) compiling miniRT$(RESET)"
	$(CC) $(FLAGS) $(FRAMEWORK) $(INCLUDES) $(LIBS) $(SRCS) -o $(NAME)

obj/%.o: $(SRCS_DIR)%.c
	@mkdir -p obj
	$(CC) -c $< -o $@

minilibx/libmlx.a:
	@echo "$(YELLOW) compiling minilibx$(RESET)"
	$(MAKE) -C ./minilibx

libft/libft.a:
	@echo "$(YELLOW) compiling libft$(RESET)"
	$(MAKE) -C ./libft bonus

clean:
	$(MAKE) -C ./libft clean
	rm -rdf obj

fclean: clean
# $(MAKE) -C ./minilibx clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

# -Warray-bounds