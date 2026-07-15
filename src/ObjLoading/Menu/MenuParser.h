
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  MenuParser : public antlr4::Parser {
public:
  enum {
    LBRACE = 1, RBRACE = 2, LPAREN = 3, RPAREN = 4, SEMICOLON = 5, OP = 6, 
    FUNCTIONDEF = 7, LOADMENU = 8, MENUDEF = 9, ITEMDEF = 10, EXECKEY = 11, 
    EXECKEYINT = 12, IF = 13, ELSEIF = 14, ELSE = 15, WHEN = 16, FLOAT = 17, 
    INTEGER = 18, IDENTIFIER = 19, STRING = 20, WS = 21, LINECOMMENT = 22, 
    BLOCKCOMMENT = 23
  };

  enum {
    RuleMenuFile = 0, RuleMenuFilePart = 1, RuleFunctionDef = 2, RuleLoadMenu = 3, 
    RuleMenuDef = 4, RuleMenuItem = 5, RuleItemItem = 6, RulePropertyValue = 7, 
    RuleExpression = 8, RuleExpressionPart = 9, RuleBlock = 10, RuleElseifClause = 11, 
    RuleElseClause = 12, RuleBlockStatement = 13, RuleBlockToken = 14
  };

  explicit MenuParser(antlr4::TokenStream *input);

  MenuParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MenuParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MenuFileContext;
  class MenuFilePartContext;
  class FunctionDefContext;
  class LoadMenuContext;
  class MenuDefContext;
  class MenuItemContext;
  class ItemItemContext;
  class PropertyValueContext;
  class ExpressionContext;
  class ExpressionPartContext;
  class BlockContext;
  class ElseifClauseContext;
  class ElseClauseContext;
  class BlockStatementContext;
  class BlockTokenContext; 

  class  MenuFileContext : public antlr4::ParserRuleContext {
  public:
    MenuFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<MenuFilePartContext *> menuFilePart();
    MenuFilePartContext* menuFilePart(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MenuFileContext* menuFile();

  class  MenuFilePartContext : public antlr4::ParserRuleContext {
  public:
    MenuFilePartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MenuFilePartContext() = default;
    void copyFrom(MenuFilePartContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WrapperMenuFilePartContext : public MenuFilePartContext {
  public:
    WrapperMenuFilePartContext(MenuFilePartContext *ctx);

    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<MenuFilePartContext *> menuFilePart();
    MenuFilePartContext* menuFilePart(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FunctionDefMenuFilePartContext : public MenuFilePartContext {
  public:
    FunctionDefMenuFilePartContext(MenuFilePartContext *ctx);

    FunctionDefContext *functionDef();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MenuDefMenuFilePartContext : public MenuFilePartContext {
  public:
    MenuDefMenuFilePartContext(MenuFilePartContext *ctx);

    MenuDefContext *menuDef();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LoadMenuMenuFilePartContext : public MenuFilePartContext {
  public:
    LoadMenuMenuFilePartContext(MenuFilePartContext *ctx);

    LoadMenuContext *loadMenu();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  MenuFilePartContext* menuFilePart();

  class  FunctionDefContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTIONDEF();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDefContext* functionDef();

  class  LoadMenuContext : public antlr4::ParserRuleContext {
  public:
    LoadMenuContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOADMENU();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LoadMenuContext* loadMenu();

  class  MenuDefContext : public antlr4::ParserRuleContext {
  public:
    MenuDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MENUDEF();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<MenuItemContext *> menuItem();
    MenuItemContext* menuItem(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MenuDefContext* menuDef();

  class  MenuItemContext : public antlr4::ParserRuleContext {
  public:
    MenuItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MenuItemContext() = default;
    void copyFrom(MenuItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BlockMenuItemContext : public MenuItemContext {
  public:
    BlockMenuItemContext(MenuItemContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExecKeyIntMenuItemContext : public MenuItemContext {
  public:
    ExecKeyIntMenuItemContext(MenuItemContext *ctx);

    antlr4::tree::TerminalNode *EXECKEYINT();
    PropertyValueContext *propertyValue();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExecKeyMenuItemContext : public MenuItemContext {
  public:
    ExecKeyMenuItemContext(MenuItemContext *ctx);

    antlr4::tree::TerminalNode *EXECKEY();
    PropertyValueContext *propertyValue();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PropertyMenuItemContext : public MenuItemContext {
  public:
    PropertyMenuItemContext(MenuItemContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<PropertyValueContext *> propertyValue();
    PropertyValueContext* propertyValue(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ItemDefMenuItemContext : public MenuItemContext {
  public:
    ItemDefMenuItemContext(MenuItemContext *ctx);

    antlr4::tree::TerminalNode *ITEMDEF();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ItemItemContext *> itemItem();
    ItemItemContext* itemItem(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  MenuItemContext* menuItem();

  class  ItemItemContext : public antlr4::ParserRuleContext {
  public:
    ItemItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ItemItemContext() = default;
    void copyFrom(ItemItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PropertyItemItemContext : public ItemItemContext {
  public:
    PropertyItemItemContext(ItemItemContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<PropertyValueContext *> propertyValue();
    PropertyValueContext* propertyValue(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExecKeyItemItemContext : public ItemItemContext {
  public:
    ExecKeyItemItemContext(ItemItemContext *ctx);

    antlr4::tree::TerminalNode *EXECKEY();
    PropertyValueContext *propertyValue();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BlockItemItemContext : public ItemItemContext {
  public:
    BlockItemItemContext(ItemItemContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExecKeyIntItemItemContext : public ItemItemContext {
  public:
    ExecKeyIntItemItemContext(ItemItemContext *ctx);

    antlr4::tree::TerminalNode *EXECKEYINT();
    PropertyValueContext *propertyValue();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ItemItemContext* itemItem();

  class  PropertyValueContext : public antlr4::ParserRuleContext {
  public:
    PropertyValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PropertyValueContext() = default;
    void copyFrom(PropertyValueContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringPropertyValueContext : public PropertyValueContext {
  public:
    StringPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FloatPropertyValueContext : public PropertyValueContext {
  public:
    FloatPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExpressionPropertyValueContext : public PropertyValueContext {
  public:
    ExpressionPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  IdentifierPropertyValueContext : public PropertyValueContext {
  public:
    IdentifierPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  IntegerPropertyValueContext : public PropertyValueContext {
  public:
    IntegerPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *INTEGER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  WhenPropertyValueContext : public PropertyValueContext {
  public:
    WhenPropertyValueContext(PropertyValueContext *ctx);

    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PropertyValueContext* propertyValue();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionPartContext *> expressionPart();
    ExpressionPartContext* expressionPart(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  ExpressionPartContext : public antlr4::ParserRuleContext {
  public:
    ExpressionPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *OP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionPartContext* expressionPart();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BlockContext() = default;
    void copyFrom(BlockContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfBlockContext : public BlockContext {
  public:
    IfBlockContext(BlockContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<ElseifClauseContext *> elseifClause();
    ElseifClauseContext* elseifClause(size_t i);
    ElseClauseContext *elseClause();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StatementBlockContext : public BlockContext {
  public:
    StatementBlockContext(BlockContext *ctx);

    BlockStatementContext *blockStatement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  BlockContext* block();

  class  ElseifClauseContext : public antlr4::ParserRuleContext {
  public:
    ElseifClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSEIF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseifClauseContext* elseifClause();

  class  ElseClauseContext : public antlr4::ParserRuleContext {
  public:
    ElseClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseClauseContext* elseClause();

  class  BlockStatementContext : public antlr4::ParserRuleContext {
  public:
    BlockStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockTokenContext *> blockToken();
    BlockTokenContext* blockToken(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockStatementContext* blockStatement();

  class  BlockTokenContext : public antlr4::ParserRuleContext {
  public:
    BlockTokenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<BlockTokenContext *> blockToken();
    BlockTokenContext* blockToken(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockTokenContext* blockToken();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

