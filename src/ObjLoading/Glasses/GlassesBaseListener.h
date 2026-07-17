
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Glasses/Glasses.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GlassesListener.h"


/**
 * This class provides an empty implementation of GlassesListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GlassesBaseListener : public GlassesListener {
public:

  virtual void enterGlassesFile(GlassesParser::GlassesFileContext * /*ctx*/) override { }
  virtual void exitGlassesFile(GlassesParser::GlassesFileContext * /*ctx*/) override { }

  virtual void enterEntry(GlassesParser::EntryContext * /*ctx*/) override { }
  virtual void exitEntry(GlassesParser::EntryContext * /*ctx*/) override { }

  virtual void enterKey(GlassesParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(GlassesParser::KeyContext * /*ctx*/) override { }

  virtual void enterFirstValue(GlassesParser::FirstValueContext * /*ctx*/) override { }
  virtual void exitFirstValue(GlassesParser::FirstValueContext * /*ctx*/) override { }

  virtual void enterRest(GlassesParser::RestContext * /*ctx*/) override { }
  virtual void exitRest(GlassesParser::RestContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

