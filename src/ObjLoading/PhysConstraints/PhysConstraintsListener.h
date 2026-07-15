
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/PhysConstraints/PhysConstraints.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PhysConstraintsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PhysConstraintsParser.
 */
class  PhysConstraintsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPhysConstraints(PhysConstraintsParser::PhysConstraintsContext *ctx) = 0;
  virtual void exitPhysConstraints(PhysConstraintsParser::PhysConstraintsContext *ctx) = 0;

  virtual void enterPair(PhysConstraintsParser::PairContext *ctx) = 0;
  virtual void exitPair(PhysConstraintsParser::PairContext *ctx) = 0;

  virtual void enterKey(PhysConstraintsParser::KeyContext *ctx) = 0;
  virtual void exitKey(PhysConstraintsParser::KeyContext *ctx) = 0;

  virtual void enterValue(PhysConstraintsParser::ValueContext *ctx) = 0;
  virtual void exitValue(PhysConstraintsParser::ValueContext *ctx) = 0;


};

