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

// Project includes
#include "../include/SgfcConstants.h"
#include "SgfcPrivateConstants.h"

// C++ Standard Library includes
#include <limits>

namespace LibSgfcPlusPlus
{
  const std::string SgfcConstants::LibraryName = "libsgfc++";
  const std::string SgfcConstants::LibraryVersion = "0.1 (alpha)";
  const std::string SgfcConstants::SgfcVersion = "1.18";

  // Must be a positive number to indicate that the message was generated by
  // SGFC.
  const int SgfcConstants::UnknownSgfcMessageID = std::numeric_limits<int>::max();
  const int SgfcConstants::InvalidMessageID = -1;
  const int SgfcConstants::ParseArgumentErrorMessageID = -2;
  const int SgfcConstants::SaveSgfContentToFilesystemErrorMessageID = -3;
  const int SgfcConstants::ReadSgfContentFromFilesystemErrorMessageID = -4;
  const int SgfcConstants::DeleteFileErrorMessageID = -5;
  const int SgfcConstants::OutOfMemoryErrorMessageID = -6;

  const int SgfcConstants::InvalidLineNumber = -1;
  const int SgfcConstants::InvalidColumnNumber = -1;

  const int SgfcConstants::LibraryErrorNumberNoError = 0;

  const std::string SgfcConstants::NoneValueString = SgfcPrivateConstants::EmptyString;
  const std::string SgfcConstants::DoubleNormalString = "1";
  const std::string SgfcConstants::DoubleEmphasizedString = "2";
  const std::string SgfcConstants::ColorBlackString = "B";
  const std::string SgfcConstants::ColorWhiteString = "W";
  const std::string SgfcConstants::GoMovePassString = SgfcPrivateConstants::EmptyString;

  const std::map<std::string, SgfcPropertyType> SgfcConstants::PropertyNameToPropertyTypeMap =
  {
    { "B", SgfcPropertyType::B },
    { "KO", SgfcPropertyType::KO },
    { "MN", SgfcPropertyType::MN },
    { "W", SgfcPropertyType::W },
    { "AB", SgfcPropertyType::AB },
    { "AE", SgfcPropertyType::AE },
    { "AW", SgfcPropertyType::AW },
    { "PL", SgfcPropertyType::PL },
    { "C", SgfcPropertyType::C },
    { "DM", SgfcPropertyType::DM },
    { "GB", SgfcPropertyType::GB },
    { "GW", SgfcPropertyType::GW },
    { "HO", SgfcPropertyType::HO },
    { "N", SgfcPropertyType::N },
    { "UC", SgfcPropertyType::UC },
    { "V", SgfcPropertyType::V },
    { "BM", SgfcPropertyType::BM },
    { "DO", SgfcPropertyType::DO },
    { "IT", SgfcPropertyType::IT },
    { "TE", SgfcPropertyType::TE },
    { "AR", SgfcPropertyType::AR },
    { "CR", SgfcPropertyType::CR },
    { "DD", SgfcPropertyType::DD },
    { "LB", SgfcPropertyType::LB },
    { "LN", SgfcPropertyType::LN },
    { "MA", SgfcPropertyType::MA },
    { "SL", SgfcPropertyType::SL },
    { "SQ", SgfcPropertyType::SQ },
    { "TR", SgfcPropertyType::TR },
    { "AP", SgfcPropertyType::AP },
    { "CA", SgfcPropertyType::CA },
    { "FF", SgfcPropertyType::FF },
    { "GM", SgfcPropertyType::GM },
    { "ST", SgfcPropertyType::ST },
    { "SZ", SgfcPropertyType::SZ },
    { "AN", SgfcPropertyType::AN },
    { "BR", SgfcPropertyType::BR },
    { "BT", SgfcPropertyType::BT },
    { "CP", SgfcPropertyType::CP },
    { "DT", SgfcPropertyType::DT },
    { "EV", SgfcPropertyType::EV },
    { "GN", SgfcPropertyType::GN },
    { "GC", SgfcPropertyType::GC },
    { "ON", SgfcPropertyType::ON },
    { "OT", SgfcPropertyType::OT },
    { "PB", SgfcPropertyType::PB },
    { "PC", SgfcPropertyType::PC },
    { "PW", SgfcPropertyType::PW },
    { "RE", SgfcPropertyType::RE },
    { "RO", SgfcPropertyType::RO },
    { "RU", SgfcPropertyType::RU },
    { "SO", SgfcPropertyType::SO },
    { "TM", SgfcPropertyType::TM },
    { "US", SgfcPropertyType::US },
    { "WR", SgfcPropertyType::WR },
    { "WT", SgfcPropertyType::WT },
    { "BL", SgfcPropertyType::BL },
    { "OB", SgfcPropertyType::OB },
    { "OW", SgfcPropertyType::OW },
    { "WL", SgfcPropertyType::WL },
    { "FG", SgfcPropertyType::FG },
    { "PM", SgfcPropertyType::PM },
    { "VW", SgfcPropertyType::VW },
    { "BS", SgfcPropertyType::BS },
    { "CH", SgfcPropertyType::CH },
    { "EL", SgfcPropertyType::EL },
    { "EX", SgfcPropertyType::EX },
    { "ID", SgfcPropertyType::ID },
    { "L", SgfcPropertyType::L },
    { "LT", SgfcPropertyType::LT },
    { "M", SgfcPropertyType::M },
    { "OM", SgfcPropertyType::OM },
    { "OP", SgfcPropertyType::OP },
    { "OV", SgfcPropertyType::OV },
    { "RG", SgfcPropertyType::RG },
    { "SC", SgfcPropertyType::SC },
    { "SE", SgfcPropertyType::SE },
    { "SI", SgfcPropertyType::SI },
    { "TC", SgfcPropertyType::TC },
    { "WS", SgfcPropertyType::WS },
    { "HA", SgfcPropertyType::HA },
    { "KM", SgfcPropertyType::KM },
    { "TB", SgfcPropertyType::TB },
    { "TW", SgfcPropertyType::TW },
    { "CO", SgfcPropertyType::CO },
    { "CV", SgfcPropertyType::CV },
    { "DI", SgfcPropertyType::DI },
    { "MI", SgfcPropertyType::MI },
    { "IY", SgfcPropertyType::IY },
    { "SU", SgfcPropertyType::SU },
    { "IS", SgfcPropertyType::IS },
    { "AA", SgfcPropertyType::AA },
    { "BO", SgfcPropertyType::BO },
    { "WO", SgfcPropertyType::WO },
    { "NP", SgfcPropertyType::NP },
    { "NR", SgfcPropertyType::NR },
    { "NS", SgfcPropertyType::NS },
    { "CS", SgfcPropertyType::CS },
    { "MS", SgfcPropertyType::MS },
    { "SS", SgfcPropertyType::SS },
    { "TS", SgfcPropertyType::TS },
    { "RP", SgfcPropertyType::RP },
    { "AS", SgfcPropertyType::AS },
    { "IP", SgfcPropertyType::IP },
    { "KI", SgfcPropertyType::KI },
  };

  const std::map<SgfcPropertyType, std::string> SgfcConstants::PropertyTypeToPropertyNameMap =
  {
    { SgfcPropertyType::B, "B" },
    { SgfcPropertyType::KO, "KO" },
    { SgfcPropertyType::MN, "MN" },
    { SgfcPropertyType::W, "W" },
    { SgfcPropertyType::AB, "AB" },
    { SgfcPropertyType::AE, "AE" },
    { SgfcPropertyType::AW, "AW" },
    { SgfcPropertyType::PL, "PL" },
    { SgfcPropertyType::C, "C" },
    { SgfcPropertyType::DM, "DM" },
    { SgfcPropertyType::GB, "GB" },
    { SgfcPropertyType::GW, "GW" },
    { SgfcPropertyType::HO, "HO" },
    { SgfcPropertyType::N, "N" },
    { SgfcPropertyType::UC, "UC" },
    { SgfcPropertyType::V, "V" },
    { SgfcPropertyType::BM, "BM" },
    { SgfcPropertyType::DO, "DO" },
    { SgfcPropertyType::IT, "IT" },
    { SgfcPropertyType::TE, "TE" },
    { SgfcPropertyType::AR, "AR" },
    { SgfcPropertyType::CR, "CR" },
    { SgfcPropertyType::DD, "DD" },
    { SgfcPropertyType::LB, "LB" },
    { SgfcPropertyType::LN, "LN" },
    { SgfcPropertyType::MA, "MA" },
    { SgfcPropertyType::SL, "SL" },
    { SgfcPropertyType::SQ, "SQ" },
    { SgfcPropertyType::TR, "TR" },
    { SgfcPropertyType::AP, "AP" },
    { SgfcPropertyType::CA, "CA" },
    { SgfcPropertyType::FF, "FF" },
    { SgfcPropertyType::GM, "GM" },
    { SgfcPropertyType::ST, "ST" },
    { SgfcPropertyType::SZ, "SZ" },
    { SgfcPropertyType::AN, "AN" },
    { SgfcPropertyType::BR, "BR" },
    { SgfcPropertyType::BT, "BT" },
    { SgfcPropertyType::CP, "CP" },
    { SgfcPropertyType::DT, "DT" },
    { SgfcPropertyType::EV, "EV" },
    { SgfcPropertyType::GN, "GN" },
    { SgfcPropertyType::GC, "GC" },
    { SgfcPropertyType::ON, "ON" },
    { SgfcPropertyType::OT, "OT" },
    { SgfcPropertyType::PB, "PB" },
    { SgfcPropertyType::PC, "PC" },
    { SgfcPropertyType::PW, "PW" },
    { SgfcPropertyType::RE, "RE" },
    { SgfcPropertyType::RO, "RO" },
    { SgfcPropertyType::RU, "RU" },
    { SgfcPropertyType::SO, "SO" },
    { SgfcPropertyType::TM, "TM" },
    { SgfcPropertyType::US, "US" },
    { SgfcPropertyType::WR, "WR" },
    { SgfcPropertyType::WT, "WT" },
    { SgfcPropertyType::BL, "BL" },
    { SgfcPropertyType::OB, "OB" },
    { SgfcPropertyType::OW, "OW" },
    { SgfcPropertyType::WL, "WL" },
    { SgfcPropertyType::FG, "FG" },
    { SgfcPropertyType::PM, "PM" },
    { SgfcPropertyType::VW, "VW" },
    { SgfcPropertyType::BS, "BS" },
    { SgfcPropertyType::CH, "CH" },
    { SgfcPropertyType::EL, "EL" },
    { SgfcPropertyType::EX, "EX" },
    { SgfcPropertyType::ID, "ID" },
    { SgfcPropertyType::L, "L" },
    { SgfcPropertyType::LT, "LT" },
    { SgfcPropertyType::M, "M" },
    { SgfcPropertyType::OM, "OM" },
    { SgfcPropertyType::OP, "OP" },
    { SgfcPropertyType::OV, "OV" },
    { SgfcPropertyType::RG, "RG" },
    { SgfcPropertyType::SC, "SC" },
    { SgfcPropertyType::SE, "SE" },
    { SgfcPropertyType::SI, "SI" },
    { SgfcPropertyType::TC, "TC" },
    { SgfcPropertyType::WS, "WS" },
    { SgfcPropertyType::HA, "HA" },
    { SgfcPropertyType::KM, "KM" },
    { SgfcPropertyType::TB, "TB" },
    { SgfcPropertyType::TW, "TW" },
    { SgfcPropertyType::CO, "CO" },
    { SgfcPropertyType::CV, "CV" },
    { SgfcPropertyType::DI, "DI" },
    { SgfcPropertyType::MI, "MI" },
    { SgfcPropertyType::IY, "IY" },
    { SgfcPropertyType::SU, "SU" },
    { SgfcPropertyType::IS, "IS" },
    { SgfcPropertyType::AA, "AA" },
    { SgfcPropertyType::BO, "BO" },
    { SgfcPropertyType::WO, "WO" },
    { SgfcPropertyType::NP, "NP" },
    { SgfcPropertyType::NR, "NR" },
    { SgfcPropertyType::NS, "NS" },
    { SgfcPropertyType::CS, "CS" },
    { SgfcPropertyType::MS, "MS" },
    { SgfcPropertyType::SS, "SS" },
    { SgfcPropertyType::TS, "TS" },
    { SgfcPropertyType::RP, "RP" },
    { SgfcPropertyType::AS, "AS" },
    { SgfcPropertyType::IP, "IP" },
    { SgfcPropertyType::KI, "KI" },
  };

  const std::map<SgfcNumber, SgfcGameType> SgfcConstants::GameTypeAsNumberToGameTypeMap =
  {
    { 1, SgfcGameType::Go },
    { 2, SgfcGameType::Othello },
    { 3, SgfcGameType::Chess },
    { 4, SgfcGameType::GomokuAndRenju },
    { 5, SgfcGameType::NineMensMorris },
    { 6, SgfcGameType::Backgammon },
    { 7, SgfcGameType::ChineseChess },
    { 8, SgfcGameType::Shogi },
    { 9, SgfcGameType::LinesOfAction },
    { 10, SgfcGameType::Ataxx },
    { 11, SgfcGameType::Hex },
    { 12, SgfcGameType::Jungle },
    { 13, SgfcGameType::Neutron },
    { 14, SgfcGameType::PhilosophersFootball },
    { 15, SgfcGameType::Quadrature },
    { 16, SgfcGameType::Trax },
    { 17, SgfcGameType::Tantrix },
    { 18, SgfcGameType::Amazons },
    { 19, SgfcGameType::Octi },
    { 20, SgfcGameType::Gess },
    { 21, SgfcGameType::Twixt },
    { 22, SgfcGameType::Zertz },
    { 23, SgfcGameType::Plateau },
    { 24, SgfcGameType::Yinsh },
    { 25, SgfcGameType::Punct },
    { 26, SgfcGameType::Gobblet },
    { 27, SgfcGameType::Hive },
    { 28, SgfcGameType::Exxit },
    { 29, SgfcGameType::Hnefatal },
    { 30, SgfcGameType::Kuba },
    { 31, SgfcGameType::Tripples },
    { 32, SgfcGameType::Chase },
    { 33, SgfcGameType::TumblingDown },
    { 34, SgfcGameType::Sahara },
    { 35, SgfcGameType::Byte },
    { 36, SgfcGameType::Focus },
    { 37, SgfcGameType::Dvonn },
    { 38, SgfcGameType::Tamsk },
    { 39, SgfcGameType::Gipf },
    { 40, SgfcGameType::Kropki },
  };

  const std::map<SgfcGameType, SgfcNumber> SgfcConstants::GameTypeToGameTypeAsNumberMap =
  {
    { SgfcGameType::Go, 1 },
    { SgfcGameType::Othello, 2 },
    { SgfcGameType::Chess, 3 },
    { SgfcGameType::GomokuAndRenju, 4 },
    { SgfcGameType::NineMensMorris, 5 },
    { SgfcGameType::Backgammon, 6 },
    { SgfcGameType::ChineseChess, 7 },
    { SgfcGameType::Shogi, 8 },
    { SgfcGameType::LinesOfAction, 9 },
    { SgfcGameType::Ataxx, 10 },
    { SgfcGameType::Hex, 11 },
    { SgfcGameType::Jungle, 12 },
    { SgfcGameType::Neutron, 13 },
    { SgfcGameType::PhilosophersFootball, 14 },
    { SgfcGameType::Quadrature, 15 },
    { SgfcGameType::Trax, 16 },
    { SgfcGameType::Tantrix, 17 },
    { SgfcGameType::Amazons, 18 },
    { SgfcGameType::Octi, 19 },
    { SgfcGameType::Gess, 20 },
    { SgfcGameType::Twixt, 21 },
    { SgfcGameType::Zertz, 22 },
    { SgfcGameType::Plateau, 23 },
    { SgfcGameType::Yinsh, 24 },
    { SgfcGameType::Punct, 25 },
    { SgfcGameType::Gobblet, 26 },
    { SgfcGameType::Hive, 27 },
    { SgfcGameType::Exxit, 28 },
    { SgfcGameType::Hnefatal, 29 },
    { SgfcGameType::Kuba, 30 },
    { SgfcGameType::Tripples, 31 },
    { SgfcGameType::Chase, 32 },
    { SgfcGameType::TumblingDown, 33 },
    { SgfcGameType::Sahara, 34 },
    { SgfcGameType::Byte, 35 },
    { SgfcGameType::Focus, 36 },
    { SgfcGameType::Dvonn, 37 },
    { SgfcGameType::Tamsk, 38 },
    { SgfcGameType::Gipf, 39 },
    { SgfcGameType::Kropki, 40 },
  };

  const SgfcGameType SgfcConstants::DefaultGameType = SgfcGameType::Go;
  const SgfcNumber SgfcConstants::GameTypeNaN = std::numeric_limits<SgfcNumber>::min();;

  const SgfcBoardSize SgfcConstants::BoardSizeMinimum = { 1, 1 };
  const SgfcBoardSize SgfcConstants::BoardSizeMaximumGo = { 52, 52 };
  const SgfcBoardSize SgfcConstants::BoardSizeDefaultGo = { 19, 19 };
  const SgfcBoardSize SgfcConstants::BoardSizeDefaultChess = { 8, 8 };

  const SgfcBoardSize SgfcConstants::BoardSizeNone = { -1, -1 };
  const SgfcBoardSize SgfcConstants::BoardSizeInvalid = { -2, -2 };
}
