#pragma once

#include "arena.hpp"
#include "types.hpp"
#include "identifier.hpp"

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>

namespace lf {
	class StringInterner {
	  public:
		using Symbol = identifier<std::string, u32>;
		
		std::string_view lookup(Symbol symbol) const;
		Symbol emplace(std::string_view text);

	  private:
		std::vector<std::string_view> _storage;
		std::unordered_map<std::string_view, Symbol> _symbols;
		ArenaAllocator _alloc;
	};
}
