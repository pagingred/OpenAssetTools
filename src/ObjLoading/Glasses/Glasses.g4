grammar Glasses;

// Parser rules

glassesFile
    : entry* EOF
    ;

entry
    : key COMMA firstValue rest* NEWLINE
    | NEWLINE
    ;

key
    : IDENTIFIER
    ;

firstValue
    : INTEGER
    |
    ;

rest
    : COMMA INTEGER?
    ;

// Lexer rules

COMMENT    : '#' ~[\r\n]* -> skip ;
COMMA      : ',' ;
NEWLINE    : '\r'? '\n' ;
INTEGER    : DIGIT+ ;
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_]* ;
WS         : [ \t]+ -> skip ;

fragment DIGIT : [0-9] ;
