%{
int chars = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+ { chars += strlen(yytext); words++; }
\n  { ++ lines; chars ++; }
.   { ++ chars; }

%%


int main() {
    yylex();
    printf("chars:%d, words: %d, lines:%d", chars, words, lines);
    return 0;
}
