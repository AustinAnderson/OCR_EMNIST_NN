#include<iostream>
#include<iomanip>
#include<vector>
//TODO: define for non-nested vectors
template<typename T>
bool operator==(const std::vector<std::vector<T> >& op1,const std::vector<std::vector<T> >& op2){
    bool equal=true;
    if(op1.size()==op2.size()){
        for(int i=0;i<op1.size();i++){//for each vector in 
            if(op1[i].size()==op2[i].size()){
                for(int j=0;j<op1[i].size();j++){
                    if(op1[i][j]!=op2[i][j]){
                        equal=false;
                    }
                }
            }else{
                equal=false;
            }
        }
    }else{
        equal=false;
    }
    return equal;
}
template<typename T>
std::ostream& operator<<(std::ostream& os,const std::vector<std::vector<T> >& vect){
    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            os<<vect[i][j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}
class Assert{
public:
    static void startNamedTest(std::string name){
        std::cout<<std::setw(50)<<name<<": ";
    }
    static void endTestWithResult(bool pass){
        if(pass){
            std::cout<<" PASS\n";
        }else{
            std::cout<<" FAIL\n";
        }
    }
    template<typename T>
    static void equals(std::string testName,std::string message,const T& expected, const T& actual){
        startNamedTest(testName);
        if(!(expected==actual)){
            std::cout<<" FAIL\n";
            std::cout<<message<<std::endl;
            std::cout<<"expected: "<<expected<<std::endl;
            std::cout<<"got: "<<actual<<std::endl;
            std::cout<<std::endl;
        }else{
            std::cout<<" PASS\n";
        }
    }
};

