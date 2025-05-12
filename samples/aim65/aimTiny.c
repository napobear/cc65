// --------------------------------------------------------------------------
// Hello World for AIM-65
//
// Uses only getchar, putchar and puts, generating smaller code than printf
//
// napobear
//
// napobear@gmail.com
// --------------------------------------------------------------------------

#include <stdio.h>
#include <aim65.h>

int main (void) {
   char c = 0x00;
   int  d = 0x00;
   int  l = 0x00;

   puts ("Hello World!\n");

   puts ("Type a line and press ENTER, please:\n");

   for ( l = 0; l < 2; l++ ) {
      beep();
      for ( d = 0; d < 10 ; d++ ) {
      }
   }

   while ( c != '\n' ) {
      c = getchar();
   }

   puts ("\n\nThanks!\n");

   for ( l = 0; l < 5; l++ ) {
      beep();
      for ( d = 0; d < 10 ; d++ ) {
      }
   }

   return 0;
}
