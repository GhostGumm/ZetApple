/**
 * Copyright 2012 Pablo Abreu pulco-citron@sourceforge.net
 */

#ifndef COMETD_H
#define COMETD_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "comet_message.h"
#include "comet_buffer.h"
#include "comet_memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/*#ifndef BOOL
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif
*/
typedef enum {
	UNCONNECTED, CONNECTING, CONNECTED
} cometd_client_state;

struct cometd_transport;
struct cometd_client;
typedef cometd_array_t * (*cometd_transport_message_parser)(const char *buffer, size_t size);
typedef void (*cometd_transport_init)(struct cometd_transport * transport, const char * serverUrl);
typedef bool (*cometd_transport_main)(struct cometd_transport * transport, struct cometd_client * client);
typedef void (*cometd_transport_message_sender)(struct cometd_transport * transport, cometd_message * message, struct cometd_client * client, bool bypassQueue);

// never call the transport functions defined here directly
typedef struct cometd_transport {
	const char * serverUrl;
	cometd_transport_message_parser parser;
	cometd_transport_message_sender sender;
	cometd_transport_main main;
	cometd_transport_init init;
} cometd_transport_t;

typedef struct cometd_client {
	char * serverUrl;
	cometd_client_state state;
	cometd_transport_t * transport;
} cometd_client_t;

/* init */
int cometd_init(void);

/* default transports (NOT singletons) */
cometd_transport_t * cometd_create_long_polling_transport(void);

/* connection */
cometd_client_t * cometd_create_client(const char * serverUrl, cometd_transport_t * transport);
/** returns true if unsuccessful*/
bool cometd_handshake(cometd_client_t * client, json_t * handshakeFields);
/** a disconnected client MUST NOT be re-used afterwards*/
void cometd_disconnect(cometd_client_t * client);
/* main loop, for one-thread synchronous behaviour*/
bool cometd_main_loop(cometd_client_t * client);
// TODO destroy client

/* pub-sub */
/** returns true if unsuccessful. Callbacks SHOULD always return false */ typedef bool (*cometd_subscription_callback)(cometd_client_t * client, cometd_message * message);
/** the current implementation only works for service channels. Channel globbing will not work */
void cometd_channel_subscribe(cometd_client_t * client, cometd_subscription_callback callback, const char * channel);
void cometd_publish(cometd_client_t * client, const char * channel, json_t * data);
// TODO unsubscribe

#ifdef __cplusplus
}
#endif

#endif

