#include <stdio.h>
#include <string.h>

#define MAX_LINE_CHARACTERS 2048
static char line[MAX_LINE_CHARACTERS];

int main(int argc, char** argv) {

  while(1){
     fputs("list-interpreter> ", stdout);
     fgets(line, MAX_LINE_CHARACTERS, stdin);
     if(strcmp("\n", line))
     {
         if(strcmp("help\n", line) == 0 ){
            fputs("help for this menu\n", stdout);
            fputs("Ctrl-D to exit\n", stdout);
         }
         else
         {
            fputs(line, stdout);
         }
     }
  }

  return 0;
}
