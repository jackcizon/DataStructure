#include"vector.h"


vector(int);

vector(float);

vector(double);

vector(char);

vector(string);

PRIVATE void int_operations();    

PRIVATE void double_operations();

PRIVATE void char_operations();

PRIVATE void string_operations();

PRIVATE void test();



void main(void) {

    int_operations();    

    double_operations();

    char_operations();

    string_operations();

    test();

    puts("press enter to exit...");
    getchar();
}




PRIVATE void test(void)
{
    int_vector* i = int_new(3, 1, 2, 3);
    int_traverse(i);

    char_vector* c = char_new(0);
    char_traverse(c);

    float_vector* l = float_new(0);
    float_traverse(l);

    double_vector* f = double_new(3, 1.0, 2.0, 3.0);
    double_traverse(f);

    
    string_vector* s = string_new(3, "aa", "bb", "cc");
    string_traverse(s);
}


PRIVATE void int_operations(void)
{
  int_vector* vdecimal = int_new(0);

    printf("%ld\n", vdecimal->size);
    int_append(vdecimal, 0);
    int_append(vdecimal, 0);
    int_append(vdecimal, 0);
    int_append(vdecimal, 0);
    int_append(vdecimal, 0);
    
    int_pop(vdecimal);
    int_pop(vdecimal);

    printf("%x\n", int_addr(vdecimal, 0));
    printf("%d\n", int_get(vdecimal, 0));
    
    int_traverse(vdecimal);
}


PRIVATE void double_operations(void)
{
  double_vector* vdouble = double_new(0);

    double_append(vdouble, 4.0);
    double_append(vdouble, 0.0);
    double_append(vdouble, 0.0);
    double_append(vdouble, 0.0);
    double_append(vdouble, 0.0);

    double_set(vdouble, 0, 0.0);

    double_traverse(vdouble);
}


PRIVATE void char_operations(void)
{
    char_vector* vchar = char_new(0);

      char_append(vchar, '\n');
      char_append(vchar, 'C');
      char_append(vchar, ' ');
      char_append(vchar, 'L');
      char_append(vchar, 'a');
      char_append(vchar, 'n');
      char_append(vchar, 'g');
      char_append(vchar, 'u');
      char_append(vchar, 'a');
      char_append(vchar, 'g');
      char_append(vchar, 'e');
      char_append(vchar, '\n');

      char_traverse(vchar);
}


PRIVATE void string_operations(void)
{
  string_vector* vstring = string_new(0);

    string_append(vstring, "quotes:\t");
    string_append(vstring, "I love C");

    string_append(vstring, "--------------------------------------------------------------------------------");
    string_append(vstring, "       _________       ____            _____               _______         __            \n");
    string_append(vstring, "      // ______/      / __ \\         / __  \\           // _____/        / /______      \n");
    string_append(vstring, "     // /            / /_/ /         / / /  //          // /             / /______/      \n");
    string_append(vstring, "    // /______      / __ _/         / /_/  //          // /_____        / / | |         \n");
    string_append(vstring, "    \\_______/     /_/ |_|          \\____//           \\______/       /_/  |_|         \n");
    string_append(vstring, "-------------------------------------------------------------------------------");

    string_traverse(vstring);
}
