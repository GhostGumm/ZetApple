#ifndef MESSAGING_ENTRY_INFO_
#define MESSAGING_ENTRY_INFO_


#include "jansson.h"
#include "comet_message.h"
#include "HashMaps.h"

typedef struct _MsgInfo
{

  HashMaps     *data;
  const char   *target;
  const char   *source;
  
}MsgInfo;


void		check_msg_type(json_t* element, int indent, MsgInfo **gda, const char *key);
MsgInfo*	InitMsg(MsgInfo *init);
void		msg_json_null(json_t *element, int indent, MsgInfo **gda);
void		msg_json_object(json_t *element, int indent, MsgInfo **gda);
void		msg_json_array(json_t *element, int indent, MsgInfo **gda, const char *key);
void		AssignMsgStringValue(json_t *element, const char *key, MsgInfo **gda);
void		msg_json_integer(json_t *element, int indent, MsgInfo **gda, const char *key);
void		msg_json_string(json_t *element, int indent, MsgInfo **gda, const char *key);
void		msg_json_real(json_t *element, int indent, MsgInfo **gda, const char *key);
void		msg_json_true(json_t *element, int indent, MsgInfo **gda, const char *key);
void		msg_json_false(json_t *element, int indent, MsgInfo **gda, const char *key);
void		printMsgData(MsgInfo **gda);
MsgInfo		*MsgInfoParsingInfo(cometd_message *message);

#endif
