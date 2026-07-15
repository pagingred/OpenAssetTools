
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Tracer/Tracer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TracerListener.h"


/**
 * This class provides an empty implementation of TracerListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TracerBaseListener : public TracerListener {
public:

  virtual void enterTracer(TracerParser::TracerContext * /*ctx*/) override { }
  virtual void exitTracer(TracerParser::TracerContext * /*ctx*/) override { }

  virtual void enterPair(TracerParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(TracerParser::PairContext * /*ctx*/) override { }

  virtual void enterKey(TracerParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(TracerParser::KeyContext * /*ctx*/) override { }

  virtual void enterValue(TracerParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(TracerParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

