// -----------------------------------------------------------------------------
// Copyright 2020 Patrick Näf (herzbube@herzbube.ch)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// -----------------------------------------------------------------------------

#pragma once

// Project includes
#include "../../../include/ISgfcRealPropertyValue.h"
#include "../SgfcSinglePropertyValue.h"

namespace LibSgfcPlusPlus
{
  /// @brief The SgfcRealPropertyValue class provides an implementation of
  /// the ISgfcRealPropertyValue interface. See the interface header file
  /// for documentation.
  ///
  /// @ingroup internals
  /// @ingroup property-value
  class SgfcRealPropertyValue : public SgfcSinglePropertyValue, public ISgfcRealPropertyValue
  {
  public:
    /// @brief Initializes a newly constructed SgfcRealPropertyValue object.
    /// The object holds the Real value @a realValue and
    /// the corresponding raw string value @a rawValue.
    SgfcRealPropertyValue(const std::string& rawValue, SgfcReal realValue);

    /// @brief Destroys and cleans up the SgfcRealPropertyValue object.
    virtual ~SgfcRealPropertyValue();

    virtual SgfcReal GetRealValue() const override;
    virtual const ISgfcRealPropertyValue* ToRealValue() const override;

  private:
    SgfcReal realValue;
  };
}
