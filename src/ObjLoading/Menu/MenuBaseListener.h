
// Generated from E:/Projects/VS/OpenAssetTools/src/ObjLoading/Menu/Menu.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MenuListener.h"


/**
 * This class provides an empty implementation of MenuListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MenuBaseListener : public MenuListener {
public:

  virtual void enterMenuFile(MenuParser::MenuFileContext * /*ctx*/) override { }
  virtual void exitMenuFile(MenuParser::MenuFileContext * /*ctx*/) override { }

  virtual void enterWrapperMenuFilePart(MenuParser::WrapperMenuFilePartContext * /*ctx*/) override { }
  virtual void exitWrapperMenuFilePart(MenuParser::WrapperMenuFilePartContext * /*ctx*/) override { }

  virtual void enterFunctionDefMenuFilePart(MenuParser::FunctionDefMenuFilePartContext * /*ctx*/) override { }
  virtual void exitFunctionDefMenuFilePart(MenuParser::FunctionDefMenuFilePartContext * /*ctx*/) override { }

  virtual void enterMenuDefMenuFilePart(MenuParser::MenuDefMenuFilePartContext * /*ctx*/) override { }
  virtual void exitMenuDefMenuFilePart(MenuParser::MenuDefMenuFilePartContext * /*ctx*/) override { }

  virtual void enterLoadMenuMenuFilePart(MenuParser::LoadMenuMenuFilePartContext * /*ctx*/) override { }
  virtual void exitLoadMenuMenuFilePart(MenuParser::LoadMenuMenuFilePartContext * /*ctx*/) override { }

  virtual void enterFunctionDef(MenuParser::FunctionDefContext * /*ctx*/) override { }
  virtual void exitFunctionDef(MenuParser::FunctionDefContext * /*ctx*/) override { }

  virtual void enterLoadMenu(MenuParser::LoadMenuContext * /*ctx*/) override { }
  virtual void exitLoadMenu(MenuParser::LoadMenuContext * /*ctx*/) override { }

  virtual void enterMenuDef(MenuParser::MenuDefContext * /*ctx*/) override { }
  virtual void exitMenuDef(MenuParser::MenuDefContext * /*ctx*/) override { }

  virtual void enterItemDefMenuItem(MenuParser::ItemDefMenuItemContext * /*ctx*/) override { }
  virtual void exitItemDefMenuItem(MenuParser::ItemDefMenuItemContext * /*ctx*/) override { }

  virtual void enterExecKeyMenuItem(MenuParser::ExecKeyMenuItemContext * /*ctx*/) override { }
  virtual void exitExecKeyMenuItem(MenuParser::ExecKeyMenuItemContext * /*ctx*/) override { }

  virtual void enterExecKeyIntMenuItem(MenuParser::ExecKeyIntMenuItemContext * /*ctx*/) override { }
  virtual void exitExecKeyIntMenuItem(MenuParser::ExecKeyIntMenuItemContext * /*ctx*/) override { }

  virtual void enterBlockMenuItem(MenuParser::BlockMenuItemContext * /*ctx*/) override { }
  virtual void exitBlockMenuItem(MenuParser::BlockMenuItemContext * /*ctx*/) override { }

  virtual void enterPropertyMenuItem(MenuParser::PropertyMenuItemContext * /*ctx*/) override { }
  virtual void exitPropertyMenuItem(MenuParser::PropertyMenuItemContext * /*ctx*/) override { }

  virtual void enterExecKeyItemItem(MenuParser::ExecKeyItemItemContext * /*ctx*/) override { }
  virtual void exitExecKeyItemItem(MenuParser::ExecKeyItemItemContext * /*ctx*/) override { }

  virtual void enterExecKeyIntItemItem(MenuParser::ExecKeyIntItemItemContext * /*ctx*/) override { }
  virtual void exitExecKeyIntItemItem(MenuParser::ExecKeyIntItemItemContext * /*ctx*/) override { }

  virtual void enterBlockItemItem(MenuParser::BlockItemItemContext * /*ctx*/) override { }
  virtual void exitBlockItemItem(MenuParser::BlockItemItemContext * /*ctx*/) override { }

  virtual void enterPropertyItemItem(MenuParser::PropertyItemItemContext * /*ctx*/) override { }
  virtual void exitPropertyItemItem(MenuParser::PropertyItemItemContext * /*ctx*/) override { }

  virtual void enterWhenPropertyValue(MenuParser::WhenPropertyValueContext * /*ctx*/) override { }
  virtual void exitWhenPropertyValue(MenuParser::WhenPropertyValueContext * /*ctx*/) override { }

  virtual void enterExpressionPropertyValue(MenuParser::ExpressionPropertyValueContext * /*ctx*/) override { }
  virtual void exitExpressionPropertyValue(MenuParser::ExpressionPropertyValueContext * /*ctx*/) override { }

  virtual void enterStringPropertyValue(MenuParser::StringPropertyValueContext * /*ctx*/) override { }
  virtual void exitStringPropertyValue(MenuParser::StringPropertyValueContext * /*ctx*/) override { }

  virtual void enterFloatPropertyValue(MenuParser::FloatPropertyValueContext * /*ctx*/) override { }
  virtual void exitFloatPropertyValue(MenuParser::FloatPropertyValueContext * /*ctx*/) override { }

  virtual void enterIntegerPropertyValue(MenuParser::IntegerPropertyValueContext * /*ctx*/) override { }
  virtual void exitIntegerPropertyValue(MenuParser::IntegerPropertyValueContext * /*ctx*/) override { }

  virtual void enterIdentifierPropertyValue(MenuParser::IdentifierPropertyValueContext * /*ctx*/) override { }
  virtual void exitIdentifierPropertyValue(MenuParser::IdentifierPropertyValueContext * /*ctx*/) override { }

  virtual void enterExpression(MenuParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(MenuParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionPart(MenuParser::ExpressionPartContext * /*ctx*/) override { }
  virtual void exitExpressionPart(MenuParser::ExpressionPartContext * /*ctx*/) override { }

  virtual void enterIfBlock(MenuParser::IfBlockContext * /*ctx*/) override { }
  virtual void exitIfBlock(MenuParser::IfBlockContext * /*ctx*/) override { }

  virtual void enterStatementBlock(MenuParser::StatementBlockContext * /*ctx*/) override { }
  virtual void exitStatementBlock(MenuParser::StatementBlockContext * /*ctx*/) override { }

  virtual void enterElseifClause(MenuParser::ElseifClauseContext * /*ctx*/) override { }
  virtual void exitElseifClause(MenuParser::ElseifClauseContext * /*ctx*/) override { }

  virtual void enterElseClause(MenuParser::ElseClauseContext * /*ctx*/) override { }
  virtual void exitElseClause(MenuParser::ElseClauseContext * /*ctx*/) override { }

  virtual void enterBlockStatement(MenuParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(MenuParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterBlockToken(MenuParser::BlockTokenContext * /*ctx*/) override { }
  virtual void exitBlockToken(MenuParser::BlockTokenContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

