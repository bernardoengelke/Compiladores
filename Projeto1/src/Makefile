# My Little Makefile
FLEX=flex
BISON=bison
CC=clang++
PARAM=-std=c++11 -fcxx-exceptions -Wno-deprecated-register
OUTPUT=myparse

all: flex yacc clang

clang: variableType/*.h variableType/*.cpp symbolTable/*.h symbolTable/*.cpp *.cpp *.h
	${CC} -o ${OUTPUT} variableType/*.cpp symbolTable/*.cpp *.cpp ${LLVMPARAM} ${PARAM}

yacc: parser.y
	${BISON} --defines=parser.h --output=parser.cpp parser.y

flex: scanner.l
	${FLEX} -o scanner.cpp scanner.l

clean:
	rm parser.cpp parser.h scanner.cpp ${OUTPUT}

test1: all
	./${OUTPUT} < exampleTests/input_example1

test2: all
	./${OUTPUT} < exampleTests/input_example2

test3: all
	./${OUTPUT} < exampleTests/input_example3

test4: all
	./${OUTPUT} < exampleTests/input_example4

test5: all
	./${OUTPUT} < exampleTests/input_example5

test6: all
	./${OUTPUT} < exampleTests/input_example6
