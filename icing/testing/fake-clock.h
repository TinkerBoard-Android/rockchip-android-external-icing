// Copyright (C) 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ICING_TESTING_FAKE_CLOCK_H_
#define ICING_TESTING_FAKE_CLOCK_H_

#include <ctime>

#include "icing/util/clock.h"

namespace icing {
namespace lib {

// Wrapper around real-time clock functions. This is separated primarily so
// tests can override this clock and inject it into the class under test.
class FakeClock : public Clock {
 public:
  std::time_t GetCurrentSeconds() const override { return seconds_; }

  void SetSeconds(std::time_t seconds) { seconds_ = seconds; }

 private:
  std::time_t seconds_ = 0;
};

}  // namespace lib
}  // namespace icing

#endif  // ICING_TESTING_FAKE_CLOCK_H_