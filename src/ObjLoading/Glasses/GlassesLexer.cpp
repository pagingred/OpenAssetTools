
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Glasses/Glasses.g4 by ANTLR 4.13.2


#include "GlassesLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct GlassesLexerStaticData final {
  GlassesLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GlassesLexerStaticData(const GlassesLexerStaticData&) = delete;
  GlassesLexerStaticData(GlassesLexerStaticData&&) = delete;
  GlassesLexerStaticData& operator=(const GlassesLexerStaticData&) = delete;
  GlassesLexerStaticData& operator=(GlassesLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag glasseslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GlassesLexerStaticData> glasseslexerLexerStaticData = nullptr;

void glasseslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (glasseslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(glasseslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GlassesLexerStaticData>(
    std::vector<std::string>{
      "COMMENT", "COMMA", "NEWLINE", "INTEGER", "IDENTIFIER", "WS", "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "','"
    },
    std::vector<std::string>{
      "", "COMMENT", "COMMA", "NEWLINE", "INTEGER", "IDENTIFIER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,52,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	1,0,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,0,1,0,1,1,1,1,1,2,3,2,28,8,2,1,
  	2,1,2,1,3,4,3,33,8,3,11,3,12,3,34,1,4,1,4,5,4,39,8,4,10,4,12,4,42,9,4,
  	1,5,4,5,45,8,5,11,5,12,5,46,1,5,1,5,1,6,1,6,0,0,7,1,1,3,2,5,3,7,4,9,5,
  	11,6,13,0,1,0,5,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,
  	95,95,97,122,2,0,9,9,32,32,1,0,48,57,55,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,
  	0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,1,15,1,0,0,0,3,24,1,0,0,0,
  	5,27,1,0,0,0,7,32,1,0,0,0,9,36,1,0,0,0,11,44,1,0,0,0,13,50,1,0,0,0,15,
  	19,5,35,0,0,16,18,8,0,0,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,1,0,0,0,19,
  	20,1,0,0,0,20,22,1,0,0,0,21,19,1,0,0,0,22,23,6,0,0,0,23,2,1,0,0,0,24,
  	25,5,44,0,0,25,4,1,0,0,0,26,28,5,13,0,0,27,26,1,0,0,0,27,28,1,0,0,0,28,
  	29,1,0,0,0,29,30,5,10,0,0,30,6,1,0,0,0,31,33,3,13,6,0,32,31,1,0,0,0,33,
  	34,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,0,35,8,1,0,0,0,36,40,7,1,0,0,37,
  	39,7,2,0,0,38,37,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,
  	10,1,0,0,0,42,40,1,0,0,0,43,45,7,3,0,0,44,43,1,0,0,0,45,46,1,0,0,0,46,
  	44,1,0,0,0,46,47,1,0,0,0,47,48,1,0,0,0,48,49,6,5,0,0,49,12,1,0,0,0,50,
  	51,7,4,0,0,51,14,1,0,0,0,6,0,19,27,34,40,46,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  glasseslexerLexerStaticData = std::move(staticData);
}

}

GlassesLexer::GlassesLexer(CharStream *input) : Lexer(input) {
  GlassesLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *glasseslexerLexerStaticData->atn, glasseslexerLexerStaticData->decisionToDFA, glasseslexerLexerStaticData->sharedContextCache);
}

GlassesLexer::~GlassesLexer() {
  delete _interpreter;
}

std::string GlassesLexer::getGrammarFileName() const {
  return "Glasses.g4";
}

const std::vector<std::string>& GlassesLexer::getRuleNames() const {
  return glasseslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& GlassesLexer::getChannelNames() const {
  return glasseslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& GlassesLexer::getModeNames() const {
  return glasseslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& GlassesLexer::getVocabulary() const {
  return glasseslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GlassesLexer::getSerializedATN() const {
  return glasseslexerLexerStaticData->serializedATN;
}

const atn::ATN& GlassesLexer::getATN() const {
  return *glasseslexerLexerStaticData->atn;
}




void GlassesLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  glasseslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(glasseslexerLexerOnceFlag, glasseslexerLexerInitialize);
#endif
}
