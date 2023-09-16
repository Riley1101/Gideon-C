#include "value.h"
#include "memory.h"
#include <memory.h>
#include <stdio.h>

/**
 * @brief initialize value array
 *
 * @param array
 */
void initValueArray(ValueArray *array) {
  array->values = NULL;
  array->capacity = 0;
  array->count = 0;
}

/**
 * @brief write and grow value array
 *
 * @param array
 * @param value
 */
void writeValueArray(ValueArray *array, Value value) {
  if (array->capacity < array->count + 1) {
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    array->values =
        GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
  }
  array->values[array->count] = value;
  array->count++;
}

/**
 * @brief free value array to initial
 *
 * @param array
 */
void freeValueArray(ValueArray *array) {
  FREE_ARRAY(Value, array->values, array->capacity);
  initValueArray(array);
}

/**
 * @brief print value for debug purposes
 *
 * @param value
 */
void printValue(Value value) { printf("%g ", value); }
