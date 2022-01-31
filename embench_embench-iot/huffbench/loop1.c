#include <stdlib.h>
#define byte size_t

void loop(size_t *freq, size_t *dptr, byte* data, size_t data_len) {
  for (int i = 0; i < data_len; ++i)
    {
      ++freq[(size_t) (*dptr)];
      ++dptr;
    }
}
