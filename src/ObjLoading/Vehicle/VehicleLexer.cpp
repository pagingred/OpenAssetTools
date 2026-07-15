
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Vehicle/Vehicle.g4 by ANTLR 4.13.2


#include "VehicleLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct VehicleLexerStaticData final {
  VehicleLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VehicleLexerStaticData(const VehicleLexerStaticData&) = delete;
  VehicleLexerStaticData(VehicleLexerStaticData&&) = delete;
  VehicleLexerStaticData& operator=(const VehicleLexerStaticData&) = delete;
  VehicleLexerStaticData& operator=(VehicleLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag vehiclelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<VehicleLexerStaticData> vehiclelexerLexerStaticData = nullptr;

void vehiclelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vehiclelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(vehiclelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VehicleLexerStaticData>(
    std::vector<std::string>{
      "VEHICLEFILE", "BACKSLASH", "FOUR_WHEEL", "FLOAT", "INTEGER", "IDENTIFIER", 
      "WS", "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,7,89,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,3,3,41,8,3,1,3,4,3,44,8,3,11,3,12,3,45,
  	1,3,1,3,5,3,50,8,3,10,3,12,3,53,9,3,1,3,3,3,56,8,3,1,3,1,3,4,3,60,8,3,
  	11,3,12,3,61,3,3,64,8,3,1,4,3,4,67,8,4,1,4,4,4,70,8,4,11,4,12,4,71,1,
  	5,1,5,5,5,76,8,5,10,5,12,5,79,9,5,1,6,4,6,82,8,6,11,6,12,6,83,1,6,1,6,
  	1,7,1,7,0,0,8,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,0,1,0,4,3,0,65,90,95,95,
  	97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,1,0,48,57,97,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,1,17,1,0,0,0,3,29,1,0,0,0,5,31,1,0,0,0,7,63,1,0,0,0,
  	9,66,1,0,0,0,11,73,1,0,0,0,13,81,1,0,0,0,15,87,1,0,0,0,17,18,5,86,0,0,
  	18,19,5,69,0,0,19,20,5,72,0,0,20,21,5,73,0,0,21,22,5,67,0,0,22,23,5,76,
  	0,0,23,24,5,69,0,0,24,25,5,70,0,0,25,26,5,73,0,0,26,27,5,76,0,0,27,28,
  	5,69,0,0,28,2,1,0,0,0,29,30,5,92,0,0,30,4,1,0,0,0,31,32,5,52,0,0,32,33,
  	5,32,0,0,33,34,5,119,0,0,34,35,5,104,0,0,35,36,5,101,0,0,36,37,5,101,
  	0,0,37,38,5,108,0,0,38,6,1,0,0,0,39,41,5,45,0,0,40,39,1,0,0,0,40,41,1,
  	0,0,0,41,43,1,0,0,0,42,44,3,15,7,0,43,42,1,0,0,0,44,45,1,0,0,0,45,43,
  	1,0,0,0,45,46,1,0,0,0,46,47,1,0,0,0,47,51,5,46,0,0,48,50,3,15,7,0,49,
  	48,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,64,1,0,0,0,53,
  	51,1,0,0,0,54,56,5,45,0,0,55,54,1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,57,
  	59,5,46,0,0,58,60,3,15,7,0,59,58,1,0,0,0,60,61,1,0,0,0,61,59,1,0,0,0,
  	61,62,1,0,0,0,62,64,1,0,0,0,63,40,1,0,0,0,63,55,1,0,0,0,64,8,1,0,0,0,
  	65,67,5,45,0,0,66,65,1,0,0,0,66,67,1,0,0,0,67,69,1,0,0,0,68,70,3,15,7,
  	0,69,68,1,0,0,0,70,71,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,10,1,0,0,
  	0,73,77,7,0,0,0,74,76,7,1,0,0,75,74,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,
  	0,77,78,1,0,0,0,78,12,1,0,0,0,79,77,1,0,0,0,80,82,7,2,0,0,81,80,1,0,0,
  	0,82,83,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,85,1,0,0,0,85,86,6,6,0,
  	0,86,14,1,0,0,0,87,88,7,3,0,0,88,16,1,0,0,0,11,0,40,45,51,55,61,63,66,
  	71,77,83,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vehiclelexerLexerStaticData = std::move(staticData);
}

}

VehicleLexer::VehicleLexer(CharStream *input) : Lexer(input) {
  VehicleLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *vehiclelexerLexerStaticData->atn, vehiclelexerLexerStaticData->decisionToDFA, vehiclelexerLexerStaticData->sharedContextCache);
}

VehicleLexer::~VehicleLexer() {
  delete _interpreter;
}

std::string VehicleLexer::getGrammarFileName() const {
  return "Vehicle.g4";
}

const std::vector<std::string>& VehicleLexer::getRuleNames() const {
  return vehiclelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& VehicleLexer::getChannelNames() const {
  return vehiclelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& VehicleLexer::getModeNames() const {
  return vehiclelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& VehicleLexer::getVocabulary() const {
  return vehiclelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VehicleLexer::getSerializedATN() const {
  return vehiclelexerLexerStaticData->serializedATN;
}

const atn::ATN& VehicleLexer::getATN() const {
  return *vehiclelexerLexerStaticData->atn;
}




void VehicleLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vehiclelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(vehiclelexerLexerOnceFlag, vehiclelexerLexerInitialize);
#endif
}
