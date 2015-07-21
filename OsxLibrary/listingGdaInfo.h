#ifndef LISTING_GDA_INFO_H__
#define LISTING_GDA_INFO_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "jansson.h"
#include <stdbool.h>
#include "comet_message.h"

typedef struct _GdaColumns GdaColumns;
typedef struct _GdaList GdaList;
typedef struct _Pageable Pageable;

struct _Pageable{
  int size;
  int totalElements;
};

struct _GdaColumns {
  int		index;
  const char	*key;
  const char	*firstName;
  const char	*lastName;
  
  GdaColumns    *next;
  GdaColumns    *prev;
};

struct _GdaList {
  const char    *owner;
  const char    *table;

  Pageable      *page;
  GdaColumns    *columns;
};

/*----------------------GdaList init and Parse Methods-----------------------*/

GdaList*	InitGda(GdaList *init);
void		printAllGda(GdaList **gda);
void		handle_json_null(json_t *element, int indent, GdaList **gda);
void		handle_json_object(json_t *element, int indent, GdaList **gda);
void		handle_json_array(json_t *element, int indent, GdaList **gda, const char *key);
void		handle_json_string(json_t *element, int indent, GdaList **gda, const char *key);
void		check_light_type(json_t* element, int indent, GdaList **gda, const char *key);
GdaList		*GdaParsingInfo(cometd_message *message);

/*--------------------------------------------------------------------------*/

#endif
