// #include <stdio.h>  

// int main ()  
// {  
//     char str[100];

//     scanf("%s",&str);
//     printf("string : %s\n",str);

//     for(int i=0;i<strlen(str);i++){
//         printf("index : %c\n",str[i]);
//     }


//     return 0;  
// }  



#include <stdio.h>
#include <string.h>  

int main () {
  char str[100];
  char *p;

  scanf("%s",&str);
  printf("string : %s\n",str);

  for(int i=0;i<strlen(str);i++){
    p = strchr(str, str[i]);
    printf("karakter : %c\n", *p);
  }

  return 0;
}