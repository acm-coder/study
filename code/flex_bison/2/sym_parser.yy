%option noyywrap yylineno nodefault case-insensitive

%{
    struct ref {
	struct ref *next;
	char* filename;
	int flags;
	int lineno;
    };
    struct symbol {
	char* name;
	struct ref *reflist;
    };

    const int NHASH = 9997;
    struct symbol symtab[NHASH];

    struct symbol* lookup(char* str);
    void addref(int, char*, char*, int);
    char * cur_filename;
    void pref();

%}


%%

a   |
an  |
and |
are |
as  |
at  |
be  |
but |
for |
in  |
is  |
it  |
of  |
on  |
or  |
that	|
the |
this	|
to

[a-z\.0-9=+-]+(\'(s|t))? { addref(yylineno, cur_filename, yytext, 0); }
.|\n
%%

int main(int argc, char** argv) {
    if (argc < 2) {
	cur_filename = "(stdin)";
	yylineno = 1;
	yylex();
    }
    else {
	for(int i = 1; i < argc; ++ i) {
	    cur_filename = argv[i];
	    FILE* file = fopen(cur_filename, "rb");
	    if (!file) {
		fprintf(stderr, "%s open failed.\n", argv[i]);
		return 1;
	    }

	    yyrestart(file);
	    yylineno = 1;
	    yylex();
	    fclose(file);
	}
	pref();
    }
    return 0;
}

void pref() {
    for(int i = 0; i < NHASH; ++ i)
	if (symtab[i].reflist)
	    for(auto t = symtab[i].reflist; t; t = t->next)
		printf("filename: %s, wrod: %s, lineno: %d, flags: %d\n", t->filename, symtab[i].name, t->lineno, t->flags);
}

unsigned int symhash(char* word) {
    unsigned int hash = 0;
    unsigned char c;
    while(c = *word++)
	hash = hash * 9 ^ c;
    return hash;
}

struct symbol* lookup(char* word) {
    struct symbol * sym = &symtab[symhash(word) % NHASH];
    int scount = NHASH;

    while (--scount >= 0) {
	if (sym->name && !strcmp(sym->name, word))
	    return sym;
	if (!sym->name) {
	    sym->name = strdup(word);
	    sym->reflist = 0;
	    return sym;
	}

	if (++sym >= symtab + NHASH) sym = symtab;
    }
    fprintf(stderr, "don't hive any symtab");
    return nullptr;
}

void addref(int lineno, char* file_name, char* word, int flag) {
    struct ref *r;
    struct symbol *sp = lookup(word);

    if (sp->reflist && sp->reflist->lineno == lineno && sp->reflist->filename == file_name) {
	return ;
    }

    r = (struct ref*)malloc(sizeof( struct ref));

    if (!r) {
	fputs("out of space", stderr);
	abort();
    }


    r->next = sp->reflist;
    r->filename = file_name;
    r->lineno = lineno;
    r->flags = flag;

    sp->reflist = r;
    sp->name = strdup(word);
}




