#ifndef COMMAND_PARSING_INFO
#define COMMAND_PARSING_INFO

#include "jansson.h"
#include "comet_message.h"






/*--------Only parsing functions---------*/

void    CommandStringValue(json_t *element, const char *key);
void    command_type(json_t* element, int indent, const char *key);
void	command_json_null(json_t *element, int indent);
void	command_json_object(json_t *element, int indent);
void	command_json_array(json_t *element, int indent, const char *key);
void	command_json_string(json_t *element, int indent, const char *key);
void    CommandStringValue(json_t *element, const char *key);
void	command_type(json_t* element, int indent, const char *key);
const char   *CommandParsinginfo(cometd_message *message);



/*---------------------------------------*/

#endif
