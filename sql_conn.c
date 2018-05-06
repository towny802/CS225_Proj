// https://dev.mysql.com/doc/refman/8.0/en/mysql-real-connect.html
// http://zetcode.com/db/mysqlc/
// https://caml.inria.fr/pub/docs/manual-ocaml/intfc.html
// https://www.linux-nantes.org/~fmonnier/OCaml/ocaml-wrapping-c.html#ref_create_tuple
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <caml/mlvalues.h>
#include <caml/custom.h>
#include <caml/alloc.h>
#include <caml/memory.h>

#include <mysql/mysql.h>

CAMLprim value query_step_pair(value con, value tbl, value field, value constraint){
	char query[100];
	sprintf(query,"select * from %s where %s='%s';",(char *) tbl,(char *) field,(char *) constraint);
	mysql_query((MYSQL*) con, query);
	MYSQL_RES *result = mysql_store_result((MYSQL*) con);
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;

//	E from the presentation, tuple, our string * int dog product
	//value e;
	//value tuple;
	CAMLlocal4( e, tuple,  key_data, val_data);
	e = caml_alloc(num_fields*200, 0);
	int x = 0;
	while ((row = mysql_fetch_row(result))) 
	{
		//for(int i = 0; i < num_fields; i++) 
		//{
			int key_len = strlen(row[0]);
			int val_len = strlen(row[1]);
			
			key_data = caml_alloc_string(key_len);
			val_data = caml_alloc_string(val_len);
			
			memcpy(String_val(key_data), row[x], key_len);
			memcpy(String_val(val_data), row[x+1], val_len);
			
			Store_field(tuple, 0, key_data );
			Store_field(tuple, 1, val_data );
			Store_field( e, x, tuple );
			x++;
			//printf("%s ", row[i] ? row[i] : "NULL");
		//}
			//printf("\n"); 
	}
	mysql_free_result(result);
	//mysql_close((MYSQL *) con);
	return e;
}

CAMLprim value sql_connect(value dbname, value dbuser, value dbpassword){

	MYSQL *con = mysql_init(NULL);
	mysql_real_connect(con,"localhost",String_val(dbuser), String_val(dbpassword),String_val(dbname),0,NULL,0);

	return (value) con;
}

CAMLprim value print_query(value con, value tbl, value field, value constraint){
	char query[100];
	sprintf(query,"select * from %s where %s='%s';",(char *) tbl,(char *) field,(char *) constraint);
	mysql_query((MYSQL*) con, query);

	MYSQL_RES *result = mysql_store_result((MYSQL*) con);
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) 
	{ 
		for(int i = 0; i < num_fields; i++) 
		{ 
			printf("%s ", row[i] ? row[i] : "NULL");
		} 
			printf("\n"); 
	}
	mysql_free_result(result);
	//mysql_close((MYSQL *) con);
	return Val_unit;
}

CAMLprim value print_f(){
	printf("no");
	return Val_unit;
}


CAMLprim value printlist(value ml_list){
	CAMLparam1( ml_list );
    CAMLlocal1( head );
    while ( ml_list != Val_emptylist )
    {
        head = Field(ml_list, 0);
        printf("%d\n", Int_val(head));
        ml_list = Field(ml_list, 1);
	}
    CAMLreturn( Val_unit );
}
