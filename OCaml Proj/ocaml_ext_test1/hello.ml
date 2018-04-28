
external print_hello: unit -> unit = "caml_print_hello"


type t = W of int | X | Y of int * int | Z | S of string
external getVal: t -> unit = "getVal"


let x = S("Zach");;
getVal(x);;
