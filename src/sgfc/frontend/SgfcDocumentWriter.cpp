// Project includes
#include "../../document/SgfcDocument.h"
#include "../../parsing/SgfcDocumentEncoder.h"
#include "../argument/SgfcArguments.h"
#include "../backend/SgfcBackendController.h"
#include "SgfcDocumentWriter.h"
#include "SgfcDocumentWriteResult.h"

// C++ Standard Library includes
#include <iostream>

namespace LibSgfcPlusPlus
{
  SgfcDocumentWriter::SgfcDocumentWriter()
    : arguments(new SgfcArguments())
  {
  }

  SgfcDocumentWriter::~SgfcDocumentWriter()
  {
  }

  std::shared_ptr<ISgfcArguments> SgfcDocumentWriter::GetArguments() const
  {
    return this->arguments;
  }

  std::shared_ptr<ISgfcDocumentWriteResult> SgfcDocumentWriter::WriteSgfFile(
    std::shared_ptr<ISgfcDocument> document,
    const std::string& sgfFilePath)
  {
    std::string sgfContent;
    return WriteSgfContentToFilesystemOrInMemoryBuffer(document, sgfFilePath, sgfContent, SgfcDataLocation::Filesystem);
  }

  std::shared_ptr<ISgfcDocumentWriteResult> SgfcDocumentWriter::WriteSgfContent(
    std::shared_ptr<ISgfcDocument> document,
    std::string& sgfContent)
  {
    std::string sgfFilePath;
    return WriteSgfContentToFilesystemOrInMemoryBuffer(document, sgfFilePath, sgfContent, SgfcDataLocation::InMemoryBuffer);
  }

  void SgfcDocumentWriter::DebugPrintToConsole(
    std::shared_ptr<ISgfcDocument> document) const
  {
    SgfcDocumentEncoder encoder(document);
    std::string sgfContent = encoder.Encode();
    std::cout << sgfContent;
  }

  std::shared_ptr<ISgfcDocumentWriteResult> SgfcDocumentWriter::WriteSgfContentToFilesystemOrInMemoryBuffer(
    std::shared_ptr<ISgfcDocument> document,
    const std::string& sgfFilePath,
    std::string& sgfContent,
    SgfcDataLocation dataLocation)
  {
    SgfcBackendController backendController(this->arguments->GetArguments());
    if (backendController.IsCommandLineValid())
    {
      SgfcDocumentEncoder encoder(document);
      sgfContent = encoder.Encode();

      std::shared_ptr<SgfcBackendDataWrapper> sgfDataWrapper =
        std::shared_ptr<SgfcBackendDataWrapper>(new SgfcBackendDataWrapper(sgfContent));

      std::shared_ptr<SgfcBackendSaveResult> backendSaveResult;
      if (dataLocation == SgfcDataLocation::Filesystem)
        backendSaveResult = backendController.SaveSgfFile(sgfFilePath, sgfDataWrapper);
      else
        backendSaveResult = backendController.SaveSgfContent(sgfContent, sgfDataWrapper);

      std::shared_ptr<ISgfcDocumentWriteResult> result = std::shared_ptr<ISgfcDocumentWriteResult>(new SgfcDocumentWriteResult(
        backendSaveResult->GetSaveResult()));
      return result;
    }
    else
    {
      std::shared_ptr<ISgfcDocumentWriteResult> result = std::shared_ptr<ISgfcDocumentWriteResult>(new SgfcDocumentWriteResult(
        backendController.GetInvalidCommandLineReason()));
      return result;
    }
  }
}
