#include "GrammarParser.h"

namespace Elite
{

Node* GrammarParser::Parse(const std::string& data) {
    yyscan_t sc;
    int res;
    yylex_init(&sc);
    yyset_in(src, sc);
    res = yyparse(sc, this);
    yylex_destroy(sc);
    return model;
}
}

Node* GrammarParser::ParseFile(const std::string& file_path) {

}


}