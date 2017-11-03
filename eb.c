/*===========================================================================*/
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*  Author: Peter Robinson                                                   */
/*                                                                           */
/*  Date: February 11, 1999                                                  */
/*                                                                           */
/*  Name: eb.c                                                               */
/*                                                                           */
/* This program converts EBCDIC characters to ascii                          */
/*                                                                           */  
/*===========================================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern int main(void)
{
   char   buffer[81];
   char   *bufPtr;
   char   *idx;
   char   out;


   while(1)   /* Loop Forever */
   {

   printf("\nEnter the EBCDIC values\n");

   gets(buffer);

   bufPtr = buffer;

   if ( (*bufPtr == '.') || (*bufPtr == '\0') ) return 0;

   while(*bufPtr !='\0')
   {

      out='.';

      if ( *bufPtr == ' ')
      {
         bufPtr++;
      }

      else
      {
         idx = bufPtr + 1;

         if (toupper(*bufPtr) == '8')
	 {
	    if (*idx == '1') out='a';
	    else if (*idx == '2') out='b';
	    else if (*idx == '3') out='c';
	    else if (*idx == '4') out='d';
	    else if (*idx == '5') out='e';
	    else if (*idx == '6') out='f';
	    else if (*idx == '7') out='g';
	    else if (*idx == '8') out='h';
	    else if (*idx == '9') out='i';
         }

         else if (toupper(*bufPtr) == '9')
	 {
	    if (*idx == '1') out='j';
	    else if (*idx == '2') out='k';
	    else if (*idx == '3') out='l';
	    else if (*idx == '4') out='m';
	    else if (*idx == '5') out='n';
	    else if (*idx == '6') out='o';
	    else if (*idx == '7') out='p';
	    else if (*idx == '8') out='q';
	    else if (*idx == '9') out='r';
         }

         else if (toupper(*bufPtr) == 'A')
	 {
	    if (*idx == '2') out='s';
	    else if (*idx == '3') out='t';
	    else if (*idx == '4') out='u';
	    else if (*idx == '5') out='v';
	    else if (*idx == '6') out='w';
	    else if (*idx == '7') out='x';
	    else if (*idx == '8') out='y';
	    else if (*idx == '9') out='z';
         }


         else if (toupper(*bufPtr) == 'C')
	 {
	    if (*idx == '1') out='A';
	    else if (*idx == '2') out='B';
	    else if (*idx == '3') out='C';
	    else if (*idx == '4') out='D';
	    else if (*idx == '5') out='E';
	    else if (*idx == '6') out='F';
	    else if (*idx == '7') out='G';
	    else if (*idx == '8') out='H';
	    else if (*idx == '9') out='I';
         }

         else if (toupper(*bufPtr) == 'D')
	 {
	    if (*idx == '1') out='J';
	    else if (*idx == '2') out='K';
	    else if (*idx == '3') out='L';
	    else if (*idx == '4') out='M';
	    else if (*idx == '5') out='N';
	    else if (*idx == '6') out='O';
	    else if (*idx == '7') out='P';
	    else if (*idx == '8') out='Q';
	    else if (*idx == '9') out='R';
         }

         else if (toupper(*bufPtr) == 'E')
	 {
	    if (*idx == '2') out='S';
	    else if (*idx == '3') out='T';
	    else if (*idx == '4') out='U';
	    else if (*idx == '5') out='V';
	    else if (*idx == '6') out='W';
	    else if (*idx == '7') out='X';
	    else if (*idx == '8') out='Y';
	    else if (*idx == '9') out='Z';
         }

         else if (toupper(*bufPtr) == 'F') out=*idx;


         printf(" %c ",out);
         bufPtr+=2;
      }
   } /* while */
   
   printf("\n");
  }

  return 0;
}
