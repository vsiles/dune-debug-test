#define CAML_NAME_SPACE
#include <caml/memory.h>
#include <caml/alloc.h>

#include <stdlib.h>
#include <string.h>

const char* const rev="abcdef+";

value get_build_revision(void) {
  CAMLparam0();
  CAMLlocal1(result);

  const char* const buf = rev;
  const size_t len = strlen(buf);
  result = caml_alloc_string(len);

  memcpy(String_val(result), buf, len);

  CAMLreturn(result);
}
