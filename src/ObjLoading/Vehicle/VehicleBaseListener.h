
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Vehicle/Vehicle.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VehicleListener.h"


/**
 * This class provides an empty implementation of VehicleListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VehicleBaseListener : public VehicleListener {
public:

  virtual void enterVehicle(VehicleParser::VehicleContext * /*ctx*/) override { }
  virtual void exitVehicle(VehicleParser::VehicleContext * /*ctx*/) override { }

  virtual void enterPair(VehicleParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(VehicleParser::PairContext * /*ctx*/) override { }

  virtual void enterKey(VehicleParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(VehicleParser::KeyContext * /*ctx*/) override { }

  virtual void enterValue(VehicleParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(VehicleParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

