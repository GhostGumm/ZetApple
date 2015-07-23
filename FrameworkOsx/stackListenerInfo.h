#include "jansson.h"
#include "HashMaps.h"
#include "comet_message.h"
#include "listingEntryInfo.h"

typedef struct _stackListeners StackListeners;

struct _stackListeners
{
  int index;
  const char *stack;
  const char *owner;
  HashMaps   *listeners;
};

void			listener_json_object(json_t *element, int indent, StackListeners **ls);
void			listener_json_array(json_t *element, int indent, StackListeners **ls, const char *key);
void			AssignStringValueToSLI(json_t *element, const char *key, StackListeners **ls);

void			listener_json_integer(json_t *element, int indent, StackListeners **ls, const char *key);
void			listener_json_string(json_t *element, int indent, StackListeners **ls, const char *key);
void			check_listener_type(json_t* element, int indent, StackListeners **ls, const char *key);
StackListeners*		ListenerParsingInfo(cometd_message *message);
