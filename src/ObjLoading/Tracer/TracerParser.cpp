
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Tracer/Tracer.g4 by ANTLR 4.13.2


#include "TracerListener.h"

#include "TracerParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TracerParserStaticData final {
  TracerParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TracerParserStaticData(const TracerParserStaticData&) = delete;
  TracerParserStaticData(TracerParserStaticData&&) = delete;
  TracerParserStaticData& operator=(const TracerParserStaticData&) = delete;
  TracerParserStaticData& operator=(TracerParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tracerParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<TracerParserStaticData> tracerParserStaticData = nullptr;

void tracerParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tracerParserStaticData != nullptr) {
    return;
  }
#else
  assert(tracerParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TracerParserStaticData>(
    std::vector<std::string>{
      "tracer", "pair", "key", "value"
    },
    std::vector<std::string>{
      "", "'TRACER'", "'\\'"
    },
    std::vector<std::string>{
      "", "TRACER", "BACKSLASH", "FLOAT", "INTEGER", "IDENTIFIER", "WS"
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
  tracerParserStaticData = std::move(staticData);
}

}

TracerParser::TracerParser(TokenStream *input) : TracerParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TracerParser::TracerParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TracerParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tracerParserStaticData->atn, tracerParserStaticData->decisionToDFA, tracerParserStaticData->sharedContextCache, options);
}

TracerParser::~TracerParser() {
  delete _interpreter;
}

const atn::ATN& TracerParser::getATN() const {
  return *tracerParserStaticData->atn;
}

std::string TracerParser::getGrammarFileName() const {
  return "Tracer.g4";
}

const std::vector<std::string>& TracerParser::getRuleNames() const {
  return tracerParserStaticData->ruleNames;
}

const dfa::Vocabulary& TracerParser::getVocabulary() const {
  return tracerParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TracerParser::getSerializedATN() const {
  return tracerParserStaticData->serializedATN;
}


//----------------- TracerContext ------------------------------------------------------------------

TracerParser::TracerContext::TracerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TracerParser::TracerContext::TRACER() {
  return getToken(TracerParser::TRACER, 0);
}

tree::TerminalNode* TracerParser::TracerContext::EOF() {
  return getToken(TracerParser::EOF, 0);
}

std::vector<TracerParser::PairContext *> TracerParser::TracerContext::pair() {
  return getRuleContexts<TracerParser::PairContext>();
}

TracerParser::PairContext* TracerParser::TracerContext::pair(size_t i) {
  return getRuleContext<TracerParser::PairContext>(i);
}


size_t TracerParser::TracerContext::getRuleIndex() const {
  return TracerParser::RuleTracer;
}

void TracerParser::TracerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTracer(this);
}

void TracerParser::TracerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTracer(this);
}

TracerParser::TracerContext* TracerParser::tracer() {
  TracerContext *_localctx = _tracker.createInstance<TracerContext>(_ctx, getState());
  enterRule(_localctx, 0, TracerParser::RuleTracer);
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
    match(TracerParser::TRACER);
    setState(12);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TracerParser::BACKSLASH) {
      setState(9);
      pair();
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(15);
    match(TracerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

TracerParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TracerParser::PairContext::BACKSLASH() {
  return getTokens(TracerParser::BACKSLASH);
}

tree::TerminalNode* TracerParser::PairContext::BACKSLASH(size_t i) {
  return getToken(TracerParser::BACKSLASH, i);
}

TracerParser::KeyContext* TracerParser::PairContext::key() {
  return getRuleContext<TracerParser::KeyContext>(0);
}

TracerParser::ValueContext* TracerParser::PairContext::value() {
  return getRuleContext<TracerParser::ValueContext>(0);
}


size_t TracerParser::PairContext::getRuleIndex() const {
  return TracerParser::RulePair;
}

void TracerParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void TracerParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

TracerParser::PairContext* TracerParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 2, TracerParser::RulePair);

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
    match(TracerParser::BACKSLASH);
    setState(18);
    key();
    setState(19);
    match(TracerParser::BACKSLASH);
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

TracerParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TracerParser::KeyContext::IDENTIFIER() {
  return getToken(TracerParser::IDENTIFIER, 0);
}


size_t TracerParser::KeyContext::getRuleIndex() const {
  return TracerParser::RuleKey;
}

void TracerParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void TracerParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

TracerParser::KeyContext* TracerParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 4, TracerParser::RuleKey);

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
    match(TracerParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

TracerParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TracerParser::ValueContext::FLOAT() {
  return getToken(TracerParser::FLOAT, 0);
}

tree::TerminalNode* TracerParser::ValueContext::INTEGER() {
  return getToken(TracerParser::INTEGER, 0);
}

tree::TerminalNode* TracerParser::ValueContext::IDENTIFIER() {
  return getToken(TracerParser::IDENTIFIER, 0);
}


size_t TracerParser::ValueContext::getRuleIndex() const {
  return TracerParser::RuleValue;
}

void TracerParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void TracerParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TracerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

TracerParser::ValueContext* TracerParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, TracerParser::RuleValue);

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
      case TracerParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(TracerParser::FLOAT);
        break;
      }

      case TracerParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(TracerParser::INTEGER);
        break;
      }

      case TracerParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(26);
        match(TracerParser::IDENTIFIER);
        break;
      }

      case TracerParser::EOF:
      case TracerParser::BACKSLASH: {
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

void TracerParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tracerParserInitialize();
#else
  ::antlr4::internal::call_once(tracerParserOnceFlag, tracerParserInitialize);
#endif
}
