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
#include "ISgfcMessage.h"
#include "SgfcExitCode.h"

// Project includes (generated)
#include "SgfcPlusPlusExport.h"

// C++ Standard Library includes
#include <memory>
#include <vector>

namespace LibSgfcPlusPlus
{
  /// @brief The ISgfcDocumentWriteResult interface provides access to the
  /// result of a write operation performed by ISgfcDocumentWriter.
  ///
  /// @ingroup public-api
  /// @ingroup sgfc-frontend
  /// @ingroup document
  ///
  /// ISgfcDocumentWriteResult is immutable, i.e. once the
  /// ISgfcDocumentWriteResult object is constructed it cannot be changed.
  class SGFCPLUSPLUS_EXPORT ISgfcDocumentWriteResult
  {
  public:
    /// @brief Initializes a newly constructed ISgfcDocumentWriteResult object.
    ISgfcDocumentWriteResult();

    /// @brief Destroys and cleans up the ISgfcDocumentWriteResult object.
    virtual ~ISgfcDocumentWriteResult();

    /// @brief Returns an SgfcExitCode value that best fits the result of the
    /// write operation. The numeric value of the SgfcExitCode corresponds to
    /// one of the exit codes of SGFC.
    virtual SgfcExitCode GetExitCode() const = 0;

    /// @brief Returns a collection of ISgfcMessage objects which together form
    /// the parse result of the write operation. The messages appear in the
    /// order in which they were generated by SGFC. The collection is empty if
    /// write operation did not generate any messages.
    virtual std::vector<std::shared_ptr<ISgfcMessage>> GetParseResult() const = 0;

    /// @brief Prints the content of the ISgfcDocumentWriteResult to stdout for
    /// debugging purposes.
    virtual void DebugPrintToConsole() const = 0;
  };
}
