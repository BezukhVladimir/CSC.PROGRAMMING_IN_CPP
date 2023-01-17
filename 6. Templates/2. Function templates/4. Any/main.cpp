struct ICloneable;
 
template <typename T>
struct ValueHolder;
 
class Any
{
public:
    Any() : ptr(nullptr) {} 
 
    ~Any() { delete ptr; }
 
    Any(const Any &other) : 
        ptr(other.ptr ? other.ptr->clone() : nullptr) {}
   
    template<typename T>
    Any(const T& val) : 
        ptr(new ValueHolder<T>(val)) {}
    
    Any& operator=(const Any &other) {
        if(this != &other) {
            delete ptr;
            ptr = other.ptr ? other.ptr->clone() : nullptr;
        }
 
        return *this;
    }
    
    template<typename T>
    Any& operator=(const T &val) {
        delete ptr;
        ptr = new ValueHolder<T>(val);
        
        return *this;
    }
    
    template<typename T>
    T * cast() {
        if (ptr == nullptr)
            return 0;
        else {
            ValueHolder<T> * pvh = dynamic_cast<ValueHolder<T>*>(ptr);
            return pvh != nullptr ? &(pvh->data_) : nullptr;
        }
    }
    
private:
    ICloneable * ptr;
};