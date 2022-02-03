#define WRITE_UINT32(p, i)                      \
do {                                            \
  (p)[0] = ((i) >> 24) & 0xff;                  \
  (p)[1] = ((i) >> 16) & 0xff;                  \
  (p)[2] = ((i) >> 8) & 0xff;                   \
  (p)[3] = (i) & 0xff;                          \
} while(0)

void loop(uint8_t *dst, uint8_t src, size_t words) {
  for (i = 0; i < words; i++, dst += 4)
    WRITE_UINT32 (dst, src[i]);
}
