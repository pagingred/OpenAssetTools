
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Glasses/Glasses.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GlassesParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GlassesParser.
 */
class  GlassesListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterGlassesFile(GlassesParser::GlassesFileContext *ctx) = 0;
  virtual void exitGlassesFile(GlassesParser::GlassesFileContext *ctx) = 0;

  virtual void enterEntry(GlassesParser::EntryContext *ctx) = 0;
  virtual void exitEntry(GlassesParser::EntryContext *ctx) = 0;

  virtual void enterKey(GlassesParser::KeyContext *ctx) = 0;
  virtual void exitKey(GlassesParser::KeyContext *ctx) = 0;

  virtual void enterFirstValue(GlassesParser::FirstValueContext *ctx) = 0;
  virtual void exitFirstValue(GlassesParser::FirstValueContext *ctx) = 0;

  virtual void enterRest(GlassesParser::RestContext *ctx) = 0;
  virtual void exitRest(GlassesParser::RestContext *ctx) = 0;


};

