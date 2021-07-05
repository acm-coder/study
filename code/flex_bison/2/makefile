
CPP_FLAGS = -std=c++11 -g


parser: parser.yy
	flex $^
	g++ lex.yy.c -o a.out -lfl $(CPP_FLAGS)

sym: sym_parser.yy
	flex $^
	g++ lex.yy.c -o a.out -lfl $(CPP_FLAGS)


.PHONY: clean


clean:
	rm lex.yy.c a.out
