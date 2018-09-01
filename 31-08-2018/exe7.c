#include <stdio.h>
#include <unistd.h>
int main()
{
 
 
    pid_t pid;
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    int i;
    for(i=0;i<numero;i++){
        
        pid=fork();
         if(pid==0){
           printf("pid do Filho %d: %d\n", i+1, getpid());
         }
    }
 printf("Fim");
 return 0;
}
