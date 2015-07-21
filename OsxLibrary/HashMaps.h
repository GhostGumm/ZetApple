#ifndef HASH_MAPS
#define HASH_MAPS

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _GDAPut GdaPut;
typedef struct _Object Object;
typedef struct _HashMaps HashMaps;


struct _HashMaps{
  /*bool      (*AddKeyValue)(char *, void *, HashMaps **);
  void     *(*GetValueFromKey)(char *, HashMaps **);
  bool      (*IfKeyExist)(char *, HashMaps **);
  int       (*GetTotalOfElements)(HashMaps **); Needs to get fixed*/

  char *type;
  int index;
  const  char *key;
  void *value;

  HashMaps *next;
  HashMaps *prev;
  
};

/*------------- control functions ------------*/

void		GoBack(HashMaps **head);
void		GoFront(HashMaps **head);
int		GetTotalElements(HashMaps *head);
HashMaps	*AddKeyValue(HashMaps *head);
HashMaps	*GetValueFromKey(char *key, HashMaps *head);
bool		IfKeyExist(char *key, HashMaps *head);
HashMaps	*HashMapInit();
void		testM(HashMaps **head);


/*------------- control functions ------------*/

#endif
