#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// unsigned short smalldes(unsigned short input, unsigned short key);
// unsigned short sbox1(unsigned short outer_bit, unsigned short inner_bit);
// unsigned short sbox2(unsigned short outer_bit, unsigned short inner_bit);
// unsigned short sbox3(unsigned short outer_bit, unsigned short inner_bit);
// unsigned short sbox4(unsigned short outer_bit, unsigned short inner_bit);

void print_binary(unsigned char *a){
  for (int j = 0; j<2; j++){
    for (int i = 0; i < 8; i++) {
        printf("%d", !!((a[j] << i) & 0x80));      //masking
    }
  }
  printf("\n");
}



void main(){
  FILE *fp;
  fp = fopen("input.txt", "r");
  int i = 0;
  int j = 0;
  int ctr = 0;
  char input_string[16] = "";
  char key_string[12] = "";
  unsigned char input[2] = "";
  unsigned char key[2] = "";
  fscanf(fp, "Input: %s key: %s", input_string, key_string);
    /*Store the input in binary in a character array */
  for (j = 0; j < 2; j++){
    for (i = 0; i < 8; i++){
      key[j] = key[j] | (key_string[ctr] == '1') << (7-i);  //Shift bits left to their proper position
      input[j] = input[j] | (input_string[ctr] == '1') << (7 - i);
      ctr++;
    }
  }

  print_binary(input);
  print_binary(key);
  // unsigned short a = sbox2(0x3, 0x1);
  // printf("%d", a);
}


unsigned char sbox1(unsigned char outer_bit, unsigned char inner_bit){
  unsigned char table[4][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};

  return table[outer_bit][inner_bit];
}

unsigned char sbox2(unsigned char outer_bit, unsigned char inner_bit){
  unsigned char table[4][4] = {{0,8,1,9},{4,12,4,12},{2,10,10,11},{6,12,7,15}};

  return table[outer_bit][inner_bit];
}

unsigned char sbox3(unsigned char outer_bit, unsigned char inner_bit){
  unsigned char table[4][4] = {{0,4,2,6},{1,5,3,7},{8,12,10,14},{9,13,11,15}}; //2 value changes per row on all sboxes

  return table[outer_bit][inner_bit];
}

unsigned char sbox4(unsigned char outer_bit, unsigned char inner_bit){
  unsigned char table[4][4] = {{0,4,2,6},{8,10,12,14},{1,3,5,7},{9,11,13,15}};

  return table[outer_bit][inner_bit];
}
