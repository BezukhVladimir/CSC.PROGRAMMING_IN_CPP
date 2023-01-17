struct Expression
{
    virtual ~Expression() {}
    virtual double evaluate() const = 0;   
};

struct Number : Expression
{
    Number(double value) : value(value) {}
    double evaluate() const override;
    
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left,
                    char op,
                    Expression const * right)
        : left(left), op(op), right(right) {}
    ~BinaryOperation();
    double evaluate() const override;

private:
    Expression const * left;
    Expression const * right;
    char op;
};

double Number::evaluate() const {
    return value;
}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}

double BinaryOperation::evaluate() const {
    switch (op) {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            if (right->evaluate())
                return left->evaluate() / right->evaluate();
        default:
            return 0.0;
    }
}