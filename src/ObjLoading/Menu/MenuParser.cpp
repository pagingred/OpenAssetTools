
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2


#include "MenuListener.h"

#include "MenuParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MenuParserStaticData final {
  MenuParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MenuParserStaticData(const MenuParserStaticData&) = delete;
  MenuParserStaticData(MenuParserStaticData&&) = delete;
  MenuParserStaticData& operator=(const MenuParserStaticData&) = delete;
  MenuParserStaticData& operator=(MenuParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag menuParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MenuParserStaticData> menuParserStaticData = nullptr;

void menuParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (menuParserStaticData != nullptr) {
    return;
  }
#else
  assert(menuParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MenuParserStaticData>(
    std::vector<std::string>{
      "menuFile", "menuFilePart", "functionDef", "loadMenu", "menuDef", 
      "menuItem", "itemItem", "propertyValue", "expression", "expressionPart", 
      "block", "elseifClause", "elseClause", "blockStatement", "blockToken"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "'('", "')'", "';'", "", "'functionDef'", "'loadMenu'", 
      "'menuDef'", "'itemDef'", "'execKey'", "'execKeyInt'", "'if'", "'elseif'", 
      "'else'", "'when'"
    },
    std::vector<std::string>{
      "", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "OP", "FUNCTIONDEF", 
      "LOADMENU", "MENUDEF", "ITEMDEF", "EXECKEY", "EXECKEYINT", "IF", "ELSEIF", 
      "ELSE", "WHEN", "FLOAT", "INTEGER", "IDENTIFIER", "STRING", "WS", 
      "LINECOMMENT", "BLOCKCOMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,23,268,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,5,0,32,8,0,10,0,12,0,35,9,0,1,0,1,0,1,1,1,1,5,1,41,8,1,10,1,12,
  	1,44,9,1,1,1,1,1,1,1,1,1,3,1,50,8,1,1,2,1,2,1,2,5,2,55,8,2,10,2,12,2,
  	58,9,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,70,8,4,10,4,12,4,73,
  	9,4,1,4,1,4,1,5,1,5,1,5,5,5,80,8,5,10,5,12,5,83,9,5,1,5,1,5,1,5,1,5,1,
  	5,5,5,90,8,5,10,5,12,5,93,9,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,101,8,5,10,
  	5,12,5,104,9,5,1,5,1,5,1,5,1,5,1,5,5,5,111,8,5,10,5,12,5,114,9,5,1,5,
  	1,5,1,5,5,5,119,8,5,10,5,12,5,122,9,5,3,5,124,8,5,1,6,1,6,1,6,1,6,5,6,
  	130,8,6,10,6,12,6,133,9,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,141,8,6,10,6,12,
  	6,144,9,6,1,6,1,6,1,6,1,6,1,6,5,6,151,8,6,10,6,12,6,154,9,6,1,6,1,6,1,
  	6,5,6,159,8,6,10,6,12,6,162,9,6,3,6,164,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,179,8,7,1,8,5,8,182,8,8,10,8,12,8,185,9,
  	8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,197,8,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,5,10,205,8,10,10,10,12,10,208,9,10,1,10,1,10,5,10,212,
  	8,10,10,10,12,10,215,9,10,1,10,3,10,218,8,10,1,10,3,10,221,8,10,1,11,
  	1,11,1,11,1,11,1,11,1,11,5,11,229,8,11,10,11,12,11,232,9,11,1,11,1,11,
  	1,12,1,12,1,12,5,12,239,8,12,10,12,12,12,242,9,12,1,12,1,12,1,13,4,13,
  	247,8,13,11,13,12,13,248,1,13,3,13,252,8,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,5,14,260,8,14,10,14,12,14,263,9,14,1,14,3,14,266,8,14,1,14,0,0,15,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,0,300,0,33,1,0,0,0,2,49,1,0,
  	0,0,4,51,1,0,0,0,6,61,1,0,0,0,8,66,1,0,0,0,10,123,1,0,0,0,12,163,1,0,
  	0,0,14,178,1,0,0,0,16,183,1,0,0,0,18,196,1,0,0,0,20,220,1,0,0,0,22,222,
  	1,0,0,0,24,235,1,0,0,0,26,246,1,0,0,0,28,265,1,0,0,0,30,32,3,2,1,0,31,
  	30,1,0,0,0,32,35,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,36,1,0,0,0,35,
  	33,1,0,0,0,36,37,5,0,0,1,37,1,1,0,0,0,38,42,5,1,0,0,39,41,3,2,1,0,40,
  	39,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,45,1,0,0,0,44,
  	42,1,0,0,0,45,50,5,2,0,0,46,50,3,4,2,0,47,50,3,8,4,0,48,50,3,6,3,0,49,
  	38,1,0,0,0,49,46,1,0,0,0,49,47,1,0,0,0,49,48,1,0,0,0,50,3,1,0,0,0,51,
  	52,5,7,0,0,52,56,5,1,0,0,53,55,3,20,10,0,54,53,1,0,0,0,55,58,1,0,0,0,
  	56,54,1,0,0,0,56,57,1,0,0,0,57,59,1,0,0,0,58,56,1,0,0,0,59,60,5,2,0,0,
  	60,5,1,0,0,0,61,62,5,8,0,0,62,63,5,1,0,0,63,64,5,20,0,0,64,65,5,2,0,0,
  	65,7,1,0,0,0,66,67,5,9,0,0,67,71,5,1,0,0,68,70,3,10,5,0,69,68,1,0,0,0,
  	70,73,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,74,1,0,0,0,73,71,1,0,0,0,
  	74,75,5,2,0,0,75,9,1,0,0,0,76,77,5,10,0,0,77,81,5,1,0,0,78,80,3,12,6,
  	0,79,78,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,
  	0,83,81,1,0,0,0,84,124,5,2,0,0,85,86,5,11,0,0,86,87,3,14,7,0,87,91,5,
  	1,0,0,88,90,3,20,10,0,89,88,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,
  	1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,95,5,2,0,0,95,124,1,0,0,0,96,97,
  	5,12,0,0,97,98,3,14,7,0,98,102,5,1,0,0,99,101,3,20,10,0,100,99,1,0,0,
  	0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,105,1,0,0,0,104,
  	102,1,0,0,0,105,106,5,2,0,0,106,124,1,0,0,0,107,108,5,19,0,0,108,112,
  	5,1,0,0,109,111,3,20,10,0,110,109,1,0,0,0,111,114,1,0,0,0,112,110,1,0,
  	0,0,112,113,1,0,0,0,113,115,1,0,0,0,114,112,1,0,0,0,115,124,5,2,0,0,116,
  	120,5,19,0,0,117,119,3,14,7,0,118,117,1,0,0,0,119,122,1,0,0,0,120,118,
  	1,0,0,0,120,121,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,123,76,1,0,0,
  	0,123,85,1,0,0,0,123,96,1,0,0,0,123,107,1,0,0,0,123,116,1,0,0,0,124,11,
  	1,0,0,0,125,126,5,11,0,0,126,127,3,14,7,0,127,131,5,1,0,0,128,130,3,20,
  	10,0,129,128,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,
  	132,134,1,0,0,0,133,131,1,0,0,0,134,135,5,2,0,0,135,164,1,0,0,0,136,137,
  	5,12,0,0,137,138,3,14,7,0,138,142,5,1,0,0,139,141,3,20,10,0,140,139,1,
  	0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,145,1,0,0,0,
  	144,142,1,0,0,0,145,146,5,2,0,0,146,164,1,0,0,0,147,148,5,19,0,0,148,
  	152,5,1,0,0,149,151,3,20,10,0,150,149,1,0,0,0,151,154,1,0,0,0,152,150,
  	1,0,0,0,152,153,1,0,0,0,153,155,1,0,0,0,154,152,1,0,0,0,155,164,5,2,0,
  	0,156,160,5,19,0,0,157,159,3,14,7,0,158,157,1,0,0,0,159,162,1,0,0,0,160,
  	158,1,0,0,0,160,161,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,163,125,1,
  	0,0,0,163,136,1,0,0,0,163,147,1,0,0,0,163,156,1,0,0,0,164,13,1,0,0,0,
  	165,166,5,16,0,0,166,167,5,3,0,0,167,168,3,16,8,0,168,169,5,4,0,0,169,
  	179,1,0,0,0,170,171,5,3,0,0,171,172,3,16,8,0,172,173,5,4,0,0,173,179,
  	1,0,0,0,174,179,5,20,0,0,175,179,5,17,0,0,176,179,5,18,0,0,177,179,5,
  	19,0,0,178,165,1,0,0,0,178,170,1,0,0,0,178,174,1,0,0,0,178,175,1,0,0,
  	0,178,176,1,0,0,0,178,177,1,0,0,0,179,15,1,0,0,0,180,182,3,18,9,0,181,
  	180,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,17,1,
  	0,0,0,185,183,1,0,0,0,186,197,5,20,0,0,187,197,5,17,0,0,188,197,5,18,
  	0,0,189,197,5,19,0,0,190,197,5,16,0,0,191,192,5,3,0,0,192,193,3,16,8,
  	0,193,194,5,4,0,0,194,197,1,0,0,0,195,197,5,6,0,0,196,186,1,0,0,0,196,
  	187,1,0,0,0,196,188,1,0,0,0,196,189,1,0,0,0,196,190,1,0,0,0,196,191,1,
  	0,0,0,196,195,1,0,0,0,197,19,1,0,0,0,198,199,5,13,0,0,199,200,5,3,0,0,
  	200,201,3,16,8,0,201,202,5,4,0,0,202,206,5,1,0,0,203,205,3,20,10,0,204,
  	203,1,0,0,0,205,208,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,209,1,
  	0,0,0,208,206,1,0,0,0,209,213,5,2,0,0,210,212,3,22,11,0,211,210,1,0,0,
  	0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,217,1,0,0,0,215,
  	213,1,0,0,0,216,218,3,24,12,0,217,216,1,0,0,0,217,218,1,0,0,0,218,221,
  	1,0,0,0,219,221,3,26,13,0,220,198,1,0,0,0,220,219,1,0,0,0,221,21,1,0,
  	0,0,222,223,5,14,0,0,223,224,5,3,0,0,224,225,3,16,8,0,225,226,5,4,0,0,
  	226,230,5,1,0,0,227,229,3,20,10,0,228,227,1,0,0,0,229,232,1,0,0,0,230,
  	228,1,0,0,0,230,231,1,0,0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,234,5,
  	2,0,0,234,23,1,0,0,0,235,236,5,15,0,0,236,240,5,1,0,0,237,239,3,20,10,
  	0,238,237,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,
  	243,1,0,0,0,242,240,1,0,0,0,243,244,5,2,0,0,244,25,1,0,0,0,245,247,3,
  	28,14,0,246,245,1,0,0,0,247,248,1,0,0,0,248,246,1,0,0,0,248,249,1,0,0,
  	0,249,251,1,0,0,0,250,252,5,5,0,0,251,250,1,0,0,0,251,252,1,0,0,0,252,
  	27,1,0,0,0,253,266,5,20,0,0,254,266,5,17,0,0,255,266,5,18,0,0,256,266,
  	5,19,0,0,257,261,5,3,0,0,258,260,3,28,14,0,259,258,1,0,0,0,260,263,1,
  	0,0,0,261,259,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,0,263,261,1,0,0,0,
  	264,266,5,4,0,0,265,253,1,0,0,0,265,254,1,0,0,0,265,255,1,0,0,0,265,256,
  	1,0,0,0,265,257,1,0,0,0,266,29,1,0,0,0,29,33,42,49,56,71,81,91,102,112,
  	120,123,131,142,152,160,163,178,183,196,206,213,217,220,230,240,248,251,
  	261,265
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  menuParserStaticData = std::move(staticData);
}

}

MenuParser::MenuParser(TokenStream *input) : MenuParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MenuParser::MenuParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MenuParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *menuParserStaticData->atn, menuParserStaticData->decisionToDFA, menuParserStaticData->sharedContextCache, options);
}

MenuParser::~MenuParser() {
  delete _interpreter;
}

const atn::ATN& MenuParser::getATN() const {
  return *menuParserStaticData->atn;
}

std::string MenuParser::getGrammarFileName() const {
  return "Menu.g4";
}

const std::vector<std::string>& MenuParser::getRuleNames() const {
  return menuParserStaticData->ruleNames;
}

const dfa::Vocabulary& MenuParser::getVocabulary() const {
  return menuParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MenuParser::getSerializedATN() const {
  return menuParserStaticData->serializedATN;
}


//----------------- MenuFileContext ------------------------------------------------------------------

MenuParser::MenuFileContext::MenuFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::MenuFileContext::EOF() {
  return getToken(MenuParser::EOF, 0);
}

std::vector<MenuParser::MenuFilePartContext *> MenuParser::MenuFileContext::menuFilePart() {
  return getRuleContexts<MenuParser::MenuFilePartContext>();
}

MenuParser::MenuFilePartContext* MenuParser::MenuFileContext::menuFilePart(size_t i) {
  return getRuleContext<MenuParser::MenuFilePartContext>(i);
}


size_t MenuParser::MenuFileContext::getRuleIndex() const {
  return MenuParser::RuleMenuFile;
}

void MenuParser::MenuFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMenuFile(this);
}

void MenuParser::MenuFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMenuFile(this);
}

MenuParser::MenuFileContext* MenuParser::menuFile() {
  MenuFileContext *_localctx = _tracker.createInstance<MenuFileContext>(_ctx, getState());
  enterRule(_localctx, 0, MenuParser::RuleMenuFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 898) != 0)) {
      setState(30);
      menuFilePart();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    match(MenuParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MenuFilePartContext ------------------------------------------------------------------

MenuParser::MenuFilePartContext::MenuFilePartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MenuParser::MenuFilePartContext::getRuleIndex() const {
  return MenuParser::RuleMenuFilePart;
}

void MenuParser::MenuFilePartContext::copyFrom(MenuFilePartContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WrapperMenuFilePartContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::WrapperMenuFilePartContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::WrapperMenuFilePartContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::MenuFilePartContext *> MenuParser::WrapperMenuFilePartContext::menuFilePart() {
  return getRuleContexts<MenuParser::MenuFilePartContext>();
}

MenuParser::MenuFilePartContext* MenuParser::WrapperMenuFilePartContext::menuFilePart(size_t i) {
  return getRuleContext<MenuParser::MenuFilePartContext>(i);
}

MenuParser::WrapperMenuFilePartContext::WrapperMenuFilePartContext(MenuFilePartContext *ctx) { copyFrom(ctx); }

void MenuParser::WrapperMenuFilePartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWrapperMenuFilePart(this);
}
void MenuParser::WrapperMenuFilePartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWrapperMenuFilePart(this);
}
//----------------- FunctionDefMenuFilePartContext ------------------------------------------------------------------

MenuParser::FunctionDefContext* MenuParser::FunctionDefMenuFilePartContext::functionDef() {
  return getRuleContext<MenuParser::FunctionDefContext>(0);
}

MenuParser::FunctionDefMenuFilePartContext::FunctionDefMenuFilePartContext(MenuFilePartContext *ctx) { copyFrom(ctx); }

void MenuParser::FunctionDefMenuFilePartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefMenuFilePart(this);
}
void MenuParser::FunctionDefMenuFilePartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefMenuFilePart(this);
}
//----------------- MenuDefMenuFilePartContext ------------------------------------------------------------------

MenuParser::MenuDefContext* MenuParser::MenuDefMenuFilePartContext::menuDef() {
  return getRuleContext<MenuParser::MenuDefContext>(0);
}

MenuParser::MenuDefMenuFilePartContext::MenuDefMenuFilePartContext(MenuFilePartContext *ctx) { copyFrom(ctx); }

void MenuParser::MenuDefMenuFilePartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMenuDefMenuFilePart(this);
}
void MenuParser::MenuDefMenuFilePartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMenuDefMenuFilePart(this);
}
//----------------- LoadMenuMenuFilePartContext ------------------------------------------------------------------

MenuParser::LoadMenuContext* MenuParser::LoadMenuMenuFilePartContext::loadMenu() {
  return getRuleContext<MenuParser::LoadMenuContext>(0);
}

MenuParser::LoadMenuMenuFilePartContext::LoadMenuMenuFilePartContext(MenuFilePartContext *ctx) { copyFrom(ctx); }

void MenuParser::LoadMenuMenuFilePartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoadMenuMenuFilePart(this);
}
void MenuParser::LoadMenuMenuFilePartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoadMenuMenuFilePart(this);
}
MenuParser::MenuFilePartContext* MenuParser::menuFilePart() {
  MenuFilePartContext *_localctx = _tracker.createInstance<MenuFilePartContext>(_ctx, getState());
  enterRule(_localctx, 2, MenuParser::RuleMenuFilePart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MenuParser::LBRACE: {
        _localctx = _tracker.createInstance<MenuParser::WrapperMenuFilePartContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(38);
        match(MenuParser::LBRACE);
        setState(42);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 898) != 0)) {
          setState(39);
          menuFilePart();
          setState(44);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(45);
        match(MenuParser::RBRACE);
        break;
      }

      case MenuParser::FUNCTIONDEF: {
        _localctx = _tracker.createInstance<MenuParser::FunctionDefMenuFilePartContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(46);
        functionDef();
        break;
      }

      case MenuParser::MENUDEF: {
        _localctx = _tracker.createInstance<MenuParser::MenuDefMenuFilePartContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(47);
        menuDef();
        break;
      }

      case MenuParser::LOADMENU: {
        _localctx = _tracker.createInstance<MenuParser::LoadMenuMenuFilePartContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(48);
        loadMenu();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefContext ------------------------------------------------------------------

MenuParser::FunctionDefContext::FunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::FunctionDefContext::FUNCTIONDEF() {
  return getToken(MenuParser::FUNCTIONDEF, 0);
}

tree::TerminalNode* MenuParser::FunctionDefContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::FunctionDefContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::FunctionDefContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::FunctionDefContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}


size_t MenuParser::FunctionDefContext::getRuleIndex() const {
  return MenuParser::RuleFunctionDef;
}

void MenuParser::FunctionDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDef(this);
}

void MenuParser::FunctionDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDef(this);
}

MenuParser::FunctionDefContext* MenuParser::functionDef() {
  FunctionDefContext *_localctx = _tracker.createInstance<FunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MenuParser::RuleFunctionDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(MenuParser::FUNCTIONDEF);
    setState(52);
    match(MenuParser::LBRACE);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1974280) != 0)) {
      setState(53);
      block();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(MenuParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoadMenuContext ------------------------------------------------------------------

MenuParser::LoadMenuContext::LoadMenuContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::LoadMenuContext::LOADMENU() {
  return getToken(MenuParser::LOADMENU, 0);
}

tree::TerminalNode* MenuParser::LoadMenuContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::LoadMenuContext::STRING() {
  return getToken(MenuParser::STRING, 0);
}

tree::TerminalNode* MenuParser::LoadMenuContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}


size_t MenuParser::LoadMenuContext::getRuleIndex() const {
  return MenuParser::RuleLoadMenu;
}

void MenuParser::LoadMenuContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoadMenu(this);
}

void MenuParser::LoadMenuContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoadMenu(this);
}

MenuParser::LoadMenuContext* MenuParser::loadMenu() {
  LoadMenuContext *_localctx = _tracker.createInstance<LoadMenuContext>(_ctx, getState());
  enterRule(_localctx, 6, MenuParser::RuleLoadMenu);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(MenuParser::LOADMENU);
    setState(62);
    match(MenuParser::LBRACE);
    setState(63);
    match(MenuParser::STRING);
    setState(64);
    match(MenuParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MenuDefContext ------------------------------------------------------------------

MenuParser::MenuDefContext::MenuDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::MenuDefContext::MENUDEF() {
  return getToken(MenuParser::MENUDEF, 0);
}

tree::TerminalNode* MenuParser::MenuDefContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::MenuDefContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::MenuItemContext *> MenuParser::MenuDefContext::menuItem() {
  return getRuleContexts<MenuParser::MenuItemContext>();
}

MenuParser::MenuItemContext* MenuParser::MenuDefContext::menuItem(size_t i) {
  return getRuleContext<MenuParser::MenuItemContext>(i);
}


size_t MenuParser::MenuDefContext::getRuleIndex() const {
  return MenuParser::RuleMenuDef;
}

void MenuParser::MenuDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMenuDef(this);
}

void MenuParser::MenuDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMenuDef(this);
}

MenuParser::MenuDefContext* MenuParser::menuDef() {
  MenuDefContext *_localctx = _tracker.createInstance<MenuDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MenuParser::RuleMenuDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(MenuParser::MENUDEF);
    setState(67);
    match(MenuParser::LBRACE);
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 531456) != 0)) {
      setState(68);
      menuItem();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(MenuParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MenuItemContext ------------------------------------------------------------------

MenuParser::MenuItemContext::MenuItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MenuParser::MenuItemContext::getRuleIndex() const {
  return MenuParser::RuleMenuItem;
}

void MenuParser::MenuItemContext::copyFrom(MenuItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlockMenuItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::BlockMenuItemContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

tree::TerminalNode* MenuParser::BlockMenuItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::BlockMenuItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::BlockMenuItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::BlockMenuItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::BlockMenuItemContext::BlockMenuItemContext(MenuItemContext *ctx) { copyFrom(ctx); }

void MenuParser::BlockMenuItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockMenuItem(this);
}
void MenuParser::BlockMenuItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockMenuItem(this);
}
//----------------- ExecKeyIntMenuItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ExecKeyIntMenuItemContext::EXECKEYINT() {
  return getToken(MenuParser::EXECKEYINT, 0);
}

MenuParser::PropertyValueContext* MenuParser::ExecKeyIntMenuItemContext::propertyValue() {
  return getRuleContext<MenuParser::PropertyValueContext>(0);
}

tree::TerminalNode* MenuParser::ExecKeyIntMenuItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ExecKeyIntMenuItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ExecKeyIntMenuItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ExecKeyIntMenuItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::ExecKeyIntMenuItemContext::ExecKeyIntMenuItemContext(MenuItemContext *ctx) { copyFrom(ctx); }

void MenuParser::ExecKeyIntMenuItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecKeyIntMenuItem(this);
}
void MenuParser::ExecKeyIntMenuItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecKeyIntMenuItem(this);
}
//----------------- ExecKeyMenuItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ExecKeyMenuItemContext::EXECKEY() {
  return getToken(MenuParser::EXECKEY, 0);
}

MenuParser::PropertyValueContext* MenuParser::ExecKeyMenuItemContext::propertyValue() {
  return getRuleContext<MenuParser::PropertyValueContext>(0);
}

tree::TerminalNode* MenuParser::ExecKeyMenuItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ExecKeyMenuItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ExecKeyMenuItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ExecKeyMenuItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::ExecKeyMenuItemContext::ExecKeyMenuItemContext(MenuItemContext *ctx) { copyFrom(ctx); }

void MenuParser::ExecKeyMenuItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecKeyMenuItem(this);
}
void MenuParser::ExecKeyMenuItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecKeyMenuItem(this);
}
//----------------- PropertyMenuItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::PropertyMenuItemContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

std::vector<MenuParser::PropertyValueContext *> MenuParser::PropertyMenuItemContext::propertyValue() {
  return getRuleContexts<MenuParser::PropertyValueContext>();
}

MenuParser::PropertyValueContext* MenuParser::PropertyMenuItemContext::propertyValue(size_t i) {
  return getRuleContext<MenuParser::PropertyValueContext>(i);
}

MenuParser::PropertyMenuItemContext::PropertyMenuItemContext(MenuItemContext *ctx) { copyFrom(ctx); }

void MenuParser::PropertyMenuItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyMenuItem(this);
}
void MenuParser::PropertyMenuItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyMenuItem(this);
}
//----------------- ItemDefMenuItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ItemDefMenuItemContext::ITEMDEF() {
  return getToken(MenuParser::ITEMDEF, 0);
}

tree::TerminalNode* MenuParser::ItemDefMenuItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ItemDefMenuItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::ItemItemContext *> MenuParser::ItemDefMenuItemContext::itemItem() {
  return getRuleContexts<MenuParser::ItemItemContext>();
}

MenuParser::ItemItemContext* MenuParser::ItemDefMenuItemContext::itemItem(size_t i) {
  return getRuleContext<MenuParser::ItemItemContext>(i);
}

MenuParser::ItemDefMenuItemContext::ItemDefMenuItemContext(MenuItemContext *ctx) { copyFrom(ctx); }

void MenuParser::ItemDefMenuItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItemDefMenuItem(this);
}
void MenuParser::ItemDefMenuItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItemDefMenuItem(this);
}
MenuParser::MenuItemContext* MenuParser::menuItem() {
  MenuItemContext *_localctx = _tracker.createInstance<MenuItemContext>(_ctx, getState());
  enterRule(_localctx, 10, MenuParser::RuleMenuItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MenuParser::ItemDefMenuItemContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(76);
      match(MenuParser::ITEMDEF);
      setState(77);
      match(MenuParser::LBRACE);
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 530432) != 0)) {
        setState(78);
        itemItem();
        setState(83);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(84);
      match(MenuParser::RBRACE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MenuParser::ExecKeyMenuItemContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(85);
      match(MenuParser::EXECKEY);
      setState(86);
      propertyValue();
      setState(87);
      match(MenuParser::LBRACE);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(88);
        block();
        setState(93);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(94);
      match(MenuParser::RBRACE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MenuParser::ExecKeyIntMenuItemContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(96);
      match(MenuParser::EXECKEYINT);
      setState(97);
      propertyValue();
      setState(98);
      match(MenuParser::LBRACE);
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(99);
        block();
        setState(104);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(105);
      match(MenuParser::RBRACE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MenuParser::BlockMenuItemContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(107);
      match(MenuParser::IDENTIFIER);
      setState(108);
      match(MenuParser::LBRACE);
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(109);
        block();
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(115);
      match(MenuParser::RBRACE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MenuParser::PropertyMenuItemContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(116);
      match(MenuParser::IDENTIFIER);
      setState(120);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(117);
          propertyValue(); 
        }
        setState(122);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ItemItemContext ------------------------------------------------------------------

MenuParser::ItemItemContext::ItemItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MenuParser::ItemItemContext::getRuleIndex() const {
  return MenuParser::RuleItemItem;
}

void MenuParser::ItemItemContext::copyFrom(ItemItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PropertyItemItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::PropertyItemItemContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

std::vector<MenuParser::PropertyValueContext *> MenuParser::PropertyItemItemContext::propertyValue() {
  return getRuleContexts<MenuParser::PropertyValueContext>();
}

MenuParser::PropertyValueContext* MenuParser::PropertyItemItemContext::propertyValue(size_t i) {
  return getRuleContext<MenuParser::PropertyValueContext>(i);
}

MenuParser::PropertyItemItemContext::PropertyItemItemContext(ItemItemContext *ctx) { copyFrom(ctx); }

void MenuParser::PropertyItemItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyItemItem(this);
}
void MenuParser::PropertyItemItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyItemItem(this);
}
//----------------- ExecKeyItemItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ExecKeyItemItemContext::EXECKEY() {
  return getToken(MenuParser::EXECKEY, 0);
}

MenuParser::PropertyValueContext* MenuParser::ExecKeyItemItemContext::propertyValue() {
  return getRuleContext<MenuParser::PropertyValueContext>(0);
}

tree::TerminalNode* MenuParser::ExecKeyItemItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ExecKeyItemItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ExecKeyItemItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ExecKeyItemItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::ExecKeyItemItemContext::ExecKeyItemItemContext(ItemItemContext *ctx) { copyFrom(ctx); }

void MenuParser::ExecKeyItemItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecKeyItemItem(this);
}
void MenuParser::ExecKeyItemItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecKeyItemItem(this);
}
//----------------- BlockItemItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::BlockItemItemContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

tree::TerminalNode* MenuParser::BlockItemItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::BlockItemItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::BlockItemItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::BlockItemItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::BlockItemItemContext::BlockItemItemContext(ItemItemContext *ctx) { copyFrom(ctx); }

void MenuParser::BlockItemItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemItem(this);
}
void MenuParser::BlockItemItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemItem(this);
}
//----------------- ExecKeyIntItemItemContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ExecKeyIntItemItemContext::EXECKEYINT() {
  return getToken(MenuParser::EXECKEYINT, 0);
}

MenuParser::PropertyValueContext* MenuParser::ExecKeyIntItemItemContext::propertyValue() {
  return getRuleContext<MenuParser::PropertyValueContext>(0);
}

tree::TerminalNode* MenuParser::ExecKeyIntItemItemContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ExecKeyIntItemItemContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ExecKeyIntItemItemContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ExecKeyIntItemItemContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

MenuParser::ExecKeyIntItemItemContext::ExecKeyIntItemItemContext(ItemItemContext *ctx) { copyFrom(ctx); }

void MenuParser::ExecKeyIntItemItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecKeyIntItemItem(this);
}
void MenuParser::ExecKeyIntItemItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecKeyIntItemItem(this);
}
MenuParser::ItemItemContext* MenuParser::itemItem() {
  ItemItemContext *_localctx = _tracker.createInstance<ItemItemContext>(_ctx, getState());
  enterRule(_localctx, 12, MenuParser::RuleItemItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MenuParser::ExecKeyItemItemContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(125);
      match(MenuParser::EXECKEY);
      setState(126);
      propertyValue();
      setState(127);
      match(MenuParser::LBRACE);
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(128);
        block();
        setState(133);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(134);
      match(MenuParser::RBRACE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MenuParser::ExecKeyIntItemItemContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(136);
      match(MenuParser::EXECKEYINT);
      setState(137);
      propertyValue();
      setState(138);
      match(MenuParser::LBRACE);
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(139);
        block();
        setState(144);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(145);
      match(MenuParser::RBRACE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MenuParser::BlockItemItemContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(147);
      match(MenuParser::IDENTIFIER);
      setState(148);
      match(MenuParser::LBRACE);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1974280) != 0)) {
        setState(149);
        block();
        setState(154);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(155);
      match(MenuParser::RBRACE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MenuParser::PropertyItemItemContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(156);
      match(MenuParser::IDENTIFIER);
      setState(160);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(157);
          propertyValue(); 
        }
        setState(162);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyValueContext ------------------------------------------------------------------

MenuParser::PropertyValueContext::PropertyValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MenuParser::PropertyValueContext::getRuleIndex() const {
  return MenuParser::RulePropertyValue;
}

void MenuParser::PropertyValueContext::copyFrom(PropertyValueContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::StringPropertyValueContext::STRING() {
  return getToken(MenuParser::STRING, 0);
}

MenuParser::StringPropertyValueContext::StringPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::StringPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringPropertyValue(this);
}
void MenuParser::StringPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringPropertyValue(this);
}
//----------------- FloatPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::FloatPropertyValueContext::FLOAT() {
  return getToken(MenuParser::FLOAT, 0);
}

MenuParser::FloatPropertyValueContext::FloatPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::FloatPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatPropertyValue(this);
}
void MenuParser::FloatPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatPropertyValue(this);
}
//----------------- ExpressionPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::ExpressionPropertyValueContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

MenuParser::ExpressionContext* MenuParser::ExpressionPropertyValueContext::expression() {
  return getRuleContext<MenuParser::ExpressionContext>(0);
}

tree::TerminalNode* MenuParser::ExpressionPropertyValueContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

MenuParser::ExpressionPropertyValueContext::ExpressionPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::ExpressionPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionPropertyValue(this);
}
void MenuParser::ExpressionPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionPropertyValue(this);
}
//----------------- IdentifierPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::IdentifierPropertyValueContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

MenuParser::IdentifierPropertyValueContext::IdentifierPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::IdentifierPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierPropertyValue(this);
}
void MenuParser::IdentifierPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierPropertyValue(this);
}
//----------------- IntegerPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::IntegerPropertyValueContext::INTEGER() {
  return getToken(MenuParser::INTEGER, 0);
}

MenuParser::IntegerPropertyValueContext::IntegerPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::IntegerPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerPropertyValue(this);
}
void MenuParser::IntegerPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerPropertyValue(this);
}
//----------------- WhenPropertyValueContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::WhenPropertyValueContext::WHEN() {
  return getToken(MenuParser::WHEN, 0);
}

tree::TerminalNode* MenuParser::WhenPropertyValueContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

MenuParser::ExpressionContext* MenuParser::WhenPropertyValueContext::expression() {
  return getRuleContext<MenuParser::ExpressionContext>(0);
}

tree::TerminalNode* MenuParser::WhenPropertyValueContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

MenuParser::WhenPropertyValueContext::WhenPropertyValueContext(PropertyValueContext *ctx) { copyFrom(ctx); }

void MenuParser::WhenPropertyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenPropertyValue(this);
}
void MenuParser::WhenPropertyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenPropertyValue(this);
}
MenuParser::PropertyValueContext* MenuParser::propertyValue() {
  PropertyValueContext *_localctx = _tracker.createInstance<PropertyValueContext>(_ctx, getState());
  enterRule(_localctx, 14, MenuParser::RulePropertyValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MenuParser::WHEN: {
        _localctx = _tracker.createInstance<MenuParser::WhenPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(165);
        match(MenuParser::WHEN);
        setState(166);
        match(MenuParser::LPAREN);
        setState(167);
        expression();
        setState(168);
        match(MenuParser::RPAREN);
        break;
      }

      case MenuParser::LPAREN: {
        _localctx = _tracker.createInstance<MenuParser::ExpressionPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(170);
        match(MenuParser::LPAREN);
        setState(171);
        expression();
        setState(172);
        match(MenuParser::RPAREN);
        break;
      }

      case MenuParser::STRING: {
        _localctx = _tracker.createInstance<MenuParser::StringPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(174);
        match(MenuParser::STRING);
        break;
      }

      case MenuParser::FLOAT: {
        _localctx = _tracker.createInstance<MenuParser::FloatPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(175);
        match(MenuParser::FLOAT);
        break;
      }

      case MenuParser::INTEGER: {
        _localctx = _tracker.createInstance<MenuParser::IntegerPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(176);
        match(MenuParser::INTEGER);
        break;
      }

      case MenuParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<MenuParser::IdentifierPropertyValueContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(177);
        match(MenuParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MenuParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MenuParser::ExpressionPartContext *> MenuParser::ExpressionContext::expressionPart() {
  return getRuleContexts<MenuParser::ExpressionPartContext>();
}

MenuParser::ExpressionPartContext* MenuParser::ExpressionContext::expressionPart(size_t i) {
  return getRuleContext<MenuParser::ExpressionPartContext>(i);
}


size_t MenuParser::ExpressionContext::getRuleIndex() const {
  return MenuParser::RuleExpression;
}

void MenuParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void MenuParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

MenuParser::ExpressionContext* MenuParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, MenuParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2031688) != 0)) {
      setState(180);
      expressionPart();
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionPartContext ------------------------------------------------------------------

MenuParser::ExpressionPartContext::ExpressionPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::ExpressionPartContext::STRING() {
  return getToken(MenuParser::STRING, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::FLOAT() {
  return getToken(MenuParser::FLOAT, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::INTEGER() {
  return getToken(MenuParser::INTEGER, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::WHEN() {
  return getToken(MenuParser::WHEN, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

MenuParser::ExpressionContext* MenuParser::ExpressionPartContext::expression() {
  return getRuleContext<MenuParser::ExpressionContext>(0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

tree::TerminalNode* MenuParser::ExpressionPartContext::OP() {
  return getToken(MenuParser::OP, 0);
}


size_t MenuParser::ExpressionPartContext::getRuleIndex() const {
  return MenuParser::RuleExpressionPart;
}

void MenuParser::ExpressionPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionPart(this);
}

void MenuParser::ExpressionPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionPart(this);
}

MenuParser::ExpressionPartContext* MenuParser::expressionPart() {
  ExpressionPartContext *_localctx = _tracker.createInstance<ExpressionPartContext>(_ctx, getState());
  enterRule(_localctx, 18, MenuParser::RuleExpressionPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MenuParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        match(MenuParser::STRING);
        break;
      }

      case MenuParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        match(MenuParser::FLOAT);
        break;
      }

      case MenuParser::INTEGER: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        match(MenuParser::INTEGER);
        break;
      }

      case MenuParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(189);
        match(MenuParser::IDENTIFIER);
        break;
      }

      case MenuParser::WHEN: {
        enterOuterAlt(_localctx, 5);
        setState(190);
        match(MenuParser::WHEN);
        break;
      }

      case MenuParser::LPAREN: {
        enterOuterAlt(_localctx, 6);
        setState(191);
        match(MenuParser::LPAREN);
        setState(192);
        expression();
        setState(193);
        match(MenuParser::RPAREN);
        break;
      }

      case MenuParser::OP: {
        enterOuterAlt(_localctx, 7);
        setState(195);
        match(MenuParser::OP);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MenuParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MenuParser::BlockContext::getRuleIndex() const {
  return MenuParser::RuleBlock;
}

void MenuParser::BlockContext::copyFrom(BlockContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfBlockContext ------------------------------------------------------------------

tree::TerminalNode* MenuParser::IfBlockContext::IF() {
  return getToken(MenuParser::IF, 0);
}

tree::TerminalNode* MenuParser::IfBlockContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

MenuParser::ExpressionContext* MenuParser::IfBlockContext::expression() {
  return getRuleContext<MenuParser::ExpressionContext>(0);
}

tree::TerminalNode* MenuParser::IfBlockContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

tree::TerminalNode* MenuParser::IfBlockContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::IfBlockContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::IfBlockContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::IfBlockContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}

std::vector<MenuParser::ElseifClauseContext *> MenuParser::IfBlockContext::elseifClause() {
  return getRuleContexts<MenuParser::ElseifClauseContext>();
}

MenuParser::ElseifClauseContext* MenuParser::IfBlockContext::elseifClause(size_t i) {
  return getRuleContext<MenuParser::ElseifClauseContext>(i);
}

MenuParser::ElseClauseContext* MenuParser::IfBlockContext::elseClause() {
  return getRuleContext<MenuParser::ElseClauseContext>(0);
}

MenuParser::IfBlockContext::IfBlockContext(BlockContext *ctx) { copyFrom(ctx); }

void MenuParser::IfBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfBlock(this);
}
void MenuParser::IfBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfBlock(this);
}
//----------------- StatementBlockContext ------------------------------------------------------------------

MenuParser::BlockStatementContext* MenuParser::StatementBlockContext::blockStatement() {
  return getRuleContext<MenuParser::BlockStatementContext>(0);
}

MenuParser::StatementBlockContext::StatementBlockContext(BlockContext *ctx) { copyFrom(ctx); }

void MenuParser::StatementBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementBlock(this);
}
void MenuParser::StatementBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementBlock(this);
}
MenuParser::BlockContext* MenuParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, MenuParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MenuParser::IF: {
        _localctx = _tracker.createInstance<MenuParser::IfBlockContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(198);
        match(MenuParser::IF);
        setState(199);
        match(MenuParser::LPAREN);
        setState(200);
        expression();
        setState(201);
        match(MenuParser::RPAREN);
        setState(202);
        match(MenuParser::LBRACE);
        setState(206);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1974280) != 0)) {
          setState(203);
          block();
          setState(208);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(209);
        match(MenuParser::RBRACE);
        setState(213);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MenuParser::ELSEIF) {
          setState(210);
          elseifClause();
          setState(215);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(217);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MenuParser::ELSE) {
          setState(216);
          elseClause();
        }
        break;
      }

      case MenuParser::LPAREN:
      case MenuParser::FLOAT:
      case MenuParser::INTEGER:
      case MenuParser::IDENTIFIER:
      case MenuParser::STRING: {
        _localctx = _tracker.createInstance<MenuParser::StatementBlockContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(219);
        blockStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseifClauseContext ------------------------------------------------------------------

MenuParser::ElseifClauseContext::ElseifClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::ElseifClauseContext::ELSEIF() {
  return getToken(MenuParser::ELSEIF, 0);
}

tree::TerminalNode* MenuParser::ElseifClauseContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

MenuParser::ExpressionContext* MenuParser::ElseifClauseContext::expression() {
  return getRuleContext<MenuParser::ExpressionContext>(0);
}

tree::TerminalNode* MenuParser::ElseifClauseContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

tree::TerminalNode* MenuParser::ElseifClauseContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ElseifClauseContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ElseifClauseContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ElseifClauseContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}


size_t MenuParser::ElseifClauseContext::getRuleIndex() const {
  return MenuParser::RuleElseifClause;
}

void MenuParser::ElseifClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseifClause(this);
}

void MenuParser::ElseifClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseifClause(this);
}

MenuParser::ElseifClauseContext* MenuParser::elseifClause() {
  ElseifClauseContext *_localctx = _tracker.createInstance<ElseifClauseContext>(_ctx, getState());
  enterRule(_localctx, 22, MenuParser::RuleElseifClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(MenuParser::ELSEIF);
    setState(223);
    match(MenuParser::LPAREN);
    setState(224);
    expression();
    setState(225);
    match(MenuParser::RPAREN);
    setState(226);
    match(MenuParser::LBRACE);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1974280) != 0)) {
      setState(227);
      block();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(MenuParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseClauseContext ------------------------------------------------------------------

MenuParser::ElseClauseContext::ElseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::ElseClauseContext::ELSE() {
  return getToken(MenuParser::ELSE, 0);
}

tree::TerminalNode* MenuParser::ElseClauseContext::LBRACE() {
  return getToken(MenuParser::LBRACE, 0);
}

tree::TerminalNode* MenuParser::ElseClauseContext::RBRACE() {
  return getToken(MenuParser::RBRACE, 0);
}

std::vector<MenuParser::BlockContext *> MenuParser::ElseClauseContext::block() {
  return getRuleContexts<MenuParser::BlockContext>();
}

MenuParser::BlockContext* MenuParser::ElseClauseContext::block(size_t i) {
  return getRuleContext<MenuParser::BlockContext>(i);
}


size_t MenuParser::ElseClauseContext::getRuleIndex() const {
  return MenuParser::RuleElseClause;
}

void MenuParser::ElseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseClause(this);
}

void MenuParser::ElseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseClause(this);
}

MenuParser::ElseClauseContext* MenuParser::elseClause() {
  ElseClauseContext *_localctx = _tracker.createInstance<ElseClauseContext>(_ctx, getState());
  enterRule(_localctx, 24, MenuParser::RuleElseClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(MenuParser::ELSE);
    setState(236);
    match(MenuParser::LBRACE);
    setState(240);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1974280) != 0)) {
      setState(237);
      block();
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(243);
    match(MenuParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStatementContext ------------------------------------------------------------------

MenuParser::BlockStatementContext::BlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MenuParser::BlockTokenContext *> MenuParser::BlockStatementContext::blockToken() {
  return getRuleContexts<MenuParser::BlockTokenContext>();
}

MenuParser::BlockTokenContext* MenuParser::BlockStatementContext::blockToken(size_t i) {
  return getRuleContext<MenuParser::BlockTokenContext>(i);
}

tree::TerminalNode* MenuParser::BlockStatementContext::SEMICOLON() {
  return getToken(MenuParser::SEMICOLON, 0);
}


size_t MenuParser::BlockStatementContext::getRuleIndex() const {
  return MenuParser::RuleBlockStatement;
}

void MenuParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}

void MenuParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}

MenuParser::BlockStatementContext* MenuParser::blockStatement() {
  BlockStatementContext *_localctx = _tracker.createInstance<BlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, MenuParser::RuleBlockStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(246); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(245);
              blockToken();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(248); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MenuParser::SEMICOLON) {
      setState(250);
      match(MenuParser::SEMICOLON);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockTokenContext ------------------------------------------------------------------

MenuParser::BlockTokenContext::BlockTokenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MenuParser::BlockTokenContext::STRING() {
  return getToken(MenuParser::STRING, 0);
}

tree::TerminalNode* MenuParser::BlockTokenContext::FLOAT() {
  return getToken(MenuParser::FLOAT, 0);
}

tree::TerminalNode* MenuParser::BlockTokenContext::INTEGER() {
  return getToken(MenuParser::INTEGER, 0);
}

tree::TerminalNode* MenuParser::BlockTokenContext::IDENTIFIER() {
  return getToken(MenuParser::IDENTIFIER, 0);
}

tree::TerminalNode* MenuParser::BlockTokenContext::LPAREN() {
  return getToken(MenuParser::LPAREN, 0);
}

tree::TerminalNode* MenuParser::BlockTokenContext::RPAREN() {
  return getToken(MenuParser::RPAREN, 0);
}

std::vector<MenuParser::BlockTokenContext *> MenuParser::BlockTokenContext::blockToken() {
  return getRuleContexts<MenuParser::BlockTokenContext>();
}

MenuParser::BlockTokenContext* MenuParser::BlockTokenContext::blockToken(size_t i) {
  return getRuleContext<MenuParser::BlockTokenContext>(i);
}


size_t MenuParser::BlockTokenContext::getRuleIndex() const {
  return MenuParser::RuleBlockToken;
}

void MenuParser::BlockTokenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockToken(this);
}

void MenuParser::BlockTokenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MenuListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockToken(this);
}

MenuParser::BlockTokenContext* MenuParser::blockToken() {
  BlockTokenContext *_localctx = _tracker.createInstance<BlockTokenContext>(_ctx, getState());
  enterRule(_localctx, 28, MenuParser::RuleBlockToken);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MenuParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(253);
        match(MenuParser::STRING);
        break;
      }

      case MenuParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(254);
        match(MenuParser::FLOAT);
        break;
      }

      case MenuParser::INTEGER: {
        enterOuterAlt(_localctx, 3);
        setState(255);
        match(MenuParser::INTEGER);
        break;
      }

      case MenuParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(256);
        match(MenuParser::IDENTIFIER);
        break;
      }

      case MenuParser::LPAREN: {
        enterOuterAlt(_localctx, 5);
        setState(257);
        match(MenuParser::LPAREN);
        setState(261);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1966088) != 0)) {
          setState(258);
          blockToken();
          setState(263);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(264);
        match(MenuParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MenuParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  menuParserInitialize();
#else
  ::antlr4::internal::call_once(menuParserOnceFlag, menuParserInitialize);
#endif
}
