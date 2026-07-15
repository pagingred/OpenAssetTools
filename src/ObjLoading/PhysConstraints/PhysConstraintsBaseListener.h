
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/PhysConstraints/PhysConstraints.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PhysConstraintsListener.h"


/**
 * This class provides an empty implementation of PhysConstraintsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PhysConstraintsBaseListener : public PhysConstraintsListener {
public:

  virtual void enterPhysConstraints(PhysConstraintsParser::PhysConstraintsContext * /*ctx*/) override { }
  virtual void exitPhysConstraints(PhysConstraintsParser::PhysConstraintsContext * /*ctx*/) override { }

  virtual void enterPair(PhysConstraintsParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(PhysConstraintsParser::PairContext * /*ctx*/) override { }

  virtual void enterKey(PhysConstraintsParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(PhysConstraintsParser::KeyContext * /*ctx*/) override { }

  virtual void enterValue(PhysConstraintsParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(PhysConstraintsParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

