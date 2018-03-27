#include <stdio.h>
int main(int argc,char** argv){
        puts("#include \"../csp.h\"");
        fputs("$pair((", stdout);
        for(int i=0;i<488;i++){
                fprintf(stdout, "(%d)", i);
        }
        fputs(")(", stdout);
        for(int i=0;i<488;i++){
                fprintf(stdout, "(%d)", i);
        }
        fputs("));\n", stdout);
        return 0;
}
