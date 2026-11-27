#include "arena.hpp"


namespace lf {
	void* ArenaAllocator::malloc(size_t size) {
		Block& current = _blocks[_current_block];

		if (void* ptr = current.malloc(size); ptr) {
			return ptr;
		}

		size_t capacity = size > current.capacity * 2 + 1 ? size : current.capacity * 2 + 1;
		Block& next = _new_block(capacity);

		return next.malloc(size);
	}

	ArenaAllocator::Block& ArenaAllocator::_new_block(size_t capacity) {
		return _blocks.emplace_back(capacity);
	}
}
