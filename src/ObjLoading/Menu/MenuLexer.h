
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  MenuLexer : public antlr4::Lexer {
public:
  enum {
    LBRACE = 1, RBRACE = 2, LPAREN = 3, RPAREN = 4, SEMICOLON = 5, OP = 6, 
    FUNCTIONDEF = 7, LOADMENU = 8, MENUDEF = 9, ITEMDEF = 10, EXECKEY = 11, 
    EXECKEYINT = 12, IF = 13, ELSEIF = 14, ELSE = 15, WHEN = 16, FLOAT = 17, 
    INTEGER = 18, IDENTIFIER = 19, STRING = 20, WS = 21, LINECOMMENT = 22, 
    BLOCKCOMMENT = 23
  };

  explicit MenuLexer(antlr4::CharStream *input);

  ~MenuLexer() override;


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

