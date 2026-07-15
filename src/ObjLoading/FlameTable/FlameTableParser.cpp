
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/FlameTable/FlameTable.g4 by ANTLR 4.13.2


#include "FlameTableListener.h"

#include "FlameTableParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FlameTableParserStaticData final {
  FlameTableParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FlameTableParserStaticData(const FlameTableParserStaticData&) = delete;
  FlameTableParserStaticData(FlameTableParserStaticData&&) = delete;
  FlameTableParserStaticData& operator=(const FlameTableParserStaticData&) = delete;
  FlameTableParserStaticData& operator=(FlameTableParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag flametableParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FlameTableParserStaticData> flametableParserStaticData = nullptr;

void flametableParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (flametableParserStaticData != nullptr) {
    return;
  }
#else
  assert(flametableParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FlameTableParserStaticData>(
    std::vector<std::string>{
      "flameTable", "pair", "key", "value"
    },
    std::vector<std::string>{
      "", "'FLAMETABLEFILE'", "'\\'"
    },
    std::vector<std::string>{
      "", "FLAMETABLEFILE", "BACKSLASH", "FLOAT", "INTEGER", "IDENTIFIER", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,31,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,5,0,11,8,0,10,0,12,0,
  	14,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,3,3,29,8,3,
  	1,3,0,0,4,0,2,4,6,0,0,30,0,8,1,0,0,0,2,17,1,0,0,0,4,22,1,0,0,0,6,28,1,
  	0,0,0,8,12,5,1,0,0,9,11,3,2,1,0,10,9,1,0,0,0,11,14,1,0,0,0,12,10,1,0,
  	0,0,12,13,1,0,0,0,13,15,1,0,0,0,14,12,1,0,0,0,15,16,5,0,0,1,16,1,1,0,
  	0,0,17,18,5,2,0,0,18,19,3,4,2,0,19,20,5,2,0,0,20,21,3,6,3,0,21,3,1,0,
  	0,0,22,23,5,5,0,0,23,5,1,0,0,0,24,29,5,3,0,0,25,29,5,4,0,0,26,29,5,5,
  	0,0,27,29,1,0,0,0,28,24,1,0,0,0,28,25,1,0,0,0,28,26,1,0,0,0,28,27,1,0,
  	0,0,29,7,1,0,0,0,2,12,28
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  flametableParserStaticData = std::move(staticData);
}

}

FlameTableParser::FlameTableParser(TokenStream *input) : FlameTableParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FlameTableParser::FlameTableParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FlameTableParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *flametableParserStaticData->atn, flametableParserStaticData->decisionToDFA, flametableParserStaticData->sharedContextCache, options);
}

FlameTableParser::~FlameTableParser() {
  delete _interpreter;
}

const atn::ATN& FlameTableParser::getATN() const {
  return *flametableParserStaticData->atn;
}

std::string FlameTableParser::getGrammarFileName() const {
  return "FlameTable.g4";
}

const std::vector<std::string>& FlameTableParser::getRuleNames() const {
  return flametableParserStaticData->ruleNames;
}

const dfa::Vocabulary& FlameTableParser::getVocabulary() const {
  return flametableParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FlameTableParser::getSerializedATN() const {
  return flametableParserStaticData->serializedATN;
}


//----------------- FlameTableContext ------------------------------------------------------------------

FlameTableParser::FlameTableContext::FlameTableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlameTableParser::FlameTableContext::FLAMETABLEFILE() {
  return getToken(FlameTableParser::FLAMETABLEFILE, 0);
}

tree::TerminalNode* FlameTableParser::FlameTableContext::EOF() {
  return getToken(FlameTableParser::EOF, 0);
}

std::vector<FlameTableParser::PairContext *> FlameTableParser::FlameTableContext::pair() {
  return getRuleContexts<FlameTableParser::PairContext>();
}

FlameTableParser::PairContext* FlameTableParser::FlameTableContext::pair(size_t i) {
  return getRuleContext<FlameTableParser::PairContext>(i);
}


size_t FlameTableParser::FlameTableContext::getRuleIndex() const {
  return FlameTableParser::RuleFlameTable;
}

void FlameTableParser::FlameTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlameTable(this);
}

void FlameTableParser::FlameTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlameTable(this);
}

FlameTableParser::FlameTableContext* FlameTableParser::flameTable() {
  FlameTableContext *_localctx = _tracker.createInstance<FlameTableContext>(_ctx, getState());
  enterRule(_localctx, 0, FlameTableParser::RuleFlameTable);
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
    setState(8);
    match(FlameTableParser::FLAMETABLEFILE);
    setState(12);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlameTableParser::BACKSLASH) {
      setState(9);
      pair();
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(15);
    match(FlameTableParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

FlameTableParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FlameTableParser::PairContext::BACKSLASH() {
  return getTokens(FlameTableParser::BACKSLASH);
}

tree::TerminalNode* FlameTableParser::PairContext::BACKSLASH(size_t i) {
  return getToken(FlameTableParser::BACKSLASH, i);
}

FlameTableParser::KeyContext* FlameTableParser::PairContext::key() {
  return getRuleContext<FlameTableParser::KeyContext>(0);
}

FlameTableParser::ValueContext* FlameTableParser::PairContext::value() {
  return getRuleContext<FlameTableParser::ValueContext>(0);
}


size_t FlameTableParser::PairContext::getRuleIndex() const {
  return FlameTableParser::RulePair;
}

void FlameTableParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void FlameTableParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

FlameTableParser::PairContext* FlameTableParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 2, FlameTableParser::RulePair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(FlameTableParser::BACKSLASH);
    setState(18);
    key();
    setState(19);
    match(FlameTableParser::BACKSLASH);
    setState(20);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyContext ------------------------------------------------------------------

FlameTableParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlameTableParser::KeyContext::IDENTIFIER() {
  return getToken(FlameTableParser::IDENTIFIER, 0);
}


size_t FlameTableParser::KeyContext::getRuleIndex() const {
  return FlameTableParser::RuleKey;
}

void FlameTableParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void FlameTableParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

FlameTableParser::KeyContext* FlameTableParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 4, FlameTableParser::RuleKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    match(FlameTableParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

FlameTableParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlameTableParser::ValueContext::FLOAT() {
  return getToken(FlameTableParser::FLOAT, 0);
}

tree::TerminalNode* FlameTableParser::ValueContext::INTEGER() {
  return getToken(FlameTableParser::INTEGER, 0);
}

tree::TerminalNode* FlameTableParser::ValueContext::IDENTIFIER() {
  return getToken(FlameTableParser::IDENTIFIER, 0);
}


size_t FlameTableParser::ValueContext::getRuleIndex() const {
  return FlameTableParser::RuleValue;
}

void FlameTableParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void FlameTableParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FlameTableListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

FlameTableParser::ValueContext* FlameTableParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, FlameTableParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlameTableParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(FlameTableParser::FLOAT);
        break;
      }

      case FlameTableParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(FlameTableParser::INTEGER);
        break;
      }

      case FlameTableParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(26);
        match(FlameTableParser::IDENTIFIER);
        break;
      }

      case FlameTableParser::EOF:
      case FlameTableParser::BACKSLASH: {
        enterOuterAlt(_localctx, 4);

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

void FlameTableParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  flametableParserInitialize();
#else
  ::antlr4::internal::call_once(flametableParserOnceFlag, flametableParserInitialize);
#endif
}
