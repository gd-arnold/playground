#include <stdlib.h>
#include <stdio.h>

#include "dbg.h"
#include "sqlite3.h"

int main(int argc, char* argv[])
{
    int rc;
    sqlite3* db = NULL;
    sqlite3_stmt* statement = NULL;

    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK)
        sentinel("Cannot open database: %s", sqlite3_errmsg(db));

    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION();", -1, &statement, 0);
    if (rc != SQLITE_OK)
        sentinel("Failed to fetch data: %s", sqlite3_errmsg(db));
    
    rc = sqlite3_step(statement);
    if (rc == SQLITE_ROW)
        log_info("sqlite version: %s", sqlite3_column_text(statement, 0));

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return EXIT_SUCCESS;

error:
    sqlite3_close(db);
    return EXIT_FAILURE;
}
