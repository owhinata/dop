
#ifndef POC_C_SRC_USER_MANAGEMENT_H_
#define POC_C_SRC_USER_MANAGEMENT_H_

#include "src/result.h"

#ifdef __cplusplus
extern "C" {
#endif

struct UserManagementData__;
typedef struct UserManagementData__ *UserManagementData;

UserManagementData UserManagementDataInit(void);
void UserManagementDataDeinit(UserManagementData user_management);

/**
 *
 */
Result UserManagementBlockMember(UserManagementData user_management,
                                 const char *member_id);

/**
 *
 */
Result UserManagementUnblockMember(UserManagementData user_management,
                                   const char *member_id);

/**
 *
 */
Result UserManagementLogin(UserManagementData user_management,
                           const char *login_info);

/**
 *
 */
Result UserManagementIsLibrarian(UserManagementData user_management,
                                 const char *user_id);

#ifdef __cplusplus
}
#endif

#endif  // POC_C_SRC_USERMANAGEMENT_H_
