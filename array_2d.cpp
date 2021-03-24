#include <iostream>

int main()
{
        int row, column;
        std::cout << "Please enter a row size ~ " << std::endl;
        std::cin >> row;
        std::cout << "Please enter a column size ~ " << std::endl;
        std::cin >> column;

        while ( column!=row )
        {
            std::cout << "Please enter the same number as entered for the row ~ " << std::endl;
            std::cin >> column;
        }

        std::cout << std::endl;
    
    int** array = new int*[row];
    for ( int i=0; i < row; i++ )
    {
            array[i] = new int[column];
    }

    for ( int i=0; i < row; i++ )
    {
            for (int j=0; j < column; j++ )
            {
                    if ( i<j )
                    {
                            array[i][j]=1;
                    } 

                    else if ( i==j )
                    {
                            array[i][j]=2;
                    }

                    else
                    {
                            array[i][j]=0;
                    }

            }
    }

    for ( int i=0; i < row; i++ )
    {
            for (int j=0; j < column; j++ )
            {
                    std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
    }

        return 0;
}
