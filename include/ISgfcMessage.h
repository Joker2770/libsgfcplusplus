#pragma once

// Project includes
#include "SgfcMessageType.h"

// C++ Standard Library includes
#include <string>

namespace LibSgfcPlusPlus
{
  /// @brief The ISgfcMessage interface represents a message that is generated
  /// when SGF data is loaded and parsed, or when SGF data is saved. Most
  /// messages are generated by SGFC, but there are a few error cases where
  /// libsgfc++ also generates messages. ISgfcMessage objects are immutable.
  ///
  /// When a message is generated by SGFC, the raw message text follows
  /// formatting guidelines that are published in the SGFC documentation.
  /// libsgfc++ makes an effort to parse the raw message text so that it can
  /// make the message content available to clients in a structured manner via
  /// ISgfcMessage.
  class ISgfcMessage
  {
  public:
    /// @brief Initializes a newly constructed ISgfcMessage object.
    ISgfcMessage();

    /// @brief Destroys and cleans up the ISgfcMessage object.
    virtual ~ISgfcMessage();

    /// @brief Returns the message's identification number. Returns zero or a
    /// positive number if the message was generated by SGFC. Returns a negative
    /// number if the message was generated by libsgfc++.
    ///
    /// Every message generated by SGFC has its own unique message ID. Consult
    /// the SGFC documentation for a list of message IDs. SGFC calls them
    /// "error codes". The exception is when libsgfc++ is unable to determine
    /// the message ID when it parses the raw message text - if that happens
    /// libsgfc++ sets the message ID to SgfcConstants::UnknownSgfcMessageID.
    ///
    /// Every message generated by libsgfc++ also has its own unique message
    /// ID. Documented constants for these are available in SgfcConstants.
    /// Messages generated by libsgfc++ are always fatal errors.
    virtual int GetMessageID() const = 0;

    /// @brief Returns the type of message.
    virtual SgfcMessageType GetMessageType() const = 0;

    /// @brief Returns the number of the line (1-based) in the parsed SGF data
    /// that caused the message. Returns SgfcConstants::InvalidLineNumber for
    /// fatal errors.
    virtual int GetLineNumber() const = 0;

    /// @brief Returns the number of the column (1-based) in the parsed SGF data
    /// that caused the message. Returns SgfcConstants::InvalidColumnNumber for
    /// fatal errors.
    virtual int GetColumnNumber() const = 0;

    /// @brief Returns true if the message describes a critical problem. Only
    /// warning and error messages can be critical. Always returns false for
    /// fatal errors.
    ///
    /// A critical problem indicates that the SGF content parsed by SGFC may be
    /// severly damaged and that information may be lost if the parsed SGF data
    /// is written.
    virtual bool IsCriticalMessage() const = 0;

    /// @brief Returns the message text.
    ///
    /// For messages generated by SGFC this is the raw message text minus
    /// the content that was parsed.
    ///
    /// When the raw message text is parsed, consecutive whitespace characters
    /// are condensed into a single space character. For messages generated by
    /// SGFC this message text can therefore differ from the original raw
    /// message text in the amount or kind of whitespace used.
    virtual std::string GetMessageText() const = 0;

    /// @brief Returns the raw message text exactly as it was generated by
    /// SGFC. If the message was generated by libsgfc++ this returns the same
    /// value as GetMessageText().
    virtual std::string GetRawMessageText() const = 0;
  };
}
