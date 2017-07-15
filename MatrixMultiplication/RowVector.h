#include "Matrix.h"
#include "ColVector.h"
#include "ASSERT.h"
template <unsigned int NUM_ELEMENTS>
class RowVector:Matrix<1,NUM_ELEMENTS>{
public:
    RowVector<NUM_ELEMENTS>():Matrix<1,NUM_ELEMENTS>(){}
    RowVector<NUM_ELEMENTS>(const double(& initializer)[NUM_ELEMENTS]):Matrix<1,NUM_ELEMENTS>({initializer}){}

    double& operator[] (unsigned int which){
        ASSERT(which>=0,"bound check on RowVect failed: which of %d was negative",which);
        ASSERT(which<NUM_ELEMENTS,"bound check on RowVect failed: which of %d greator or equal to NUM_ELEMENTS, %d",which,NUM_ELEMENTS);
        return this->data[0][which];
    }
    template <unsigned int OTHER_COLS>
    RowVector<NUM_ELEMENTS> operator *(const Matrix<NUM_ELEMENTS,OTHER_COLS>& other){
        return (*this)*other;
    }
    RowVector<NUM_ELEMENTS> hammondProd(const RowVector<NUM_ELEMENTS>& other)const {
        RowVector<NUM_ELEMENTS> product;
        for(unsigned int i=0;i<NUM_ELEMENTS;i++){
            product.data[0][i]=this->data[0][i]*other.data[0][i];
        }
        return product;
    }
    double dotProd(const ColVector<NUM_ELEMENTS>& other) const{
        double dotP=0;
        for(unsigned int i=0;i<NUM_ELEMENTS;i++){
            dotP+=this->data[0][i]*other.data[0][i];
        }
        return dotP;
    }
    ColVector<NUM_ELEMENTS> transpose(){
        return this->transpose();
    }
};
