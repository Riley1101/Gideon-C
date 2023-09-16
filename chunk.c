#include "chunk.h"
#include "memory.h"
#include "stdio.h"
#include "value.h"

/**
 * @brief init a chunk of code
 * eg. 0000 0000 0000 0000
 * @param chunk
 */
void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

/**
 * @brief free chunk of code
 *
 * @param chunk
 */
void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  FREE_ARRAY(int, chunk->lines, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

/**
 * @brief write chunk of code
 *
 * @param chunk
 * @param byte
 * @param lines
 */
void writeChunk(Chunk *chunk, uint8_t byte, int lines) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->lines[chunk->count] = lines;
  chunk->count++;
}

/**
 * @brief chunk for constants
 * eg. 2.3
 *
 * @param chunk
 * @param value
 * @return
 */
int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}
