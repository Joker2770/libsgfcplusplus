#pragma once

// Project includes
#include "ISgfcMessage.h"
#include "SgfcExitCode.h"

// C++ Standard Library includes
#include <memory>
#include <string>
#include <vector>

namespace LibSgfcPlusPlus
{
  /// @brief The ISgfcCommandLine interface is used to operate the SGFC backend
  /// in command line mode. Use SgfcPlusPlusFactory to construct new
  /// ISgfcCommandLine objects.
  class ISgfcCommandLine
  {
  public:
    /// @brief Initializes a newly constructed ISgfcCommandLine object.
    ISgfcCommandLine();

    /// @brief Destroys and cleans up the ISgfcCommandLine object.
    virtual ~ISgfcCommandLine();

    /// @brief Loads a single .sgf file from the specified path and puts it
    /// through the SGFC parser.
    ///
    /// @return An SgfcExitCode value whose numeric value matches one of the
    /// exit codes of SGFC.
    virtual SgfcExitCode LoadSgfFile(const std::string& sgfFilePath) = 0;
  
    /// @brief Loads the specified SGF content and puts it through the SGFC
    /// parser.
    ///
    /// The implementation of this method saves the specified SGF content to a
    /// temporary file and then instructs SGFC to load that file. After the
    /// load operation the implementation deletes the temporary file.
    ///
    /// @return An SgfcExitCode value whose numeric value matches one of the
    /// exit codes of SGFC.
    virtual SgfcExitCode LoadSgfContent(const std::string& sgfContent) = 0;
  
    /// @brief Returns a collection of ISgfcMessage objects which together form
    /// the parse result from the most recent invocation of either LoadSgfFile()
    /// or LoadSgfContent().
    ///
    /// The collection is empty if none of the methods have been invoked yet.
    ///
    /// If the collection is not empty, the messages appear in the order in
    /// which they were generated by SGFC.
    virtual std::vector<std::shared_ptr<ISgfcMessage>> GetParseResult() const = 0;
  
    /// @brief Saves the SGF content generated by SGFC after the most recent
    /// invocation of either LoadSgfFile() or LoadSgfContent() to the .sgf
    /// file at the specified path.
    ///
    /// If a file already exists at the specified path it is overwritten.
    virtual void SaveSgfFile(const std::string& fileName) const = 0;
  
    /// @brief Saves the SGF content generated by SGFC after the most recent
    /// invocation of either LoadSgfFile() or LoadSgfContent() into the
    /// specified string object.
    ///
    /// The implementation of this method saves the generated SGF content to a
    /// temporary file and then loads the content of that file into the
    /// specified string object. After the load operation the implementation
    /// deletes the temporary file.
    virtual void SaveSgfContent(std::string& sgfContent) const = 0;
  };
}
