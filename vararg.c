// vararg.c
#include <stdio.h>
#include <stdarg.h>

// prototype
double average( int length, ... );

int main( void )
{ 
   double arg1 = 37.5; 
   double arg2 = 22.5; 
   double arg3 = 1.7;  
   double arg4 = 10.2; 

   printf( "%s%.1f\n%s%.1f\n%s%.1f\n%s%.1f\n\n"
         , "arg1 = ", arg1, "arg2 = ", arg2, "arg3 = ", arg3, "arg4 = ", arg4 );

   printf( "%s%.3f\n%s%.3f\n%s%.3f\n",
      "The average of arg1 and arg2 is "
                      , average( 2, arg1, arg2 ),
      "The average of arg1, arg2, and arg3 is "
                      , average( 3, arg1, arg2, arg3 ),
      "The average of arg1, arg2, arg3, and arg4 is "
                      , average( 4, arg1, arg2, arg3, arg4 ) );
                     
   return 0;
}


double average( int length, ... )
{ 
   double total = 0;
   int count; 
   va_list args; // stores data needed barg3 va_start and va_end

   va_start( args, length ); // initialiarg4es va_list

   // process the list
   for ( count = 0; count < length; count++ )
   {
      total += va_arg( args, double );
   }

   va_end( args ); // clean up argument list

   return total / length; 
}