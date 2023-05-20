/*
--------------------------------------------------
Project: cp264oc-a1q1
File:    caseflip.c
Author:  Abdinasir Ali
Version: 2023-05-16
--------------------------------------------------
*/

#include <stdio.h>
#include <ctype.h>

int main() {
  //the following line are for Eclipse console none-buffered output, in case you are using Eclipse to do your assignment
  //setbuf(stdout, NULL);

  char c = 0, temp;
  do {
    printf("Please enter a character\n");
    scanf("%c", &c); //this is to get a character input from keyboard stdin.

  // flush the input buffer
    do { // this loop is to get rid of additional characters in stdin buffer
      scanf("%c", &temp);
      if (temp == '\n') break;
    } while (1);

    char result;
    if (c >= 65 && c <= 90) {
      result = c + 32;
      printf("%c:%d,%c,%d\n", c, c, result, result);
    } else if (c >= 97 && c <= 122) {
      result = c - 32;
      printf("%c:%d,%c,%d\n", c, c, result, result);
    } else if (isdigit(c)) {
      result = c - '0';
      printf("%c:%d,%c,%d\n", c, c, c, (result * result));
    } else if (c == '!') {
      printf("%c:quit", c);
      break;
    } else {
      printf("%c:invalid\n", c);
    }

  } while (1);

  return 0;
}