#include <stdio.h>
#include <stdlib.h>
#include <caml/mlvalues.h>

#include "pql_interface.c"

int main() {

        PGconn *conn = connection();

//	printf("%ld\n",getVersion(conn));


	PGresult *result = PQexec( conn, "select * from dogs" );
	//printf("%d\n",PQnfields(result));
	printf("%s\n",PQgetvalue(result, 0, 0));
	PQclear(result);

	closeConnection(conn);

	return 0;
}
