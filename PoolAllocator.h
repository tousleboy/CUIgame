#pragma once

#include "MenoBohaviour.h"
#include <string>

// class Tを最大MAXSIZE個確保可能なPoolAllocatorを実装してください
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// コンストラクタ
	PoolAllocator() {
		// TODO: 必要に応じて実装してください
		for (int i = 0; i < MAXSIZE - 1; ++i) {
			m_data[i].next = &m_data[i + 1];
		}
		m_data[MAXSIZE - 1].next = nullptr;
		m_list = &m_data[0];
	}

	// デストラクタ
	~PoolAllocator() {
		// TODO: 必要に応じて実装してください
	}

	// 確保できない場合はnullptrを返す事。
	T* Alloc() {
		// TODO: 実装してください
		if (m_list) {
			DATA* current = m_list;
			DATA* next = current->next;
			m_list = next;
			T* ret = reinterpret_cast<T*>(current->data);
			return ret;
		}
		return nullptr;
	}

	// Free(nullptr)で誤動作しないようにする事。
	void Free(T* addr) {
		// TODO: 実装してください
		if (addr) {
			DATA* ptr = reinterpret_cast<DATA*>(addr);
			ptr->next = m_list;
			m_list = ptr;
		}
	}

private:

	union DATA {
		DATA* next;
		char data[sizeof(T)];
	};

	DATA m_data[MAXSIZE];
	DATA* m_list;
};
