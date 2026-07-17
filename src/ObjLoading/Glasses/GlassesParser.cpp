
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Glasses/Glasses.g4 by ANTLR 4.13.2


#include "GlassesListener.h"

#include "GlassesParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GlassesParserStaticData final {
  GlassesParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GlassesParserStaticData(const GlassesParserStaticData&) = delete;
  GlassesParserStaticData(GlassesParserStaticData&&) = delete;
  GlassesParserStaticData& operator=(const GlassesParserStaticData&) = delete;
  GlassesParserStaticData& operator=(GlassesParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag glassesParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GlassesParserStaticData> glassesParserStaticData = nullptr;

void glassesParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (glassesParserStaticData != nullptr) {
    return;
  }
#else
  assert(glassesParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GlassesParserStaticData>(
    std::vector<std::string>{
      "glassesFile", "entry", "key", "firstValue", "rest"
    },
    std::vector<std::string>{
      "", "", "','"
    },
    std::vector<std::string>{
      "", "COMMENT", "COMMA", "NEWLINE", "INTEGER", "IDENTIFIER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,43,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,5,0,12,8,0,10,0,
  	12,0,15,9,0,1,0,1,0,1,1,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,1,1,
  	1,1,1,3,1,31,8,1,1,2,1,2,1,3,1,3,3,3,37,8,3,1,4,1,4,3,4,41,8,4,1,4,0,
  	0,5,0,2,4,6,8,0,0,42,0,13,1,0,0,0,2,30,1,0,0,0,4,32,1,0,0,0,6,36,1,0,
  	0,0,8,38,1,0,0,0,10,12,3,2,1,0,11,10,1,0,0,0,12,15,1,0,0,0,13,11,1,0,
  	0,0,13,14,1,0,0,0,14,16,1,0,0,0,15,13,1,0,0,0,16,17,5,0,0,1,17,1,1,0,
  	0,0,18,19,3,4,2,0,19,20,5,2,0,0,20,24,3,6,3,0,21,23,3,8,4,0,22,21,1,0,
  	0,0,23,26,1,0,0,0,24,22,1,0,0,0,24,25,1,0,0,0,25,27,1,0,0,0,26,24,1,0,
  	0,0,27,28,5,3,0,0,28,31,1,0,0,0,29,31,5,3,0,0,30,18,1,0,0,0,30,29,1,0,
  	0,0,31,3,1,0,0,0,32,33,5,5,0,0,33,5,1,0,0,0,34,37,5,4,0,0,35,37,1,0,0,
  	0,36,34,1,0,0,0,36,35,1,0,0,0,37,7,1,0,0,0,38,40,5,2,0,0,39,41,5,4,0,
  	0,40,39,1,0,0,0,40,41,1,0,0,0,41,9,1,0,0,0,5,13,24,30,36,40
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  glassesParserStaticData = std::move(staticData);
}

}

GlassesParser::GlassesParser(TokenStream *input) : GlassesParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GlassesParser::GlassesParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GlassesParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *glassesParserStaticData->atn, glassesParserStaticData->decisionToDFA, glassesParserStaticData->sharedContextCache, options);
}

GlassesParser::~GlassesParser() {
  delete _interpreter;
}

const atn::ATN& GlassesParser::getATN() const {
  return *glassesParserStaticData->atn;
}

std::string GlassesParser::getGrammarFileName() const {
  return "Glasses.g4";
}

const std::vector<std::string>& GlassesParser::getRuleNames() const {
  return glassesParserStaticData->ruleNames;
}

const dfa::Vocabulary& GlassesParser::getVocabulary() const {
  return glassesParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GlassesParser::getSerializedATN() const {
  return glassesParserStaticData->serializedATN;
}


//----------------- GlassesFileContext ------------------------------------------------------------------

GlassesParser::GlassesFileContext::GlassesFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlassesParser::GlassesFileContext::EOF() {
  return getToken(GlassesParser::EOF, 0);
}

std::vector<GlassesParser::EntryContext *> GlassesParser::GlassesFileContext::entry() {
  return getRuleContexts<GlassesParser::EntryContext>();
}

GlassesParser::EntryContext* GlassesParser::GlassesFileContext::entry(size_t i) {
  return getRuleContext<GlassesParser::EntryContext>(i);
}


size_t GlassesParser::GlassesFileContext::getRuleIndex() const {
  return GlassesParser::RuleGlassesFile;
}

void GlassesParser::GlassesFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlassesFile(this);
}

void GlassesParser::GlassesFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlassesFile(this);
}

GlassesParser::GlassesFileContext* GlassesParser::glassesFile() {
  GlassesFileContext *_localctx = _tracker.createInstance<GlassesFileContext>(_ctx, getState());
  enterRule(_localctx, 0, GlassesParser::RuleGlassesFile);
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
    setState(13);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GlassesParser::NEWLINE

    || _la == GlassesParser::IDENTIFIER) {
      setState(10);
      entry();
      setState(15);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(16);
    match(GlassesParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntryContext ------------------------------------------------------------------

GlassesParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlassesParser::KeyContext* GlassesParser::EntryContext::key() {
  return getRuleContext<GlassesParser::KeyContext>(0);
}

tree::TerminalNode* GlassesParser::EntryContext::COMMA() {
  return getToken(GlassesParser::COMMA, 0);
}

GlassesParser::FirstValueContext* GlassesParser::EntryContext::firstValue() {
  return getRuleContext<GlassesParser::FirstValueContext>(0);
}

tree::TerminalNode* GlassesParser::EntryContext::NEWLINE() {
  return getToken(GlassesParser::NEWLINE, 0);
}

std::vector<GlassesParser::RestContext *> GlassesParser::EntryContext::rest() {
  return getRuleContexts<GlassesParser::RestContext>();
}

GlassesParser::RestContext* GlassesParser::EntryContext::rest(size_t i) {
  return getRuleContext<GlassesParser::RestContext>(i);
}


size_t GlassesParser::EntryContext::getRuleIndex() const {
  return GlassesParser::RuleEntry;
}

void GlassesParser::EntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry(this);
}

void GlassesParser::EntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry(this);
}

GlassesParser::EntryContext* GlassesParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 2, GlassesParser::RuleEntry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(30);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlassesParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(18);
        key();
        setState(19);
        match(GlassesParser::COMMA);
        setState(20);
        firstValue();
        setState(24);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GlassesParser::COMMA) {
          setState(21);
          rest();
          setState(26);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(27);
        match(GlassesParser::NEWLINE);
        break;
      }

      case GlassesParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(29);
        match(GlassesParser::NEWLINE);
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

//----------------- KeyContext ------------------------------------------------------------------

GlassesParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlassesParser::KeyContext::IDENTIFIER() {
  return getToken(GlassesParser::IDENTIFIER, 0);
}


size_t GlassesParser::KeyContext::getRuleIndex() const {
  return GlassesParser::RuleKey;
}

void GlassesParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void GlassesParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

GlassesParser::KeyContext* GlassesParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 4, GlassesParser::RuleKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(GlassesParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FirstValueContext ------------------------------------------------------------------

GlassesParser::FirstValueContext::FirstValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlassesParser::FirstValueContext::INTEGER() {
  return getToken(GlassesParser::INTEGER, 0);
}


size_t GlassesParser::FirstValueContext::getRuleIndex() const {
  return GlassesParser::RuleFirstValue;
}

void GlassesParser::FirstValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstValue(this);
}

void GlassesParser::FirstValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstValue(this);
}

GlassesParser::FirstValueContext* GlassesParser::firstValue() {
  FirstValueContext *_localctx = _tracker.createInstance<FirstValueContext>(_ctx, getState());
  enterRule(_localctx, 6, GlassesParser::RuleFirstValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlassesParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(GlassesParser::INTEGER);
        break;
      }

      case GlassesParser::COMMA:
      case GlassesParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);

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

//----------------- RestContext ------------------------------------------------------------------

GlassesParser::RestContext::RestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlassesParser::RestContext::COMMA() {
  return getToken(GlassesParser::COMMA, 0);
}

tree::TerminalNode* GlassesParser::RestContext::INTEGER() {
  return getToken(GlassesParser::INTEGER, 0);
}


size_t GlassesParser::RestContext::getRuleIndex() const {
  return GlassesParser::RuleRest;
}

void GlassesParser::RestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRest(this);
}

void GlassesParser::RestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GlassesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRest(this);
}

GlassesParser::RestContext* GlassesParser::rest() {
  RestContext *_localctx = _tracker.createInstance<RestContext>(_ctx, getState());
  enterRule(_localctx, 8, GlassesParser::RuleRest);
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
    setState(38);
    match(GlassesParser::COMMA);
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlassesParser::INTEGER) {
      setState(39);
      match(GlassesParser::INTEGER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void GlassesParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  glassesParserInitialize();
#else
  ::antlr4::internal::call_once(glassesParserOnceFlag, glassesParserInitialize);
#endif
}
