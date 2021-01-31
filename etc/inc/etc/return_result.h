#ifndef ETC_RETURN_RESULT_H
#define ETC_RETURN_RESULT_H

#include "tchain/types.h"

template <typename T>
class ReturnResult {
  T value_;
  int32_t error_;

 public:
  using ValueType = T;

  constexpr ReturnResult(const T& value) : value_{value}, error_{} {}

  constexpr ReturnResult(const int32_t error) : value_{}, error_{error} {}

  int32_t Error(void) const { return error_; }

  bool IsValid(void) const { return (error_ == 0); }

  T Value(void) const { return value_; }

  ReturnResult<T>& operator=(const ReturnResult<T>& other) {
    value_ = other.value_;
    error_ = other.error_;
    return *this;
  }
};

template <>
class ReturnResult<void> {
  int32_t error_;

 public:
  using ValueType = void;

  constexpr ReturnResult(int32_t error = 0) : error_{error} {}

  int32_t Error(void) const { return error_; }

  bool IsValid(void) const { return (error_ == int32_t{}); }

  ReturnResult<void>& operator=(const ReturnResult<void>& other) {
    error_ = other.error_;
    return *this;
  }
};

#endif /* ETC_RETURN_RESULT_H */
