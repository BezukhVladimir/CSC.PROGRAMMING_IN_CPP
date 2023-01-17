constexpr unsigned gcd(const unsigned &a,
                       const unsigned &b) {
    return b ? gcd(b, a % b) : a;
}