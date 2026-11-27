
#include "types.hpp"
#include "lexer.hpp"
#include "string_interner.hpp"

#include <CLI\CLI.hpp>

#include <iostream>
#include <string_view> 
#include <vector>
#include <print>

const char* code = R"(
var Foo : i32 = 50.3; void
0i32 return something;

)";


i32 main(i32 argc, char* argv[]) {

	auto [tokens, strings] = lf::Lexer::lex(std::string_view(code));
    for (auto token : tokens) {
		std::println("{}", token);
    }
	return 0;
}