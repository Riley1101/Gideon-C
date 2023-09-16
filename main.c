#include "chunk.h"
#include "common.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  printf("Hello world\n");
  return 0;
}
