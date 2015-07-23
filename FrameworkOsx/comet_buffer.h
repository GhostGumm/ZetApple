

#ifndef COMETD_BUFFER_H
#define COMETD_BUFFER_H

#include <stddef.h>

#include "comet_memory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cometd_buffer {
	char * buffer;
	char * writeCurrent;
	const char * readCurrent;
	size_t size;
} cometd_buffer_t;

/** allocates char buffer for an existing buffer struct and returns 'buffer'*/ 
cometd_buffer_t * cometd_buffer_create(cometd_buffer_t * buffer, size_t size);
/** frees the char buffer, but not 'buffer'*/
void cometd_buffer_free(cometd_buffer_t * buffer);
/** appends data to the current pos of buffer. returns non-zero if error (remaining space too small), in which case nothing is copied*/
int cometd_buffer_append(cometd_buffer_t * buffer, const void * data, size_t size);
/** reads data from the current pos of buffer. returns the number of bytes read (max is 'size', anything less means that everything was read)*/
int cometd_buffer_read(cometd_buffer_t * buffer, void * dest, size_t size);
/** fseek like*/
int cometd_buffer_read_seek(cometd_buffer_t * buffer, long int offset, int origin);
void cometd_buffer_reset(cometd_buffer_t * buffer);
size_t cometd_buffer_readable_bytes(cometd_buffer_t * buffer);


typedef struct cometd_array {
	void ** array;
	size_t capacity;
} cometd_array_t;

void cometd_array_add(void * element, cometd_array_t** array);
void cometd_array_free(cometd_array_t** array, cometd_free elementFree);

#ifdef __cplusplus
}
#endif

#endif

