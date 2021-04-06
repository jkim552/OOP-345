#ifndef SDDS_Collection_H
#define SDDS_Collection_H
#include <iostream>
#include <string>

namespace sdds {
	template <class T>
	class Collection {
		std::string c_name = "";
		T* c_items = nullptr;
		size_t c_size = 0;
		void (*c_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name) {
			c_name = name;
			c_items = nullptr;
		};

		Collection(const Collection& c) = delete;

		~Collection() {
			delete[] c_items;
		};

		const std::string& name() const {
			return c_name;
		};

		size_t size() const {
			return c_size;
		};

		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		};

		Collection<T>& operator+=(const T& item) {
			bool exist = false;
			for (size_t i = 0; i < c_size; i++) {
				if (c_items[i].title() == item.title()) {
					exist = true;
				}
			}
			if (!exist) {
				int update = c_size + 1;
				T* temp = nullptr;
				T temp = new T[update];
				for (size_t i = 0; i < c_size; i++) {
					temp[i] = c_items[i];
				}
				temp[c_size] = item;
				if (c_items != nullptr) {
					delete[] c_items;
				}
				c_items = new T[update];
				for (size_t i = 0; i < update; i++) {
					c_items[i] = temp[i];
				}
				c_size = update;
				if (c_observer != nullptr) {
					c_observer(*this, item);
				}
				delete[] temp;
				/*T* temp = c_items;
				c_items = new T[c_size + 1];
				for (size_t i = 0; i < c_size; i++) {
					c_items[i] = temp[i];
				}
				c_items[c_size] = item;
				c_size++;
				if (c_observer != nullptr) {
					c_observer(*this, item);
				}
				delete[] temp;*/
			}
			return *this;
		};

		T& operator[](size_t idx) const {
			if (idx >= c_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
			}
			return c_items[idx];
		};

		T* operator[](std::string title) const {
			for (size_t i = 0; i < c_size; i++) {
				if (c_items[i].title() == title) {
					return &c_items[i];
				}
			}
			return nullptr;
		};
		
		friend std::ostream& operator<<(std::ostream& os, const Collection& c) {
			for (size_t i = 0; i < c.size(); i++) {
				os << c[i];
			}
			return os;
		};
	};
}





#endif // !SDDS_Collection_H
