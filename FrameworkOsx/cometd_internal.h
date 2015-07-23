

#ifndef COMETD_INTERNAL_H
#define COMETD_INTERNAL_H

#include "cometd.h"
#include "HashMaps.h"

#ifdef __cplusplus
extern "C" {
#endif
extern cometd_malloc cometd_malloc_fn;
void * cometd_zmalloc_fn(size_t size);
extern cometd_free cometd_free_fn;
#define CALLOC(TYPE, VAR) TYPE * VAR = (TYPE *)cometd_zmalloc_fn(sizeof(TYPE));
cometd_array_t * cometd_transport_default_message_parser(const char *buffer, size_t size);
int cometd_http_transport_init(cometd_transport_message_parser);
bool cometd_dispatch_message(cometd_client_t * client, cometd_message * message);
bool cometd_connect(cometd_client_t * client, cometd_message * msg);

bool cometd_string_startsWith(const char * string, const char * prefix);
  
typedef struct {
  cometd_client_t base;
  void * subscriptions;
  const char * clientId;
  const char * userId;
  bool firstHandshakeOk;
  json_t * handshakeFields;
} cometd_client_impl;

typedef struct {
	const char * channel;
	cometd_array_t * callbacks;
} cometd_client_subscription;

#define MSG_FIELD     "messaging"
#define SERVICE_PREFIX  "/service/"
#define META_PREFIX  "/meta/"
#define META_HANDSHAKE "/meta/handshake"
#define META_CONNECT "/meta/connect"
#define META_DISCONNECT "/meta/disconnect"
#define META_SUBSCRIBE "/meta/subscribe"
#define META_UNSUBSCRIBE "/meta/unsubscribe"
#define CLIENT_ID_FIELD "clientId"
#define DATA_FIELD "data"
#define CHANNEL_FIELD "channel"
#define ID_FIELD "id"
#define ERROR_FIELD "error"
#define TIMESTAMP_FIELD "timestamp"
#define TRANSPORT_FIELD "transport"
#define ADVICE_FIELD "advice"
#define SUCCESSFUL_FIELD "successful"
#define SUBSCRIPTION_FIELD "subscription"
#define EXT_FIELD "ext"
#define CONNECTION_TYPE_FIELD "connectionType"
#define VERSION_FIELD "version"
#define MIN_VERSION_FIELD "minimumVersion"
#define SUPPORTED_CONNECTION_TYPES_FIELD "supportedConnectionTypes"
#define LONG_POLLING "long-polling"
#define RECONNECT_FIELD "reconnect"
#define INTERVAL_FIELD "interval"
#define TIMEOUT_FIELD "timeout"
#define RECONNECT_RETRY_VALUE "retry"
#define RECONNECT_HANDSHAKE_VALUE "handshake"
#define RECONNECT_NONE_VALUE "none"
#define DEFAULT_VERSION "1.0"

// traces. '__func__' is C99 compliant
#define DEBUG
  #ifdef DEBUG
  #include <time.h>
#define printtime {time_t rawtime;char __cmtd_buf_time[80];struct tm * timeinfo;time ( &rawtime );timeinfo = localtime ( &rawtime );strftime (__cmtd_buf_time,80,"%X ",timeinfo);printf ("%s", __cmtd_buf_time);}
#define CMTD_TRACE_IN static int __cmtd_counter=0;const int __cmtd_counter_current=__cmtd_counter++;printtime;printf(__func__ );printf(" IN %d\n", __cmtd_counter_current);
#define CMTD_TRACE_DEBUG(...) printtime;printf(__func__ );printf(" DEBUG "); printf(__VA_ARGS__);
#define CMTD_OUT __cmtd_counter--;printtime;printf(__func__ );printf(" OUT %d\n", __cmtd_counter_current);
#define CMTD_TRACE_OUT CMTD_OUT;
#define CMTD_RETURN(VAL) CMTD_OUT; return (VAL);
  #else
  #define CMTD_TRACE_IN
#define CMTD_TRACE_DEBUG(...)
  #define CMTD_TRACE_OUT
#define CMTD_RETURN(VAL) return (VAL);
#endif

#ifdef __cplusplus
}
#endif

#endif

