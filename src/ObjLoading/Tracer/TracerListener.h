
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Tracer/Tracer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TracerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TracerParser.
 */
class  TracerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTracer(TracerParser::TracerContext *ctx) = 0;
  virtual void exitTracer(TracerParser::TracerContext *ctx) = 0;

  virtual void enterPair(TracerParser::PairContext *ctx) = 0;
  virtual void exitPair(TracerParser::PairContext *ctx) = 0;

  virtual void enterKey(TracerParser::KeyContext *ctx) = 0;
  virtual void exitKey(TracerParser::KeyContext *ctx) = 0;

  virtual void enterValue(TracerParser::ValueContext *ctx) = 0;
  virtual void exitValue(TracerParser::ValueContext *ctx) = 0;


};

