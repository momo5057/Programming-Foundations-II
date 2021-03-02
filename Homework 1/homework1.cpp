#include "mystrok.h"
using namespace::std;

int main()
{
   mystrok M;
   char *ptr;
   char str[] ="Sample string";
   ptr=M.mystrok(str, " ");
   while(ptr != NULL)
   {
      cout << ("%s\n", ptr);
      ptr = M.mystrok(NULL, " ");
   }

   return 0;
}
