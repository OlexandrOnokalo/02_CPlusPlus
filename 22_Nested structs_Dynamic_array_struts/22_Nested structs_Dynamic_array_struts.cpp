//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <string>
//using namespace std;
//
//const int NAME_SIZE = 100;
//
//struct Marks {
//    int Python;
//    int HTML;
//    int Cpp;
//};
//
//
//struct Student {
//    int id;
//    string Name;
//    Marks marks;
//};
//
//void printMarks(const Marks& marks) {
//    cout << "Python: " << marks.Python << endl;
//    cout << "HTML: " << marks.HTML << endl;
//    cout << "C++: " << marks.Cpp << endl;
//
//}
//
//void intputMarks(Marks& marks) {
//    cout << "Enter Python mark: ";
//    cin >> marks.Python;
//    cout << "Enter HTML mark: ";
//    cin >> marks.HTML;
//    cout << "Enter C++ mark: ";
//    cin >> marks.Cpp;
//}
//
//
//void printStudent(const Student& stud) {
//    cout << "ID: " << stud.id << endl;
//    cout << "Name: " << stud.Name << endl;
//    printMarks(stud.marks);
//}
//void intputStudent(Student& stud) {
//    cout << "Enter id: ";
//    cin >> stud.id;
//    cout << "Enter Name: ";
//    cin >> stud.Name;
//    intputMarks(stud.marks);
//}
//
//void writeToFile(const Student& stud, string path = "stud.txt")
//{
//    ofstream file;
//    file.open(path);
//    
//    if (!file) 
//    {
//        cout << "Error file " << path << endl;
//        return;
//    }
//    file << stud.id << endl;
//    file << stud.Name << endl;
//    file << stud.marks.Python << endl;
//    file << stud.marks.HTML << endl;
//    file << stud.marks.Cpp << endl;
//
//
//}
//void readFromFile(Student& stud, string path = "stud.txt")
//{
//    ifstream file;
//    file.open(path);
//    if (!file) 
//    {
//        cout << "Error file " << path << endl;
//        return;
//    }
//    
//    file >> stud.id;
//    file.ignore(1);
//    getline(file, stud.Name);
//    file >> stud.marks.Python;
//    file >> stud.marks.HTML;
//    file >> stud.marks.Cpp;
//    
//}
//
//
//
//int main()
//{
//    int capacity = 10;
//    int actualSize = 0;
//    Student stud1;
//    Student stud2;
//    
//    cout << "Enter stud info: " << endl;
//    intputStudent(stud1);
//    cout << endl;
//    printStudent(stud1);
//    cout << "Save to file...\n" << endl;
//    writeToFile(stud1);
//    readFromFile(stud2);
//    cout << "Loaded from file:\n" << endl;
//    printStudent(stud2);
//
//
//    int capacity = 10;
//    int actualSize = 0;
//    Student* students = new Student[capacity];
//
//
//
//
//
//}

