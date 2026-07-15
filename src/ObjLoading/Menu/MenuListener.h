
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MenuParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MenuParser.
 */
class  MenuListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMenuFile(MenuParser::MenuFileContext *ctx) = 0;
  virtual void exitMenuFile(MenuParser::MenuFileContext *ctx) = 0;

  virtual void enterWrapperMenuFilePart(MenuParser::WrapperMenuFilePartContext *ctx) = 0;
  virtual void exitWrapperMenuFilePart(MenuParser::WrapperMenuFilePartContext *ctx) = 0;

  virtual void enterFunctionDefMenuFilePart(MenuParser::FunctionDefMenuFilePartContext *ctx) = 0;
  virtual void exitFunctionDefMenuFilePart(MenuParser::FunctionDefMenuFilePartContext *ctx) = 0;

  virtual void enterMenuDefMenuFilePart(MenuParser::MenuDefMenuFilePartContext *ctx) = 0;
  virtual void exitMenuDefMenuFilePart(MenuParser::MenuDefMenuFilePartContext *ctx) = 0;

  virtual void enterLoadMenuMenuFilePart(MenuParser::LoadMenuMenuFilePartContext *ctx) = 0;
  virtual void exitLoadMenuMenuFilePart(MenuParser::LoadMenuMenuFilePartContext *ctx) = 0;

  virtual void enterFunctionDef(MenuParser::FunctionDefContext *ctx) = 0;
  virtual void exitFunctionDef(MenuParser::FunctionDefContext *ctx) = 0;

  virtual void enterLoadMenu(MenuParser::LoadMenuContext *ctx) = 0;
  virtual void exitLoadMenu(MenuParser::LoadMenuContext *ctx) = 0;

  virtual void enterMenuDef(MenuParser::MenuDefContext *ctx) = 0;
  virtual void exitMenuDef(MenuParser::MenuDefContext *ctx) = 0;

  virtual void enterItemDefMenuItem(MenuParser::ItemDefMenuItemContext *ctx) = 0;
  virtual void exitItemDefMenuItem(MenuParser::ItemDefMenuItemContext *ctx) = 0;

  virtual void enterExecKeyMenuItem(MenuParser::ExecKeyMenuItemContext *ctx) = 0;
  virtual void exitExecKeyMenuItem(MenuParser::ExecKeyMenuItemContext *ctx) = 0;

  virtual void enterExecKeyIntMenuItem(MenuParser::ExecKeyIntMenuItemContext *ctx) = 0;
  virtual void exitExecKeyIntMenuItem(MenuParser::ExecKeyIntMenuItemContext *ctx) = 0;

  virtual void enterBlockMenuItem(MenuParser::BlockMenuItemContext *ctx) = 0;
  virtual void exitBlockMenuItem(MenuParser::BlockMenuItemContext *ctx) = 0;

  virtual void enterPropertyMenuItem(MenuParser::PropertyMenuItemContext *ctx) = 0;
  virtual void exitPropertyMenuItem(MenuParser::PropertyMenuItemContext *ctx) = 0;

  virtual void enterExecKeyItemItem(MenuParser::ExecKeyItemItemContext *ctx) = 0;
  virtual void exitExecKeyItemItem(MenuParser::ExecKeyItemItemContext *ctx) = 0;

  virtual void enterExecKeyIntItemItem(MenuParser::ExecKeyIntItemItemContext *ctx) = 0;
  virtual void exitExecKeyIntItemItem(MenuParser::ExecKeyIntItemItemContext *ctx) = 0;

  virtual void enterBlockItemItem(MenuParser::BlockItemItemContext *ctx) = 0;
  virtual void exitBlockItemItem(MenuParser::BlockItemItemContext *ctx) = 0;

  virtual void enterPropertyItemItem(MenuParser::PropertyItemItemContext *ctx) = 0;
  virtual void exitPropertyItemItem(MenuParser::PropertyItemItemContext *ctx) = 0;

  virtual void enterWhenPropertyValue(MenuParser::WhenPropertyValueContext *ctx) = 0;
  virtual void exitWhenPropertyValue(MenuParser::WhenPropertyValueContext *ctx) = 0;

  virtual void enterExpressionPropertyValue(MenuParser::ExpressionPropertyValueContext *ctx) = 0;
  virtual void exitExpressionPropertyValue(MenuParser::ExpressionPropertyValueContext *ctx) = 0;

  virtual void enterStringPropertyValue(MenuParser::StringPropertyValueContext *ctx) = 0;
  virtual void exitStringPropertyValue(MenuParser::StringPropertyValueContext *ctx) = 0;

  virtual void enterFloatPropertyValue(MenuParser::FloatPropertyValueContext *ctx) = 0;
  virtual void exitFloatPropertyValue(MenuParser::FloatPropertyValueContext *ctx) = 0;

  virtual void enterIntegerPropertyValue(MenuParser::IntegerPropertyValueContext *ctx) = 0;
  virtual void exitIntegerPropertyValue(MenuParser::IntegerPropertyValueContext *ctx) = 0;

  virtual void enterIdentifierPropertyValue(MenuParser::IdentifierPropertyValueContext *ctx) = 0;
  virtual void exitIdentifierPropertyValue(MenuParser::IdentifierPropertyValueContext *ctx) = 0;

  virtual void enterExpression(MenuParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MenuParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionPart(MenuParser::ExpressionPartContext *ctx) = 0;
  virtual void exitExpressionPart(MenuParser::ExpressionPartContext *ctx) = 0;

  virtual void enterIfBlock(MenuParser::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(MenuParser::IfBlockContext *ctx) = 0;

  virtual void enterStatementBlock(MenuParser::StatementBlockContext *ctx) = 0;
  virtual void exitStatementBlock(MenuParser::StatementBlockContext *ctx) = 0;

  virtual void enterElseifClause(MenuParser::ElseifClauseContext *ctx) = 0;
  virtual void exitElseifClause(MenuParser::ElseifClauseContext *ctx) = 0;

  virtual void enterElseClause(MenuParser::ElseClauseContext *ctx) = 0;
  virtual void exitElseClause(MenuParser::ElseClauseContext *ctx) = 0;

  virtual void enterBlockStatement(MenuParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(MenuParser::BlockStatementContext *ctx) = 0;

  virtual void enterBlockToken(MenuParser::BlockTokenContext *ctx) = 0;
  virtual void exitBlockToken(MenuParser::BlockTokenContext *ctx) = 0;


};

