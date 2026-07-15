
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/FlameTable/FlameTable.g4 by ANTLR 4.13.2


#include "FlameTableLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct FlameTableLexerStaticData final {
  FlameTableLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FlameTableLexerStaticData(const FlameTableLexerStaticData&) = delete;
  FlameTableLexerStaticData(FlameTableLexerStaticData&&) = delete;
  FlameTableLexerStaticData& operator=(const FlameTableLexerStaticData&) = delete;
  FlameTableLexerStaticData& operator=(FlameTableLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag flametablelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FlameTableLexerStaticData> flametablelexerLexerStaticData = nullptr;

void flametablelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (flametablelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(flametablelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FlameTableLexerStaticData>(
    std::vector<std::string>{
      "FLAMETABLEFILE", "BACKSLASH", "FLOAT", "INTEGER", "IDENTIFIER", "WS", 
      "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,6,82,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,
  	2,3,2,34,8,2,1,2,4,2,37,8,2,11,2,12,2,38,1,2,1,2,5,2,43,8,2,10,2,12,2,
  	46,9,2,1,2,3,2,49,8,2,1,2,1,2,4,2,53,8,2,11,2,12,2,54,3,2,57,8,2,1,3,
  	3,3,60,8,3,1,3,4,3,63,8,3,11,3,12,3,64,1,4,1,4,5,4,69,8,4,10,4,12,4,72,
  	9,4,1,5,4,5,75,8,5,11,5,12,5,76,1,5,1,5,1,6,1,6,0,0,7,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,0,1,0,4,3,0,65,90,95,95,97,122,5,0,46,46,48,57,65,90,95,95,
  	97,122,3,0,9,10,13,13,32,32,1,0,48,57,90,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,1,15,1,0,0,0,3,30,1,0,0,
  	0,5,56,1,0,0,0,7,59,1,0,0,0,9,66,1,0,0,0,11,74,1,0,0,0,13,80,1,0,0,0,
  	15,16,5,70,0,0,16,17,5,76,0,0,17,18,5,65,0,0,18,19,5,77,0,0,19,20,5,69,
  	0,0,20,21,5,84,0,0,21,22,5,65,0,0,22,23,5,66,0,0,23,24,5,76,0,0,24,25,
  	5,69,0,0,25,26,5,70,0,0,26,27,5,73,0,0,27,28,5,76,0,0,28,29,5,69,0,0,
  	29,2,1,0,0,0,30,31,5,92,0,0,31,4,1,0,0,0,32,34,5,45,0,0,33,32,1,0,0,0,
  	33,34,1,0,0,0,34,36,1,0,0,0,35,37,3,13,6,0,36,35,1,0,0,0,37,38,1,0,0,
  	0,38,36,1,0,0,0,38,39,1,0,0,0,39,40,1,0,0,0,40,44,5,46,0,0,41,43,3,13,
  	6,0,42,41,1,0,0,0,43,46,1,0,0,0,44,42,1,0,0,0,44,45,1,0,0,0,45,57,1,0,
  	0,0,46,44,1,0,0,0,47,49,5,45,0,0,48,47,1,0,0,0,48,49,1,0,0,0,49,50,1,
  	0,0,0,50,52,5,46,0,0,51,53,3,13,6,0,52,51,1,0,0,0,53,54,1,0,0,0,54,52,
  	1,0,0,0,54,55,1,0,0,0,55,57,1,0,0,0,56,33,1,0,0,0,56,48,1,0,0,0,57,6,
  	1,0,0,0,58,60,5,45,0,0,59,58,1,0,0,0,59,60,1,0,0,0,60,62,1,0,0,0,61,63,
  	3,13,6,0,62,61,1,0,0,0,63,64,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,0,65,8,
  	1,0,0,0,66,70,7,0,0,0,67,69,7,1,0,0,68,67,1,0,0,0,69,72,1,0,0,0,70,68,
  	1,0,0,0,70,71,1,0,0,0,71,10,1,0,0,0,72,70,1,0,0,0,73,75,7,2,0,0,74,73,
  	1,0,0,0,75,76,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,78,1,0,0,0,78,79,
  	6,5,0,0,79,12,1,0,0,0,80,81,7,3,0,0,81,14,1,0,0,0,11,0,33,38,44,48,54,
  	56,59,64,70,76,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  flametablelexerLexerStaticData = std::move(staticData);
}

}

FlameTableLexer::FlameTableLexer(CharStream *input) : Lexer(input) {
  FlameTableLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *flametablelexerLexerStaticData->atn, flametablelexerLexerStaticData->decisionToDFA, flametablelexerLexerStaticData->sharedContextCache);
}

FlameTableLexer::~FlameTableLexer() {
  delete _interpreter;
}

std::string FlameTableLexer::getGrammarFileName() const {
  return "FlameTable.g4";
}

const std::vector<std::string>& FlameTableLexer::getRuleNames() const {
  return flametablelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& FlameTableLexer::getChannelNames() const {
  return flametablelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& FlameTableLexer::getModeNames() const {
  return flametablelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& FlameTableLexer::getVocabulary() const {
  return flametablelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FlameTableLexer::getSerializedATN() const {
  return flametablelexerLexerStaticData->serializedATN;
}

const atn::ATN& FlameTableLexer::getATN() const {
  return *flametablelexerLexerStaticData->atn;
}




void FlameTableLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  flametablelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(flametablelexerLexerOnceFlag, flametablelexerLexerInitialize);
#endif
}
