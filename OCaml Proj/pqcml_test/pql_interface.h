
#ifndef _MYLIB_H_
#define _MYLIB_H_
#include </usr/include/postgresql/libpq-fe.h>

void do_exit(PGconn *conn);

PGconn connect();

long getVersion(PGconn *conn);

void closeConnection(PGconn *conn);

#endif



