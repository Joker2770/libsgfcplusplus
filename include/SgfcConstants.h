#pragma once

// Project includes
#include "SgfcBoardSize.h"
#include "SgfcGameType.h"
#include "SgfcPropertyType.h"
#include "SgfcTypedefs.h"

// C++ Standard Library includes
#include <map>
#include <string>

namespace LibSgfcPlusPlus
{
  /// @brief The SgfcConstants class is a container class for constants.
  class SgfcConstants
  {
  public:
    /// @name libsgfc++ constants
    //@{
    static const std::string LibraryName;
    //@}

    /// @name ISgfcMessage related constants
    //@{
    /// @brief Indicates that the message was generated by SGFC, but libsgfc++
    /// was unable to determine the message ID when it parsed the raw message
    /// text.
    ///
    /// This message ID is a positive number in order to satisfy the guarantee
    /// that SGFC-generated messages always have message IDs >= 0. libsgfc++
    /// strives to use a number that is not in the list of message IDs that are
    /// documented by SGFC.
    static const int UnknownSgfcMessageID;
    /// @brief Indicates a message without a valid ID. If a message with this
    /// ID is seen by a library client this indicates a coding error in
    /// libsgfc++.
    static const int InvalidMessageID;
    /// @brief Indicates a fatal error due to an SGFC command line argument
    /// that is banned by libsgfc++.
    static const int BannedArgumentMessageID;
    /// @brief Indicates that a fatal error occurred when SGFC parsed command
    /// line arguments, but libsgfc++ was unable to obtain the fatal error
    /// message from SGFC.
    static const int ParseArgumentErrorMessageID;
    /// @brief Indicates a fatal error that occurred while libsgfc++ attempted
    /// to save of a piece of SGF content to the file system.
    static const int SaveSgfContentToFilesystemErrorMessageID;
    /// @brief Indicates an invalid line number. This is used for fatal error
    /// messages that do not refer to a specific line number in a piece of
    /// SGF content.
    static const int InvalidLineNumber;
    /// @brief Indicates an invalid column number. This is used for fatal error
    /// messages that do not refer to a specific column number in a piece of
    /// SGF content.
    static const int InvalidColumnNumber;
    //@}

    /// @name String constants defined by the SGF standard
    //@{
    static const std::string NoneString;
    static const std::string DoubleNormalString;
    static const std::string DoubleEmphasizedString;
    static const std::string ColorBlackString;
    static const std::string ColorWhiteString;
    /// @brief Maps property names as defined by the SGF standard to values from
    /// the enumeration SgfcPropertyType.
    static const std::map<std::string, SgfcPropertyType> PropertyNameToPropertyTypeMap;
    /// @brief Maps values from the enumeration SgfcPropertyType to property
    /// names as defined by the SGF standard. SgfcPropertyType::Unknown does
    /// not appear in the map.
    static const std::map<SgfcPropertyType, std::string> PropertyTypeToPropertyNameMap;
    /// @brief Maps game type Number values as defined by the SGF standard to
    /// values from the enumeration SgfcGameType.
    static const std::map<SgfcNumber, SgfcGameType> GameTypeAsNumberToGameTypeMap;
    /// @brief Maps values from the enumeration SgfcGameType to Number values
    /// as defined by the SGF standard. SgfcGameType::Unknown does not appear
    /// in the map.
    static const std::map<SgfcGameType, SgfcNumber> GameTypeToGameTypeAsNumberMap;
    //@}

    /// @name Other constants for values defined by the SGF standard
    //@{
    /// @brief The default game type if the SgfcPropertyType::GM property exists
    /// but has no value.
    ///
    /// The SGF standard defines this to be SgfcGameType::Go.
    static const SgfcGameType DefaultGameType;

    /// @brief The minimum board size that is allowed for SgfcPropertyType::SZ.
    ///
    /// The SGF standard defines this to be 1x1.
    static const SgfcBoardSize BoardSizeMinimum;

    /// @brief The maximum board size that is allowed for SgfcPropertyType::SZ
    /// if the game type is SgfcGameType::Go.
    ///
    /// The SGF standard defines this to be 52x52.
    static const SgfcBoardSize BoardSizeMaximumGo;

    /// @brief The default board size if the game type is SgfcGameType::Go.
    ///
    /// The SGF standard defines this to be 19x19.
    static const SgfcBoardSize BoardSizeDefaultGo;

    /// @brief The default board size if the game type is SgfcGameType::Chess.
    ///
    /// The SGF standard defines this to be 8x8.
    static const SgfcBoardSize BoardSizeDefaultChess;
    //@}

    /// @name Other constants
    //@{
    /// @brief A number value denoting "no game type".
    ///
    /// ISgfcGame::GetGameTypeAsNumber() returns this value, for instance, if
    /// the SgfcPropertyType::GM property is not present in a game's root ndoe,
    /// or if the game has no root node.
    static const SgfcNumber GameTypeNone;

    /// @brief A board size value denoting "no board size".
    ///
    /// ISgfcGame::GetBoardSize() returns this value, for instance, if the
    /// SgfcPropertyType::SZ property is not present in a game's root ndoe,
    /// or if the game has no root node.
    static const SgfcBoardSize BoardSizeNone;
    //@}
  };
}
