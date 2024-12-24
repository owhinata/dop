
#include "src/library.h"

#include <stdlib.h>

#include "src/catalog.h"
#include "src/user_management.h"

struct LibraryData__ {
  char name[64];
  char address[128];
  CatalogData catalog;
  UserManagementData user_management;
};

LibraryData LibraryDataInit(void) {
  struct LibraryData__* d = calloc(1, sizeof(*d));
  if (d == NULL) {
    return NULL;
  }

  d->catalog = CatalogDataInit();
  d->user_management = UserManagementDataInit();

  if (d->catalog == NULL || d->user_management == NULL) {
    CatalogDataDeinit(d->catalog);
    UserManagementDataDeinit(d->user_management);
    return NULL;
  }

  return d;
}

void LibraryDataDeinit(LibraryData library) {
  struct LibraryData__* d = library;
  if (d) {
    CatalogDataDeinit(d->catalog);
    UserManagementDataDeinit(d->user_management);
    free(d);
  }
}

Result LibrarySearchBooke(LibraryData library, const char *search_query) {
  return ResultOk;
}

Result LibraryAddBookItem(LibraryData library, const char *user_id,
                          const char *book_item_info) {
  return ResultOk;
}

Result LibraryBlockMember(LibraryData library, const char *member_id) {
  return ResultOk;
}

Result LibraryUnblockMemory(LibraryData library, const char *member_id) {
  return ResultOk;
}

Result LibraryLogin(LibraryData library, const char *login_info) {
  return ResultOk;
}

Result LibraryGetBookLendings(LibraryData library, const char *user_id,
                              const char *member_id) {
  return ResultOk;
}

Result LibraryCheckoutBook(LibraryData library, const char *user_id,
                           const char *book_item_id) {
  return ResultOk;
}

Result LibraryReturnBook(LibraryData library, const char *user_id,
                         const char *book_item_id) {
  return ResultOk;
}
