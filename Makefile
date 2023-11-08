# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 15:49:23 by jtaravel          #+#    #+#              #
#    Updated: 2023/11/08 15:51:51 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	computor

SRCS_FILES	=	main.cpp calculMath.cpp parsing.cpp Poly.cpp reducedForm.cpp utils.cpp

INC_FILES	=	Poly.hpp

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CXX	=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./includes -g3

OBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)

OBJS	=	$(addprefix objs/, $(OBJS_FILES))

DEP		=	$(OBJS:%.o=%.d)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean	:
	rm -rf $(OBJS) $(DEP)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

objs/%.o	: srcs/%.cpp $(INCS)
	mkdir -p objs
	$(CXX) $(CPPFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re
