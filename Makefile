# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 13:18:15 by tfurukaw          #+#    #+#              #
#    Updated: 2021/03/10 16:45:04 by skuzawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = bsq.c output.c input.c board.c 

OBJS = ${SRCS:.c=.o}

.c.o:
	gcc -Wall -Werror -Wextra -c ${SRCS}

${NAME}:${SRCS}
	gcc -Wall -Werror -Wextra -o ${NAME} ${SRCS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean:clean
	rm -f ${NAME}

re: fclean all