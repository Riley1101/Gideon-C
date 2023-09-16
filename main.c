#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  initVM();
  Chunk chunk;
  initChunk(&chunk);
  interpret(&chunk);
  freeChunk(&chunk);
  freeVM();
  return 0;
}
