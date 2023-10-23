#include <stdio.h>
#include <string.h>

int main() {
  char input[256];
  scanf("%s",input);

  int freq[130]={0};

  int length = strlen(input);
  for(int i=0;i<length;i++){
    freq[input[i]]++;
    // printf("%d\n",freq[input[i]]);
  }

  for(int i=0;i<=130;i++){
    for(int j=0;j<freq[i];j++){
        printf("%c",i);
    }
    if(i >= 'A' && i<= 'Z'){
        i += 31;
    } else if (i>='a' && i<='z'){
        i -= 32;
    }
  }

  return 0;
}
