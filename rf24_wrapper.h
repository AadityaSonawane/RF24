#ifndef RF24_WRAPPER_H
#define RF24_WRAPPER_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void init_rf24();
bool rf24_send(void *data, size_t len);
bool rf24_receive(void *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif  // RF24_WRAPPER_H
