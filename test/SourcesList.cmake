set (
  SOURCES
  main.cpp
  document/SgfcDocumentTest.cpp
  document/SgfcGameTest.cpp
  document/SgfcNodeTest.cpp
  document/SgfcTreeBuilderTest.cpp
  game/go/SgfcGoMoveTest.cpp
  game/go/SgfcGoPointTest.cpp
  game/go/SgfcGoStoneTest.cpp
  parsing/SgfcPropertyDecoderTest.cpp
  parsing/SgfcValueConverterTest.cpp
  sgfc/argument/SgfcArgumentTest.cpp
  sgfc/backend/SgfcBackendControllerTest.cpp
  sgfc/backend/SgfcBackendDataWrapperTest.cpp
  sgfc/frontend/SgfcCommandLineTest.cpp
  sgfc/frontend/SgfcDocumentReaderTest.cpp
  sgfc/frontend/SgfcDocumentWriterTest.cpp
  sgfc/message/SgfcMessageParserTest.cpp
  sgfc/message/SgfcMessageStreamTest.cpp
  sgfc/message/SgfcMessageTest.cpp
  sgfc/save/SgfcSaveStreamTest.cpp
  sgfc/save/SgfcSgfContentTest.cpp
  SourcesList.cmake
  TestDataGenerator.cpp
  TestDataGenerator.h
)
