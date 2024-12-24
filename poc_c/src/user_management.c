
#include "src/user_management.h"

#include <stdbool.h>
#include <stdlib.h>

#include "klib/khash.h"
#include "klib/kvec.h"

#include "src/common_types.h"

struct LibrarianData__ {
  Email email;
  Password encrypted_password;
};

KHASH_MAP_INIT_STR(librarian, struct LibrarianData__);

struct MemberData__ {
  Email email;
  Password encrypted_password;
  bool is_blocked;
  kvec_t(struct BookLendingData__) book_lendings;
};

KHASH_MAP_INIT_STR(member, struct MemberData__);

struct BookLendingData__ {
  Date lending_date;
  Id book_item_id;
  Isbn book_isbn;
};

struct UserManagementData__ {
  khash_t(librarian)* librarians_by_email;
  khash_t(member)* members_by_email;
};

UserManagementData UserManagementDataInit(void) {
  struct UserManagementData__* d = calloc(1, sizeof(*d));
  if (d == NULL) {
    return NULL;
  }

  d->librarians_by_email = kh_init(librarian);
  d->members_by_email = kh_init(member);

  if (d->librarians_by_email == NULL || d->members_by_email == NULL) {
    kh_destroy(librarian, d->librarians_by_email);
    kh_destroy(member, d->members_by_email);
    free(d);
    return NULL;
  }

  return d;
}

void UserManagementDataDeinit(UserManagementData user_management) {
  struct UserManagementData__* d = user_management;
  if (d) {
    kh_destroy(librarian, d->librarians_by_email);
    if (d->members_by_email) {
      khash_t(member)* h = d->members_by_email;
      for (khiter_t k = kh_begin(h); k != kh_end(h); ++k) {
        if (kh_exist(h, k)) {
          struct MemberData__* n = &kh_value(h, k);
          kv_destroy(n->book_lendings);
        }
      }
      kh_destroy(member, d->members_by_email);
    }
    free(d);
  }
}

Result UserManagementBlockMember(UserManagementData user_management,
                                 const char *member_id) {
  return ResultOk;
}

Result UserManagementUnblockMember(UserManagementData user_management,
                                   const char *member_id) {
  return ResultOk;
}

Result UserManagementLogin(UserManagementData user_management,
                           const char *login_info) {
  return ResultOk;
}

Result UserManagementIsLibrarian(UserManagementData user_management,
                                 const char *user_id) {
  return ResultOk;
}
