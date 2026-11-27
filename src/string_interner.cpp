#include "string_interner.hpp"


namespace lf {
	std::string_view StringInterner::lookup(Symbol symbol) const {
		if (symbol.index() > _storage.size()) {
			throw "Symbol out of range.";
		}


		return _storage[symbol.index()];
	}

	StringInterner::Symbol StringInterner::emplace(std::string_view text) {
		if (auto it = _symbols.find(text); it != _symbols.end()) {
			return it->second;
		}
		
		char* mem = (char*)_alloc.malloc(text.size() + 1);
		std::memcpy(mem, text.data(), text.size());
		mem[text.size()] = '\0';

		std::string_view allocated = std::string_view(mem, text.size());
		Symbol symbol = Symbol((u32)_storage.size());
		_storage.emplace_back(allocated);
		auto& stuff = _symbols[allocated];
		stuff = symbol;
		return symbol;
	}
}
