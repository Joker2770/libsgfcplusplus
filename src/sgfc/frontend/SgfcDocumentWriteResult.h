#pragma once

// Project includes
#include "../../../include/ISgfcDocumentWriteResult.h"

namespace LibSgfcPlusPlus
{
  /// @brief The SgfcDocumentWriteResult class provides an implementation of the
  /// ISgfcDocumentWriteResult interface. See the interface header file for
  /// documentation.
  class SgfcDocumentWriteResult : public ISgfcDocumentWriteResult
  {
  public:
    SgfcDocumentWriteResult();
    SgfcDocumentWriteResult(
      std::shared_ptr<ISgfcMessage> invalidCommandLineReason);
    SgfcDocumentWriteResult(
      std::vector<std::shared_ptr<ISgfcMessage>> parseResult);
    virtual ~SgfcDocumentWriteResult();

    virtual SgfcExitCode GetExitCode() const;
    virtual std::vector<std::shared_ptr<ISgfcMessage>> GetParseResult() const;
    virtual void DebugPrintToConsole() const;

  private:
    SgfcExitCode exitCode;
    std::vector<std::shared_ptr<ISgfcMessage>> parseResult;
  };
}
