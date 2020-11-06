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
#include "ISgfcSinglePropertyValue.h"

// Project includes (generated)
#include "SgfcPlusPlusExport.h"

namespace LibSgfcPlusPlus
{
  // Forward declarations
  class ISgfcGoPointPropertyValue;

  /// @brief The ISgfcPointPropertyValue interface provides access to one of
  /// the values of a property of an SGF node. The value type is
  /// SgfcPropertyValueType::Point.
  ///
  /// @ingroup public-api
  /// @ingroup property-value
  ///
  /// ISgfcPointPropertyValue is immutable, i.e. once the
  /// ISgfcPointPropertyValue object is constructed it cannot be changed.
  class SGFCPLUSPLUS_EXPORT ISgfcPointPropertyValue : virtual public ISgfcSinglePropertyValue
  {
  public:
    /// @brief Initializes a newly constructed ISgfcPointPropertyValue object.
    ISgfcPointPropertyValue();

    /// @brief Destroys and cleans up the ISgfcPointPropertyValue object.
    virtual ~ISgfcPointPropertyValue();

    /// @brief Returns the uninterpreted Point value. This is the same value
    /// that GetRawValue() returns.
    ///
    /// The SGF standard does not provide a universal definition of how a Point
    /// value should look like. Instead it says that the interpretation of
    /// Point values is game specific.
    virtual std::string GetRawPointValue() const = 0;

    /// @brief Returns an ISgfcGoPointPropertyValue object if the game tree that
    /// this property value is associated with has SgfcGameType::Go. Returns
    /// @e nullptr otherwise. The caller is not the owner of the returned
    /// object.
    virtual const ISgfcGoPointPropertyValue* ToGoPointValue() const = 0;
  };
}
