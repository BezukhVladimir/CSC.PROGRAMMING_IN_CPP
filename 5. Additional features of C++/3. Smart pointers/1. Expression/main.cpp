struct Number;
struct Expression;
struct BinaryOperation;
 
struct ScopedPtr 
{
    explicit ScopedPtr(Expression * ptr = 0) {
        m_ptr = ptr;
    }
    
    ~ScopedPtr() {
        delete m_ptr;
    }
    
    Expression * get() const {
        return m_ptr;
    }
    
    Expression * release() {
        Expression * ptr = m_ptr;
        m_ptr = nullptr;
        return ptr;
    }
    
    void reset(Expression * ptr = 0) {
        delete m_ptr;
        m_ptr = ptr;
    }
    
    Expression& operator*() const {
        return *m_ptr;
    }
    
    Expression* operator->() const {
        return m_ptr;
    }
    
private:
    ScopedPtr& operator=(const ScopedPtr &other) {}
    ScopedPtr(const ScopedPtr &other) {}
    Expression * m_ptr;
};