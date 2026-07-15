
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2


#include "MenuLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MenuLexerStaticData final {
  MenuLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MenuLexerStaticData(const MenuLexerStaticData&) = delete;
  MenuLexerStaticData(MenuLexerStaticData&&) = delete;
  MenuLexerStaticData& operator=(const MenuLexerStaticData&) = delete;
  MenuLexerStaticData& operator=(MenuLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag menulexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MenuLexerStaticData> menulexerLexerStaticData = nullptr;

void menulexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (menulexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(menulexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MenuLexerStaticData>(
    std::vector<std::string>{
      "LBRACE", "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "OP", "FUNCTIONDEF", 
      "LOADMENU", "MENUDEF", "ITEMDEF", "EXECKEY", "EXECKEYINT", "IF", "ELSEIF", 
      "ELSE", "WHEN", "FLOAT", "INTEGER", "IDENTIFIER", "STRING", "WS", 
      "LINECOMMENT", "BLOCKCOMMENT", "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,23,240,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,77,
  	8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,
  	16,3,16,156,8,16,1,16,4,16,159,8,16,11,16,12,16,160,1,16,1,16,5,16,165,
  	8,16,10,16,12,16,168,9,16,1,16,3,16,171,8,16,1,16,1,16,4,16,175,8,16,
  	11,16,12,16,176,3,16,179,8,16,1,17,3,17,182,8,17,1,17,4,17,185,8,17,11,
  	17,12,17,186,1,18,1,18,5,18,191,8,18,10,18,12,18,194,9,18,1,19,1,19,1,
  	19,1,19,5,19,200,8,19,10,19,12,19,203,9,19,1,19,1,19,1,20,4,20,208,8,
  	20,11,20,12,20,209,1,20,1,20,1,21,1,21,1,21,1,21,5,21,218,8,21,10,21,
  	12,21,221,9,21,1,21,1,21,1,22,1,22,1,22,1,22,5,22,229,8,22,10,22,12,22,
  	232,9,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,230,0,24,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,
  	17,35,18,37,19,39,20,41,21,43,22,45,23,47,0,1,0,7,9,0,33,33,37,38,42,
  	43,45,45,47,47,60,60,62,62,124,124,126,126,3,0,65,90,95,95,97,122,5,0,
  	46,46,48,57,65,90,95,95,97,122,4,0,10,10,13,13,34,34,92,92,3,0,9,10,13,
  	13,32,32,2,0,10,10,13,13,1,0,48,57,260,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,
  	0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,
  	0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,
  	1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,
  	0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,1,49,1,0,0,0,
  	3,51,1,0,0,0,5,53,1,0,0,0,7,55,1,0,0,0,9,57,1,0,0,0,11,76,1,0,0,0,13,
  	78,1,0,0,0,15,90,1,0,0,0,17,99,1,0,0,0,19,107,1,0,0,0,21,115,1,0,0,0,
  	23,123,1,0,0,0,25,134,1,0,0,0,27,137,1,0,0,0,29,144,1,0,0,0,31,149,1,
  	0,0,0,33,178,1,0,0,0,35,181,1,0,0,0,37,188,1,0,0,0,39,195,1,0,0,0,41,
  	207,1,0,0,0,43,213,1,0,0,0,45,224,1,0,0,0,47,238,1,0,0,0,49,50,5,123,
  	0,0,50,2,1,0,0,0,51,52,5,125,0,0,52,4,1,0,0,0,53,54,5,40,0,0,54,6,1,0,
  	0,0,55,56,5,41,0,0,56,8,1,0,0,0,57,58,5,59,0,0,58,10,1,0,0,0,59,60,5,
  	38,0,0,60,77,5,38,0,0,61,62,5,124,0,0,62,77,5,124,0,0,63,64,5,61,0,0,
  	64,77,5,61,0,0,65,66,5,33,0,0,66,77,5,61,0,0,67,68,5,60,0,0,68,77,5,61,
  	0,0,69,70,5,62,0,0,70,77,5,61,0,0,71,72,5,60,0,0,72,77,5,60,0,0,73,74,
  	5,62,0,0,74,77,5,62,0,0,75,77,7,0,0,0,76,59,1,0,0,0,76,61,1,0,0,0,76,
  	63,1,0,0,0,76,65,1,0,0,0,76,67,1,0,0,0,76,69,1,0,0,0,76,71,1,0,0,0,76,
  	73,1,0,0,0,76,75,1,0,0,0,77,12,1,0,0,0,78,79,5,102,0,0,79,80,5,117,0,
  	0,80,81,5,110,0,0,81,82,5,99,0,0,82,83,5,116,0,0,83,84,5,105,0,0,84,85,
  	5,111,0,0,85,86,5,110,0,0,86,87,5,68,0,0,87,88,5,101,0,0,88,89,5,102,
  	0,0,89,14,1,0,0,0,90,91,5,108,0,0,91,92,5,111,0,0,92,93,5,97,0,0,93,94,
  	5,100,0,0,94,95,5,77,0,0,95,96,5,101,0,0,96,97,5,110,0,0,97,98,5,117,
  	0,0,98,16,1,0,0,0,99,100,5,109,0,0,100,101,5,101,0,0,101,102,5,110,0,
  	0,102,103,5,117,0,0,103,104,5,68,0,0,104,105,5,101,0,0,105,106,5,102,
  	0,0,106,18,1,0,0,0,107,108,5,105,0,0,108,109,5,116,0,0,109,110,5,101,
  	0,0,110,111,5,109,0,0,111,112,5,68,0,0,112,113,5,101,0,0,113,114,5,102,
  	0,0,114,20,1,0,0,0,115,116,5,101,0,0,116,117,5,120,0,0,117,118,5,101,
  	0,0,118,119,5,99,0,0,119,120,5,75,0,0,120,121,5,101,0,0,121,122,5,121,
  	0,0,122,22,1,0,0,0,123,124,5,101,0,0,124,125,5,120,0,0,125,126,5,101,
  	0,0,126,127,5,99,0,0,127,128,5,75,0,0,128,129,5,101,0,0,129,130,5,121,
  	0,0,130,131,5,73,0,0,131,132,5,110,0,0,132,133,5,116,0,0,133,24,1,0,0,
  	0,134,135,5,105,0,0,135,136,5,102,0,0,136,26,1,0,0,0,137,138,5,101,0,
  	0,138,139,5,108,0,0,139,140,5,115,0,0,140,141,5,101,0,0,141,142,5,105,
  	0,0,142,143,5,102,0,0,143,28,1,0,0,0,144,145,5,101,0,0,145,146,5,108,
  	0,0,146,147,5,115,0,0,147,148,5,101,0,0,148,30,1,0,0,0,149,150,5,119,
  	0,0,150,151,5,104,0,0,151,152,5,101,0,0,152,153,5,110,0,0,153,32,1,0,
  	0,0,154,156,5,45,0,0,155,154,1,0,0,0,155,156,1,0,0,0,156,158,1,0,0,0,
  	157,159,3,47,23,0,158,157,1,0,0,0,159,160,1,0,0,0,160,158,1,0,0,0,160,
  	161,1,0,0,0,161,162,1,0,0,0,162,166,5,46,0,0,163,165,3,47,23,0,164,163,
  	1,0,0,0,165,168,1,0,0,0,166,164,1,0,0,0,166,167,1,0,0,0,167,179,1,0,0,
  	0,168,166,1,0,0,0,169,171,5,45,0,0,170,169,1,0,0,0,170,171,1,0,0,0,171,
  	172,1,0,0,0,172,174,5,46,0,0,173,175,3,47,23,0,174,173,1,0,0,0,175,176,
  	1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,0,178,155,1,0,0,
  	0,178,170,1,0,0,0,179,34,1,0,0,0,180,182,5,45,0,0,181,180,1,0,0,0,181,
  	182,1,0,0,0,182,184,1,0,0,0,183,185,3,47,23,0,184,183,1,0,0,0,185,186,
  	1,0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,36,1,0,0,0,188,192,7,1,0,
  	0,189,191,7,2,0,0,190,189,1,0,0,0,191,194,1,0,0,0,192,190,1,0,0,0,192,
  	193,1,0,0,0,193,38,1,0,0,0,194,192,1,0,0,0,195,201,5,34,0,0,196,200,8,
  	3,0,0,197,198,5,92,0,0,198,200,9,0,0,0,199,196,1,0,0,0,199,197,1,0,0,
  	0,200,203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,204,1,0,0,0,203,
  	201,1,0,0,0,204,205,5,34,0,0,205,40,1,0,0,0,206,208,7,4,0,0,207,206,1,
  	0,0,0,208,209,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,211,1,0,0,0,
  	211,212,6,20,0,0,212,42,1,0,0,0,213,214,5,47,0,0,214,215,5,47,0,0,215,
  	219,1,0,0,0,216,218,8,5,0,0,217,216,1,0,0,0,218,221,1,0,0,0,219,217,1,
  	0,0,0,219,220,1,0,0,0,220,222,1,0,0,0,221,219,1,0,0,0,222,223,6,21,0,
  	0,223,44,1,0,0,0,224,225,5,47,0,0,225,226,5,42,0,0,226,230,1,0,0,0,227,
  	229,9,0,0,0,228,227,1,0,0,0,229,232,1,0,0,0,230,231,1,0,0,0,230,228,1,
  	0,0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,234,5,42,0,0,234,235,5,47,0,
  	0,235,236,1,0,0,0,236,237,6,22,0,0,237,46,1,0,0,0,238,239,7,6,0,0,239,
  	48,1,0,0,0,16,0,76,155,160,166,170,176,178,181,186,192,199,201,209,219,
  	230,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  menulexerLexerStaticData = std::move(staticData);
}

}

MenuLexer::MenuLexer(CharStream *input) : Lexer(input) {
  MenuLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *menulexerLexerStaticData->atn, menulexerLexerStaticData->decisionToDFA, menulexerLexerStaticData->sharedContextCache);
}

MenuLexer::~MenuLexer() {
  delete _interpreter;
}

std::string MenuLexer::getGrammarFileName() const {
  return "Menu.g4";
}

const std::vector<std::string>& MenuLexer::getRuleNames() const {
  return menulexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MenuLexer::getChannelNames() const {
  return menulexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MenuLexer::getModeNames() const {
  return menulexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MenuLexer::getVocabulary() const {
  return menulexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MenuLexer::getSerializedATN() const {
  return menulexerLexerStaticData->serializedATN;
}

const atn::ATN& MenuLexer::getATN() const {
  return *menulexerLexerStaticData->atn;
}




void MenuLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  menulexerLexerInitialize();
#else
  ::antlr4::internal::call_once(menulexerLexerOnceFlag, menulexerLexerInitialize);
#endif
}
