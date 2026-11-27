#pragma once

#include <concepts>

namespace lf {
	template<typename T, typename value_type> 
	struct identifier {

		constexpr identifier() = default;
		explicit constexpr identifier(value_type value) : _value(value) {}

		inline size_t index() const { return _value + 1; }

		inline value_type value() const noexcept { return _value; }

	  private:
		value_type _value{};
	};
}
