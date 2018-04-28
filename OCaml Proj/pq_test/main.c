#include <stdio.h>
#include <stdlib.h>
#include </usr/include/postgresql/libpq-fe.h>
#include <caml/mlvalues.h>

#include "mylib.h"

void do_exit(PGconn *conn) {

    PQfinish(conn);
    exit(1);
}

int main() {

    PGconn *conn = PQconnectdb("user=burger dbname=burger");

    if (PQstatus(conn) == CONNECTION_BAD) {

        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    }

    int ver = PQserverVersion(conn);

    printf("Server version: %d\n", ver);

    PQfinish(conn);

    return 0;
}
