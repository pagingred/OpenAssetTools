
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Glasses/Glasses.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  GlassesParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, COMMA = 2, NEWLINE = 3, INTEGER = 4, IDENTIFIER = 5, WS = 6
  };

  enum {
    RuleGlassesFile = 0, RuleEntry = 1, RuleKey = 2, RuleFirstValue = 3, 
    RuleRest = 4
  };

  explicit GlassesParser(antlr4::TokenStream *input);

  GlassesParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~GlassesParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class GlassesFileContext;
  class EntryContext;
  class KeyContext;
  class FirstValueContext;
  class RestContext; 

  class  GlassesFileContext : public antlr4::ParserRuleContext {
  public:
    GlassesFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<EntryContext *> entry();
    EntryContext* entry(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GlassesFileContext* glassesFile();

  class  EntryContext : public antlr4::ParserRuleContext {
  public:
    EntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyContext *key();
    antlr4::tree::TerminalNode *COMMA();
    FirstValueContext *firstValue();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<RestContext *> rest();
    RestContext* rest(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EntryContext* entry();

  class  KeyContext : public antlr4::ParserRuleContext {
  public:
    KeyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  KeyContext* key();

  class  FirstValueContext : public antlr4::ParserRuleContext {
  public:
    FirstValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FirstValueContext* firstValue();

  class  RestContext : public antlr4::ParserRuleContext {
  public:
    RestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RestContext* rest();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

