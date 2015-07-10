LEARN C THE HARD WAY
====================

**notes and solutions for learn c the hard way**

The book is can be found here [learn c the hard way](http://c.learncodethehardway.org/book/)  

----
### Introduction
```
The c programming language's only failing is giving you access
to what is really there, and telling you the cold hard raw truth. 
C gives you the red pill. C pulls the curtain back to show you 
the wizzard. C is truth.
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
 
### ex5 program breakdown
* walk through a basic hello-world ish program and explain the each line

### ex6 types of variables (primatives)
* **signed char** - 8bit signed char -128 to 127
* **unsigned char** - 8bit char 0 to 255
* **char** - depending on the sys its signed char or unsigned char
* **short int** - 16bit signed int -32,768 to 32,767
* **unsigned short int** - 16bit uint 0 to 65,535
* **int** - 32bit signed int −2,147,483,648 to 2,147,483,647
* **unsigned int** - 32bit unsigned int 0 to 4,294,967,295
* **long int** - 64bit signed int 
* **unsigned long int** - 64bit unsigned int
* **float** - 16bit float
* **double** - 32bit float
* **long double** - 64bit float

### ex7 a little arythmitc and more on primatives
* aritymatic and printf

### ex8 a little about arrays
* arrays are lists of a specific prymitave type
* strings are arays pf chars ending withd **\0**
* `sizeof()` tells you the number of bytes something has
* `sizeof(array) / sizeof(int)` size of array / size of sizeof arraytype gives you the array length

### ex9 strings are arrays of characters
* strings are arrays of characters

### ex10 arrays of strings / argv
* strings are arrays
* arrays of strings are arrays of arrays
* args to a cmd are just arrays of strings

### ex11 while loops and bool expressions
* there is no boolean type in c99
* bollion expressions are things like `1 > 0` this will evaluate to True
* the number **0** is false, all other numers are true
* while loops ya'know
 * use them when you dont know exactly how long a loop gun run

### ex12 if, if else , else
* if, if else else ya' know
* one way to controll the flow of your program

### ex13 switch
* switch what yo do depending on some cases with a swtich
* switch staments dont use boolean expressions, they are a jump table

### ex14 functions
* use functions whenever something is re-usable
* use functions to moduluarize your code
* if you are going to call the functions in an order that they are not defined in you must proto type the functions at the top before thay are called;
 * ie.
```
#include <ctype.h>

// prototype o the function
int canIPrintIt(char ch);

int main(){
  char anEx = 'x';
  
  // call the function
  if(canIPrintIt(anEx){
    printf("%c\n", anEx);
  } 
}

// implement the function
int canIPrintIt(char ch){
 return isalpha(ch) || isblank(ch);
}
```

### ex15 POINTERS!
* pointers are refrences to memory address
* use ** * ** to make a pointer and use ** * ** to defrefrence a pointer
* good times to use a pointer
 * when passing larg chunks of data
 * when working with a chunk of mem (strings, arrays, structs \*\*)
 * taking the address of a function so you can use it as a dynamic callback **:)**
 * use arrays if you can!
 * complex scanning of chunks of memory such as converting bytes off a network socket into data structures or parsing file
* because pointers are numbers (memory address numbers) you can do arithmatic with them
 * for example with arrays **ex1 and ex2 are the same**
``` 
#include <stdio.h>

int main(){

  /// ex1 -- without pointer arithmatic;
  int ex1[] = { 11,13,15,17};
  int ex1Length = sizeof(ex1)/sizeof(int);

  for (int i=0; i<ex1Length; i++){
    printf("ext1[%d]:  %d\n", i, ex1[i]);
  }

  /// ex2 -- with pointer arithmatic;
  int *ex2 = ex1;

  int *cur = ex2;
  while ( cur < (ex2 + ex1Length) ){
    printf("ext[%d]:  %d\n", cur, *(cur));
    cur++;
  }

}
// ext1[0]:  11
// ext1[1]:  13
// ext1[2]:  15
// ext1[3]:  17
// ext[-1050837024]:  11
// ext[-1050837020]:  13
// ext[-1050837016]:  15
// ext[-1050837012]:  17

```
* pointer lexicon
 * `type *ptr` - a pointer of type name ptr
 * `*ptr` - the value of what ever ptr is pointed at
 * `(ptr + 1)` - the value you of what ever ever ptr is pointed at plus i 
 * `&thing` - the addres of a thing
 * `type *ptr = &thing` - a pointer of type named ptr set to the address of thing
 * `ptr++` - increment where ptr points

###
