#include <stdio.h>
int main(int argc,char **argv){
        puts("#define DELAY_REF(x) x _n()");
        puts("#define DELAY_REF_2(x) x _n()");
        puts("#define DELAY_INT_2(x) DELAY_REF(DELAY_REF_2)(x)");
        for(int i=3;i<1000;i++){
                printf("#define DELAY_INT_%d(x) DELAY_REF(DELAY_INT_%d)(x)\n",i,i-1);
        }
        return 0;
}
