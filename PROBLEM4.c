# include <stdio.h>
# include <string.h>

int main(){
char words [100]={} ;
printf("Please Enter a String Input : ");

fgets(words, sizeof(words), stdin);  //  Read input including spaces
words[strcspn(words, "\n")] = '\0';  // Remove the newline character

char *ptr=words;
int sum=0;

while(*ptr!='\0'){

if(*ptr=='a'||*ptr=='e'||*ptr=='i'||*ptr=='o'||*ptr=='u'||
  *ptr=='A'||*ptr=='E'||*ptr=='I'||*ptr=='O'||*ptr=='U'){

 sum+=1;
}
ptr++;

}


printf("The Number of vowels Characters here = %d",sum);

return 0;


}
