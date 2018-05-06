main:
	ocamlopt main.ml -cc "gcc -Wall sql_conn.c -lmysqlclient"
