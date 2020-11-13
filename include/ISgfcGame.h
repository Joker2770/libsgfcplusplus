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
#include "ISgfcNode.h"
#include "SgfcBoardSize.h"
#include "SgfcGameType.h"
#include "SgfcTypedefs.h"

// Project includes (generated)
#include "SgfcPlusPlusExport.h"

// C++ Standard Library includes
#include <memory>

namespace LibSgfcPlusPlus
{
  // Forward declarations
  class ISgfcTreeBuilder;

  /// @brief The ISgfcGame interface provides access to the data of one SGF
  /// game, in the form of a tree of ISgfcNode objects. Each branch in the tree
  /// is a variation in game play. A tree without branches is a game without
  /// variations.
  ///
  /// @ingroup public-api
  /// @ingroup game-tree
  class SGFCPLUSPLUS_EXPORT ISgfcGame
  {
  public:
    /// @brief Initializes a newly constructed ISgfcGame object.
    ISgfcGame();

    /// @brief Destroys and cleans up the ISgfcGame object.
    virtual ~ISgfcGame();

    /// @brief Returns the property value(s) found in the root node property of
    /// type SgfcPropertyType::GM, interpreted as an SgfcGameType value.
    ///
    /// @retval SgfcGameType If the property is present and has a single Number
    ///         value, and that value is defined in the SGF standard, then the
    ///         SgfcGameType value that corresponds to the Number value is
    ///         returned. The value is guaranteed not to be
    ///         SgfcGameType::Unknown.
    /// @retval SgfcConstants::DefaultGameType If the property is not present,
    ///         or if the game has no root node, or if the property is present
    ///         but has no value. The value is guaranteed not to be
    ///         SgfcGameType::Unknown.
    /// @retval SgfcGameType::Unknown If the property is present but its
    ///         value(s) cannot be converted to a Number value (the property
    ///         has more than one value, or the single value is not a Number
    ///         value), or if conversion is possible but the Number value is
    ///         not defined in the SGF standard. Invoke GetGameTypeAsNumber()
    ///         to obtain the game type as Number value.
    virtual SgfcGameType GetGameType() const = 0;

    /// @brief Returns the property value(s) found in the root node property of
    /// type SgfcPropertyType::GM, as an SgfcNumber value.
    ///
    /// This is useful if GetGameType() returns SgfcGameType::Unknown because
    /// the Number value is not defined in the SGF standard and cannot be
    /// mapped to a member of the enumeration SgfcGameType.
    ///
    /// @retval SgfcNumber If the property is present and contains a single
    ///         Number value, then that Number value is returned. If the
    ///         property is not present, or if the game has no root node, or if
    ///         the property is present but has no value, then this method
    ///         returns the Number value that corresponds to
    ///         SgfcConstants::DefaultGameType.
    /// @retval SgfcConstants::GameTypeNaN If the property is present but its
    ///         value(s) cannot be converted to a Number value, either because
    ///         the property has more than one value, or its single value is
    ///         not a Number value.
    virtual SgfcNumber GetGameTypeAsNumber() const = 0;

    /// @brief Returns true if the game has a board size. Returns false if the
    /// game has no board size.
    ///
    /// The game has no board size if GetBoardSize() returns
    /// SgfcConstants::BoardSizeNone or SgfcConstants::BoardSizeInvalid.
    virtual bool HasBoardSize() const = 0;

    /// @brief Returns the board size found in the root node property of type
    /// SgfcPropertyType::SZ, as an SgfcBoardSize value.
    ///
    /// @retval SgfcBoardSize If the property is present and has a valid value.
    ///         The value is guaranteed not to be SgfcConstants::BoardSizeNone
    ///         nor SgfcConstants::BoardSizeInvalid.
    /// @retval SgfcConstants::BoardSizeDefaultGo If GetGameType() returns
    ///         SgfcGameType::Go and one of the following is true: The game has
    ///         no root node, or the game has a root node but the property is
    ///         not present, or the game has a root node and the property is
    ///         present but has no value (e.g. while the game tree is being set
    ///         up programmatically).
    /// @retval SgfcConstants::BoardSizeDefaultChess If GetGameType() returns
    ///         SgfcGameType::Chess and one of the following is true: The game
    ///         has a root node but the property is not present, or the game has
    ///         a root node and the property is present but has no value (e.g.
    ///         while the game tree is being set up programmatically).
    /// @retval SgfcConstants::BoardSizeNone If GetGameType() returns neither
    ///         SgfcGameType::Go nor SgfcGameType::Chess (these are the two game
    ///         types for which the SGF standard defines a default board size)
    ///         and one of the following is true: The game has a root node but
    ///         the property is not present, or the game has a root node and the
    ///         property is present but has no value (e.g. while the game tree
    ///         is being set up programmatically).
    /// @retval SgfcConstants::BoardSizeInvalid If the property is present but
    ///         either its property value(s) cannot be converted to an
    ///         SgfcBoardSize value (the property has more than one value, or
    ///         it has a single value that is neither a Number nor a composed
    ///         value consisting of two Number values), or if conversion is
    ///         possible but the SgfcBoardSize value violates the constraints
    ///         defined by the SGF standard. See the documentation of
    ///         SgfcConstants::BoardSizeInvalid for details.
    virtual SgfcBoardSize GetBoardSize() const = 0;

    /// @brief Returns true if the game has a root node. Returns false if the
    /// game has no root node.
    virtual bool HasRootNode() const = 0;

    /// @brief Returns the game tree's root node. Returns @e nullptr if
    /// HasRootNode() returns false.
    virtual std::shared_ptr<ISgfcNode> GetRootNode() const = 0;

    /// @brief Sets the game tree's root node to @a rootNode. The previous
    /// root node, and with it the entire previous game tree, is discarded.
    virtual void SetRootNode(std::shared_ptr<ISgfcNode> rootNode) = 0;

    /// @brief Returns an ISgfcTreeBuilder object that can be used to
    /// manipulate the game tree.
    virtual std::shared_ptr<ISgfcTreeBuilder> GetTreeBuilder() const = 0;
  };
}
