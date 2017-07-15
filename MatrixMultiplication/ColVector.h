#include "Matrix.h"
#include "RowVector.h"
#include "ASSERT.h"
template <unsigned int NUM_ELEMENTS>
class ColVector:Matrix<NUM_ELEMENTS,1>{
public:
    ColVector<NUM_ELEMENTS>():Matrix<NUM_ELEMENTS,1>(){}
    ColVector<NUM_ELEMENTS>(const double(& initializer)[NUM_ELEMENTS]):Matrix<NUM_ELEMENTS,1>(){
        for(int i=0;i<NUM_ELEMENTS;i++){
            this->data[i][0]=initializer[i];
        }
    }
    double& operator[] (unsigned int which){
        ASSERT(which>=0,"bound check on ColVect failed: which of %d was negative",which);
        ASSERT(which<NUM_ELEMENTS,"bound check on ColVect failed: which of %d greator or equal to NUM_ELEMENTS, %d",which,NUM_ELEMENTS);
        return this->data[which][0];
    }
    template <unsigned int OTHER_COLS>
    ColVector<NUM_ELEMENTS> operator *(const Matrix<NUM_ELEMENTS,OTHER_COLS>& other){
        return (*this)*other;
    }
    ColVector<NUM_ELEMENTS> hammondProd(const ColVector<NUM_ELEMENTS>& other)const {
        ColVector<NUM_ELEMENTS> product;
        for(unsigned int i=0;i<NUM_ELEMENTS;i++){
            product.data[i][0]=this->data[i][0]*other.data[i][0];
        }
        return product;
    }
    double dotProd(const ColVector<NUM_ELEMENTS>& other) const{
        double dotP=0;
        for(unsigned int i=0;i<NUM_ELEMENTS;i++){
            dotP+=this->data[i][0]*other.data[i][0];
        }
        return dotP;
    }
    RowVector<NUM_ELEMENTS> transpose(){
        return this->transpose();
    }
};
