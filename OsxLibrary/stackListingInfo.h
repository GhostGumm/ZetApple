#include "jansson.h"
#include "HashMaps.h"
#include "comet_message.h"
#include "listingEntryInfo.h"


typedef struct _stackList       StackListing;
typedef struct _pageableStack   StackPage;

struct  _stackList
{
  int index;
  int total;
  const char*	owner;
  const char*	stack;
  double	pageSize;
  double	pageNumber;
  double	offset;

  HashMaps*	metadata;

  StackListing*	next;
  StackListing*	prev;
};

void		check_stack_type(json_t* element, int indent, StackListing **ls, const char *key);
StackListing*	StackInit(StackListing *init);
void		stack_json_null(json_t *element, int indent, StackListing **ls);
void		stack_json_object(json_t *element, int indent, StackListing **ls);
void		stack_json_array(json_t *element, int indent, StackListing **ls, const char *key);
void		AssignStackStringValue(json_t *element, const char *key, StackListing **ls);
void		AssignStackIntegerValue(json_t *element, const char *key, StackListing **ls);
void		stack_json_integer(json_t *element, int indent, StackListing **ls, const char *key);
void		stack_json_string(json_t *element, int indent, StackListing **ls, const char *key);
void		check_stack_type(json_t* element, int indent, StackListing **ls, const char *key);
void		printStack(StackListing **ls);
StackListing*	StackListParsingInfo(cometd_message *message);
