struct Rational
{
    Rational(int numerator = 0, int denominator = 1);
    
    bool is_null() {
        return numerator_ == 0;
    }
    
    bool is_neg() {
        return (numerator_ < 0) ^ (denominator_ < 0);
    }

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator==(const Rational &lhs,
                const Rational &rhs) {
    return (lhs - rhs).is_null();
}

bool operator!=(const Rational &lhs,
                const Rational &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational &lhs,
               const Rational &rhs) {
    return (lhs - rhs).is_neg();
}

bool operator>(const Rational &lhs,
               const Rational &rhs) {
    return rhs < lhs;
}

bool operator<=(const Rational &lhs,
                const Rational &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Rational &lhs,
                const Rational &rhs) {
    return !(lhs < rhs);
}