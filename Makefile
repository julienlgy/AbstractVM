##
## EPITECH PROJECT, 2019
## AbstractVM
## File description:
## Makefile
##

NAME	=	abstractVM

SRC	=	main.cpp AvmReader.cpp AvmInstructions.cpp Stack.cpp Factory.cpp Operand.cpp CoreProcess.cpp Exceptions.cpp

OBJ	=	$(SRC:%.cpp=obj/%.o)

CPP	=	g++

CFLAGS	+= 	-Wextra -Wall -g -g3 -Wswitch -Iinclude/

all	:	$(NAME)

$(NAME)	:	obj $(OBJ)
		$(CPP) -o $(NAME) $(OBJ) $(CFLAGS)

obj/%.o	:	src/%.cpp
		$(CXX) $(CFLAGS) -o $@ -c $<

obj	:
		mkdir -p obj

clean	:
		rm -rf obj

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

test	:
		$(info ************  TESTING  ************)
		$(info please make sure you have built the project)
		@./abstractVM ./tests/test01.avm > temp.txt
		@diff temp.txt ./tests/test01.out
		$(info test01 : [Executed])
		@./abstractVM ./tests/test02.avm > temp.txt
		@diff temp.txt ./tests/test02.out
		$(info test02 : [Executed])
		@./abstractVM ./tests/test03.avm > temp.txt
		@diff temp.txt ./tests/test03.out
		$(info test03 : [Executed])
		@./abstractVM ./tests/test04.avm > temp.txt
		@diff temp.txt ./tests/test04.out
		$(info test04 : [Executed])
		@./abstractVM ./tests/test05.avm > temp.txt
		@diff temp.txt ./tests/test05.out
		$(info test05 : [Executed] {print})
		$(info ***************** see errors below :)
		@rm temp.txt
