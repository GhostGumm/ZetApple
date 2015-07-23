#ifndef _GDA_GET_
#define _GDA_GET_

#include "HashMaps.h"
#include "putGdaInfo.h"
#include "listingGdaInfo.h"

typedef struct _GdaGet{
  int index;
  HashMaps *data;  /* Little HashMap actually a linked list with two fields and few methods to extract push and manage the data the way you want it to behave. */
  GdaPut   *Row; /* Point to a GDAPut structure implementing a HashMaps too */

  struct _GdaGet   *next;
  struct _GdaGet   *prev;
}GdaGet;

/*--------------- GdaGet Methods----------------*/

GdaGet	       *AddGdaGet(GdaGet *head);
GdaGet	       *InitGetGda(GdaGet *init);
void		get_json_null(json_t *element, int indent, GdaGet **gda);
void		get_json_object(json_t *element, int indent, GdaGet **gda);
void		get_json_array(json_t *element, int indent, GdaGet **gda, const char *key);
void		AssignGetStringValue(json_t *element, const char *key, GdaGet **gda);
void		AssignGetIntegerValue(json_t *element, const char *key, GdaGet **gda);
void		get_json_integer(json_t *element, int indent, GdaGet **gda, const char *key);
void		get_json_string(json_t *element, int indent, GdaGet **gda, const char *key);
void		get_json_real(json_t *element, int indent, GdaGet **gda, const char *key);
void		get_json_true(json_t *element, int indent, GdaGet **gda, const char *key);
void		get_json_false(json_t *element, int indent, GdaGet **gda, const char *key);
void		check_get_type(json_t* element, int indent, GdaGet **gda, const char *key);
GdaGet	        *GdaGetParsingInfo(cometd_message *message);

/*----------------------------------------------*/
#endif
