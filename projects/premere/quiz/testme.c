#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // use ascii code to return a random
    // give random from lower case a to z in ascii
    // return the char
    char arr[] = { ' ', '(', ')', '{', '}', '[', ']', 'a', 'x' };

    int newChar;
    //newChar = (rand() % (125 - 32)) + 32; // ASCII values for everything between 'a' and 'z'
    newChar = arr[rand() % 9];

    return newChar;
}

char *inputString()
{
    char newChar;
    char arr[] = { 'r', 'e', 's', 't' };
    
    char *newString = NULL;
    newString = malloc(sizeof(char) * (6));
    memset(newString, '\0', 6);
    
    // generate 5 char's then \0
    for (int i = 0; i < 5; i++)
    {
        //newChar = (rand() % (122 - 97)) + 97;
        newChar = arr[rand() % 4];
        newString[i] = newChar;
    }
    
    // printf("\nnewString: %s\n\n", newString);

    return newString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    tcCount++;
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

