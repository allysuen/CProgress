//Factorial.c
//Returns the factorial of a given value using recursive functions and using a for loop.

#include <stdio.h>


int factorial_recursiveFunc(int i)
{
  
  if(i>1)
   return i*factorial_recursiveFunc(i-1);

}

int factorial_loop(int i)
{
    int ans=i;
    for (int j = i; j >1; j--)
    {
        ans = ans * (j-1);
    }

    return ans;
}

int main() {
    
    int i = 4; 
   
    int answer = factorial_recursiveFunc(i);
    int ans = factorial_loop(i);
    
    printf("%d! is %d\n", i, answer);
    printf("%d! using loops is %d", i, ans);
        
	return 0;
}