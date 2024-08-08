#pragma once

// class T���ő�MAXSIZE�m�ۉ\��PoolAllocator���������Ă�������
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// �R���X�g���N�^
	PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
		buffer = new T[MAXSIZE];

		freelist = nullptr;
		for (size_t i = 0; i < MAXSIZE; i++) {
			element_type* addr = reinterpret_cast<element_type*>(&buffer[i]);
			addr->next = reinterpret_cast<uintptr_t>(freelist);
			freelist = addr;
		}
	}

	// �f�X�g���N�^
	~PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
		delete[] reinterpret_cast<element_type*>(buffer);
	}

	// �m�ۂł��Ȃ��ꍇ��nullptr��Ԃ����B
	T* Alloc() {
		// TODO: �������Ă�������
		if (freelist == nullptr) {
			return nullptr;
		}
		T* result = reinterpret_cast<T*>(freelist);
		freelist = reinterpret_cast<element_type*>(freelist->next);
		return result;
	}

	// Free(nullptr)�Ō듮�삵�Ȃ��悤�ɂ��鎖�B
	void Free(T* addr) {
		// TODO: �������Ă�������
		if (addr == nullptr) {
			return;
		}
		element_type* elem = reinterpret_cast<element_type*>(addr);
		elem->next = reinterpret_cast<uintptr_t>(freelist);
		freelist = elem;
	}

private:
	// TODO: �������Ă�������
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
