struct Rational
{
    Rational(int numerator = 0, int denominator = 1);
    
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    const Rational operator+() const {
        return *this;
    }
    const Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }
    Rational& operator+=(const Rational &right) {
        this->add(right);
        return *this;
    }
    Rational& operator-=(const Rational &right) {
        this->sub(right);
        return *this;
    }
    Rational& operator*=(const Rational &right) {
        this->mul(right);
        return *this;
    }
    Rational& operator/=(const Rational &right) {
        this->div(right);
        return *this;
    }
    
private:
    int numerator_;
    int denominator_;
};