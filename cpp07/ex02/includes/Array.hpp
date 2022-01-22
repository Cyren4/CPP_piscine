#ifndef ARRAY_HPP
#define ARRAY_HPP

// class Array<int>{}

template <typename T>
class Array{
    private:

		T* tab;
		unsigned int	_size;
    public:
    	Array() {
			tab = NULL;
			_size = 0;
			};

    	Array(unsigned int n) {
			tab = NULL;
			_size = n;
			if (n > 0)
				tab = new T[n];
		};

    	Array(const Array & src) {
			this->tab = NULL;
			*this = src;
		};
		
    	~Array() {
			delete tab;
		};

    	Array&	operator=(const Array & src){
			if (this == &src)
				return *this;
			if (this->_size > 0 || this->tab == NULL)
				delete this->tab;
			this->_size = src._size;
			if (!src._size)
				return *this;
			this->tab = new T[src._size];
			for (size_t i = 0; i < src._size; i++)
				this->tab[i] = src.tab[i];
			return *this;
		}

		T& operator[](std::size_t index) const { 
			if (index >= _size)
				throw (std::out_of_range("Array: out of range"));
			return this->tab[index];
		}

		std::size_t	size(void) const { 
			return _size;
		}
};

#endif
