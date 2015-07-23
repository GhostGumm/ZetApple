
#ifndef COMETD_MESSAGE_H
#define COMETD_MESSAGE_H

#include <stdbool.h>
#include <stdio.h> // FILE
#include "jansson.h" // includes stdarg

#include "comet_buffer.h"
#include "HashMaps.h"
#include "queueInfo.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	bool present;
	const char * reconnect;
	int interval;
	json_t * sourceAdvice;// for transport specific fields
	// json_t * hosts; TODO ?
	// bool multipleClients; not needed ?
} cometd_message_advice;

typedef struct {
  const char * channel;
  const char * clientId;
  const char * version;
  const char * minimumVersion;
  const char * connectionType;
  const char * userId;
  json_t * supportedConnectionTypes;// FIXME array
  cometd_message_advice advice;
  const char * id;
  json_t * data;
  const char * timestamp;// TODO ? 
  bool successful, successfulSet;
  const char * subscription;
  json_t * ext;
  json_t * source;
} cometd_message;

  /* --------- Json Initers --------- */

  
  json_t        *init_execute_data(char *cmd, HashMaps *data, char *from, char *fromRes, char *owner, char *resource);
  json_t        *init_pong_data(char *action, bool avaible, char *owner, char *resource, char *uid, char *user);
  json_t        *init_ping_data(char *action);  
  json_t        *init_macro_call_data(char *name, HashMaps *params);
  json_t        *init_del_user_data(char *group, char *owner, char *user);
  json_t        *init_del_users_data(char *group, char *groupName, char *owner, HashMaps *user);
  json_t        *init_groups_mygroups_data(const char *owner);
  json_t        *init_list_grant_data(HashMaps *data, char *group, const char *owner, char *ressource); 
  json_t        *init_revoke_data(char *action, char *group, const char *owner, char *ressource);
  json_t        *init_add_users_data(char *Group, const char *GroupName, const char *Owner, HashMaps * users);
  json_t        *init_add_me_data(char *group, const char *owner, const char *user);
  json_t	*init_group_create_data(char *group, char *groupName, const char *owner);
  json_t	*init_queue_done_data(HashMaps *data, bool success, char *taskId);
  json_t	*init_queue_submit_data(OwnerRessource* origin, char *desc, char *origBusy, char *origDep, HashMaps *data);
  json_t	*init_queue_register_data(int);
  json_t	*init_messaging_data(char *Message, char *Target);
  json_t	*init_request_data(char *request, char *service, char *pNum, char *pSize);
  json_t	*init_put_data(char *table, char *column, char *key, char *key2, HashMaps *YourData);
  json_t	*init_stack_data(char *stack, char *page, char *owner);
  json_t	*init_stack_push_data(char *Guid, char *Stack, HashMaps *Data, char *Owner);
  json_t	*init_stack_remove_data(HashMaps *Data, char *Stack, char *Owner, int type);
  json_t	*init_stack_get_listeners_data(char *Stack, char *Owner);
  
  /* --------------------------------- */
  
/* cometd_message instances MUST NOT be allocated on the stack, because processing can be deferred and asynchronous */
cometd_message * cometd_message_create(void);
void cometd_message_free(cometd_message * message);

bool cometd_isMeta(const cometd_message * message);

int cometd_dump_message(void * output, cometd_message * message, json_dump_callback_t callback);
int cometd_dump_message_file(FILE * f, cometd_message * message);
int cometd_dump_message_buffer(cometd_buffer_t* buffer, cometd_message * message);

int cometd_dump_messages(void * output, cometd_array_t * messageList, json_dump_callback_t callback);
int cometd_dump_messages_file(FILE * f, cometd_array_t * messageList);
int cometd_dump_messages_buffer(cometd_buffer_t* buffer, cometd_array_t * messageList);

cometd_array_t * comet_message_list_create(cometd_message * firstMessage);

  
#ifdef __cplusplus
}
#endif

#endif

