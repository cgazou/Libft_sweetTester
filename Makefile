# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 19:52:48 by cgazen            #+#    #+#              #
#    Updated: 2025/10/24 20:32:11 by cgazen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=SweetTester

#CHANGE PATH TO YOUR LIBFT
LIBFTDIR=/home/cgazou/42/Rank00/Libft

INCDIR=/home/cgazou/42/Rank00/SweetTester
TOOLSDIR=tools
TESTSDIR=tests

TOOLFILES=main.c test_print.c test_utils.c
TESTFILES=test_isalnum.c test_isalpha.c test_isascii.c test_isdigit.c test_isprint.c

SRCS=$(addprefix $(TOOLSDIR)/, $(TOOLFILES)) $(addprefix $(TESTSDIR)/, $(TESTFILES))
OBJS=$(SRCS:.c=.o)

.PHONY: all exec clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft 

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

exec: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)




