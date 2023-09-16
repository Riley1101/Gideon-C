#include "chunk.h"
#include "common.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  writeChunk(&chunk, OP_RETURN, 123);

  int constant = addConstant(&chunk, 3.2);
  writeChunk(&chunk, constant, 123);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
