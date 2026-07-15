
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/PhysConstraints/PhysConstraints.g4 by ANTLR 4.13.2


#include "PhysConstraintsListener.h"

#include "PhysConstraintsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PhysConstraintsParserStaticData final {
  PhysConstraintsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PhysConstraintsParserStaticData(const PhysConstraintsParserStaticData&) = delete;
  PhysConstraintsParserStaticData(PhysConstraintsParserStaticData&&) = delete;
  PhysConstraintsParserStaticData& operator=(const PhysConstraintsParserStaticData&) = delete;
  PhysConstraintsParserStaticData& operator=(PhysConstraintsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag physconstraintsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PhysConstraintsParserStaticData> physconstraintsParserStaticData = nullptr;

void physconstraintsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (physconstraintsParserStaticData != nullptr) {
    return;
  }
#else
  assert(physconstraintsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PhysConstraintsParserStaticData>(
    std::vector<std::string>{
      "physConstraints", "pair", "key", "value"
    },
    std::vector<std::string>{
      "", "'PHYSCONSTRAINTS'", "'\\'"
    },
    std::vector<std::string>{
      "", "PHYSCONSTRAINTS", "BACKSLASH", "FLOAT", "INTEGER", "IDENTIFIER", 
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
  physconstraintsParserStaticData = std::move(staticData);
}

}

PhysConstraintsParser::PhysConstraintsParser(TokenStream *input) : PhysConstraintsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PhysConstraintsParser::PhysConstraintsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PhysConstraintsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *physconstraintsParserStaticData->atn, physconstraintsParserStaticData->decisionToDFA, physconstraintsParserStaticData->sharedContextCache, options);
}

PhysConstraintsParser::~PhysConstraintsParser() {
  delete _interpreter;
}

const atn::ATN& PhysConstraintsParser::getATN() const {
  return *physconstraintsParserStaticData->atn;
}

std::string PhysConstraintsParser::getGrammarFileName() const {
  return "PhysConstraints.g4";
}

const std::vector<std::string>& PhysConstraintsParser::getRuleNames() const {
  return physconstraintsParserStaticData->ruleNames;
}

const dfa::Vocabulary& PhysConstraintsParser::getVocabulary() const {
  return physconstraintsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PhysConstraintsParser::getSerializedATN() const {
  return physconstraintsParserStaticData->serializedATN;
}


//----------------- PhysConstraintsContext ------------------------------------------------------------------

PhysConstraintsParser::PhysConstraintsContext::PhysConstraintsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PhysConstraintsParser::PhysConstraintsContext::PHYSCONSTRAINTS() {
  return getToken(PhysConstraintsParser::PHYSCONSTRAINTS, 0);
}

tree::TerminalNode* PhysConstraintsParser::PhysConstraintsContext::EOF() {
  return getToken(PhysConstraintsParser::EOF, 0);
}

std::vector<PhysConstraintsParser::PairContext *> PhysConstraintsParser::PhysConstraintsContext::pair() {
  return getRuleContexts<PhysConstraintsParser::PairContext>();
}

PhysConstraintsParser::PairContext* PhysConstraintsParser::PhysConstraintsContext::pair(size_t i) {
  return getRuleContext<PhysConstraintsParser::PairContext>(i);
}


size_t PhysConstraintsParser::PhysConstraintsContext::getRuleIndex() const {
  return PhysConstraintsParser::RulePhysConstraints;
}

void PhysConstraintsParser::PhysConstraintsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhysConstraints(this);
}

void PhysConstraintsParser::PhysConstraintsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhysConstraints(this);
}

PhysConstraintsParser::PhysConstraintsContext* PhysConstraintsParser::physConstraints() {
  PhysConstraintsContext *_localctx = _tracker.createInstance<PhysConstraintsContext>(_ctx, getState());
  enterRule(_localctx, 0, PhysConstraintsParser::RulePhysConstraints);
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
    match(PhysConstraintsParser::PHYSCONSTRAINTS);
    setState(12);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PhysConstraintsParser::BACKSLASH) {
      setState(9);
      pair();
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(15);
    match(PhysConstraintsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

PhysConstraintsParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PhysConstraintsParser::PairContext::BACKSLASH() {
  return getTokens(PhysConstraintsParser::BACKSLASH);
}

tree::TerminalNode* PhysConstraintsParser::PairContext::BACKSLASH(size_t i) {
  return getToken(PhysConstraintsParser::BACKSLASH, i);
}

PhysConstraintsParser::KeyContext* PhysConstraintsParser::PairContext::key() {
  return getRuleContext<PhysConstraintsParser::KeyContext>(0);
}

PhysConstraintsParser::ValueContext* PhysConstraintsParser::PairContext::value() {
  return getRuleContext<PhysConstraintsParser::ValueContext>(0);
}


size_t PhysConstraintsParser::PairContext::getRuleIndex() const {
  return PhysConstraintsParser::RulePair;
}

void PhysConstraintsParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void PhysConstraintsParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

PhysConstraintsParser::PairContext* PhysConstraintsParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 2, PhysConstraintsParser::RulePair);

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
    match(PhysConstraintsParser::BACKSLASH);
    setState(18);
    key();
    setState(19);
    match(PhysConstraintsParser::BACKSLASH);
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

PhysConstraintsParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PhysConstraintsParser::KeyContext::IDENTIFIER() {
  return getToken(PhysConstraintsParser::IDENTIFIER, 0);
}


size_t PhysConstraintsParser::KeyContext::getRuleIndex() const {
  return PhysConstraintsParser::RuleKey;
}

void PhysConstraintsParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void PhysConstraintsParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

PhysConstraintsParser::KeyContext* PhysConstraintsParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 4, PhysConstraintsParser::RuleKey);

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
    match(PhysConstraintsParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

PhysConstraintsParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PhysConstraintsParser::ValueContext::FLOAT() {
  return getToken(PhysConstraintsParser::FLOAT, 0);
}

tree::TerminalNode* PhysConstraintsParser::ValueContext::INTEGER() {
  return getToken(PhysConstraintsParser::INTEGER, 0);
}

tree::TerminalNode* PhysConstraintsParser::ValueContext::IDENTIFIER() {
  return getToken(PhysConstraintsParser::IDENTIFIER, 0);
}


size_t PhysConstraintsParser::ValueContext::getRuleIndex() const {
  return PhysConstraintsParser::RuleValue;
}

void PhysConstraintsParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void PhysConstraintsParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PhysConstraintsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

PhysConstraintsParser::ValueContext* PhysConstraintsParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, PhysConstraintsParser::RuleValue);

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
      case PhysConstraintsParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(PhysConstraintsParser::FLOAT);
        break;
      }

      case PhysConstraintsParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(PhysConstraintsParser::INTEGER);
        break;
      }

      case PhysConstraintsParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(26);
        match(PhysConstraintsParser::IDENTIFIER);
        break;
      }

      case PhysConstraintsParser::EOF:
      case PhysConstraintsParser::BACKSLASH: {
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

void PhysConstraintsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  physconstraintsParserInitialize();
#else
  ::antlr4::internal::call_once(physconstraintsParserOnceFlag, physconstraintsParserInitialize);
#endif
}
