struct ICloneable
{
	virtual ICloneable * clone() const = 0;
	virtual ~ICloneable() {}
};

template <typename T>
struct ValueHolder : ICloneable 
{
    T data;
    
    ValueHolder(T const &val) {
        new (&data) T(val);
    }
    
    ValueHolder * clone() const {
        return new ValueHolder(data);
    }
};