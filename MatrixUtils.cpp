#include "MatrixUtils.h"

void matrix_utils::pError(unsigned int ecode) {
  const static int built_in_LED = 13;
  pinMode(built_in_LED, OUTPUT);

  // for ecode == 0
  while (ecode == 0) {
    digitalWrite(built_in_LED, HIGH);
    delay(10000);
  }
  
  // for ecode >= 1
  while (true) {
    for (unsigned int i = 0; i < ecode; ++i) {
      digitalWrite(built_in_LED, HIGH);
      delay(50);
    }
    digitalWrite(built_in_LED, LOW);
    delay(1000);
  }
}

uint8_t **matrix_utils::alloc2dimArray(short outer_size, short inner_size) {
  uint8_t **res = (uint8_t **)malloc(sizeof(uint8_t *) * outer_size);
  if (res == NULL) matrix_utils::pError(2);
  for (short i = 0; i < outer_size; ++i) {
    res[i] = (uint8_t *)calloc(inner_size, sizeof(uint8_t));
    if (res[i] == NULL) matrix_utils::pError(2);
  }

  return res;
}

void matrix_utils::free2dimArray(uint8_t **array, short outer_size) {
  for (short i = 0; i < outer_size; ++i) {
    free(array[i]);
  }
  free(array);
}
