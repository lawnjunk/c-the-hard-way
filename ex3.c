#include <stdio.h>

  /*
   * printf format charicters
   * d = signed decimal int
   * u = unsigned decimal interger
   * 0 = unsigned octal
   * x = unsigned hexadecimal integer
   * C = unsigned hexadecimal integer (uppercase)
   * f = decimal floating point (lowercase)
   * F = decimal floating point (Uppercase)
   * e = scientific notation (mantissa/expnent) (lowercase)
   * E = scientific notation (mantissa/expnent) (uppercase)
   * g = use the shortest representation of: %e or %f
   * G = use the shortest representation of: %E or %F
   * a = Hexadecimal floating poing (lowercase)
   * A = Hexadecimal floating poing (uppercase)
   * c = character
   * s = string of characters
   * p = pointer address
   * n = nothing printed
   * % = print a literal % 
   */

int main(int argc, char **argv){
  char *name = "Duncan Marsh";
  int age = 24;
  float shred2ZoneRatio = 33.33;

  printf("%s is my name.\n", name);
  printf("I am %d years old.\n", age);
  printf("my shred 2 zone ration is only %f./n", shred2ZoneRatio);

  return 0;
}
