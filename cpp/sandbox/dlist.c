#include <iostream>

// Double linked list
class DList {
	private:
		// Nested Class DList::Node
		class Node {
			public:
				// Explicit initialization of Fundamental Types
				// Since next is a pointer variable, it is initialized 
				// to a nullptr since we use the initialization list 
				// syntax {}. An initializer list forces value 
				// initialization
				Node(int data) : prev(nullptr),
								 next{},
								 _data(data) {
				
				}

				~Node() {}
				const int& data(void) const { return _data;}
				Node* prev;
				Node* next;
			private:
				int _data;
		}; // DList::Node
		
		Node* _handle;
		
		DList::Node* handle() const {
			return _handle;
		}

		void push_front(Node* node) {
			node->prev = nullptr;
			node->next = _handle;
			_handle->prev = node;
			_handle = node;
		}

	public:
		DList(): _handle(nullptr) {

		}

		// This constructor is called when uniform initialization is used
		// to define objects.
		DList(std::initializer_list<int> ilist) : _handle{} {
			// Automatic type deduction using auto
			// The type of the variable declared with auto is
			// deduced from its initializer.
			for (auto iter = ilist.begin(); iter != ilist.end(); ++iter) {
				this->push_back(*iter);
			}
		}

		~DList() {
			if (_handle == nullptr) {
				return;
			}

			while(_handle) {
				auto node = _handle;
				_handle = _handle->next;
				delete node;
			}

			_handle = nullptr;
		}

		void push_back(int data) {
			auto node = new Node {data};

			if (_handle == nullptr) {
				_handle = node;
			} else {
				auto current = _handle;

				while(current->next != nullptr) {
					current = current->next;
				}

				current->next = node;
				node->prev = current;
			}
		}

		void push_front(int data) {
			auto node = new Node {data};

			if (_handle == nullptr) {
				_handle = node;
			} else {
				auto anchor = _handle;
				_handle = node;
				node->next = anchor;
				anchor->prev = node;
			}
		}

		void reverse() {
			auto anchor = _handle;

			if (!anchor || !anchor->next) { return; }

			// Node to be moved
			decltype(anchor) temp = anchor->next;

			// Terminate the first node
			anchor->next = nullptr;
			
			while(temp) {
				// Next node to be moved
				anchor = temp->next;
				// Move it
				push_front(temp);
				// Onto the next
				temp = anchor;
			}
		}

	// You can trust a friend with your private code
	// Uses new function declaration syntax
	friend auto operator<<(std::ostream& os, const DList& dl) -> decltype(os);
};

// Uses new function declaration syntax
auto operator<<(std::ostream& os, const DList& dl) -> decltype(os) {
	auto handle = dl.handle();
	
	if (handle == nullptr) {
		return os;
	}
	
	do {
		// handle->data() = 1000;
		os << handle->data() << " ";
		handle = handle->next;
	} while(handle);
	
	os << std::endl;

	return os;
}


int main(int argc, char* argv[]) {
	DList dl;

	dl.reverse();

	dl.push_back(200);
	dl.push_back(300);

	std::cout << dl;

	dl.push_front(100);

	std::cout << dl;

	dl.reverse();

	std::cout << dl;

	// Let compiler figure out the type for dl2 based on expression
	const decltype(dl) dl2 {10, 20, 30, 40, 50};
	
	std::cout << dl2;
	//dl2.push_front(0);

	decltype(dl) dl3 = {1000, 2000, 3000, 4000, 5000};
	dl3.reverse();

	std::cout << dl3;

	return 0;
}

