//Scrabble_solution.c 
//Code that requires a list of words from users, calculates the score of each words according to the rules of Scrabble 
//and returns the word with the highest score 
//(pointers practice)

#include <stdio.h>
#include <string.h>

//function that counts the score of a word. 
int char_points(char * start, char * end){
   
     int pts = 0;
 for (char * p = start; p != end ; ++p){
   printf("%c",*p);

        if(*p == 'e' || *p == 'a' || *p == 'i' || *p == 'o' || *p == 'n'|| *p == 'r'|| *p == 't'|| *p == 'l'|| *p == 's'|| *p == 'u')
        {
            pts += 1;
        }
        
        else if(*p =='d' || *p == 'g') 
        {
            pts += 2; 
        }
        
        else if( *p == 'b'|| *p == 'c'|| *p == 'm'|| *p == 'p')
        {
            pts +=3;
        }
        else if ( *p == 'f'|| *p == 'h'|| *p == 'v'|| *p == 'w'|| *p == 'y')
        {
            pts +=4;
        }
        else if (*p == 'k') {pts +=5;}
        else if (*p == 'j' || *p == 'x') { pts += 8;}
        else if  (*p == 'q' || *p == 'z') { pts += 10;}
    }
    printf("\t%-d\n",pts);
    return pts;
}

//Capture word function to return a string: 

void print_word(char * start, char * end)
{
    printf("\nThe word with the most points is: ");
    for(char * p = start; p != end; ++p)
    {
        printf("%c",*p);   
    }
    
}




//main
int main() {
    
    //User input: 
    char words[100];
    gets(words);
    
    //char * words = "giraffe hive bee worker null"; //dummy sentence to test
    
    char * start = words; //start pointer
    char * end = 0;//end pointer
    int points = 0; //int to store points for each word
   
    char * mostpts_start = words ; 
    char * mostpts_end = 0;
    int mostpts = 0;
    
    int one_input = 0;
   
    for(char * p = words; *p; ++p)
    {
        
        if(isspace(*p)){
            one_input = 1;
            end = p;
            points = char_points(start, end);
            
            //if more points, store the pointers for the start and end of the word.
            if(points > mostpts)
            {
                mostpts = points;
                mostpts_start = start;
                mostpts_end = end;
            }
            
            start = p+1; 
    
            
            continue;
        }
   

    }
    
    //if input is only one word (no space)
    if(one_input ==0) 
    {
        mostpts_start = words;
        mostpts_end = words + (int)strlen(words);
        mostpts = char_points(mostpts_start,mostpts_end);
    }
    else{
    //for last word: 
    start = end+1;
    end = words + (int)strlen(words);
    points = char_points(start,end);
    if(points > mostpts)
            {
                mostpts = points;
                mostpts_start = start;
                mostpts_end = end;
            }
            
    }
    //print word with max points
    print_word(mostpts_start, mostpts_end);
   
   
    
    
	return 0;
}

