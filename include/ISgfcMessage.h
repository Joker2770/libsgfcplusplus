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
#include "SgfcMessageID.h"
#include "SgfcMessageType.h"

// Project includes (generated)
#include "SgfcPlusPlusExport.h"

// C++ Standard Library includes
#include <string>

namespace LibSgfcPlusPlus
{
  /// @brief The ISgfcMessage interface represents a message that is generated
  /// when SGF data is loaded and parsed, or when SGF data is saved. Most
  /// messages are generated by SGFC, but there are a few error cases where
  /// libsgfc++ also generates messages. ISgfcMessage objects are immutable.
  ///
  /// @ingroup public-api
  /// @ingroup sgfc-message
  class SGFCPLUSPLUS_EXPORT ISgfcMessage
  {
  public:
    /// @brief Initializes a newly constructed ISgfcMessage object.
    ISgfcMessage();

    /// @brief Destroys and cleans up the ISgfcMessage object.
    virtual ~ISgfcMessage();

    /// @brief Returns the message's unique identification number.
    ///
    /// Every message generated by SGFC has its own unique message ID. Consult
    /// the SGFC documentation for a list of message IDs. SGFC calls them
    /// "error codes". The exception is when libsgfc++ is unable to determine
    /// the message ID when it receives the message data from SGFC - in the
    /// very unlikely case that this happens libsgfc++ sets the message ID to
    /// SgfcConstants::UnknownSgfcMessageID.
    ///
    /// Every message generated by libsgfc++ also has its own unique message
    /// ID that is distinct from all SGFC-generated message IDs. Messages
    /// generated by libsgfc++ are always fatal errors.
    ///
    /// @see SgfcMessageID
    virtual SgfcMessageID GetMessageID() const = 0;

    /// @brief Returns the type of message.
    virtual SgfcMessageType GetMessageType() const = 0;

    /// @brief Returns the number of the line (1-based) in the parsed SGF data
    /// that caused the message. Returns SgfcConstants::InvalidLineNumber if
    /// the message does not refer to a specific line in the SGF data (most
    /// fatal errors, but also some errors and warnings).
    virtual int GetLineNumber() const = 0;

    /// @brief Returns the number of the column (1-based) in the parsed SGF data
    /// that caused the message. Returns SgfcConstants::InvalidColumnNumber if
    /// the message does not refer to a specific column in the SGF data (most
    /// fatal errors, but also some errors and warnings).
    virtual int GetColumnNumber() const = 0;

    /// @brief Returns true if the message describes a critical problem. Only
    /// warning and error messages can be critical. Always returns false for
    /// fatal errors.
    ///
    /// A critical problem indicates that the SGF content parsed by SGFC may be
    /// severely damaged and that information may be lost if the parsed SGF data
    /// is written.
    virtual bool IsCriticalMessage() const = 0;

    /// @brief Returns an error number that indicates what went wrong when a
    /// standard C library function was invoked by SGFC. The value 0 (zero)
    /// indicates "no error", a non-zero value indicates an error.
    ///
    /// As a convenience the library provides the constant
    /// SgfcConstants::LibraryErrorNumberNoError in case you prefer to use
    /// a constant to implement your program logic.
    ///
    /// A non-zero value is a copy of the global @e errno value, made shortly
    /// after the failing function call. In the unlikely case that you need
    /// to evaluate this, consult the standard C library documentation of
    /// @e errno.
    ///
    /// In case this method returns a non-zero error number, the text returned
    /// by GetFormattedMessageText() already includes an error message that
    /// results from invoking @e strerror() with the error number.
    ///
    /// @note Messages for which this method returns a non-zero value are
    /// usually fatal error messages related to file I/O. There is no guarantee
    /// that this will always be the case, though.
    ///
    /// @note This method always returns 0 (zero) for messages generated by
    /// libsgfc++.
    virtual int GetLibraryErrorNumber() const = 0;

    /// @brief Returns the message text.
    virtual std::string GetMessageText() const = 0;

    /// @brief Returns the formatted message text as if it had been printed by
    /// SGFC on the command-line. If the message was generated by libsgfc++ this
    /// returns the same value as GetMessageText().
    ///
    /// When the command-line version of SGFC prints messages it assembles the
    /// individual message parts into a formatted text. libsgfc++ emulates
    /// this formatting as closely as possible to generate the value returned
    /// by this method. There is no guarantee for an exact match, though.
    virtual std::string GetFormattedMessageText() const = 0;
  };
}
