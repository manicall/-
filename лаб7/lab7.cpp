#include "ListOfPoints.h"

int main()
{
	setlocale(LC_ALL, "ru");
	ListOfPoints List;

	try {
		List.insert(xyPoint(1, 2), 0);
		List.print_list();
		List.insert(xyPoint(4, 5), 1);
		List.print_list();
		List.insert(xyPoint(40, 50), 2);
		List.print_list();
		List.insert(xyPoint(400, 500), 1);
		List.print_list();
		List.insert(xyPoint(33, 33), 1);
		List.print_list();
		List.insert(xyPoint(1, 111), 4);
		List.print_list();
		List.insert(xyPoint(55, 55), 2);
		List.print_list();
		List.insert(xyPoint(44, 44), 3);
		List.print_list();
		List.insert(xyPoint(11, 11), 3);
		List.print_list();
		List.insert(xyPoint(1, 1), 8);
		List.print_list();
		List.insert(xyPoint(2, 2),8);
		List.print_list();
		List.insert(xyPoint(3, 3), 8);
		List.print_list();
		List.insert(xyPoint(4, 4), 7);
		List.print_list();
		List.pop(3);
		List.print_list();
		List.pop(0);
		List.print_list();
		List.pop(List.get_size() - 3);
		List.print_list();
		//std::cout << List.at(10);
		//List.pop(-10);
	}
	catch (std::exception ex) { std::cerr << ex.what()<<std::endl; }

}