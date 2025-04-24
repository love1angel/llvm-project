// RUN: %check_clang_tidy %s misra-array-declaration %t

#include <stdint.h>

extern int32_t array1[];
// CHECK-MESSAGES: :[[@LINE-1]]:16: warning: array: array1 's size is not specificed. [misra-array-declaration]

int32_t array2[10];

int32_t array3[] = {0, 10 , 15};

extern int32_t array4[42];
