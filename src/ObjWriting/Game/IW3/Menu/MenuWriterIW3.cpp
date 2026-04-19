#include "MenuWriterIW3.h"

#include "Game/IW3/MenuConstantsIW3.h"
#include "Menu/AbstractMenuWriter.h"
#include "ObjWriting.h"

#include <cassert>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <Game/IW3/IW3_Assets.h>

using namespace IW3;

// Uncomment this macro to skip interpretative expression dumping
// #define DUMP_NAIVE

#ifdef DUMP_NAIVE
#define DUMP_FUNC WriteStatementNaive
#else
#define DUMP_FUNC WriteStatementSkipInitialUnnecessaryParenthesis
#endif

namespace
{
    size_t FindStatementClosingParenthesis(const statement_s& statement, const size_t openingParenthesisPosition)
    {
        assert(statement.numEntries >= 0);
        assert(openingParenthesisPosition < static_cast<size_t>(statement.numEntries));

        const auto statementEnd = static_cast<size_t>(statement.numEntries);

        // The openingParenthesisPosition does not necessarily point to an actual opening parenthesis operator. That's fine though.
        // We will pretend it does since the game does sometimes leave out opening parenthesis from the entries.
        auto currentParenthesisDepth = 1;
        for (auto currentSearchPosition = openingParenthesisPosition + 1; currentSearchPosition < statementEnd; currentSearchPosition++)
        {
            const auto& expEntry = statement.entries[currentSearchPosition];
            if (expEntry->type != EET_OPERATOR)
                continue;

            // Any function means a "left out" left paren
            if (expEntry->data.op == OP_LEFTPAREN || expEntry->data.op >= OP_COUNT)
            {
                currentParenthesisDepth++;
            }
            else if (expEntry->data.op == OP_RIGHTPAREN)
            {
                if (currentParenthesisDepth > 0)
                    currentParenthesisDepth--;
                if (currentParenthesisDepth == 0)
                    return currentSearchPosition;
            }
        }

        return statementEnd;
    }

    class MenuWriter final : public ::menu::AbstractBaseWriter, public menu::IWriterIW3
    {
    public:
        explicit MenuWriter(std::ostream& stream)
            : AbstractBaseWriter(stream)
        {
        }

        void WriteFunctionDef(const std::string& functionName, const statement_s& statement) override
        {
            StartFunctionDefScope();

            WriteStringProperty("name", functionName);
            WriteStatementProperty("value", statement, false);

            EndScope();
        }

        void WriteMenu(const menuDef_t& menu) override
        {
            StartMenuDefScope();

            WriteMenuData(&menu);

            EndScope();
        }

        void Start() override
        {
            AbstractBaseWriter::Start();
        }

        void End() override
        {
            AbstractBaseWriter::End();
        }

        void IncludeMenu(const std::string& menuPath) const override
        {
            AbstractBaseWriter::IncludeMenu(menuPath);
        }

    private:
        std::string FormatFloat(double value, int minDecimals, int maxDecimals) const
        {
            if (std::fabs(value - std::round(value)) < std::numeric_limits<double>::epsilon())
            {
                std::ostringstream ss;
                ss << std::fixed << std::setprecision(minDecimals) << value;
                return ss.str();
            }

            std::ostringstream ss;
            ss << std::fixed << std::setprecision(maxDecimals) << value;

            std::string str = ss.str();

            // Trim trailing zeros
            if (auto dotPos = str.find('.'); dotPos != std::string::npos)
            {
                while (!str.empty() && str.back() == '0')
                    str.pop_back();

                if (!str.empty() && str.back() == '.')
                    str.pop_back();
            }

            // Ensure minimum decimals
            auto dotPos = str.find('.');
            if (dotPos == std::string::npos)
            {
                if (minDecimals > 0)
                {
                    str += '.';
                    str.append(minDecimals, '0');
                }
            }
            else
            {
                int currentDecimals = static_cast<int>(str.size() - dotPos - 1);
                if (currentDecimals < minDecimals)
                    str.append(minDecimals - currentDecimals, '0');
            }

            return str;
        }

        void WriteFormattedFloatProperty(const std::string& propertyKey, const float propertyValue, const float defaultValue) const
        {
            if (std::fabs(propertyValue - defaultValue) < std::numeric_limits<float>::epsilon())
                return;

            Indent();
            WriteKey(propertyKey);
            m_stream << FormatFloat(propertyValue, 2, 5) << "\n";
            
        }

        void WriteStatementNaive(const statement_s& statement) const
        {
            const auto entryCount = static_cast<size_t>(statement.numEntries);

            const auto missingClosingParenthesis = statement.numEntries > 0 && statement.entries[0]->type == EET_OPERATOR
                                                   && statement.entries[0]->data.op == OP_LEFTPAREN
                                                   && FindStatementClosingParenthesis(statement, 0) >= static_cast<size_t>(statement.numEntries);

            for (auto i = 0uz; i < entryCount; i++)
            {
                const auto& entry = statement.entries[i];
                if (entry->type == EET_OPERAND)
                {
                    size_t pos = i;
                    bool discard = false;
                    WriteStatementOperand(statement, pos, discard);
                }
                else
                {
                    assert(entry->data.op >= 0 && static_cast<unsigned>(entry->data.op) < std::extent_v<decltype(g_expFunctionNames)>);
                    if (entry->data.op >= 0 && static_cast<unsigned>(entry->data.op) < std::extent_v<decltype(g_expFunctionNames)>)
                        m_stream << g_expFunctionNames[entry->data.op];
                    if (entry->data.op >= OP_COUNT)
                        m_stream << "(";
                }
            }

            if (missingClosingParenthesis)
                m_stream << ")";
        }

        void WriteStatementOperator(const statement_s& statement, size_t& currentPos, bool& spaceNext) const
        {
            const auto& expEntry = statement.entries[currentPos];
            const auto op = expEntry->data.op;

            if (spaceNext && op != OP_COMMA)
                m_stream << " ";

            if (op == OP_LEFTPAREN)
            {
                const auto closingParenPos = FindStatementClosingParenthesis(statement, currentPos);

                m_stream << "(";
                WriteStatementEntryRange(statement, currentPos + 1, closingParenPos);
                m_stream << ")";

                currentPos = closingParenPos + 1;
                spaceNext = true;
                return;
            }

            if (op >= OP_FIRSTFUNCTIONCALL && op < OP_COUNT)
            {
                const auto endPos = FindStatementClosingParenthesis(statement, currentPos);

                // function name
                if (static_cast<unsigned>(op) < std::extent_v<decltype(g_expFunctionNames)>)
                    m_stream << g_expFunctionNames[op];

                m_stream << "(";
                WriteStatementEntryRange(statement, currentPos + 1, endPos);
                m_stream << ")";

                currentPos = endPos;
                spaceNext = true;
                return;
            }

            if (op >= 0 && static_cast<unsigned>(op) < std::extent_v<decltype(g_expFunctionNames)>)
            {
                m_stream << g_expFunctionNames[op];
            }

            currentPos++;
            spaceNext = (op != OP_NOT);
        }

        void WriteStatementOperand(const statement_s& statement, size_t& currentPos, bool& spaceNext) const
        {
            const auto& expEntry = statement.entries[currentPos];

            if (spaceNext)
                m_stream << " ";

            const auto& operand = expEntry->data.operand;

            switch (operand.dataType)
            {
            case VAL_FLOAT:
                m_stream << operand.internals.floatVal;
                break;

            case VAL_INT:
                m_stream << operand.internals.intVal;
                break;

            case VAL_STRING:
                WriteEscapedString(operand.internals.stringVal);
                break;

            default:
                break;
            }

            currentPos++;
            spaceNext = true;
        }

        void WriteStatementEntryRange(const statement_s& statement, size_t startOffset, size_t endOffset) const
        {
            assert(startOffset <= endOffset);
            assert(endOffset <= static_cast<size_t>(statement.numEntries));

            auto currentPos = startOffset;
            auto spaceNext = false;
            while (currentPos < endOffset)
            {
                const auto& expEntry = statement.entries[currentPos];

                if (expEntry->type == EET_OPERATOR)
                {
                    WriteStatementOperator(statement, currentPos, spaceNext);
                }
                else
                {
                    WriteStatementOperand(statement, currentPos, spaceNext);
                }
            }
        }

        void WriteStatement(const statement_s& statement) const
        {
            if (statement.numEntries < 0)
                return;

            WriteStatementEntryRange(statement, 0, static_cast<size_t>(statement.numEntries));
        }

        void WriteStatementSkipInitialUnnecessaryParenthesis(const statement_s& statementValue) const
        {
            if (statementValue.numEntries < 0)
                return;

            const auto statementEnd = static_cast<size_t>(statementValue.numEntries);

            if (statementValue.numEntries >= 1 && statementValue.entries[0]->type == EET_OPERATOR && statementValue.entries[0]->data.op == OP_LEFTPAREN)
            {
                const auto parenthesisEnd = FindStatementClosingParenthesis(statementValue, 0);

                if (parenthesisEnd >= statementEnd)
                    WriteStatementEntryRange(statementValue, 1, statementEnd);
                else if (parenthesisEnd == statementEnd - 1)
                    WriteStatementEntryRange(statementValue, 1, statementEnd - 1);
                else
                    WriteStatementEntryRange(statementValue, 0, statementEnd);
            }
            else
            {
                WriteStatementEntryRange(statementValue, 0, statementEnd);
            }
        }

        void WriteStatementProperty(const std::string& propertyKey, const statement_s& statementValue, bool isBooleanStatement) const
        {
            if (statementValue.numEntries <= 0)
                return;

            Indent();
            WriteKey(propertyKey);

            if (isBooleanStatement)
            {
                m_stream << "when(";
                DUMP_FUNC(statementValue);
                m_stream << ");\n";
            }
            else
            {
                DUMP_FUNC(statementValue);
                m_stream << ";\n";
            }
        }

        void WriteExpStatementProperty(const std::string& propertyKey, const statement_s& statementValue, bool isBooleanStatement) const
        {
            if (statementValue.numEntries <= 0)
                return;

            Indent();
            WriteKey("exp");
            m_stream << propertyKey;

            if (isBooleanStatement)
            {
                m_stream << "when(";
                DUMP_FUNC(statementValue);
                m_stream << ");\n";
            }
            else
            {
                DUMP_FUNC(statementValue);
                m_stream << ";\n";
            }
        }

        // #define WRITE_ORIGINAL_SCRIPT
        void WriteUnconditionalScript(const char* script) const
        {
#ifdef WRITE_ORIGINAL_SCRIPT
            Indent();
            m_stream << script << "\n";
            return;
#endif

            const auto tokenList = CreateScriptTokenList(script);

            auto isNewStatement = true;
            for (const auto& token : tokenList)
            {
                if (isNewStatement)
                {
                    if (token == ";")
                        continue;

                    Indent();
                }

                if (token == ";")
                {
                    m_stream << ";\n";
                    isNewStatement = true;
                    continue;
                }

                if (!isNewStatement)
                    m_stream << " ";
                else
                    isNewStatement = false;

                if (DoesTokenNeedQuotationMarks(token))
                    m_stream << "\"" << token << "\"";
                else
                    m_stream << token;
            }

            if (!isNewStatement)
                m_stream << ";\n";
        }

        void WriteRectProperty(const std::string& propertyKey, const rectDef_s& rect) const
        {
            Indent();
            WriteKey(propertyKey);

            m_stream << rect.x << " " << rect.y << " ";

            if (rect.w || rect.h)
            {
                m_stream << rect.w << " " << rect.h << " ";
                
                if (rect.horzAlign || rect.vertAlign)
                {
                    m_stream << static_cast<int>(rect.horzAlign) << " " << static_cast<int>(rect.vertAlign);
                }
            }

             m_stream << "\n";
        }

        void WriteMaterialProperty(const std::string& propertyKey, const Material* materialValue) const
        {
            if (materialValue == nullptr || materialValue->info.name == nullptr)
                return;

            if (materialValue->info.name[0] == ',')
                WriteStringProperty(propertyKey, &materialValue->info.name[1]);
            else
                WriteStringProperty(propertyKey, materialValue->info.name);
        }

        void WriteSoundAliasProperty(const std::string& propertyKey, const snd_alias_list_t* soundAliasValue) const
        {
            if (soundAliasValue == nullptr)
                return;

            WriteStringProperty(propertyKey, soundAliasValue->aliasName);
        }

        void WriteItemKeyHandlerProperty(const ItemKeyHandler* itemKeyHandlerValue)
        {
            if (itemKeyHandlerValue == nullptr)
                return;

            if (itemKeyHandlerValue->next != nullptr)
                WriteItemKeyHandlerProperty(itemKeyHandlerValue->next);

            m_stream << itemKeyHandlerValue->action;
        }

        void WriteMultiTokenStringProperty(const std::string& propertyKey, const char* value) const
        {
            if (!value)
                return;

            Indent();
            WriteKey(propertyKey);

            const auto tokenList = CreateScriptTokenList(value);

            auto firstToken = true;
            m_stream << "{ ";
            for (const auto& token : tokenList)
            {
                if (firstToken)
                    firstToken = false;
                else
                    m_stream << ";";
                m_stream << "\"" << token << "\"";
            }
            if (!firstToken)
                m_stream << " ";
            m_stream << "}\n";
        }

        void WriteColumnProperty(const std::string& propertyKey, const listBoxDef_s* listBox) const
        {
            if (listBox->numColumns <= 0)
                return;

            Indent();
            WriteKey(propertyKey);
            m_stream << listBox->numColumns << "\n";

            for (auto col = 0; col < listBox->numColumns; col++)
            {
                Indent();
                for (auto i = 0u; i < MENU_KEY_SPACING; i++)
                    m_stream << " ";

                m_stream << listBox->columnInfo[col].pos << " " << listBox->columnInfo[col].width << " " << listBox->columnInfo[col].maxChars << " "
                         << listBox->columnInfo[col].alignment << "\n";
            }
        }

        void WriteKeyHandlerProperty(const std::string& propertyKey, const char* propertyValue) 
        {
            if (propertyValue == nullptr)
                return;

            StartScope(propertyKey);
            Indent();
            m_stream << propertyValue << "\n";
            EndScope();
        }

        void WriteListBoxProperties(const itemDef_s* item)
        {
            if (item->type != ITEM_TYPE_LISTBOX || item->typeData.listBox == nullptr)
                return;

            const auto* listBox = item->typeData.listBox;
            WriteKeywordProperty("notselectable", listBox->notselectable != 0);
            WriteKeywordProperty("noscrollbars", listBox->noScrollBars != 0);
            WriteKeywordProperty("usepaging", listBox->usePaging != 0);
            WriteFloatProperty("elementwidth", listBox->elementWidth, 0.0f);
            WriteFloatProperty("elementheight", listBox->elementHeight, 0.0f);
            WriteFloatProperty("feeder", item->special, 0.0f);
            WriteIntProperty("elementtype", listBox->elementStyle, 0);
            WriteColumnProperty("columns", listBox);
            WriteColorProperty("selectBorder", listBox->selectBorder, COLOR_0000);
            WriteMaterialProperty("selectIcon", listBox->selectIcon);
        }

        void WriteDvarFloatProperty(const std::string& propertyKey, const itemDef_s* item, const editFieldDef_s* editField) const
        {
            if (item->dvar == nullptr)
                return;

            Indent();
            WriteKey(propertyKey);
            m_stream << "\"" << item->dvar << "\" " << editField->defVal << " " << editField->minVal << " " << editField->maxVal << "\n";
        }

        void WriteEditFieldProperties(const itemDef_s* item) const
        {
            switch (item->type)
            {
            case ITEM_TYPE_TEXT:
            case ITEM_TYPE_EDITFIELD:
            case ITEM_TYPE_NUMERICFIELD:
            case ITEM_TYPE_SLIDER:
            case ITEM_TYPE_YESNO:
            case ITEM_TYPE_BIND:
            case ITEM_TYPE_VALIDFILEFIELD:
            case ITEM_TYPE_DECIMALFIELD:
            case ITEM_TYPE_UPREDITFIELD:
                break;

            default:
                return;
            }

            if (item->typeData.editField == nullptr)
                return;

            const auto* editField = item->typeData.editField;
            if (std::fabs(-1.0f - editField->defVal) >= std::numeric_limits<float>::epsilon()
                || std::fabs(-1.0f - editField->minVal) >= std::numeric_limits<float>::epsilon()
                || std::fabs(-1.0f - editField->maxVal) >= std::numeric_limits<float>::epsilon())
            {
                WriteDvarFloatProperty("dvarFloat", item, editField);
            }
            else
            {
                WriteStringProperty("dvar", item->dvar);
            }
            WriteIntProperty("maxChars", editField->maxChars, 0);
            WriteKeywordProperty("maxCharsGotoNext", editField->maxCharsGotoNext != 0);
            WriteIntProperty("maxPaintChars", editField->maxPaintChars, 0);
        }

        void WriteMultiValueProperty(const multiDef_s* multiDef) const
        {
            Indent();
            if (multiDef->strDef)
                WriteKey("dvarStrList");
            else
                WriteKey("dvarFloatList");

            m_stream << "{";
            for (auto i = 0; i < multiDef->count; i++)
            {
                if (multiDef->dvarList[i] == nullptr || multiDef->strDef && multiDef->dvarStr[i] == nullptr)
                    continue;

                m_stream << " \"" << multiDef->dvarList[i] << "\"";

                if (multiDef->strDef)
                    m_stream << " \"" << multiDef->dvarStr[i] << "\"";
                else
                    m_stream << " " << multiDef->dvarValue[i] << "";
            }
            m_stream << " }\n";
        }

        void WriteMultiProperties(const itemDef_s* item) const
        {
            if (item->type != ITEM_TYPE_MULTI || item->typeData.multi == nullptr)
                return;

            const auto* multiDef = item->typeData.multi;

            if (multiDef->count <= 0)
                return;

            WriteStringProperty("dvar", item->dvar);
            WriteMultiValueProperty(multiDef);
        }

        void WriteEnumDvarProperties(const itemDef_s* item) const
        {
            if (item->type != ITEM_TYPE_DVARENUM)
                return;

            WriteStringProperty("dvar", item->dvar);
            WriteStringProperty("dvarEnumList", item->typeData.enumDvarName);
        }

        void WriteItemData(const itemDef_s* item)
        {
            WriteStringProperty("name", item->window.name);
            WriteStringProperty("text", item->text);
            // WriteKeywordProperty("textsavegame", item->itemFlags & ITEM_FLAG_SAVE_GAME_INFO);
            // WriteKeywordProperty("textcinematicsubtitle", item->itemFlags & ITEM_FLAG_CINEMATIC_SUBTITLE);
            WriteStringProperty("group", item->window.group);
            WriteRectProperty("rect", item->window.rectClient);
            WriteIntProperty("style", item->window.style, 0);
            WriteKeywordProperty("decoration", item->window.staticFlags & WINDOW_FLAG_DECORATION);
            WriteKeywordProperty("autowrapped", item->window.staticFlags & WINDOW_FLAG_AUTO_WRAPPED);
            WriteKeywordProperty("horizontalscroll", item->window.staticFlags & WINDOW_FLAG_HORIZONTAL_SCROLL);
            WriteIntProperty("type", item->type, ITEM_TYPE_TEXT);
            WriteIntProperty("border", item->window.border, 0);
            WriteFloatProperty("borderSize", item->window.borderSize, 0.0f);

            if (item->visibleExp.numEntries > 0)
                WriteStatementProperty("visible", item->visibleExp, true);
            else if (item->window.dynamicFlags[0] & WINDOW_FLAG_VISIBLE)
                WriteIntProperty("visible", 1, 0);

            //WriteStatementProperty("disabled", item->disabledExp, true);
            WriteIntProperty("ownerdraw", item->window.ownerDraw, 0);
            WriteFlagsProperty("ownerdrawFlag", item->window.ownerDrawFlags);
            WriteIntProperty("align", item->alignment, 0);
            WriteIntProperty("textalign", item->textAlignMode, 0);
            WriteFloatProperty("textalignx", item->textalignx, 0.0f);
            WriteFloatProperty("textaligny", item->textaligny, 0.0f);
            WriteFloatProperty("textscale", item->textscale, 0.0f);
            WriteIntProperty("textstyle", item->textStyle, 0);
            WriteIntProperty("textfont", item->fontEnum, 0);
            WriteColorProperty("backcolor", item->window.backColor, COLOR_0000);
            WriteColorProperty("forecolor", item->window.foreColor, COLOR_1111);
            WriteColorProperty("bordercolor", item->window.borderColor, COLOR_0000);
            WriteColorProperty("outlinecolor", item->window.outlineColor, COLOR_0000);
            //WriteColorProperty("disablecolor", item->window.disableColor, COLOR_0000);
            //WriteColorProperty("glowcolor", item->glowColor, COLOR_0000);
            WriteMaterialProperty("background", item->window.background);
            // WriteMenuEventHandlerSetProperty("onFocus", item->onFocus);
            // WriteMenuEventHandlerSetProperty("leaveFocus", item->leaveFocus);
            // WriteMenuEventHandlerSetProperty("mouseEnter", item->mouseEnter);
            // WriteMenuEventHandlerSetProperty("mouseExit", item->mouseExit);
            // WriteMenuEventHandlerSetProperty("mouseEnterText", item->mouseEnterText);
            // WriteMenuEventHandlerSetProperty("mouseExitText", item->mouseExitText);
            // WriteMenuEventHandlerSetProperty("action", item->action);
            // WriteMenuEventHandlerSetProperty("accept", item->accept);
            // WriteFloatProperty("special", item->special, 0.0f);
            WriteSoundAliasProperty("focusSound", item->focusSound);
            WriteStringProperty("dvarTest", item->dvarTest);

            // if (item->dvarFlags & ITEM_DVAR_FLAG_ENABLE)
            // WriteMultiTokenStringProperty("enableDvar", item->enableDvar);
            // else if (item->dvarFlags & ITEM_DVAR_FLAG_DISABLE)
            // WriteMultiTokenStringProperty("disableDvar", item->enableDvar);
            // else if (item->dvarFlags & ITEM_DVAR_FLAG_SHOW)
            // WriteMultiTokenStringProperty("showDvar", item->enableDvar);
            // else if (item->dvarFlags & ITEM_DVAR_FLAG_HIDE)
            // WriteMultiTokenStringProperty("hideDvar", item->enableDvar);
            // else if (item->dvarFlags & ITEM_DVAR_FLAG_FOCUS)
            // WriteMultiTokenStringProperty("focusDvar", item->enableDvar);

            WriteItemKeyHandlerProperty(item->onKey);
            WriteExpStatementProperty("text", item->textExp, false);
            WriteExpStatementProperty("material", item->materialExp, false);
            // WriteFloatExpressionsProperty(item->floatExpressions, item->floatExpressionCount);
            WriteIntProperty("gamemsgwindowindex", item->gameMsgWindowIndex, 0);
            WriteIntProperty("gamemsgwindowmode", item->gameMsgWindowMode, 0);
            // WriteDecodeEffectProperty("decodeEffect", item);

            WriteListBoxProperties(item);
            WriteEditFieldProperties(item);
            WriteMultiProperties(item);
            WriteEnumDvarProperties(item);
            // WriteTickerProperties(item);
        }

        void WriteItemDefs(const itemDef_s* const* itemDefs, size_t itemCount)
        {
            for (auto i = 0u; i < itemCount; i++)
            {
                StartItemDefScope();

                WriteItemData(itemDefs[i]);

                EndScope();
            }
        }

        void WriteMenuData(const menuDef_t* menu)
        {
            WriteStringProperty("name", menu->window.name);
            WriteBoolProperty("fullscreen", menu->fullScreen, false);
            WriteKeywordProperty("screenSpace", menu->window.staticFlags & WINDOW_FLAG_SCREEN_SPACE);
            WriteKeywordProperty("decoration", menu->window.staticFlags & WINDOW_FLAG_DECORATION);
            WriteRectProperty("rect", menu->window.rect);
            WriteIntProperty("style", menu->window.style, 0);
            WriteIntProperty("border", menu->window.border, 0);
            WriteFloatProperty("borderSize", menu->window.borderSize, 0.0f);
            WriteColorProperty("backcolor", menu->window.backColor, COLOR_0000);
            WriteColorProperty("forecolor", menu->window.foreColor, COLOR_1111);
            WriteColorProperty("bordercolor", menu->window.borderColor, COLOR_0000);
            WriteColorProperty("focuscolor", menu->focusColor, COLOR_0000);
            WriteColorProperty("outlinecolor", menu->window.outlineColor, COLOR_0000);
            WriteMaterialProperty("background", menu->window.background);
            WriteIntProperty("ownerdraw", menu->window.ownerDraw, 0);
            WriteFlagsProperty("ownerdrawFlag", menu->window.ownerDrawFlags);
            WriteKeywordProperty("outOfBoundsClick", menu->window.staticFlags & WINDOW_FLAG_OUT_OF_BOUNDS_CLICK);
            WriteStringProperty("soundLoop", menu->soundName);
            WriteKeywordProperty("popup", menu->window.staticFlags & WINDOW_FLAG_POPUP);
            WriteFloatProperty("fadeClamp", menu->fadeClamp, 0.0f);
            WriteIntProperty("fadeCycle", menu->fadeCycle, 0);
            WriteFloatProperty("fadeAmount", menu->fadeAmount, 0.0f);
            WriteFloatProperty("fadeInAmount", menu->fadeInAmount, 0.0f);
            WriteFloatProperty("blurWorld", menu->blurRadius, 0.0f);
            WriteKeywordProperty("legacySplitScreenScale", menu->window.staticFlags & WINDOW_FLAG_LEGACY_SPLIT_SCREEN_SCALE);
            WriteKeywordProperty("hiddenDuringScope", menu->window.staticFlags & WINDOW_FLAG_HIDDEN_DURING_SCOPE);
            WriteKeywordProperty("hiddenDuringFlashbang", menu->window.staticFlags & WINDOW_FLAG_HIDDEN_DURING_FLASH_BANG);
            WriteKeywordProperty("hiddenDuringUI", menu->window.staticFlags & WINDOW_FLAG_HIDDEN_DURING_UI);
            WriteStringProperty("allowedBinding", menu->allowedBinding);
            WriteKeywordProperty("textOnlyFocus", menu->window.staticFlags & WINDOW_FLAG_TEXT_ONLY_FOCUS);

            if (menu->visibleExp.numEntries > 0)
                WriteStatementProperty("visible", menu->visibleExp, true);
            else if (menu->window.dynamicFlags[0] & WINDOW_FLAG_VISIBLE)
                WriteIntProperty("visible", 1, 0);

            WriteStatementProperty("exp rect X", menu->rectXExp, false);
            WriteStatementProperty("exp rect Y", menu->rectYExp, false);
            // WriteStatementProperty("exp rect W", menu->rectWExp, false);
            // WriteStatementProperty("exp rect H", menu->rectHExp, false);
            // WriteStatementProperty("exp openSound", menu->openSoundExp, false);
            // WriteStatementProperty("exp closeSound", menu->closeSoundExp, false);
            WriteKeyHandlerProperty("onOpen", menu->onOpen);
            WriteKeyHandlerProperty("onClose", menu->onClose);
            WriteKeyHandlerProperty("onESC", menu->onESC);
            WriteItemKeyHandlerProperty(menu->onKey);
            WriteItemDefs(menu->items, menu->itemCount);
        }
    };
} // namespace

namespace menu
{
    std::unique_ptr<IWriterIW3> CreateMenuWriterIW3(std::ostream& stream)
    {
        return std::make_unique<MenuWriter>(stream);
    }
} // namespace menu
