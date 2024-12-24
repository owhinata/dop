
#ifndef POC_C_SRC_LIBRARY_H_
#define POC_C_SRC_LIBRARY_H_

#include "src/result.h"

#ifdef __cplusplus
extern "C" {
#endif

struct LibraryData__;
typedef struct LibraryData__ *LibraryData;

LibraryData LibraryDataInit(void);
void LibraryDataDeinit(LibraryData library);

/**
 *
 */
Result LibrarySearchBooke(LibraryData library, const char *search_query);

/**
 *
 */
Result LibraryAddBookItem(LibraryData library, const char *user_id,
                          const char *book_item_info);

/**
 *
 */
Result LibraryBlockMember(LibraryData library, const char *member_id);

/**
 *
 */
Result LibraryUnblockMemory(LibraryData library, const char *member_id);

/**
 *
 */
Result LibraryLogin(LibraryData library, const char *login_info);

/**
 *
 */
Result LibraryGetBookLendings(LibraryData library, const char *user_id,
                              const char *member_id);

/**
 *
 */
Result LibraryCheckoutBook(LibraryData library, const char *user_id,
                           const char *book_item_id);

/**
 *
 */
Result LibraryReturnBook(LibraryData library, const char *user_id,
                         const char *book_item_id);

#ifdef __cplusplus
}
#endif

#endif  // POC_C_SRC_LIBRARY_H_
