#ifndef SKEIN_H
#define SKEIN_H

#ifdef __cplusplus
extern "C" {
#endif

void skein_hash(const char* input, char* output, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
