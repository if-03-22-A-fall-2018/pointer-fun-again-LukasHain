#include <stdio.h>

struct PlayStruct{
  unsigned int int_value;
  double double_value;
  unsigned char a_string[64];
};

void print_struct(struct PlayStruct ps, struct PlayStruct* pps){
  printf("Values of struct ps: <%d> <%f> <%s>\n", ps.int_value, ps.double_value, ps.a_string);
  printf("Values of struct pps: <%d> <%f> <%s>\n", pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps, struct PlayStruct* pps){
  ps.int_value = 6;
  ps.double_value = 6.6;
  ps.a_string[0] = 'b';
  ps.a_string[1] = 'y';
  ps.a_string[2] = 'e';
  ps.a_string[3] = 'b';
  ps.a_string[4] = 'y';
  ps.a_string[5] = 'e';

  pps->int_value = 7;
  pps->double_value = 7.7;
  pps->a_string[0] = 't';
  pps->a_string[1] = 's';
  pps->a_string[2] = 'c';
  pps->a_string[3] = 'h';
  pps->a_string[4] = 'a';
  pps->a_string[5] = 'u';
}

void print_string(unsigned char string_to_print[]){
  printf("%s\n", string_to_print);
}

void change_string(unsigned char string1[], unsigned char* p_string[]){
  string1[2] = '\0';
  *p_string[1] = '\0';
}

int main(int argc, char const *argv[]) {
  struct PlayStruct play_struct = {5, 5.5, "Hello"};
  struct PlayStruct* play_struct_pointer = &play_struct;

  print_struct(play_struct, play_struct_pointer);
  change_struct(play_struct, play_struct_pointer);
  print_struct(play_struct, play_struct_pointer);
  //The value of ps is the same as the value of pps, because the change of pps affects both ps and pps.
  printf("\n");

  print_string(play_struct.a_string);

  unsigned char another_string[16]="abcde";
  unsigned char *another_string_pointer = another_string;

  change_string(play_struct.a_string, another_string_pointer);
  print_string(play_struct.a_string);
  print_string(another_string);
//both strings got cut because I added '\0'

  return 0;
}
