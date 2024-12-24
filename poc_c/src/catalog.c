
#include "src/catalog.h"

#include "klib/kvec.h"
#include "klib/khash.h"

#include "src/common_types.h"

struct BookData__ {
  Isbn isbn;
  Name title;
  Year publication_year;
  kvec_t(Id) author_ids;
  kvec_t(struct BookItem__) book_items;
};

KHASH_MAP_INIT_STR(book, struct BookData__);

struct AuthorData__ {
  Id id;
  Name name;
  kvec_t(Isbn) book_isbns;
};

KHASH_MAP_INIT_STR(author, struct AuthorData__);

struct CatalogData__ {
  khash_t(book)* books_by_isbn;
  khash_t(author)* authors_by_id;
};

CatalogData CatalogDataInit(void) {
  struct CatalogData__* d = calloc(1, sizeof(*d));
  if (d == NULL) {
    return NULL;
  }

  d->books_by_isbn = kh_init(book);
  d->authors_by_id = kh_init(author);

  if (d->books_by_isbn == NULL || d->authors_by_id == NULL) {
    kh_destroy(book, d->books_by_isbn);
    kh_destroy(author, d->authors_by_id);
    free(d);
  }

  return d;
}

void CatalogDataDeinit(CatalogData catalog) {
  struct CatalogData__* d = catalog;
  if (d) {
    if (d->books_by_isbn) {
      khash_t(book)* h = d->books_by_isbn;
      for (khiter_t k = kh_begin(h); k != kh_end(h); ++k) {
        if (kh_exist(h, k)) {
          struct BookData__* n = &kh_value(h, k);
          kv_destroy(n->author_ids);
          kv_destroy(n->book_items);
        }
      }
      kh_destroy(book, d->books_by_isbn);
    }
    if (d->authors_by_id) {
      khash_t(author)* h = d->authors_by_id;
      for (khiter_t k = kh_begin(h); k != kh_end(h); ++k) {
        if (kh_exist(h, k)) {
          struct AuthorData__* n = &kh_value(h, k);
          kv_destroy(n->book_isbns);
        }
      }
      kh_destroy(author, d->authors_by_id);
    }
    free(d);
  }
}

Result CatalogSearchBooke(CatalogData catalog, const char *search_query) {
  return ResultOk;
}

Result CatalogAddBookItem(CatalogData catalog, const char *book_item_info) {
  return ResultOk;
}

Result CatalogCheckoutBook(CatalogData catalog, const char *book_item_id) {
  return ResultOk;
}

Result CatalogReturnBook(CatalogData catalog, const char *book_item_id) {
  return ResultOk;
}

Result CatalogGetBookLendings(CatalogData catalog, const char *member_id) {
  return ResultOk;
}
