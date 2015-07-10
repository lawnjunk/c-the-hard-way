LEARN C THE HARD WAY
====================

**notes and solutions for learn c the hard way**

The book is can be found here [learn c the hard way](http://c.learncodethehardway.org/book/)  

----
### Introduction
```
The c programming language's only failing is giving you access to what is really there, and telling you the cold hard raw truth. C gives you the red pill. C pulls the curtain back to show you the wizzard. C is truth.
```
**-Zed**

### ex1 Hello wolrd
* write a hello wold program
* compile it using cc
* add `-Wall` to **CFLAGS** and enable all compiler warnings
* add `#include <stdio.h>` and to link stdio lib

### ex2 Makefile
* C programs are not interperated by a pre-compiled binary like JavaScript instead they are compiled
* Make can be used to compile your programs, run your tests, and automate tasks
* write a Makefile to compile ex1 and clean build dir

### ex3 Formatted Printing 
* write a program that uses printf to print diff types o primitive
* the data is just 0s in 1s, print f chooses to interperate that data as a __ primitave
* add exercise to Makefile
```
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
```

### ex4 valgrind
* valgrind is a tool for debuging c programs it helps with:
 * detecting many memory management and thread bugs
 * avoding hours of frustrating bug hunting
 * makeing you programs more stable
 * perform detailed profiling to help speed up your programs
 * more [about valgrind](http://valgrind.org/info/about.html)
 
