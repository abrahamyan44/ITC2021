#include<iostream>

void  triangle(int a) {
 for(int i = a; i >= 1; --i) {
      for (int s = i; s < a; ++s) {
         std::cout << " ";
      }
      for(int j = 1; j <=  i ; ++j) {
         if(i == a || j == 1 || j == i) {
            std::cout << "* ";
         }
         else {
            std::cout << "  ";
         }
      }
      std::cout<<std::endl;
   }
}

void  triangle_reverse(int a){
 for(int i = 1; i <= a; ++i){
       for (int s = i; s < a; ++s) {
          std::cout << " ";
       }
       for(int j = 1; j <= a; ++j) {
          if( i == a || j == 1 || j == i) {
            std::cout << "* ";
          } else {
            std::cout << "  ";
          }
       }
        std::cout << std::endl;
     }

}



int main()
{
   int r;
   std::cout << "Enter number of rows of triangle: ";
   std::cin >> r;
   triangle(r);
   std::cout << "\n\n";
   triangle_reverse(r);
   return 0;
}
