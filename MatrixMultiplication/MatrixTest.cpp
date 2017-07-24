#include "Matrix.h"
#include "TestAsserts.h"
#include <vector>
int main(){
    RowVector<2> row_2({
        {2,2}
    });
    Matrix<2,2> mat_2_2({
        {1,2},
        {3,4}
    });
    ColVector<2> col_2({
        {3},
        {6}
    });
    Matrix<2,4> mat_2_4({
        {1,2,3,4},
        {3,4,5,6}
    });
    RowVector<4> row_4({
        {1,5,2,3}
    });
    Matrix<4,4> mat_4_4({
        {-2, 0,-3, 9},
        {-8, 0,-5, 9},
        {-1,-6,-2, 8},
        { 0, 0,-2, 6}
    });
    Matrix<4,2> mat_4_2({
        {-2,-2},
        { 8,-7},
        {-5, 9},
        {-7,-5}
    });

    Matrix<1,1> cell({{2}});

    Matrix<4,2> mat_2_4$T({
        {1,3},
        {2,4},
        {3,5},
        {4,6}
    });


    Assert::startNamedTest("test indexing");
    std::vector<std::vector<double> > expected={
        {1,2,3,4},
        {3,4,5,6}
    };
    std::vector<std::vector<double> > actual={
        {mat_2_4(0,0),mat_2_4(0,1),mat_2_4(0,2),mat_2_4(0,3)},
        {mat_2_4(1,0),mat_2_4(1,1),mat_2_4(1,2),mat_2_4(1,3)}
    };
    bool equal=true;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(expected[i][j]!=actual[i][j]){
                equal=false;
            }
        }
    }
    Assert::endTestWithResult(equal);
    if(!equal){
        std::cout<<"expected:"<<std::endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                std::cout<<expected[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<"got:"<<std::endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                std::cout<<actual[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }


    

    Assert::equals("rowvect.dotProd(rowvect)","row vector dot product failed",8.0,row_2.dotProd(row_2));
    Assert::equals("colvect.dotprod(colvect)","column vector dot product failed",45.0,col_2.dotProd(col_2));
    Assert::equals("1x1.dotprod(1x1)","single cell dot product failed",4.0,cell.dotProd(cell));

    Assert::equals("rowvect.HammondProd(rowvect)","row vector hammond product failed ([1,5,2,3] with self)",RowVector<4> ({{1,25,4,9}}),row_4.HammondProd(row_4));
    Assert::equals("colvect.HammondProd(colvect)","column vector hammond product failed ([3,6]T with self)",
        ColVector<2> ({
            {9},
            {36}
        }),
        col_2.HammondProd(col_2)
    );
    Assert::equals("1x1.HammondProd(1x1)","single cell hammond product failed ([2] with self)",Matrix<1,1> ({{4}}),cell.HammondProd(cell));

    Assert::equals("rowvect*mat","vector times matrix failed",RowVector<2>({{8,12}}),(row_2*mat_2_2));
    Assert::equals("mat*colvect","matrix times column vector failed",
        ColVector<2>({
            {15},
            {33}
        }),
        (mat_2_2*col_2)
    );
    Assert::equals("squareMat*longMat","[2x2]*[2x4] failed",
        Matrix<2,4>({
            {7,10,13,16},
            {15,22,29,36}
        }),
        (mat_2_2*mat_2_4)
    );
    Assert::equals("squareMat*tallMat","[4x4]*[4x2] failed",
        Matrix<4,2>({
            {-44,-68},
            {-22,-74},
            {-92,-14},
            {-32,-48}
        }),
        (mat_4_4*mat_4_2)
    );
    Assert::equals("squareMat*squareMat","[4x4]*[4x4] failed",
        Matrix<4,4>({
            {  7, 18, -6, 12},
            { 21, 30, 16,-58},
            { 52, 12, 21,-31},
            {  2, 12, -8,-20}
        }),
        (mat_4_4*mat_4_4)
    );
    Assert::equals("longMat*squareMat","[2x4]*[4x4] failed",
        Matrix<2,4>({
            { -21, -18, -27, 75},
            { -43, -30, -51,139}
        }),
        (mat_2_4*mat_4_4)
    );
    Assert::equals("tallMat*squareMat","[4x2]*[2x2] failed",
        Matrix<4,2>({
            { -8,-12},
            {-13,-12},
            { 22, 26},
            {-22,-34}
        }),
        (mat_4_2*mat_2_2)
    );
    Assert::equals("longMat*tallMat","[2x4]*[4x2] failed",
        Matrix<2,2>({
            {-29, -9},
            {-41,-19}
        }),
        (mat_2_4*mat_4_2)
    );
    Assert::equals("tallMat*longMat","[4x2]*[2x4] failed",
        Matrix<4,4>({
            { -8,-12,-16,-20},
            {-13,-12,-11,-10},
            { 22, 26, 30, 34},
            {-22,-34,-46,-58}
        }),
        (mat_4_2*mat_2_4)
    );

    Assert::equals("colvect transpose","columnVec to row transpose failed",
        ColVector<2> ({
            {2},
            {2}
        }),
        row_2.transpose()
    );
    Assert::equals("squareMat transpose","squareMat transpose failed",
        Matrix<2,2> ({
            {1,3},
            {2,4}
        }),
        mat_2_2.transpose()
    );
    Assert::equals("longMat transpose","2x4 matrix transpose failed",mat_2_4$T,mat_2_4.transpose());
    Assert::equals("tallMat transpose","4x2 matrix transpose failed",mat_2_4,mat_2_4$T.transpose());
    Assert::equals("rowvect transpose","rowVec to col transpose failed",
        RowVector<2> ({
            {3,6}
        }),
        col_2.transpose()
    );

    return 0;
}
