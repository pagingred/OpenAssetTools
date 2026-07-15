grammar Tracer;

// Parser rules

tracer
    : TRACER pair* EOF
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

TRACER     : 'TRACER' ;
BACKSLASH  : '\\' ;
FLOAT      : '-'? DIGIT+ '.' DIGIT*
           | '-'? '.' DIGIT+
           ;
INTEGER    : '-'? DIGIT+ ;
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_./]* ;
WS         : [ \t\r\n]+ -> skip ;

fragment DIGIT : [0-9] ;
