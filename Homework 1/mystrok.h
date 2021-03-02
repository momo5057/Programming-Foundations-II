#include <iostream>

using namespace::std;

class mystrok
{
   public:
      mystrok();
      mystrok(mystrok& other);
      ~mystrok();

      char *mystrtok(char *str, const char *delim);
      char *find_first_non_in_the_set(char *str, const char *set);
      char *find_first_in_the_set(char *str, const char *set);
};
