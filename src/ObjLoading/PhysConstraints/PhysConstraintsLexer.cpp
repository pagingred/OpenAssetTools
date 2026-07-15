
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/PhysConstraints/PhysConstraints.g4 by ANTLR 4.13.2


#include "PhysConstraintsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PhysConstraintsLexerStaticData final {
  PhysConstraintsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PhysConstraintsLexerStaticData(const PhysConstraintsLexerStaticData&) = delete;
  PhysConstraintsLexerStaticData(PhysConstraintsLexerStaticData&&) = delete;
  PhysConstraintsLexerStaticData& operator=(const PhysConstraintsLexerStaticData&) = delete;
  PhysConstraintsLexerStaticData& operator=(PhysConstraintsLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag physconstraintslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PhysConstraintsLexerStaticData> physconstraintslexerLexerStaticData = nullptr;

void physconstraintslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (physconstraintslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(physconstraintslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PhysConstraintsLexerStaticData>(
    std::vector<std::string>{
      "PHYSCONSTRAINTS", "BACKSLASH", "FLOAT", "INTEGER", "IDENTIFIER", 
      "WS", "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,6,83,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,
  	1,1,2,3,2,35,8,2,1,2,4,2,38,8,2,11,2,12,2,39,1,2,1,2,5,2,44,8,2,10,2,
  	12,2,47,9,2,1,2,3,2,50,8,2,1,2,1,2,4,2,54,8,2,11,2,12,2,55,3,2,58,8,2,
  	1,3,3,3,61,8,3,1,3,4,3,64,8,3,11,3,12,3,65,1,4,1,4,5,4,70,8,4,10,4,12,
  	4,73,9,4,1,5,4,5,76,8,5,11,5,12,5,77,1,5,1,5,1,6,1,6,0,0,7,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,0,1,0,4,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,
  	97,122,3,0,9,10,13,13,32,32,1,0,48,57,91,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,1,15,1,0,0,0,3,31,1,0,0,
  	0,5,57,1,0,0,0,7,60,1,0,0,0,9,67,1,0,0,0,11,75,1,0,0,0,13,81,1,0,0,0,
  	15,16,5,80,0,0,16,17,5,72,0,0,17,18,5,89,0,0,18,19,5,83,0,0,19,20,5,67,
  	0,0,20,21,5,79,0,0,21,22,5,78,0,0,22,23,5,83,0,0,23,24,5,84,0,0,24,25,
  	5,82,0,0,25,26,5,65,0,0,26,27,5,73,0,0,27,28,5,78,0,0,28,29,5,84,0,0,
  	29,30,5,83,0,0,30,2,1,0,0,0,31,32,5,92,0,0,32,4,1,0,0,0,33,35,5,45,0,
  	0,34,33,1,0,0,0,34,35,1,0,0,0,35,37,1,0,0,0,36,38,3,13,6,0,37,36,1,0,
  	0,0,38,39,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,41,1,0,0,0,41,45,5,46,
  	0,0,42,44,3,13,6,0,43,42,1,0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,45,46,1,
  	0,0,0,46,58,1,0,0,0,47,45,1,0,0,0,48,50,5,45,0,0,49,48,1,0,0,0,49,50,
  	1,0,0,0,50,51,1,0,0,0,51,53,5,46,0,0,52,54,3,13,6,0,53,52,1,0,0,0,54,
  	55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,58,1,0,0,0,57,34,1,0,0,0,57,
  	49,1,0,0,0,58,6,1,0,0,0,59,61,5,45,0,0,60,59,1,0,0,0,60,61,1,0,0,0,61,
  	63,1,0,0,0,62,64,3,13,6,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,0,65,
  	66,1,0,0,0,66,8,1,0,0,0,67,71,7,0,0,0,68,70,7,1,0,0,69,68,1,0,0,0,70,
  	73,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,10,1,0,0,0,73,71,1,0,0,0,74,
  	76,7,2,0,0,75,74,1,0,0,0,76,77,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,
  	79,1,0,0,0,79,80,6,5,0,0,80,12,1,0,0,0,81,82,7,3,0,0,82,14,1,0,0,0,11,
  	0,34,39,45,49,55,57,60,65,71,77,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  physconstraintslexerLexerStaticData = std::move(staticData);
}

}

PhysConstraintsLexer::PhysConstraintsLexer(CharStream *input) : Lexer(input) {
  PhysConstraintsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *physconstraintslexerLexerStaticData->atn, physconstraintslexerLexerStaticData->decisionToDFA, physconstraintslexerLexerStaticData->sharedContextCache);
}

PhysConstraintsLexer::~PhysConstraintsLexer() {
  delete _interpreter;
}

std::string PhysConstraintsLexer::getGrammarFileName() const {
  return "PhysConstraints.g4";
}

const std::vector<std::string>& PhysConstraintsLexer::getRuleNames() const {
  return physconstraintslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PhysConstraintsLexer::getChannelNames() const {
  return physconstraintslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PhysConstraintsLexer::getModeNames() const {
  return physconstraintslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PhysConstraintsLexer::getVocabulary() const {
  return physconstraintslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PhysConstraintsLexer::getSerializedATN() const {
  return physconstraintslexerLexerStaticData->serializedATN;
}

const atn::ATN& PhysConstraintsLexer::getATN() const {
  return *physconstraintslexerLexerStaticData->atn;
}




void PhysConstraintsLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  physconstraintslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(physconstraintslexerLexerOnceFlag, physconstraintslexerLexerInitialize);
#endif
}
