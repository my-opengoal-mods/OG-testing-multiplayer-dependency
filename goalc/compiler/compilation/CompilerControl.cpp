#include "goalc/compiler/Compiler.h"

Val * Compiler::compile_exit(const goos::Object& form, const goos::Object& rest, Env* env) {
  (void)env;
  auto args = get_va(form, rest);
  va_check(form, args, {}, {});
  if(m_listener.is_connected()) {
    m_listener.send_reset();
  }
  m_want_exit = true;
  return get_none();
}