
#ifndef LISTING_ENTRY_INFO__
#define LISTING_ENTRY_INFO__

#include <stdbool.h>
#include "comet_message.h"
#include "hashMaps.h"

typedef struct  _FolderListing    FolderListing;

struct _FolderListing{

  int			index;
  const char*		name;
  const char*		fileType;
  const char*		url;

  HashMaps*		metadata;
  const char*		tag;
  bool			exists;

  FolderListing*	next;
  FolderListing*	prev;

};
/*--------------- Entry Info -------------*/

FolderListing   *FolderInit(FolderListing *init);
FolderListing   *FolderListingAdd(FolderListing *head);
FolderListing   *FolderParsingInfo(cometd_message *message);
void		print_json_indent(int indent);
void		list_json_real(json_t *element, int indent);
void		list_json_true(json_t *element, int indent);
void		list_json_false(json_t *element, int indent);

/*--------------- Json Print ------------*/

#endif
