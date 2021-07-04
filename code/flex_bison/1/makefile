

a.out: lex.yy.c scanner.tab.h
	g++ $^  -o $@ -lfl

lex.yy.c: parser.yy
	flex $^

scanner.tab.h: scanner.II
	bison -d $^
	mv scanner.tab.II $@


.PHONY: clean

clean:
	rm lex.yy.c scanner.tab.h a.out	
