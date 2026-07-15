
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Vehicle/Vehicle.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "VehicleParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by VehicleParser.
 */
class  VehicleListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterVehicle(VehicleParser::VehicleContext *ctx) = 0;
  virtual void exitVehicle(VehicleParser::VehicleContext *ctx) = 0;

  virtual void enterPair(VehicleParser::PairContext *ctx) = 0;
  virtual void exitPair(VehicleParser::PairContext *ctx) = 0;

  virtual void enterKey(VehicleParser::KeyContext *ctx) = 0;
  virtual void exitKey(VehicleParser::KeyContext *ctx) = 0;

  virtual void enterValue(VehicleParser::ValueContext *ctx) = 0;
  virtual void exitValue(VehicleParser::ValueContext *ctx) = 0;


};

