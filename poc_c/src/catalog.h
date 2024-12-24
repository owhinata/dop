
#ifndef POC_C_SRC_CATALOG_H_
#define POC_C_SRC_CATALOG_H_

#include "src/result.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CatalogData__;
typedef struct CatalogData__ *CatalogData;

CatalogData CatalogDataInit(void);
void CatalogDataDeinit(CatalogData catalog);

/**
 *
 */
Result CatalogSearchBooke(CatalogData catalog, const char *search_query);

/**
 *
 */
Result CatalogAddBookItem(CatalogData catalog, const char *book_item_info);

/**
 *
 */
Result CatalogCheckoutBook(CatalogData catalog, const char *book_item_id);

/**
 *
 */
Result CatalogReturnBook(CatalogData catalog, const char *book_item_id);

/**
 *
 */
Result CatalogGetBookLendings(CatalogData catalog, const char *member_id);

#ifdef __cplusplus
}
#endif

#endif  // POC_C_SRC_CATALOG_H_
