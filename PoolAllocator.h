#pragma once

// class Tを最大MAXSIZE個確保可能なPoolAllocatorを実装してください
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// コンストラクタ
	PoolAllocator() {
		// TODO: 必要に応じて実装してください
		buffer = new T[MAXSIZE];

		freelist = nullptr;
		for (size_t i = 0; i < MAXSIZE; i++) {
			element_type* addr = reinterpret_cast<element_type*>(&buffer[i]);
			addr->next = reinterpret_cast<uintptr_t>(freelist);
			freelist = addr;
		}
	}

	// デストラクタ
	~PoolAllocator() {
		// TODO: 必要に応じて実装してください
		delete[] reinterpret_cast<element_type*>(buffer);
	}

	// 確保できない場合はnullptrを返す事。
	T* Alloc() {
		// TODO: 実装してください
		if (freelist == nullptr) {
			return nullptr;
		}
		T* result = reinterpret_cast<T*>(freelist);
		freelist = reinterpret_cast<element_type*>(freelist->next);
		return result;
	}

	// Free(nullptr)で誤動作しないようにする事。
	void Free(T* addr) {
		// TODO: 実装してください
		if (addr == nullptr) {
			return;
		}
		element_type* elem = reinterpret_cast<element_type*>(addr);
		elem->next = reinterpret_cast<uintptr_t>(freelist);
		freelist = elem;
	}

private:
	// TODO: 実装してください
	union element_type {
		T t;
		std::uintptr_t next;

		element_type() {}
		~element_type() {}
	};
	T* buffer;
	element_type* freelist;
};
#pragma once
