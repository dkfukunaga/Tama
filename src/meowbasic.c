#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    int con2 = addConstant(&chunk, 3.14);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, con2, 123);
    int con3 = addConstant(&chunk, 2.71);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, con3, 123);
    int con4 = addConstant(&chunk, 123.456);
    writeChunk(&chunk, OP_CONSTANT, 124);
    writeChunk(&chunk, con4, 124);


    writeChunk(&chunk, OP_RETURN, 250);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}