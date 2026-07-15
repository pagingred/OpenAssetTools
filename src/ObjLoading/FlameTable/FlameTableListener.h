
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/FlameTable/FlameTable.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FlameTableParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by FlameTableParser.
 */
class  FlameTableListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFlameTable(FlameTableParser::FlameTableContext *ctx) = 0;
  virtual void exitFlameTable(FlameTableParser::FlameTableContext *ctx) = 0;

  virtual void enterPair(FlameTableParser::PairContext *ctx) = 0;
  virtual void exitPair(FlameTableParser::PairContext *ctx) = 0;

  virtual void enterKey(FlameTableParser::KeyContext *ctx) = 0;
  virtual void exitKey(FlameTableParser::KeyContext *ctx) = 0;

  virtual void enterValue(FlameTableParser::ValueContext *ctx) = 0;
  virtual void exitValue(FlameTableParser::ValueContext *ctx) = 0;


};

