grammar Menu;

// ============= Parser Rules =============

menuFile
    : menuFilePart* EOF
    ;

menuFilePart
    : LBRACE menuFilePart* RBRACE   # WrapperMenuFilePart
    | functionDef                    # FunctionDefMenuFilePart
    | menuDef                        # MenuDefMenuFilePart
    | loadMenu                       # LoadMenuMenuFilePart
    ;

functionDef
    : FUNCTIONDEF LBRACE block* RBRACE
    ;

loadMenu
    : LOADMENU LBRACE STRING RBRACE
    ;

menuDef
    : MENUDEF LBRACE menuItem* RBRACE
    ;

menuItem
    : ITEMDEF LBRACE itemItem* RBRACE                 # ItemDefMenuItem
    | EXECKEY propertyValue LBRACE block* RBRACE      # ExecKeyMenuItem
    | EXECKEYINT propertyValue LBRACE block* RBRACE   # ExecKeyIntMenuItem
    | IDENTIFIER LBRACE block* RBRACE                 # BlockMenuItem
    | IDENTIFIER propertyValue*                        # PropertyMenuItem
    ;

itemItem
    : EXECKEY propertyValue LBRACE block* RBRACE      # ExecKeyItemItem
    | EXECKEYINT propertyValue LBRACE block* RBRACE   # ExecKeyIntItemItem
    | IDENTIFIER LBRACE block* RBRACE                 # BlockItemItem
    | IDENTIFIER propertyValue*                        # PropertyItemItem
    ;

propertyValue
    : WHEN LPAREN expression RPAREN  # WhenPropertyValue
    | LPAREN expression RPAREN       # ExpressionPropertyValue
    | STRING                         # StringPropertyValue
    | FLOAT                          # FloatPropertyValue
    | INTEGER                        # IntegerPropertyValue
    | IDENTIFIER                     # IdentifierPropertyValue
    ;

expression
    : expressionPart*
    ;

expressionPart
    : STRING
    | FLOAT
    | INTEGER
    | IDENTIFIER
    | WHEN
    | LPAREN expression RPAREN
    | OP
    ;

block
    : IF LPAREN expression RPAREN LBRACE block* RBRACE elseifClause* elseClause?  # IfBlock
    | blockStatement                                                                 # StatementBlock
    ;

elseifClause
    : ELSEIF LPAREN expression RPAREN LBRACE block* RBRACE
    ;

elseClause
    : ELSE LBRACE block* RBRACE
    ;

blockStatement
    : blockToken+ SEMICOLON?
    ;

blockToken
    : STRING
    | FLOAT
    | INTEGER
    | IDENTIFIER
    | LPAREN blockToken* RPAREN
    ;

// ============= Lexer Rules =============

LBRACE    : '{' ;
RBRACE    : '}' ;
LPAREN    : '(' ;
RPAREN    : ')' ;
SEMICOLON : ';' ;

OP
    : '&&' | '||' | '==' | '!='
    | '<=' | '>=' | '<<' | '>>'
    | '!' | '+' | '-' | '*' | '/' | '%'
    | '&' | '|' | '~' | '<' | '>'
    ;

FUNCTIONDEF : 'functionDef' ;
LOADMENU    : 'loadMenu' ;
MENUDEF     : 'menuDef' ;
ITEMDEF     : 'itemDef' ;
EXECKEY     : 'execKey' ;
EXECKEYINT  : 'execKeyInt' ;
IF          : 'if' ;
ELSEIF      : 'elseif' ;
ELSE        : 'else' ;
WHEN        : 'when' ;

FLOAT
    : '-'? DIGIT+ '.' DIGIT*
    | '-'? '.' DIGIT+
    ;
INTEGER    : '-'? DIGIT+ ;
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_.]* ;
STRING     : '"' (~["\\\r\n] | '\\' .)* '"' ;

WS           : [ \t\r\n]+ -> skip ;
LINECOMMENT  : '//' ~[\r\n]* -> skip ;
BLOCKCOMMENT : '/*' .*? '*/' -> skip ;

fragment DIGIT : [0-9] ;
