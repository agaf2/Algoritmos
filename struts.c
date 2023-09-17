#include <stdio.h>

int main(){
char str[50]; // String
        char str_inv[50]; // String invertida
        char *ptr_str = str;
        char *ptr_inv = str_inv;
        int i=-1;
        scanf(" %s", str);
        *ptr_inv = *ptr_str;
        for(i=0; *(ptr_str + i) != '\0'; i++){
            
        }// aq tem o tamanho da string +1
        i--;
        for(; i>=0; i--){ //<= por causa do /0
            *ptr_inv = *(ptr_str + i);
            ptr_inv++;
        }
        *(ptr_inv + 1) = '\0';

        printf(" O inverso da string : %s\n\n",str_inv);
        return 0;
}