#include <iostream>
#include <cassert>
#include <type_traits>
template <unsigned int ROWS, unsigned int COLS>
class Matrix{
public:
    template <unsigned int NEWROW,unsigned int NEWCOL>
    friend class Matrix;//all matricies of any size can access any other size's private members


    Matrix<ROWS,COLS>(){
        data=new double*[ROWS];
        for(unsigned int i=0;i<ROWS;i++){
            data[i]=new double[COLS];
        }
    }
    Matrix<ROWS,COLS>(const double(& initializer)[ROWS][COLS]){
        data=new double*[ROWS];
        for(unsigned int i=0;i<ROWS;i++){
            data[i]=new double[COLS];
            for(unsigned int j=0;j<COLS;j++){
                this->data[i][j]=initializer[i][j];
            }
        }
    }
    Matrix<ROWS,COLS>& operator *=(const Matrix<COLS,ROWS>& other){
        static_assert(ROWS==COLS,"*= only valid if src and target are both same size square Matricies");
        (*this)=(*this)*other;
    }
    template <unsigned int OTHER_COLS>
    Matrix<ROWS,OTHER_COLS> operator *(const Matrix<COLS,OTHER_COLS>& other){
        Matrix<ROWS,OTHER_COLS> product;
        for(unsigned int i=0;i<ROWS;i++){
            for(unsigned int j=0;j<OTHER_COLS;j++){
                for(unsigned int k=0;k<COLS;k++){
                    product.data[i][j]+=(data[i][k]*other.data[k][j]);
                }
            }
        }
        return product;
    }

    Matrix<COLS,ROWS> transpose(){
        Matrix<COLS,ROWS> transposed;
        for(unsigned int i=0;i<ROWS;i++){
            for(unsigned int j=0;j<COLS;j++){
                transposed.data[j][i]=data[i][j];
            }
        }
        return transposed;
    }

    Matrix<ROWS,1> colVectHammondProd(const Matrix<ROWS,1>& other)const {
        static_assert(COLS==1,"hammondProd only valid for two vectors");
        Matrix<ROWS,1> product;
        for(unsigned int i=0;i<ROWS;i++){
            product.data[i][0]=this->data[i][0]*other.data[i][0];
        }
        return product;
    }
    double dotProd(const Matrix<ROWS,1>& other) const{
        static_assert(COLS==1,"dotProd only valid for two vectors");
        double dotP=0;
        for(unsigned int i=0;i<ROWS;i++){
            dotP+=this->data[i][0]*other.data[i][0];
        }
        return dotP;
    }
    Matrix<1,COLS> rowVectHammondProd(const Matrix<1,COLS>& other)const {
        static_assert(ROWS==1,"hammondProd only valid for two vectors");
        Matrix<1,COLS> product;
        for(unsigned int i=0;i<COLS;i++){
            product.data[0][i]=this->data[0][i]*other.data[0][i];
        }
        return product;
    }
    double dotProd(const Matrix<1,COLS>& other) const{
        static_assert(ROWS==1,"dotProd only valid for two vectors");
        double dotP=0;
        for(unsigned int i=0;i<COLS;i++){
            dotP+=this->data[0][i]*other.data[0][i];
        }
        return dotP;
    }

    friend std::ostream& operator<<(std::ostream& os,const Matrix<ROWS,COLS>& mat){
        for(unsigned int i=0;i<ROWS;i++){
            for(unsigned int j=0;j<COLS;j++){
                os<<mat.data[i][j]<<" ";
            }
            os<<std::endl;
        }
    }

    template <unsigned int OTHER_ROWS,unsigned int OTHER_COLS>
    bool operator != (const Matrix<OTHER_ROWS,OTHER_COLS>& )const{ return true;}

    template <unsigned int OTHER_ROWS,unsigned int OTHER_COLS>
    bool operator == (const Matrix<OTHER_ROWS,OTHER_COLS>&)const{ return false;} 

    bool operator != (const Matrix<ROWS,COLS>& other) const { 
        return !(*this==other);
    }
    bool operator == (const Matrix<ROWS,COLS>& other) const {
        bool equal=true;
        for(unsigned int i=0;i<ROWS;i++){
            for(unsigned int j=0;j<COLS;j++){
                if(data[i][j]!=other.data[i][j]){
                    equal=false;
                    break;
                }
            }
        }
        return equal;
    }

    double& operator()(unsigned int r, unsigned int c){
        assert(r>=0&&r<ROWS);
        assert(c>=0&&c<COLS);
        return data[r][c];
    }
    Matrix<ROWS,COLS>& operator=(const Matrix<ROWS,COLS>& other){
        for(unsigned int i=0;i<ROWS;i++){
            for(unsigned int j=0;j<COLS;j++){
                this->data[i][j]=other.data[i][j];
            }
        }
        return *this;
    }
    ~Matrix(){
        for(unsigned int i=0;i<ROWS;i++){
            delete[] data[i];
        }
        delete[] data;
    }
private:

    double** data;
    Matrix<ROWS,COLS>(Matrix<ROWS,COLS>& toCopy):Matrix(){
        *this=toCopy;
    }
};
