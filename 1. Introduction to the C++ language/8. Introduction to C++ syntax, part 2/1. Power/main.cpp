constexpr long long power(const long long &x, unsigned p)
{
    long long result = 1;
    
    for (unsigned i = 0; i < p; ++i)
        result *= x; 
   
    return result;
}