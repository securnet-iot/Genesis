#ifndef TCHAIN_ATTRIBUTES_H_
#define TCHAIN_ATTRIBUTES_H_

/**
 * @brief Variable attribute for an unused variable.
 * 
 * e.g. void foo(var_t var) { TCHAIN_UNUSED_VAR(var); ... }
 */
#define TCHAIN_UNUSED_VAR(var) (void) var

/** @brief Linker section placement attribute. */
#define TCHAIN_VAR_PLACE( var, sec_name ) \
  var __attribute__ ( ( section ( sec_name ) ) )

#endif /* TCHAIN_ATTRIBUTES_H_ */
