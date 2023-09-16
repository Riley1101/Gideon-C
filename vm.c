#include "vm.h"
#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "stdio.h"

VM vm;

void initVM() {}

void freeVM() {}

static InterpretResult run() {

#undef READ_CONSTANT
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define READ_BYTE() (*vm.ip++)
  for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
    case OP_RETURN: {
      return INTERPRET_OK;
      break;
    }
    case OP_CONSTANT: {
      Value constant = READ_CONSTANT();
      printValue(constant);
      printf("\n");
      break;
    }
    }
  }
#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}
