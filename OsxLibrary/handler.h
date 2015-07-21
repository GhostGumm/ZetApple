#ifndef _HANDLER_H__
#define _HANDLER_H__

#include "zetaclient.h"

bool     cometd_ping_request(cometd_client_t *client, zeta_handshake_manager_t *hm, char *SDepId, char *action);
bool     cometd_pong_request(cometd_client_t *client, zeta_handshake_manager_t *hm, char *SDepId, char *action, char* avaible, char *owner, char *ressource, char *uid, char *user);
bool     cometd_execute_request(cometd_client_t *client, zeta_handshake_manager_t *hm, char *SDepId, char *cmd, HashMaps *data, char *from, char *fromRes, char *owner, char *resource);
bool     cometd_macro_call_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *name, HashMaps *param);
bool     cometd_my_groups_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, const char *owner);
bool     cometd_groups_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *owner);
bool     cometd_group_del_users_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *groupName, char *owner, HashMaps *users);
bool     cometd_group_del_user_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *owner, char *user);
bool     cometd_group_list_grant_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, HashMaps *action, char *group, char *owner, char *ressource, bool rorg);
bool     cometd_group_revoke_and_grant_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *action, char *group, char *owner, char *ressource, bool rorg);
bool     cometd_group_del_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *groupe, char *owner);
bool     cometd_group_add_users_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *groupName, char *owner, HashMaps *users);
bool     cometd_group_users_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *owner);
bool     cometd_add_me_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *owner, char * user);
bool     cometd_all_groups_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *owner);
bool     cometd_group_create_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *group, char *groupName);
bool     cometd_queue_done_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, HashMaps *result, bool success, char *taskId);
bool     cometd_queue_submit_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, OwnerRessource *origin, char *desc, char *origBusy, char *origDep, HashMaps *data);
bool     cometd_queue_submit_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, OwnerRessource *origin, char *desc, char *origBusy, char *origDep, HashMaps *data);
bool     cometd_queue_register_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, int qid);
bool     cometd_stack_get_listeners_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *stack, char *owner);
bool     cometd_stack_set_listeners_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, HashMaps *setString, char *stack, char *owner);
bool     cometd_stack_remove_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, HashMaps *guidList, char *stack, char *owner);
bool     cometd_stack_push_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *guid, char *stack, HashMaps *data, char *owner);
bool     cometd_stack_listing_request(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *stack, char *page, char *owner);
bool     cometd_request_messaging(cometd_client_t *client, zeta_handshake_manager_t *hm, const char *SDepId, char *Target, char *Message);
bool     cometd_request_get_gda(cometd_client_t* client, zeta_handshake_manager_t *hm, const char *SDepId, char *table,  char *column , char *key, char *key2);
bool     cometd_request_put_gda(cometd_client_t* client, zeta_handshake_manager_t *hm, const char *SDepId, char *table,  char *column , char *key, char *key2, HashMaps *YourData);
bool     cometd_request_list_gda(cometd_client_t* client, zeta_handshake_manager_t *hm, const char *SDepId, char *table, char *column, char *pNum, char *pSize);
bool     cometd_request_echo(cometd_client_t* client, zeta_handshake_manager_t *hm, char *request, const char *SDepId);
bool     cometd_request_ls(cometd_client_t* client, zeta_handshake_manager_t *hm, char *folder, const char* SDepId);






bool		ls_redirection_handler(cometd_client_t* client, cometd_message* message);
bool		echo_redirection_handler(cometd_client_t *client, cometd_message *message);
bool		gda_list_handler(cometd_client_t *client, cometd_message *message);
bool		gda_put_handler(cometd_client_t *client, cometd_message *message);
bool		gda_get_handler(cometd_client_t *client, cometd_message *message);
bool		messaging_handler(cometd_client_t *client, cometd_message *message);
bool		receive_handler(cometd_client_t *client, cometd_message *message);
bool		stack_list_handler(cometd_client_t *client, cometd_message *message);
bool		stack_remove_handler(cometd_client_t *client, cometd_message *message);
bool		stack_set_listeners_handler(cometd_client_t *client, cometd_message *message);
bool		stack_get_listeners_handler(cometd_client_t *client, cometd_message *message);
bool		queue_register_handler(cometd_client_t *client, cometd_message *message);
bool		queue_submit_handler(cometd_client_t *client, cometd_message *message);
bool		queue_done_handler(cometd_client_t *client, cometd_message *message);
bool		group_create_handler(cometd_client_t *client, cometd_message *message);
bool		add_me_handler(cometd_client_t *client, cometd_message *message);
bool		group_users_handler(cometd_client_t *client, cometd_message *message);
bool		group_add_users_handler(cometd_client_t *client, cometd_message *message);
bool		group_revoke_handler(cometd_client_t *client, cometd_message *message);
bool		group_grant_handler(cometd_client_t *client, cometd_message *message);
bool		group_error_handler(cometd_client_t *client, cometd_message *message);
bool		group_list_grant_handler(cometd_client_t *client, cometd_message *message);
bool		my_groups_handler(cometd_client_t *client, cometd_message *message);
bool		groups_handler(cometd_client_t *client, cometd_message *message);
bool		group_del_users_handler(cometd_client_t *client, cometd_message *message);
bool		group_del_user_handler(cometd_client_t *client, cometd_message *message);
bool		macro_call_handler(cometd_client_t *client, cometd_message *message);


#endif
