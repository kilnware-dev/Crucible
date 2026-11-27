#pragma once

#include "error.hpp"
#include "string_interner.hpp"
#include "token.hpp"
#include "types.hpp"

#include <expected>
#include <string>
#include <string_view>
#include <vector>
#include <tuple>
namespace lf {

	struct LexResult {
		std::vector<Token> tokens;
		StringInterner strings;
	};

	struct Lexer {
		static std::tuple<std::vector<Token>, StringInterner> lex(Lexer&& lexer);
		Lexer(std::string_view source);

		uchar peek(u64 amount = 0) const;
		uchar advance();
		bool skip_whitespace();

		Token lex_next();
		Token lex_identifier();
		Token lex_number();
		Token lex_operator();

	  private:
		static bool can_lex_identifier(uchar next);
		static bool can_lex_number(uchar next);
		static bool can_lex_operator(uchar next);



		std::string _source;
		u64 _position = 0;
		StringInterner _strings;
	};

} // namespace lf