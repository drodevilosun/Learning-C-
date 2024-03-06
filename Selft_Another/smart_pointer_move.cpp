#include <iostream>
#include <memory>



int main(){

	std::cout << "------" << std::endl;

    std::unique_ptr<int> ptr_int = std::make_unique<int>(33);

	std::cout << "*ptr_int : " << *ptr_int << std::endl;

	// // steal the data from ptr_int
	std::unique_ptr<int> ptr_int_copy1 = std::move(ptr_int);


	if(ptr_int){
		std::cout << "*ptr_int : " << *ptr_int << std::endl;
	}else{
		std::cout << "ptr_int doesn't contain any valid data" << std::endl;
	}

	std::cout << "*ptr_int_copy1 : " << *ptr_int_copy1 << std::endl;



  
    return 0;
}