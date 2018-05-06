
type dbconn

type query_out

external print_query: dbconn -> string -> string -> string -> unit = "print_query"

external sql_connect: string -> string -> string -> dbconn = "sql_connect"

external printlist: int list -> unit = "printlist"

external query_step_pair: dbconn -> string -> string -> string -> query_out = "query_step_pair"

(*external print_f: unit -> unit = "print_f"
print_f();;
*)

let database = "dogs";;
let user = "root";;
let pwd = "kafka";;

let tbl = "dogs";;
let field = "Name";;
let arg = "reximus";;

let db = sql_connect database user pwd;;
print_query db tbl field arg;;
let output = query_step_pair db tbl field arg;;
(*printlist [1;2;3;4;5;6];;
*)

