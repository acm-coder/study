%option noyywrap
%{
int chars = 0;
int lines = 0;
int words = 0;

%}

%%

[a-zA-Z0-9] { chars += strlen(yytext), words ++; }
\n	    { chars ++, lines ++; }
.	    { ++ chars; }

%%


int main(int argc, char** argv) {

    if (argc < 2) {
	yylex();
	printf("%d, %d, %d\n", chars, words, lines);
	return 0;
    }
    
    int tot_c = 0, tot_w = 0, tot_l = 0;
    for (int i = 1; i < argc; ++ i) {
	FILE *file = fopen(argv[i], "rb");
	if (!file) {
	    fprintf(stderr, "open file failed\n");
	    return 0;
	}

	yyrestart(file);
	yylex();
	fclose(file);
	tot_c += chars, tot_w += words, tot_l += lines;
	printf("%s:%d, %d, %d\n", argv[i], chars, words, lines);
	chars = words = lines = 0;
    }
    printf("tot: chars:%d, words:%d, lines:%d\n", tot_c, tot_w, tot_l);
    return 0;
}

