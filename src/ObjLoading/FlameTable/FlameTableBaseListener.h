
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/FlameTable/FlameTable.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FlameTableListener.h"


/**
 * This class provides an empty implementation of FlameTableListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  FlameTableBaseListener : public FlameTableListener {
public:

  virtual void enterFlameTable(FlameTableParser::FlameTableContext * /*ctx*/) override { }
  virtual void exitFlameTable(FlameTableParser::FlameTableContext * /*ctx*/) override { }

  virtual void enterPair(FlameTableParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(FlameTableParser::PairContext * /*ctx*/) override { }

  virtual void enterKey(FlameTableParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(FlameTableParser::KeyContext * /*ctx*/) override { }

  virtual void enterValue(FlameTableParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(FlameTableParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

