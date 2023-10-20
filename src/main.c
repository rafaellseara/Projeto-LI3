//verificar se o programa recebe 3 argumentos se sim modo batch se nao receber argumentos modo interativo e incluir 
// depois é necessário dar include aos outros ficheiros .h 
#include <stdio.h>

// main já recebe logo 1 argumento por isso é que tem 3 e não 2, porque no projeto tecnicamente 2, o argv[0] é o nome do executável
//quando na main o programa é executado corretamente retorna 0
int main(int argc, char **argv){

if(argc == 3){
   batch_mode(argv[1],argv[2]);
    }

else if (argc == 1)
{
   menu_mode();
}

else{
    printf("Error");
    return 1;
}
}
