#ifndef HASH_H
#define HASH_H

#include "../Common/Node/Node.h"

typedef struct Hash {

  Node** hashTables;
  int hashSize;
  int hashPopulation;

  void (*DisplayTable)(struct Hash tHash);
  void (*FreeAll)(struct Hash* tHash);
  void (*Insert)(struct Hash* tHash, char* tValue);
  char* (*Remove)(struct Hash* tHash, char* tValue);
  char* (*Find)(struct Hash tHash, char* tValue);

} Hash;

unsigned int GetHashCode(char* tValue, unsigned int hashSize);
Hash H_Constructor(unsigned int hashSize);
Hash RehashTable(Hash* tHash);

#endif
