%option noyywrap yylineno nodefault
%x COMMIT
%x IFILE

UNC (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP ([Ee][-+]?[0-9]+)
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

%{
    struct symbol {
        struct ref *reflist;
        char *name;
    };

    struct ref {
        struct ref *next;
        char* file_name;
        int flags;
        int lineno;
    };

    struct bufstack {
        struct bufstack* prev;
        YY_BUFFER_STATE bs;
        int lineno;
        char* file_name;
        FILE* file_handle;  
    };
    
    
    const int NHASH = 13331;
    struct symbol hashtab[NHASH];
    struct symbol* lookup(char* word);
    void addref(int lineno, char* file_name, char* word, int flag);
    char* cur_filename;
    
    int newfile(char* fn);
    int popfile();
    int defining;
%}
%%
"/*"                        { BEGIN(COMMIT); }
<COMMIT>"*/"                { BEGIN(INITIAL); }
<COMMIT>([^*]|\n)+|.
<COMMIT><<EOF>>             {   printf("%s: %d: Unterminated comment\n), cur_filename, yylineno);
                                return 0;
                            }
"//".*\n

_BOOL           |
_Complex        |
_Imageinary     |
auto            |
char            |
const           |
double          |
enum            |
extern          |
float           |
inline          |
int             |
long            |
register        |
restrict        |
short           |
signed          |
static          |
struct          |
typedef         |
union           |
unsigned        |
void            |
volatile    { defining = 1; }

break
case
continue
default
do
else
for
goto
if
return
sizeof
switch
while
%%


int main(int argc, char** argv) {

    if (argc < 2) {
	perror("can't get the file name");
	return 0;
    }
    
    for(int i = 0; i < argc; ++ i) {


    }
}

