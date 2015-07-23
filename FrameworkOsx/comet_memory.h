

#ifndef COMET_MEMORY_H
#define COMET_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

/* custom memory allocation */
typedef void *(*cometd_malloc)(size_t);
typedef void (*cometd_free)(void *);
/* to be called only at init*/
void cometd_set_alloc_funcs(cometd_malloc malloc_fn, cometd_free free_fn);

#ifdef __cplusplus
}
#endif

#endif

