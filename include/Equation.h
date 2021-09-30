#pragma once
#include <vector>

struct Axis {
    double x;
    double z;
    double t;
};
struct Parametrs {
    double a;
    double b;
    double c;

};

class Term { 
public:
    Term(char o, double p) {
        op = o; number = p;
    }
    double Done(double num) {
        if (op == '+') {
            num += number;
        } if (op == '-') {
            num -= number;
        }
        return num;
    }
private:
    char op;
    double number;
};

class NumberOfTerm {
public:
    void AddTerm(char op, double n) {
        terms.push_back({op,n});
    }
    double Execute(double num) {
        for (Term term : terms) {
            num += term.Done(num);
        }
        return num;
    }

private:
    std::vector<Term> terms;

};

double EvaluateX(Axis ax, Parametrs p, double Y);
double EvaluateX(Parametrs p, Axis a, double Y);
double EvaluateY(Axis ax, Parametrs p);
double EvaluateY(Parametrs p, Axis a);
NumberOfTerm MakeY(Parametrs p, Axis ax);
NumberOfTerm MakeX(Parametrs p, Axis ax);