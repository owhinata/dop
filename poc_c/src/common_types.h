
#ifndef POC_C_SRC_COMMON_TYPES_H_
#define POC_C_SRC_COMMON_TYPES_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef char Id[32];
typedef char Date[32];
typedef char Email[64];
typedef char Password[64];
typedef char Isbn[13];
typedef char Name[64];
typedef char Year[4];

struct BookItem__ {
  Id id;
  Id lib_id;
  Date purchase_date;
  bool is_lent;
};

#ifdef __cplusplus
}
#endif

#endif  // POC_C_SRC_COMMON_TYPES_H_
