#ifndef _PUT_GDA_INFO
#define _PUT_GDA_INFO

#include <stdbool.h>
#include "comet_message.h"
#include "HashMaps.h"
#include "listingEntryInfo.h"

struct _GDAPut {
  int        index;
  const char *column;
  const char *key;
  const char *key2;
/* 
The HasMaps Object is meant to take anything so it accepts a sting as a key and a void * as a value.
But remember what you put in it, as i can't cast for every situation known on earth and predict what casted type you wish to come from the Json file.
*/
/*
To ease up the use of the map each Object contains the info of each "data" Json_Object. So concretly, you can iterate on Object with the ->next and ->prev pointers.
For example you have 4 JSon "data" Objects. You will get 4 GDAPut structures, but the HashMaps Object field hides multiple variables within its stucture with key, value,index and type. So you only have to iterate over the *object pointer to get all your info from one Json Object. Be warned ! The value field will allways return a void *, so check the Type field before and cast it to the good type.  
*/
  HashMaps *object;
  GdaPut   *next;
  GdaPut   *prev;
  
};


/*------------------GDA Methods and Parse Methods----------------*/

GdaPut		*AddGdaPut(GdaPut *head);
GdaPut		*InitPutGda(GdaPut *init);
void		put_json_null(json_t *elemenat, int indent, GdaPut **gda);
void		put_json_object(json_t *element, int indent, GdaPut **gda);
void		put_json_array(json_t *element, int indent, GdaPut **gda, const char *key);
void		AssignPutStringValue(json_t *element, const char *key, GdaPut **gda);
void		AssignPutIntegerValue(json_t *element, const char *key, GdaPut **gda);
void		put_json_integer(json_t *element, int indent, GdaPut **gda, const char *key);
void		put_json_string(json_t *element, int indent, GdaPut **gda, const char *key);
void		put_json_real(json_t *element, int indent, GdaPut **gda, const char *key);
void		put_json_true(json_t *element, int indent, GdaPut **gda, const char *key);
void		put_json_false(json_t *element, int indent, GdaPut **gda, const char *key);
void		check_put_type(json_t* element, int indent, GdaPut **gda, const char *key);
void		printPutGda(GdaPut **gda);
void		testGVFK(GdaPut **gda);
void		testIKE(GdaPut **gda);
void		testGTE(GdaPut **gda);
GdaPut		*GdaPutParsingInfo(cometd_message *message);


/*---------------------------------------------------------------*/
#endif
