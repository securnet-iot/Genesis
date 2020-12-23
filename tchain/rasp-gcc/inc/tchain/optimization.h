#ifndef TCHAIN_OPTIMIZATION_H_
#define TCHAIN_OPTIMIZATION_H_

/**
 * @brief Branch prediction macro hinting condition being true.
 * @param condition Expression for evaluation.
 */
#define TCHAIN_LIKELY(condition) __builtin_expect(!!(condition),1)

/**
 * @brief Branch prediction macro hinting condition being false.
 * @param condition Expression for evaluation.
 */
#define TCHAIN_UNLIKELY(condition) __builtin_expect(!!(condition),0)

#endif /* TCHAIN_OPTIMIZATION_H_ */
