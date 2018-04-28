#include <stdio.h>
#include <caml/mlvalues.h>

CAMLprim value caml_print_hello(value unit)
{
    printf("Hello\n");
    return Val_unit;
}

value getVal(value x){
	if(Is_long(x)){
		switch(Int_val(x)){
			case 0: printf("X\n"); break;
			case 1: printf("Z\n"); break;
		}
	}
	else {
		switch(Tag_val(x)){
			case 0:
				printf("W: %ld\n", (long) Field(x,0)); 
				fflush(stdout);
			break;
			case 1: printf("Y\n"); break;
			case 2: printf("S: %s",String_val(Field(x,0)));
		}
	}
	return Val_unit;
}

CAMLprim value field(value type){
}
