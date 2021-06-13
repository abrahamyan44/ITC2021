#include <iostream>


void print_matrix(int** matrix, int r){
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<r;++j)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}


void give_values_matrix(int** matrix ,int r)
{
    for(int i=0;i<r;++i){
        for(int j=0;j<r;++j)
        {
            if(j>i){
                matrix[i][j]=0;
                }
                else if(j<i)
                {
                    matrix[i][j]=1;
                }
                else
                {
                    matrix[i][j]=2;
                }
        }
    }
    print_matrix(matrix,r);
} 


int main()
{
    int size;
    while(true){
    std::cout<<"size=";
    std::cin>>size;
        if(size<0){
        break;
        }
       else if(size<2){
             std::cout<<"Please input size more then 4"<<std::endl;
        }
    int** matrix = new int*[size];
    for(int i=0;i<size;++i)
    {
         matrix[i] = new int[size];
    }
    give_values_matrix(matrix,size);
    }
return 0;
}
