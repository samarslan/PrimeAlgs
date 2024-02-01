#include <stdio.h>
#include <stdbool.h>

int main(){
  int x;
  int counter=2;
  bool isPrime=true;
  
  //printf("Enter Number: ");
  //scanf("%d", &x);
  x=530737389;

  while(counter<x){
    if(x==2)
    {
      isPrime=true;
      break;
    }
    if(x%counter==0)
    {
      isPrime=false;
      break;
    }
    counter++;
  }
  
  if(isPrime){
    printf("\nPrime\n");
  }
  else{
    printf("\nNot Prime\n");
  }
}