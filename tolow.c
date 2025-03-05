#include <ctype.h>
#include <stdio.h>

int main() {
  int i;
  char car[676] = "toyota";
  printf("I want to convert lower case to upper cade");
  for (i = 0; car[i] != '\0'; i++) {
    car[i] = toupper(car[i]);
  }
  printf("converted string %s", car);
}
