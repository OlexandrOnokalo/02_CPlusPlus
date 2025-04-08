#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Point {
	int x;
	int y;
};


void printPoint(const Point& point) {
	cout << "Point: (" << point.x << ", " << point.y << ")" << endl;
}


void inputPoint(Point& point) {
	cout << "Enter x: ";
	cin >> point.x;
	cout << "Enter y: ";
	cin >> point.y;
}


void printPointsArray(const Point* pointsArray, int size) {
	for (int i = 0; i < size; ++i) {
		printPoint(pointsArray[i]);
	}
}


void writePointToFileStream(const Point& point, ofstream& file) {
	file << point.x << "\t" << point.y << endl;
}


void readPointFromFileStream(Point& point, ifstream& file) {
	file >> point.x >> point.y;
}


struct Marks {
	int Python;
	int HTML;
	int Cpp;
};


struct Student {
	int id;
	string Name;
	Marks marks;
};


void viewStudents(Student* group, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "ID: " << group[i].id << ", Name: " << group[i].Name
			<< ", Python: " << group[i].marks.Python
			<< ", HTML: " << group[i].marks.HTML
			<< ", C++: " << group[i].marks.Cpp << endl;
	}
}


void showTopStudents(Student* group, int size) {
	for (int i = 0; i < size; ++i) {
		double avg = (group[i].marks.Python + group[i].marks.HTML + group[i].marks.Cpp) / 3.0;
		if (avg > 10) {
			cout << "Top student: " << group[i].Name << " (Average: " << avg << ")" << endl;
		}
	}
}


void addStudent(Student* group, int& actualSize) {
	cout << "Enter ID: ";
	cin >> group[actualSize].id;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, group[actualSize].Name);
	cout << "Enter Python mark: ";
	cin >> group[actualSize].marks.Python;
	cout << "Enter HTML mark: ";
	cin >> group[actualSize].marks.HTML;
	cout << "Enter C++ mark: ";
	cin >> group[actualSize].marks.Cpp;
	actualSize++;
}


void writeStudentsToFile(Student* group, int size, const string& filename) {
	ofstream file(filename);
	file << size << endl;
	for (int i = 0; i < size; ++i) {
		file << group[i].id << "\t" << group[i].Name << "\t"
			<< group[i].marks.Python << "\t"
			<< group[i].marks.HTML << "\t"
			<< group[i].marks.Cpp << endl;
	}
	file.close();
}


Student* loadStudentsFromFile(int& actualSize, int& capacity, const string& filename) {
	ifstream file(filename);
	file >> actualSize;
	capacity = actualSize + 5; 
	Student* group = new Student[capacity];
	for (int i = 0; i < actualSize; ++i) {
		file >> group[i].id;
		file >> ws;
		getline(file, group[i].Name, '\t');
		file >> group[i].marks.Python >> group[i].marks.HTML >> group[i].marks.Cpp;
	}
	file.close();
	return group;
}



int main()
{
	
	const int SIZE = 5;
	Point points[SIZE]{};

	
	for (int i = 0; i < SIZE; ++i) {
		cout << "Enter point #" << i + 1 << ":" << endl;
		inputPoint(points[i]);
	}

	ofstream file("points.txt"); 

	
	for (int i = 0; i < SIZE; ++i) {
		writePointToFileStream(points[i], file);
	}

	file.close();

	ifstream file2("points.txt");

	
	int count = 0;
	int tempX, tempY;
	while (file2 >> tempX >> tempY) {
		count++;
	}
	file2.clear();
	file2.seekg(0);

	Point* readPoint = new Point[count];

	for (int i = 0; i < count; ++i) {
		readPointFromFileStream(readPoint[i], file2);
	}

	cout << "\nPoints loaded from file:" << endl;
	printPointsArray(readPoint, count);
	delete[] readPoint;
	file2.close();

	
	int capacity = 10;
	int actualSize = 0;
	Student* group = new Student[capacity];

	
	addStudent(group, actualSize);
	addStudent(group, actualSize);

	cout << "\nAll students:" << endl;
	viewStudents(group, actualSize);

	cout << "\nTop students:" << endl;
	showTopStudents(group, actualSize);

	writeStudentsToFile(group, actualSize, "students.txt");

	
	int loadedSize, loadedCapacity;
	Student* loadedGroup = loadStudentsFromFile(loadedSize, loadedCapacity, "students.txt");

	cout << "\nStudents loaded from file:" << endl;
	viewStudents(loadedGroup, loadedSize);

	delete[] group;
	delete[] loadedGroup;

	return 0;
}
