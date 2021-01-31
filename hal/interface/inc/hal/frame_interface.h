#ifndef HAL_FRAME_INTERFACE_H
#define HAL_FRAME_INTERFACE_H

#include "etc/return_result.h"

namespace hal {

template <typename T>
class FrameInterface {
 public:
  using Frame = T;

  virtual ~FrameInterface();

  virtual ReturnResult<Frame> GetFrame() = 0;
  virtual ReturnResult<void> ShowFrame(Frame frame) = 0;
  virtual ReturnResult<bool> IsAvailable() = 0;
  virtual ReturnResult<void> SaveFrameAsJpg(::std::string file_path,
                                            ::std::string file_name,
                                            Frame frame) = 0;
};

template <typename T>
inline FrameInterface<T>::~FrameInterface() {}

}  // namespace hal

#endif /* HAL_FRAME_INTERFACE_H */