#ifndef GROUP_USERS_INFO
#define  GROUP_USERS_INFO

#include "jansson.h"
#include "HashMaps.h"
#include "comet_message.h"


typedef struct _groupUsers GroupUsers;

struct _groupUsers {
  
  const char * group;
  const char * groupName;
  const char * owner;

  HashMaps *userList;
};



void	users_json_object(json_t *element, int indent, GroupUsers **ls);
void	users_json_array(json_t *element, int indent, GroupUsers **ls, const char *key);
void  AssignStringValueToUsers(json_t *element, const char *key, GroupUsers **ls);
void	users_json_string(json_t *element, int indent, GroupUsers **ls, const char *key);
void	check_users_type(json_t* element, int indent, GroupUsers **ls, const char *key);
GroupUsers   *UsersInit(GroupUsers *ls);
GroupUsers   *UsersParsingInfo(cometd_message *message);



#endif
