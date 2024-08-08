#pragma once

#include "MenoBohaviour.h"
#include <string>

// class T���ő�MAXSIZE�m�ۉ\��PoolAllocator���������Ă�������
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// �R���X�g���N�^
	PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
		for (int i = 0; i < MAXSIZE - 1; ++i) {
			m_data[i].next = &m_data[i + 1];
		}
		m_data[MAXSIZE - 1].next = nullptr;
		m_list = &m_data[0];
	}

	// �f�X�g���N�^
	~PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
	}

	// �m�ۂł��Ȃ��ꍇ��nullptr��Ԃ����B
	T* Alloc() {
		// TODO: �������Ă�������
		if (m_list) {
			DATA* current = m_list;
			DATA* next = current->next;
			m_list = next;
			T* ret = reinterpret_cast<T*>(current->data);
			return ret;
		}
		return nullptr;
	}

	// Free(nullptr)�Ō듮�삵�Ȃ��悤�ɂ��鎖�B
	void Free(T* addr) {
		// TODO: �������Ă�������
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
