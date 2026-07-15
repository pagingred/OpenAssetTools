
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Vehicle/Vehicle.g4 by ANTLR 4.13.2


#include "VehicleListener.h"

#include "VehicleParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VehicleParserStaticData final {
  VehicleParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VehicleParserStaticData(const VehicleParserStaticData&) = delete;
  VehicleParserStaticData(VehicleParserStaticData&&) = delete;
  VehicleParserStaticData& operator=(const VehicleParserStaticData&) = delete;
  VehicleParserStaticData& operator=(VehicleParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag vehicleParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<VehicleParserStaticData> vehicleParserStaticData = nullptr;

void vehicleParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vehicleParserStaticData != nullptr) {
    return;
  }
#else
  assert(vehicleParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VehicleParserStaticData>(
    std::vector<std::string>{
      "vehicle", "pair", "key", "value"
    },
    std::vector<std::string>{
      "", "'VEHICLEFILE'", "'\\'", "'4 wheel'"
    },
    std::vector<std::string>{
      "", "VEHICLEFILE", "BACKSLASH", "FOUR_WHEEL", "FLOAT", "INTEGER", 
      "IDENTIFIER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,7,32,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,5,0,11,8,0,10,0,12,0,
  	14,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,3,3,30,
  	8,3,1,3,0,0,4,0,2,4,6,0,0,32,0,8,1,0,0,0,2,17,1,0,0,0,4,22,1,0,0,0,6,
  	29,1,0,0,0,8,12,5,1,0,0,9,11,3,2,1,0,10,9,1,0,0,0,11,14,1,0,0,0,12,10,
  	1,0,0,0,12,13,1,0,0,0,13,15,1,0,0,0,14,12,1,0,0,0,15,16,5,0,0,1,16,1,
  	1,0,0,0,17,18,5,2,0,0,18,19,3,4,2,0,19,20,5,2,0,0,20,21,3,6,3,0,21,3,
  	1,0,0,0,22,23,5,6,0,0,23,5,1,0,0,0,24,30,5,4,0,0,25,30,5,5,0,0,26,30,
  	5,6,0,0,27,30,5,3,0,0,28,30,1,0,0,0,29,24,1,0,0,0,29,25,1,0,0,0,29,26,
  	1,0,0,0,29,27,1,0,0,0,29,28,1,0,0,0,30,7,1,0,0,0,2,12,29
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vehicleParserStaticData = std::move(staticData);
}

}

VehicleParser::VehicleParser(TokenStream *input) : VehicleParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VehicleParser::VehicleParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VehicleParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vehicleParserStaticData->atn, vehicleParserStaticData->decisionToDFA, vehicleParserStaticData->sharedContextCache, options);
}

VehicleParser::~VehicleParser() {
  delete _interpreter;
}

const atn::ATN& VehicleParser::getATN() const {
  return *vehicleParserStaticData->atn;
}

std::string VehicleParser::getGrammarFileName() const {
  return "Vehicle.g4";
}

const std::vector<std::string>& VehicleParser::getRuleNames() const {
  return vehicleParserStaticData->ruleNames;
}

const dfa::Vocabulary& VehicleParser::getVocabulary() const {
  return vehicleParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VehicleParser::getSerializedATN() const {
  return vehicleParserStaticData->serializedATN;
}


//----------------- VehicleContext ------------------------------------------------------------------

VehicleParser::VehicleContext::VehicleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VehicleParser::VehicleContext::VEHICLEFILE() {
  return getToken(VehicleParser::VEHICLEFILE, 0);
}

tree::TerminalNode* VehicleParser::VehicleContext::EOF() {
  return getToken(VehicleParser::EOF, 0);
}

std::vector<VehicleParser::PairContext *> VehicleParser::VehicleContext::pair() {
  return getRuleContexts<VehicleParser::PairContext>();
}

VehicleParser::PairContext* VehicleParser::VehicleContext::pair(size_t i) {
  return getRuleContext<VehicleParser::PairContext>(i);
}


size_t VehicleParser::VehicleContext::getRuleIndex() const {
  return VehicleParser::RuleVehicle;
}

void VehicleParser::VehicleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVehicle(this);
}

void VehicleParser::VehicleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVehicle(this);
}

VehicleParser::VehicleContext* VehicleParser::vehicle() {
  VehicleContext *_localctx = _tracker.createInstance<VehicleContext>(_ctx, getState());
  enterRule(_localctx, 0, VehicleParser::RuleVehicle);
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
    match(VehicleParser::VEHICLEFILE);
    setState(12);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == VehicleParser::BACKSLASH) {
      setState(9);
      pair();
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(15);
    match(VehicleParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

VehicleParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> VehicleParser::PairContext::BACKSLASH() {
  return getTokens(VehicleParser::BACKSLASH);
}

tree::TerminalNode* VehicleParser::PairContext::BACKSLASH(size_t i) {
  return getToken(VehicleParser::BACKSLASH, i);
}

VehicleParser::KeyContext* VehicleParser::PairContext::key() {
  return getRuleContext<VehicleParser::KeyContext>(0);
}

VehicleParser::ValueContext* VehicleParser::PairContext::value() {
  return getRuleContext<VehicleParser::ValueContext>(0);
}


size_t VehicleParser::PairContext::getRuleIndex() const {
  return VehicleParser::RulePair;
}

void VehicleParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void VehicleParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

VehicleParser::PairContext* VehicleParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 2, VehicleParser::RulePair);

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
    match(VehicleParser::BACKSLASH);
    setState(18);
    key();
    setState(19);
    match(VehicleParser::BACKSLASH);
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

VehicleParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VehicleParser::KeyContext::IDENTIFIER() {
  return getToken(VehicleParser::IDENTIFIER, 0);
}


size_t VehicleParser::KeyContext::getRuleIndex() const {
  return VehicleParser::RuleKey;
}

void VehicleParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void VehicleParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

VehicleParser::KeyContext* VehicleParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 4, VehicleParser::RuleKey);

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
    match(VehicleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

VehicleParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VehicleParser::ValueContext::FLOAT() {
  return getToken(VehicleParser::FLOAT, 0);
}

tree::TerminalNode* VehicleParser::ValueContext::INTEGER() {
  return getToken(VehicleParser::INTEGER, 0);
}

tree::TerminalNode* VehicleParser::ValueContext::IDENTIFIER() {
  return getToken(VehicleParser::IDENTIFIER, 0);
}

tree::TerminalNode* VehicleParser::ValueContext::FOUR_WHEEL() {
  return getToken(VehicleParser::FOUR_WHEEL, 0);
}


size_t VehicleParser::ValueContext::getRuleIndex() const {
  return VehicleParser::RuleValue;
}

void VehicleParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void VehicleParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VehicleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

VehicleParser::ValueContext* VehicleParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, VehicleParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(29);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VehicleParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(VehicleParser::FLOAT);
        break;
      }

      case VehicleParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(VehicleParser::INTEGER);
        break;
      }

      case VehicleParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(26);
        match(VehicleParser::IDENTIFIER);
        break;
      }

      case VehicleParser::FOUR_WHEEL: {
        enterOuterAlt(_localctx, 4);
        setState(27);
        match(VehicleParser::FOUR_WHEEL);
        break;
      }

      case VehicleParser::EOF:
      case VehicleParser::BACKSLASH: {
        enterOuterAlt(_localctx, 5);

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

void VehicleParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vehicleParserInitialize();
#else
  ::antlr4::internal::call_once(vehicleParserOnceFlag, vehicleParserInitialize);
#endif
}
