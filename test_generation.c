#include "atf.h"
//#include "atf.c"
#include <stdlib.h>
#include <stdio.h>

bool TS1_divides_N(int N, int TS1, int TS2, int TS3, int unused2, int unused3, int unused4, int unused5, int unused6, int unused7) {
  // configurations where TS1 divides N are valid
  return N % TS1 == 0;
}
bool TS2_less_than_or_eq_TS1(int N, int TS1, int TS2, int TS3, int unused2, int unused3, int unused4, int unused5, int unused6, int unused7) {
  // configurations where TS2 is less than or equal TS1 are valid
  return TS2 <= TS1;
}
bool TS3_eq_TS1(int N, int TS1, int TS2, int TS3, int unused2, int unused3, int unused4, int unused5, int unused6, int unused7) {
  return TS1 == TS3;
}
bool TS1_equal_TS4(int N, int TS1, int TS2, int TS3, int TS4, int unused3, int unused4, int unused5, int unused6, int unused7) {
  return TS1 == TS4;
}

int main() {
  // define tuning parameters
  tp_t parameters[] = {
    create_tp("N",   16, 16, NULL),
    create_tp("TS1",  1, 16, TS1_divides_N),
    create_tp("TS2",  1, 16, TS2_less_than_or_eq_TS1)//,
    //create_tp("TS3",  1, 16, TS3_eq_TS1)//,
    //create_tp("TS4",  1, 16, TS1_equal_TS4),
  };
  
  // generate search space
  printf("    N  TS1  TS2 \n");
  search_space_t search_space;
  generate_search_space(parameters, 3, &search_space);
}
