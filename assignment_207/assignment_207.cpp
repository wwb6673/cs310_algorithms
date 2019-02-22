/**
 * @author William Briggs
 * @version 2/2/2019
 *
 * This program tests the methods of the linked list class
 */

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
  List <string> list_1;
  list_1.push_front ("Ali") ;
  list_1.push_front ("Bob") ;
  list_1.push_front ("Cas") ;
  list_1.push_front ("Don") ;

  cout << "The front element is: " << endl;
  cout << list_1.front() << endl << endl;

  cout << "The entire list is:" << endl;
  cout << list_1.to_string() << endl << endl;

  list_1.reverse();
  cout << "Reversed List: " << endl;
  cout << list_1.to_string() << endl << endl;

  list_1.push_back("Eli");
  cout << "After adding element to the back:" << endl;
  cout << list_1.to_string() << endl << endl;

  list_1.pop_front();
  cout << "After removing the first element:" << endl;
  cout << list_1.to_string() << endl << endl;

  List <string> list_2 (list_1); // use the copy constructor
  cout << "a copy of the previous list is: " << endl;
  cout << list_2.to_string() << endl << endl;

  List <string> list_3;
  list_3 = list_2; // use operator=
  cout << "a copy of the copy appears as: " << endl;
  cout << list_3.to_string() << endl << endl;
  return 0;
}
