

#ifndef ZETACLIENT_H
#define ZETACLIENT_H

#include "cometd.h"

#ifdef __cplusplus
extern "C" {
#endif

struct zeta_client;
typedef json_t * (*zeta_handshake_fields)(struct zeta_client * zetaClient);
typedef struct zeta_handshake_manager {
	const char * businessId;
	const char * deploymentId;
	const char * authType;
	const char * authVersion;
	zeta_handshake_fields handshakeFields;
	cometd_array_t* data;
} zeta_handshake_manager_t;

typedef struct zeta_client {
	cometd_client_t * cometClient;
	const char * businessId;
	const char * resource;
	zeta_handshake_manager_t * handshakeManager;
} zeta_client_t;


/* connection */
zeta_handshake_manager_t * zeta_create_handshake_manager(const char * businessId, const char * deploymentId, const char * authType, const char * authVersion, zeta_handshake_fields handshakeFields);
zeta_handshake_manager_t * zeta_create_mem_handshake_manager(const char * businessId, const char * deploymentId, const char * login, const char * password);
  zeta_client_t * zeta_create_client(const char * serverUrl, cometd_transport_t * transport, const char * businessId, zeta_handshake_manager_t * handshakeManager, const char *resource);
bool zeta_handshake(zeta_client_t * client);



#ifdef __cplusplus
}
#endif

#endif

