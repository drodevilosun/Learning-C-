#include <iostream>
class Point
{
  public: 
  friend std::basic_ostream<char> & operator<<(std::basic_ostream<char> & out, const Point & operand);
  
  public: 
  inline Point(double x, double y)
  : m_x{x}
  , m_y{y}
  {
  }
  
  inline Point()
  : m_x{0.0}
  , m_y{0.0}
  {
  }
  
  
  private: 
  double m_x;
  double m_y;
  public: 
  // inline Point & operator=(const Point &) noexcept = default;
};



std::basic_ostream<char> & operator<<(std::basic_ostream<char> & out, const Point & operand)
{
  std::operator<<(std::operator<<(std::operator<<(out, "Point [ x : ").operator<<(operand.m_x), ",y : ").operator<<(operand.m_y), "]");
  return out;
}


template<typename T>
class BoxContainer
{
  static const size_t DEFAULT_CAPACITY = 5;
  static const size_t EXPAND_STEPS = 5;
  
  public: 
  BoxContainer(size_t capacity);
  
  BoxContainer(const BoxContainer<T> & source);
  
  ~BoxContainer();
  
  inline size_t size() const
  {
    return this->m_size;
  }
  
  inline size_t capacity() const
  {
    return this->m_capacity;
  }
  
  inline T get_item(size_t index) const
  {
    return this->m_items[index];
  }
  
  void add(const T & item);
  
  bool remove_item(const T & item);
  
  size_t remove_all(const T & item);
  
  void operator+=(const BoxContainer<T> & operand);
  
  void operator=(const BoxContainer<T> & source);
  
  
  private: 
  void expand(size_t new_capacity);
  
  
  private: 
  T * m_items;
  size_t m_capacity;
  size_t m_size;
};

/* First instantiated from: insights.cpp:243 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class BoxContainer<int>
{
  static const size_t DEFAULT_CAPACITY = 5;
  static const size_t EXPAND_STEPS = 5;
  
  public: 
  BoxContainer(size_t capacity)
  : m_capacity{10}
  {
    this->m_items = new int[capacity];
    this->m_capacity = capacity;
    this->m_size = 0;
  }
  
  BoxContainer(const BoxContainer<int> & source);
  
  ~BoxContainer() noexcept
  {
    delete[] this->m_items;
  }
  
  inline size_t size() const
  {
    return this->m_size;
  }
  
  inline size_t capacity() const
  {
    return this->m_capacity;
  }
  
  inline int get_item(size_t index) const
  {
    return this->m_items[index];
  }
  
  void add(const int & item)
  {
    if(this->m_size == this->m_capacity) {
      this->expand(this->m_size + EXPAND_STEPS);
    } 
    
    this->m_items[this->m_size] = item;
    ++this->m_size;
  }
  
  bool remove_item(const int & item);
  
  size_t remove_all(const int & item);
  
  void operator+=(const BoxContainer<int> & operand);
  
  void operator=(const BoxContainer<int> & source);
  
  
  private: 
  void expand(size_t new_capacity)
  {
    std::operator<<(std::cout, "Expanding to ").operator<<(new_capacity).operator<<(std::endl);
    int * new_items_container;
    if(new_capacity <= this->m_capacity) {
      return;
    } 
    
    new_items_container = new int[new_capacity];
    for(size_t i = {}; i < this->m_size; ++i) {
      new_items_container[i] = this->m_items[i];
    }
    
    delete[] this->m_items;
    this->m_items = new_items_container;
    this->m_capacity = new_capacity;
  }
  
  
  private: 
  int * m_items;
  size_t m_capacity;
  size_t m_size;
};

#endif
/* First instantiated from: insights.cpp:248 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class BoxContainer<Point>
{
  static const size_t DEFAULT_CAPACITY = 5;
  static const size_t EXPAND_STEPS = 5;
  
  public: 
  BoxContainer(size_t capacity)
  : m_capacity{10}
  {
    this->m_items = new Point[]();
    this->m_capacity = capacity;
    this->m_size = 0;
  }
  
  BoxContainer(const BoxContainer<Point> & source);
  
  ~BoxContainer() noexcept
  {
    delete[] this->m_items;
  }
  
  inline size_t size() const;
  
  inline size_t capacity() const;
  
  inline Point get_item(size_t index) const;
  
  void add(const Point & item)
  {
    if(this->m_size == this->m_capacity) {
      this->expand(this->m_size + EXPAND_STEPS);
    } 
    
    this->m_items[this->m_size].operator=(item);
    ++this->m_size;
  }
  
  bool remove_item(const Point & item);
  
  size_t remove_all(const Point & item);
  
  void operator+=(const BoxContainer<Point> & operand);
  
  void operator=(const BoxContainer<Point> & source);
  
  
  private: 
  void expand(size_t new_capacity)
  {
    std::operator<<(std::cout, "Expanding to ").operator<<(new_capacity).operator<<(std::endl);
    Point * new_items_container;
    if(new_capacity <= this->m_capacity) {
      return;
    } 
    
    new_items_container = new Point[]();
    for(size_t i = {}; i < this->m_size; ++i) {
      new_items_container[i].operator=(this->m_items[i]);
    }
    
    delete[] this->m_items;
    this->m_items = new_items_container;
    this->m_capacity = new_capacity;
  }
  
  
  private: 
  Point * m_items;
  size_t m_capacity;
  size_t m_size;
};

#endif
/* First instantiated from: insights.cpp:252 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class BoxContainer<char>
{
  static const size_t DEFAULT_CAPACITY = 5;
  static const size_t EXPAND_STEPS = 5;
  
  public: 
  BoxContainer(size_t capacity)
  : m_capacity{10}
  {
    this->m_items = new char[capacity];
    this->m_capacity = capacity;
    this->m_size = 0;
  }
  
  BoxContainer(const BoxContainer<char> & source);
  
  ~BoxContainer() noexcept
  {
    delete[] this->m_items;
  }
  
  inline size_t size() const;
  
  inline size_t capacity() const;
  
  inline char get_item(size_t index) const;
  
  void add(const char & item)
  {
    if(this->m_size == this->m_capacity) {
      this->expand(this->m_size + EXPAND_STEPS);
    } 
    
    this->m_items[this->m_size] = item;
    ++this->m_size;
  }
  
  bool remove_item(const char & item);
  
  size_t remove_all(const char & item);
  
  void operator+=(const BoxContainer<char> & operand);
  
  void operator=(const BoxContainer<char> & source);
  
  
  private: 
  void expand(size_t new_capacity)
  {
    std::operator<<(std::cout, "Expanding to ").operator<<(new_capacity).operator<<(std::endl);
    char * new_items_container;
    if(new_capacity <= this->m_capacity) {
      return;
    } 
    
    new_items_container = new char[new_capacity];
    for(size_t i = {}; i < this->m_size; ++i) {
      new_items_container[i] = this->m_items[i];
    }
    
    delete[] this->m_items;
    this->m_items = new_items_container;
    this->m_capacity = new_capacity;
  }
  
  
  private: 
  char * m_items;
  size_t m_capacity;
  size_t m_size;
};

#endif


//Free operators
template<typename T>
BoxContainer<T> operator+(const BoxContainer<T> & left, const BoxContainer<T> & right);
;

template<typename T>
inline std::basic_ostream<char> & operator<<(std::basic_ostream<char> & out, const BoxContainer<T> & operand)
{
  operator<<(operator<<(operator<<(operator<<(std::operator<<(out, "BoxContainer : [ size :  "), operand.size()), ", capacity : "), operand.capacity()), ", items : ");
  for(size_t i = {0}; i < operand.size(); ++i) {
    operator<<(operator<<(out, operand.get_item(i)), " ");
  }
  
  std::operator<<(out, "]");
  return out;
}


/* First instantiated from: insights.cpp:246 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
inline std::basic_ostream<char> & operator<<<int>(std::basic_ostream<char> & out, const BoxContainer<int> & operand)
{
  std::operator<<(std::operator<<(std::operator<<(out, "BoxContainer : [ size :  ").operator<<(operand.size()), ", capacity : ").operator<<(operand.capacity()), ", items : ");
  for(size_t i = {0}; i < operand.size(); ++i) {
    std::operator<<(out.operator<<(operand.get_item(i)), " ");
  }
  
  std::operator<<(out, "]");
  return out;
}
#endif



//Definitions moved into here

template <typename T>
BoxContainer<T>::BoxContainer(size_t capacity)
{
	m_items = new T[capacity];
	m_capacity = capacity;
	m_size =0;
}

template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& source)
{
	//Set up the new box
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;
	
	//Copy the items over from source 
	for(size_t i{} ; i < source.size(); ++i){
		m_items[i] = source.m_items[i];
	}
}

template <typename T>
BoxContainer<T>::~BoxContainer()
{
	delete[] m_items;
}


template <typename T>
void BoxContainer<T>::expand(size_t new_capacity){
	std::cout << "Expanding to " << new_capacity << std::endl;
	T *new_items_container;

	if (new_capacity <= m_capacity)
		return; // The needed capacity is already there
	
	//Allocate new(larger) memory
	new_items_container = new T[new_capacity];

	//Copy the items over from old array to new 
	for(size_t i{} ; i < m_size; ++i){
		new_items_container[i] = m_items[i];
	}
	
	//Release the old array
	delete [ ] m_items;
	
	//Make the current box wrap around the new array
	m_items = new_items_container;
	
	//Use the new capacity
	m_capacity = new_capacity;
}

template <typename T>
void BoxContainer<T>::add(const T& item){
	if (m_size == m_capacity)
		//expand(m_size+5); // Let's expand in increments of 5 to optimize on the calls to expand
		expand(m_size + EXPAND_STEPS);
	m_items[m_size] = item;
	++m_size;
}


template <typename T>
bool BoxContainer<T>::remove_item(const T& item){
	
	//Find the target item
	size_t index {m_capacity + 999}; // A large value outside the range of the current 
										// array
	for(size_t i{0}; i < m_size ; ++i){
		if (m_items[i] == item){
			index = i;
			break; // No need for the loop to go on
		}
	}
	
	if(index > m_size)
		return false; // Item not found in our box here
		
	//If we fall here, the item is located at m_items[index]
	
	//Overshadow item at index with last element and decrement m_size
	m_items[index] = m_items[m_size-1];
	m_size--;
	return true;
}


//Removing all is just removing one item, several times, until
//none is left, keeping track of the removed items.
template <typename T>
size_t BoxContainer<T>::remove_all(const T& item){
	
	size_t remove_count{};
	
	bool removed = remove_item(item);
	if(removed)
		++remove_count;
	
	while(removed == true){
		removed = remove_item(item);
		if(removed)
			++ remove_count;
	}
	
	return remove_count;
}

template <typename T>
void BoxContainer<T>::operator +=(const BoxContainer<T>& operand){
	
	//Make sure the current box can acommodate for the added new elements
	if( (m_size + operand.size()) > m_capacity)
		expand(m_size + operand.size());
		
	//Copy over the elements
	for(size_t i{} ; i < operand.m_size; ++i){
		m_items [m_size + i] = operand.m_items[i];
	}
	
	m_size += operand.m_size;
}

template<typename T>
BoxContainer<T> operator+(const BoxContainer<T> & left, const BoxContainer<T> & right)
{
  BoxContainer<T> result = operator+(left.size(), right.size()) /* NRVO variable */;
  result = static_cast<BoxContainer<T>>(static_cast<<dependent type>>(result) + left);
  result = static_cast<BoxContainer<T>>(static_cast<<dependent type>>(result) + right);
  return result;
}


template <typename T>
void BoxContainer<T>::operator =(const BoxContainer<T>& source){
	T *new_items;

	// Check for self-assignment:
	if (this == &source)
            return;
/*
	// If the capacities are different, set up a new internal array
	//that matches source, because we want object we are assigning to 
	//to match source as much as possible.
	*/
	if (m_capacity != source.m_capacity)
	{ 
	    new_items = new T[source.m_capacity];
	    delete [ ] m_items;
	    m_items = new_items;
	    m_capacity = source.m_capacity;
	}
	
	//Copy the items over from source 
	for(size_t i{} ; i < source.size(); ++i){
		m_items[i] = source.m_items[i];
	}
	
	m_size = source.m_size;
}


int main()
{
  std::operator<<(std::cout, "BoxContainer of int : ").operator<<(std::endl);
  BoxContainer<int> int_box = BoxContainer<int>(BoxContainer<int>::DEFAULT_CAPACITY);
  int_box.add(33);
  int_box.add(44);
  operator<<(std::operator<<(std::cout, "int_box : "), int_box).operator<<(std::endl);
  BoxContainer<Point> point_box = BoxContainer<Point>(BoxContainer<Point>::DEFAULT_CAPACITY);
  point_box.add(Point(20.100000000000001, 20.199999999999999));
  point_box.add(Point(200.22, 300.32999999999998));
  BoxContainer<char> char_box = BoxContainer<char>(BoxContainer<char>::DEFAULT_CAPACITY);
  char_box.add('H');
  char_box.add('e');
  return 0;
}

  