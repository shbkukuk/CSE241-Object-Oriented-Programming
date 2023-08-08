#ifndef PFARRAYD_H
#define PFARRAYD_H
#include<string>

using std::string;
class Exception
{
};
class OutOfRange:public Exception
{
    public:
        OutOfRange(string thisMessage,int thisIndex);
        string getMessage()const;
        int getIndex()const;
    private:
        string message;
        int index;
};
//Objectsofthisclassarepartiallyfilledarraysofdoubles.
class PFArrayD
{
    public:
        PFArrayD();
        //Initializeswithacapacityof50.
        PFArrayD(int capacityValue);
        PFArrayD(const PFArrayD&pfaObject);
        void addElement(double element);
        bool full() const { return ( capacity == used);}
        // Re turns t r u e i f t h e arr a y i s f u l l , f a l s e o t h e r w i s e .
        int getCapacity() const { return capacity; }
        int getNumberUsed ( ) const { return used ; }
        void emptyArray ( ){ used = 0 ;}
        // Empt ies t h e arr a y .
        double& operator [] (int index);
        //Read and change a c c e s s t o elemen t s 0 t h r o ug h numberUsed − 1 .
        
        ~PFArrayD();
    private :
        double *a; // f o r an arr a y o f d o u bl e s .
        int capacity; // f o r t h e s i z e o f t h e arr a y .
        int used ; // f o r t h e number o f arr a y p o s i t i o n s c u r r e n t l y in use .
} ;
#endif 
