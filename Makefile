##
## Makefile for  in /home/soussa_y/rendu/CPE_2015_BSQ
## 
## Made by yoram soussan
## Login   <soussa_y@epitech.net>
## 
## Started on  Sun Dec 20 23:10:53 2015 yoram soussan
## Last update Sun Dec 20 23:28:26 2015 yoram soussan
##

SRCS	= main.c		\
	  get_next_line.c	\
	  map.c			\
	  my_error.c		\
	  tools.c		\
	 tools_map.c


OBJS	= $(addprefix src/, $(SRCS:.c=.o))

NAME	= bsq

RM	= rm -f

CC	= gcc

CFLAGS	= -W -Wall -Wextra -Werror -pedantic -ansi

$(PROJECT):	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
