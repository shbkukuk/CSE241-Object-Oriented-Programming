#include <iostream>
using namespace std;

class Polynominal{
    public:
        Polynominal();
        Polynominal(double *coeffients, int degree);
        Polynominal(Polynominal &eqution); // copy constructor
        friend const Polynominal operator +(const Polynominal& equation1);
        friend const Polynominal operator -(const Polynominal& equation1);
        friend const Polynominal operator *(const Polynominal& equation1);
        friend const Polynominal operator =(const Polynominal& equation1);
        void evuluate();
        ~Polynominal();
        

    private:
        typedef char *coefficients;
        int degree;

};

int main()
{
Polynomial empty;
double one[] = {1};
Polynomial One(one, 1);
double quad[] = {3, 2, 1};
double cubic[] = {1, 2, 0, 3};
Polynomial q(quad, 3); // q is 3 + 2*x + x*x
Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
Polynomial p = q; // test copy constructor
Polynomial r;
r = q; //test operator=
r = c;
cout << "Polynomial q " << endl;
{for(int i = 0; i < 3; i++)
cout << "term with degree " << i
<< " has coefficient " << q[i] << endl;
}
cout << "Polynomial c " << endl;
{for(int i = 0; i < 4; i++)
cout << "term with degree " << i
<< " has coefficient " << c[i] << endl;
}
cout << "value of q(2) is " << evaluate(q, 2) << endl;
cout << "value of p(2) is " << evaluate(p, 2) << endl;
cout << "value of r(2) is " << evaluate(r, 2) << endl;
cout << "value of c(2) is " << evaluate(c, 2) << endl;
r = q + c;
cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
r = q - c;
cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
r = q * c;
cout << "size of q*c is " << r.mySize() << endl;
cout << "Polynomial r (= q*c) " << endl;
for(int i = 0; i < r.mySize(); i++)
cout << "term with degree " << i
<< " has coefficient " << r[i] << endl;
cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
return 0;
}


Polynominal::Polynominal(){
    degree = 0;
    coefficients c;
    c = new double[1];
    c[0] = 0;

}
Polynominal::Polynominal(double coeffients, int degree){
    coefficients *x = new coefficients[degree];


}

Polynominal::~Polynominal(){
    delete [] coefficients;
}

const Polynominal operator +(const Polynominal& equation1){
    int maxDegree = std::max(degree, equation1.degree);
        double* resultCoefficients = new double[maxDegree+1];
        for (int i = 0; i <= maxDegree; i++) {
            double a = (i <= degree) ? coefficients[i] : 0;
            double b = (i <= equation1.degree) ? equation1.coefficients[i] : 0;
            resultCoefficients[i] = a + b;
        }
        Polynomial result(maxDegree, resultCoefficients);
        delete[] resultCoefficients;
        return result;

}
const Polynominal operator -(const Polynominal& equation1){
    int maxDegree = std::max(degree, equation1.degree);
        double* resultCoefficients = new double[maxDegree+1];
        for (int i = 0; i <= maxDegree; i++) {
            double a = (i <= degree) ? coefficients[i] : 0;
            double b = (i <= equation1.degree) ? equation1.coefficients[i] : 0;
            resultCoefficients[i] = a - b;
        }
        Polynomial result(maxDegree, resultCoefficients);
        delete[] resultCoefficients;
        return result;

}
const Polynominal operator *(const Polynominal& equation1){
    int resultDegree = degree + equation1.degree;
        double* resultCoefficients = new double[resultDegree+1];
        for (int i = 0; i <= resultDegree; i++) {
            resultCoefficients[i] = 0;
        }
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= equation1.degree; j++) {
                resultCoefficients[i+j] += coefficients[i] * equation1.coefficients[j];
            }
        }
        Polynomial result(resultDegree, resultCoefficients);
        delete[] resultCoefficients;
        return result;

}
const Polynominal operator =(const Polynominal& equation1){
    if (this != &equation1) {
            delete[] coefficients;
            degree = equation1.degree;
            coefficients = new double[degree+1];
            for (int i = 0; i <= degree; i++) {
                coefficients[i] = equation1.coefficients[i];
            }
        }
        return *this;

}
