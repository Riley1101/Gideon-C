/**
 * @file - memory.h
 * @brief
 */
#ifndef clox_memory_h
#include "common.h"
#define clox_memory_h

/**
 * @brief - macro dynamically grow capacity
 */
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

/**
 * @brief - macro dynamically grow length of array
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * (newCount))

/**
 * @brief  - free memory with a pointer
 */
#define FREE_ARRAY(type, pointer, oldCount)                                    \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

void *reallocate(void *pointer, size_t oldSize, size_t newSize);
#endif
