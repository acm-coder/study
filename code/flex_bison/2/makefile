parse.yy: a.out


a.out: parser.yy
	flex $^
	g++ lex.yy.c -o $@ -lfl


.PHONY: clean


clean:
	rm lex.yy.c a.out
