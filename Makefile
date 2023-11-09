# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:37:15 by jtaravel          #+#    #+#              #
#    Updated: 2023/11/09 19:22:56 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	computor

SRCS_FILES	=	../main.cpp calculMath.cpp  parsing.cpp  Poly.cpp  reducedForm.cpp  utils.cpp

INC_FILES	=	Poly.hpp

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CC	=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./includes -g3

BFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./includes -g3 -D BONUS=1

TFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./includes -g3 -D TESTER=1

OBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)
BOBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)
TOBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)

OBJS	=	$(addprefix objs/, $(OBJS_FILES))
BOBJS	=	$(addprefix bobjs/, $(BOBJS_FILES))
TOBJS	=	$(addprefix tobjs/, $(TOBJS_FILES))

DEP		=	$(OBJS:%.o=%.d)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus 	:	fclean $(BOBJS)
		$(CC) $(BFLAGS) -o $(NAME) $(BOBJS)

tester 	:	fclean $(TOBJS)
		$(CC) $(TFLAGS) -o $(NAME) $(TOBJS)

clean	:
	rm -rf $(OBJS) $(DEP)
	rm -rf $(BOBJS)
	rm -rf $(TOBJS)
	rm -rf objs/
	rm -rf bobjs/
	rm -rf tobjs/
	rm -rf main.d

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

./objs/%.o :	./srcs/%.cpp $(INCS)
		mkdir -p objs
		$(CC) $(FLAGS) -MMD -I ./includes/ -o $@ -c $<

./bobjs/%.o :	./srcs/%.cpp $(INCS)
		mkdir -p bobjs
		$(CC) $(BFLAGS) -MMD -I ./includes/ -o $@ -c $<

./tobjs/%.o :	./srcs/%.cpp $(INCS)
		mkdir -p tobjs
		$(CC) $(TFLAGS) -MMD -I ./includes/ -o $@ -c $<

.PHONY : all re clean fclean
