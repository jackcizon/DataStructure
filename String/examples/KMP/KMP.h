#ifndef KMP_H
#define KMP_H

#endif

#include"heapstring.h"

void ComputePrefix(HeapStr* match, int* prefix);

int KMPMatch(HeapStr* target, HeapStr* match);