#include "Matrix.h"
#include "ASSERT.h"

/*
template <unsigned int expectedR,unsigned int expectedC, unsigned int actualR, unsigned int actualC>
void assertEquals(std::string message,const Matrix<expectedR,expectedC>& expected,const Matrix<actualR,actualC>& actual ){
    if(expected!=actual){
        std::cerr<<message<<std::endl;
        std::cerr<<"expected: "<<expected<<std::endl;
        std::cerr<<"got: "<<actual<<std::endl;
    }
}
*/
int main(){
    /*
    Matrix<1,2> a({
        {2,2}
    });
    Matrix<2,2> b({
        {1,2},
        {3,4}
    });
    Matrix<2,1> c({
        {3},
        {6}
    });

    Matrix<1,2> expectedAB({
        {8,12}
    });
    Matrix<2,1> expectedBC({
        {15},
        {33}
    });

    Matrix<2,1> expectedA_T({
        {2},
        {2}
    });
    Matrix<2,2> expectedB_T({
        {1,3},
        {2,4}
    });
    Matrix<1,2> expectedC_T({
        {3,6}
    });

    assertEquals("vector times matrix failed",expectedAB,(a*b));
    assertEquals("matrix times column vector failed",expectedBC,(b*c));
    assertEquals("columnVec to row transpose failed",expectedA_T,a.transpose());
    assertEquals("squareMat transpose failed",expectedB_T,b.transpose());
    assertEquals("rowVec to col transpose failed",expectedC_T,c.transpose());
    //*/

    ASSERT(1==2,"bounds check %d failed",2);
    std::cout<<"asdf"<<std::endl;
    return 0;
}
