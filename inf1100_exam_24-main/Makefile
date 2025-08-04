# add your source files here:
SRC := src/lexer_preprocessor.c \
        src/stack.c \
        src/interpreter.c

# add your header files here
INC := inc/lexer_preprocessor.h \
        inc/stack.h \
        inc/interpreter.h

FLAGS := -g -Wall


8inf: 8inf.c $(SRC) $(INC)
	gcc -g -Wall -Iinc 8inf.c src/lexer_preprocessor.c src/stack.c src/interpreter.c -o 8inf


clean:
	rm -f 8inf


.PHONY: clean
