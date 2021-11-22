Systems Programing Lap , OpenU , Fall 2022
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
