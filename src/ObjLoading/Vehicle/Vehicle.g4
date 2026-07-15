grammar Vehicle;

vehicle : VEHICLEFILE pair* EOF ;
pair    : BACKSLASH key BACKSLASH value ;
key     : IDENTIFIER ;
value   : FLOAT | INTEGER | IDENTIFIER | FOUR_WHEEL | ;

VEHICLEFILE : 'VEHICLEFILE' ;
BACKSLASH   : '\\' ;
FOUR_WHEEL  : '4 wheel' ;
FLOAT       : '-'? DIGIT+ '.' DIGIT* | '-'? '.' DIGIT+ ;
INTEGER     : '-'? DIGIT+ ;
IDENTIFIER  : [a-zA-Z_][a-zA-Z0-9_]* ;
WS          : [ \t\r\n]+ -> skip ;

fragment DIGIT : [0-9] ;
