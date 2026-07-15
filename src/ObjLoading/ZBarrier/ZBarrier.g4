grammar ZBarrier;

// Parser rules

zBarrier
    : ZBARRIER pair* EOF
    ;

pair
    : BACKSLASH key BACKSLASH value
    ;

key
    : IDENTIFIER
    ;

value
    : FLOAT
    | INTEGER
    | IDENTIFIER
    |
    ;

// Lexer rules

ZBARRIER   : 'ZBARRIER' ;
BACKSLASH  : '\\' ;
FLOAT      : '-'? DIGIT+ '.' DIGIT*
           | '-'? '.' DIGIT+
           ;
INTEGER    : '-'? DIGIT+ ;
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_./]* ;
WS         : [ \t\r\n]+ -> skip ;

fragment DIGIT : [0-9] ;
