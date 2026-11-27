#pragma once

#include <cstddef>
#include <memory>
#include <vector>

namespace lf {
	class ArenaAllocator {
	  public:

		  ArenaAllocator() {
			_new_block(1024);
		  }
		void* malloc(size_t size);

	  private:
		struct Block {
			std::unique_ptr<std::byte[]> bytes;
			size_t capacity{};
			size_t offset = 0;

			Block(size_t capacity) : capacity(capacity) {
				bytes = std::make_unique<std::byte[]>(capacity);
			}

			void* malloc(size_t size) {
				if (size > capacity - offset) { return nullptr; }
				std::byte* ptr = &bytes.get()[offset];
				offset += size;
				return ptr;
			}

		};
		std::vector<Block> _blocks;
		size_t _current_block{};

		Block& _new_block(size_t capacity);
	};
}
