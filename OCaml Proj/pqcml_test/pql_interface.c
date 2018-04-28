#include <stdio.h>
#include <stdlib.h>

#include </usr/include/postgresql/libpq-fe.h>
//#include "pql_interface.h"

void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

PGconn *connection(){
	PGconn *conn = PQconnectdb("user=burger dbname=burger");

	if (PQstatus(conn) == CONNECTION_BAD) {
		fprintf(stderr, "Connection to database failed: %s\n",
		PQerrorMessage(conn));
        	do_exit(conn);
    	}

	return conn;

}

long getVersion(PGconn *conn){
	long ver = PQserverVersion(conn);
	return ver;
}

void closeConnection(PGconn *conn){
 	PQfinish(conn);
}
