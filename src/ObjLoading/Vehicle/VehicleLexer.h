
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Vehicle/Vehicle.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  VehicleLexer : public antlr4::Lexer {
public:
  enum {
    VEHICLEFILE = 1, BACKSLASH = 2, FOUR_WHEEL = 3, FLOAT = 4, INTEGER = 5, 
    IDENTIFIER = 6, WS = 7
  };

  explicit VehicleLexer(antlr4::CharStream *input);

  ~VehicleLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

