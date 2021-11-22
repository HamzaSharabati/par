/*Systems Programing Lap , OpenU , Fall 2022
11 Assignment , Q2 
by Hamza Sharabati 
This program checks the balance of three types of brackets : () {} [] 
Line by line and in the whole text .
Text inside comments and string quotations is ignored .
input/output is from the standard input/output .
stack is used to hold the instances of starting brackets in the text one by one , one opening bracket is removed from list for the next matching closing bracket,
if the next closing bracket is not matching or there is no closing bracket then the text is not balanced ,
the same function is used for lines and the whole text .
assumed limits for char in each line and in the whole input is defined in macro MAXLINE,MAXTEXT , number of lines is not limited .
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 100
#define MAXTEXT 10000
#define FALSE 0
#define TRUE 1 
/* structure of stack node */
struct sNode {
    char data;
    struct sNode* next;
};
/* function to check if 2 barackets are matching */
int  isMatch(char char1, char char2) ;
/* Function to push an item to stack */
void push(struct sNode** top_ref, int new_data);
 
/* Function to pop an item from stack */
int pop(struct sNode** top_ref);
/* function to check the text , return TRUE if balanced & FALSE if not */ 
int isBalanced (char text[] ) ;
/*main function */
int main()
{ /* arrays to hold separate lines and the whole text */
  char line[MAXLINE] ;
  char all[MAXTEXT] ;
printf("please insert your text \n ") ;

 while((fgets(line,MAXLINE,stdin))!=NULL)
  
 {/*adding current line to the Whole text array */
  strcat(all,line) ;
  /*printing current line */
  fputs(line , stdout) ;
  /*calling the function for the current line and printing the result */
  if(isBalanced(line)) 
  printf("this line is balanced \n")  ;
  else 
  printf("this line in not balanced \n") ;

}
  /*calling the function for the whole text and printing the result */
   if(isBalanced(all)) 
  printf("\n ......\n the whole text is balanced \n")  ;
  else 
  printf("\n ......\n the whole text in not balanced \n") ;
return 0 ;
}

 int isBalanced (char text[] )
{   /* strng & doc to determine whether the text is part of documentation or string */
    int strng=FALSE ;
    int doc=FALSE ;
    int i=0 ;
    /* declare empty charc stack */
    struct sNode* stack = NULL;
    
    while (text[i]) 
    {   /*end of string */
        if ((strng) && (text[i]=='\"'))

        strng=FALSE ;
        /*end of comment */
        if ((doc) && (text[i]=='*') && (text[i+1]== '/'))
        doc=FALSE ;

        
        /* if next char is not part of string or doucumentation */
        if((!strng) && (!doc))
      { /* pushing the openning bracket to the stack */
        if (text[i] == '{' || text[i] == '(' || text[i] == '[')
            push(&stack, text[i]);
        /* if current char is closing bracket then if stack is empty or the last char in stack
         is not matching the current char then  the text is not balnced */
        if (text[i]== '}' || text[i] == ')' || text[i]== ']') 
        { 
            if (stack==NULL|| !isMatch(pop(&stack), text[i])) 
            return FALSE ;


        }
        /* if next char is '"' the next text is inside string and is ignored */
        if (text[i]=='\"') 
        strng=TRUE ;
        /* if next 2 char determine starting  of comment */
        if ((text[i]=='/') && (text[i+1]=='*'))
        doc=TRUE ;
      }
    
    
    
    

        i++ ;
    }

    /* if stack is empty , the brackets is balance and true is returned */

  if(stack==NULL)
  return TRUE ;
  return FALSE ;
}
/* function to push char to the stack */
void push(struct sNode** top_ref, int new_data)
{
    
    struct sNode* new_node
        = (struct sNode*)malloc(sizeof(struct sNode));
 
    /* put in the data */
    new_node->data = new_data;
 
    new_node->next = (*top_ref);
 
     /* move the head to point to the new node */
    (*top_ref) = new_node;
}
/*function to pop from stack */
int pop(struct sNode** top_ref)
{
    char res;
    struct sNode* top;
 

        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    
}
/* function to check if 2 brackets are matching */
int  isMatch(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return TRUE;
    else if (char1 == '{' && char2 == '}')
        return TRUE;
    else if (char1 == '[' && char2 == ']')
        return TRUE;
    else
        return FALSE;
}
