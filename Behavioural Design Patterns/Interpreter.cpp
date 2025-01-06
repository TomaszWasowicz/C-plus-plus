/*

The Interpreter Pattern is used to define a grammar 
for a language and provide an interpreter 
to evaluate sentences in that language

Explanation:
1. Expression Interface:
- Defines the interpret method, which is implemented by all concrete expressions.
2. Terminal Expressions:
- VariableExpression evaluates variables based on a given context.
- ConstantExpression directly returns a constant value.
3. Non-Terminal Expressions:
- AddExpression and SubtractExpression combine other expressions.
4. Context:
- A map holding variable values that the VariableExpression can query.
5. Client Code:
- Builds a composite expression tree, interprets it, and prints the result.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

// Abstract base class for expressions
class Expression {
public:
    virtual ~Expression() = default;

    // Method to interpret the expression
    virtual int interpret(const std::unordered_map<std::string, int>& context) const = 0;
};

// Terminal expression for variables
class VariableExpression : public Expression {
    std::string name;

public:
    explicit VariableExpression(const std::string& variableName) : name(variableName) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        auto it = context.find(name);
        if (it != context.end()) {
            return it->second;
        }
        throw std::invalid_argument("Variable not found in context: " + name);
    }
};

// Terminal expression for constants
class ConstantExpression : public Expression {
    int value;

public:
    explicit ConstantExpression(int val) : value(val) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        return value; // Constant has a fixed value
    }
};

// Non-terminal expression for addition
class AddExpression : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    AddExpression(std::unique_ptr<Expression> leftExpr, std::unique_ptr<Expression> rightExpr)
        : left(std::move(leftExpr)), right(std::move(rightExpr)) {
    }

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        return left->interpret(context) + right->interpret(context);
    }
};

// Non-terminal expression for subtraction
class SubtractExpression : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

public:
    SubtractExpression(std::unique_ptr<Expression> leftExpr, std::unique_ptr<Expression> rightExpr)
        : left(std::move(leftExpr)), right(std::move(rightExpr)) {
    }

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        return left->interpret(context) - right->interpret(context);
    }
};

// Client code to test the Interpreter pattern
int main() {
    // Context: defines the values of variables
    std::unordered_map<std::string, int> context = { {"x", 10}, {"y", 20}, {"z", 5} };

    // Construct the expression: (x + y) - z
    auto expression = std::make_unique<SubtractExpression>(
        std::make_unique<AddExpression>(
            std::make_unique<VariableExpression>("x"),
            std::make_unique<VariableExpression>("y")
        ),
        std::make_unique<VariableExpression>("z")
    );

    // Interpret and evaluate the expression
    try {
        std::cout << "Result: " << expression->interpret(context) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
