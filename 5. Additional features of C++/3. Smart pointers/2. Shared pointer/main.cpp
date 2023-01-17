#include <utility>

struct Number;
struct Expression;
struct BinaryOperation;

struct SharedPtr
{
    explicit SharedPtr(Expression * ptr = 0)
        : m_ptr(ptr), m_counter(0) {
        if (m_ptr)
            m_counter = new size_t(1);
    }
    
    SharedPtr(const SharedPtr &other)
        : m_ptr(other.m_ptr),
          m_counter(other.m_counter) {
        if (m_ptr)
	        ++(*m_counter);
    }

    ~SharedPtr() {
        if (m_ptr && --(*m_counter) == 0) {
            delete m_ptr;
            delete m_counter;
        }
    }

    Expression * get() const {
        return m_ptr;
    }

    void reset(Expression * other = 0) {
        SharedPtr(other).swap(*this);
    }

    void swap(SharedPtr &other) {
        std::swap(m_ptr, other.m_ptr);
        std::swap(m_counter, other.m_counter);
    }

    SharedPtr& operator=(const SharedPtr &other) {
        if (this != &other)
            SharedPtr(other).swap(*this);

        return *this;
    }

    Expression& operator*() const {
        return *m_ptr;
    }

    Expression* operator->() const {
        return m_ptr; }

private:
    Expression * m_ptr;
    size_t * m_counter;
};