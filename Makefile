NAME		=	so_long
SRCS		= 	sources/main.c \
				sources/do_points.c \
				sources/moving.c \
				sources/start.c \
				sources/errors.c \
				sources/utils.c

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	sources/so_long.h

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS)
				$(MAKE) -C ./minilibx_mms_20200219
				cp ./minilibx_mms_20200219/libmlx.dylib .
				${CC} ${OBJS} ${CFLAGS} ${MLX} ./libmlx.dylib -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				$(MAKE) clean -C ./minilibx_mms_20200219
				${RM} $(OBJS) $(NAME) ./libmlx.dylib

re:				clean all

.PHONY:			all clean re