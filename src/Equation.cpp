#include "Equation.h"
#include <vector>
using namespace std;



NumberOfTerm MakeY(Parametrs p, Axis ax) { 
    NumberOfTerm func;
    func.AddTerm('-',ax.z * p.a + p.b);
    func.AddTerm('+', ax.t * p.c);
    return func;
}

NumberOfTerm MakeX(Parametrs p, Axis ax) { 
    NumberOfTerm func;
    func.AddTerm('+',ax.z * p.a + p.b);
    func.AddTerm('-', ax.t * p.c);
    return func;
}

double EvaluateY(Parametrs p, Axis a) {
    NumberOfTerm func = MakeY(p, a);
    return func.Execute(a.x);
}

// double EvaluateY(Axis ax, Parametrs p) {
//     double Y;
//     Y = ax.x;
//     Y -= ax.z * p.a + p.b;
//     Y += ax.t * p.c;
//     return Y;
// }
 
double EvaluateX(Axis ax, Parametrs p, double Y) {
    double X;
    X = Y;
    X += ax.z * p.a + p.b;
    X -= ax.t * p.c;
    return X;
}

double EvaluateX(Parametrs p, Axis a, double Y) {
    NumberOfTerm func = MakeX(p, a);
    return func.Execute(Y);
}
