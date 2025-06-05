#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>    /*для формування табличного виводу */
#include <stdexcept> 
#include <algorithm>  /*пошук, макс, ремув*/

using namespace std;

//початковий абстрактний класс
class Savable {
public:
    virtual void save(ofstream& ofs) const = 0;
    virtual void load(ifstream& ifs) = 0;
    virtual void display() const = 0;
    virtual ~Savable() {}
};

                 /*перевірки:*/

// чи не пустий рядок
void validateNonEmptyString(const string& s, const string& fieldName) {
    if (s.empty()) {
        throw invalid_argument(fieldName + " cannot be empty.");
    }
}

// перевірка вводу дати
void validateDate(const string& date) {
    if (date.size() != 10 || date[2] != '.' || date[5] != '.') {
        throw invalid_argument("Date format must be DD.MM.YYYY");
    }
    int day, month, year;
    try {
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));
    }
    catch (...) {
        throw invalid_argument("Date contains invalid numbers.");
    }
    if (year < 1965 || year > 2007) {
        throw invalid_argument("Year must be between 1965 and 2007.");
    }
    if (month < 1 || month > 12) {
        throw invalid_argument("Month must be between 1 and 12.");
    }
    
    //кількість днів у місяці
    int mdays[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };    
    bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (isLeap) mdays[2] = 29;
    if (day < 1 || day > mdays[month]) {
        throw invalid_argument("Day is out of range for the given month.");
    }
}



//предмет

class Subject : public Savable {
private:
    string name; 
public:
    Subject() = default;
    Subject(const string& n) {
        setName(n);
    }


    void setName(const string& n) {
        validateNonEmptyString(n, "Subject name");
        name = n;
    }
    string getName() const { return name; }

   

    void save(ofstream& ofs) const override {
        size_t len = name.size(); //для нейма
        ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
        ofs.write(name.c_str(), len);
    }
    void load(ifstream& ifs) override {
        size_t len;
        ifs.read(reinterpret_cast<char*>(&len), sizeof(len));
        name.resize(len);
        ifs.read(&name[0], len);
    }
    void display() const override {
        cout << left << setw(30) << name << "\n";
    }
};

//группа 
class Group : public Savable {
private:
    string id; 
public:
    Group() = default;
    Group(const string& gid) {
        setId(gid);
    }

   
    void setId(const string& gid) {
        validateNonEmptyString(gid, "Group ID");
        id = gid;
    }
    string getId() const { return id; }

    void save(ofstream& ofs) const override {
        size_t len = id.size();
        ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
        ofs.write(id.c_str(), len);
    }
    void load(ifstream& ifs) override {
        size_t len;
        ifs.read(reinterpret_cast<char*>(&len), sizeof(len));
        id.resize(len);
        ifs.read(&id[0], len);
    }
    void display() const override {
        cout << left << setw(8) << id << "\n";
    }
};



class Person : public Savable {
private:
    int id;                  
    string fullName;         
    string birthDate;        
protected:
    
public:
    Person() = default;
    Person(int _id, const string& _fn, const string& _bd) {
        setId(_id);
        setFullName(_fn);
        setBirthDate(_bd);
    }
    virtual ~Person() {}

    
    void setId(int _id) {
        if (_id <= 0) throw invalid_argument("ID must be positive.");
        id = _id;
    }
    void setFullName(const string& _fn) {
        validateNonEmptyString(_fn, "Full name");
        fullName = _fn;
    }
    void setBirthDate(const string& _bd) {
        validateDate(_bd);
        birthDate = _bd;
    }

    
    int getId() const { return id; }
    string getFullName() const { return fullName; }
    string getBirthDate() const { return birthDate; }

    
    void save(ofstream& ofs) const override {
        ofs.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        size_t fn_len = fullName.size();
        ofs.write(reinterpret_cast<const char*>(&fn_len), sizeof(fn_len));
        ofs.write(fullName.c_str(), fn_len);
        
        size_t bd_len = birthDate.size();
        ofs.write(reinterpret_cast<const char*>(&bd_len), sizeof(bd_len));
        ofs.write(birthDate.c_str(), bd_len);
    }
    void load(ifstream& ifs) override {
        ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        size_t fn_len;
        ifs.read(reinterpret_cast<char*>(&fn_len), sizeof(fn_len));
        fullName.resize(fn_len);
        ifs.read(&fullName[0], fn_len);
        
        size_t bd_len;
        ifs.read(reinterpret_cast<char*>(&bd_len), sizeof(bd_len));
        birthDate.resize(bd_len);
        ifs.read(&birthDate[0], bd_len);
    }

    
    void display() const override {
        cout << left << setw(6) << id
            << setw(25) << fullName
            << setw(12) << birthDate;
    }
};


class Teacher : public Person {
private:
    vector<string> subjects; // вектор з предметами
public:
    Teacher() = default;
    Teacher(int _id, const string& _fn, const string& _bd, const vector<string>& _subs)
        : Person(_id, _fn, _bd), subjects(_subs) {
        if (subjects.empty()) throw invalid_argument("Teacher must teach at least one subject.");
        for (auto& s : subjects) validateNonEmptyString(s, "Subject in teacher's list");
    }

    
    void addSubject(const string& sname) {
        if (find(subjects.begin(), subjects.end(), sname) == subjects.end()) {
            subjects.push_back(sname);
        }
    }
    void removeSubject(const string& sname) {
        subjects.erase(remove(subjects.begin(), subjects.end(), sname), subjects.end());
    }
    vector<string> getSubjects() const { return subjects; }

    
    void save(ofstream& ofs) const override {
        Person::save(ofs);
        size_t subs_count = subjects.size();
        ofs.write(reinterpret_cast<const char*>(&subs_count), sizeof(subs_count));
        for (auto& s : subjects) {
            size_t slen = s.size();
            ofs.write(reinterpret_cast<const char*>(&slen), sizeof(slen));
            ofs.write(s.c_str(), slen);
        }
    }
    void load(ifstream& ifs) override {
        Person::load(ifs);
        size_t subs_count;
        ifs.read(reinterpret_cast<char*>(&subs_count), sizeof(subs_count));
        subjects.clear();
        for (size_t i = 0; i < subs_count; ++i) {
            size_t slen;
            ifs.read(reinterpret_cast<char*>(&slen), sizeof(slen));
            string s;
            s.resize(slen);
            ifs.read(&s[0], slen);
            subjects.push_back(s);
        }
    }

    
    void display() const override {
        Person::display();
        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << subjects[i];
            if (i + 1 < subjects.size()) cout << ", ";
        }
        cout << "\n";
    }
};



class Student : public Person {
private:
    string groupID;                
    map<string, int> grades;       
public:
    Student() = default;
    Student(int _id, const string& _fn, const string& _bd, const string& _gid)
        : Person(_id, _fn, _bd) {
        setGroupID(_gid);
    }

    
    void setGroupID(const string& _gid) {
        
        if (!_gid.empty()) {
            validateNonEmptyString(_gid, "Group ID");
        }
        groupID = _gid;
    }
    string getGroupID() const { return groupID; }

    
    void assignGrade(const string& subjectName, int grade) {
        if (grade < 0 || grade > 100) {
            throw invalid_argument("Grade must be between 0 and 100.");
        }
        grades[subjectName] = grade;
    }
    void removeGrade(const string& subjectName) {
        grades.erase(subjectName);
    }
    map<string, int> getGrades() const { return grades; }

    //знову і опять, як мені дорог і любім цей бінарний запис

    void save(ofstream& ofs) const override {
        Person::save(ofs);
        //груп айді
        size_t gid_len = groupID.size();
        ofs.write(reinterpret_cast<const char*>(&gid_len), sizeof(gid_len));
        ofs.write(groupID.c_str(), gid_len);
        // мап оцінок
        size_t grades_count = grades.size();
        ofs.write(reinterpret_cast<const char*>(&grades_count), sizeof(grades_count));
        for (auto& p : grades) {
            //предмет
            size_t sn_len = p.first.size();
            ofs.write(reinterpret_cast<const char*>(&sn_len), sizeof(sn_len));
            ofs.write(p.first.c_str(), sn_len);
            // оцінка
            ofs.write(reinterpret_cast<const char*>(&p.second), sizeof(p.second));
        }
    }
    void load(ifstream& ifs) override {
        Person::load(ifs);
        //груп айді
        size_t gid_len;
        ifs.read(reinterpret_cast<char*>(&gid_len), sizeof(gid_len));
        groupID.resize(gid_len);
        ifs.read(&groupID[0], gid_len);
        // оцінки
        size_t grades_count;
        ifs.read(reinterpret_cast<char*>(&grades_count), sizeof(grades_count));
        grades.clear();
        for (size_t i = 0; i < grades_count; ++i) {
            size_t sn_len;
            ifs.read(reinterpret_cast<char*>(&sn_len), sizeof(sn_len));
            string subject;
            subject.resize(sn_len);
            ifs.read(&subject[0], sn_len);
            int gr;
            ifs.read(reinterpret_cast<char*>(&gr), sizeof(gr));
            grades[subject] = gr;
        }
    }

    
    void display() const override {
        Person::display();
        cout << left << setw(8) << groupID;
        
        cout << "\n";
    }
};



vector<Subject> subjects;      
vector<Group> groups;          
vector<Teacher> teachers;      
vector<Student> students;     

//А от я знаю що Ви зараз мене запитаєте ))))))))
//бо мало елементів, доступ по індексу, тра часто пробігати 



//унікальність

//айді і імя студента
void checkStudentUnique(int id, const string& name) {
    for (const auto& s : students) {
        if (s.getId() == id) throw invalid_argument("Duplicate student ID.");
        if (s.getFullName() == name) throw invalid_argument("Duplicate student name.");
    }
}

// викладача
void checkTeacherUnique(int id, const string& name) {
    for (const auto& t : teachers) {
        if (t.getId() == id) throw invalid_argument("Duplicate teacher ID.");
        if (t.getFullName() == name) throw invalid_argument("Duplicate teacher name.");
    }
}

// предмета
void checkSubjectUnique(const string& name) {
    for (const auto& sub : subjects) {
        if (sub.getName() == name) throw invalid_argument("Duplicate subject name.");
    }
}

// групи
void checkGroupUnique(const string& gid) {
    for (const auto& g : groups) {
        if (g.getId() == gid) throw invalid_argument("Duplicate group ID.");
    }
}


//пошук


//індекс студента по айді
int findStudentIndexByID(int id) {
    for (int i = 0; i < (int)students.size(); ++i) {
        if (students[i].getId() == id) return i;
    }
    return -1;
}

// по імені
int findStudentIndexByName(const string& name) {
    for (int i = 0; i < (int)students.size(); ++i) {
        if (students[i].getFullName() == name) return i;
    }
    return -1;
}

// викладач за айді
int findTeacherIndexByID(int id) {
    for (int i = 0; i < (int)teachers.size(); ++i) {
        if (teachers[i].getId() == id) return i;
    }
    return -1;
}

// викладач за імям
int findTeacherIndexByName(const string& name) {
    for (int i = 0; i < (int)teachers.size(); ++i) {
        if (teachers[i].getFullName() == name) return i;
    }
    return -1;
}

// предмет за назвою
int findSubjectIndexByName(const string& name) {
    for (int i = 0; i < (int)subjects.size(); ++i) {
        if (subjects[i].getName() == name) return i;
    }
    return -1;
}

// індекс групи за айді
int findGroupIndexByID(const string& gid) {
    for (int i = 0; i < (int)groups.size(); ++i) {
        if (groups[i].getId() == gid) return i;
    }
    return -1;
}

// таблична красота і ляпота

// студенти + оцінки
void printAllStudents() {
    if (students.empty()) {
        cout << "No students in database.\n";
        return;
    }
    
    //заголовок
    cout << left << setw(6) << "ID"
        << setw(25) << "Full Name"
        << setw(12) << "BirthDate"
        << setw(8) << "Group";
    //колонки
    for (const auto& sub : subjects) {
        cout << setw(8) << sub.getName().substr(0, 7);
    }
    cout << "\n";

    // лінії
    int totalWidth = 6 + 25 + 12 + 8 + 8 * (int)subjects.size();
    cout << string(totalWidth, '=') << "\n";

    // рядки інфи студентів
    for (const auto& s : students) {
        
        cout << left << setw(6) << s.getId()
            << setw(25) << s.getFullName()
            << setw(12) << s.getBirthDate()
            << setw(8) << s.getGroupID();
        //оцінки
        auto grades = s.getGrades();
        for (const auto& sub : subjects) {
            auto it = grades.find(sub.getName());
            if (it != grades.end()) {
                cout << setw(8) << it->second;
            }
            else {
                cout << setw(8) << "-";
            }
        }
        cout << "\n";
    }
}

// прінт викладачів
void printAllTeachers() {
    if (teachers.empty()) {
        cout << "No teachers in database.\n";
        return;
    }
    cout << left << setw(6) << "ID"
        << setw(25) << "Full Name"
        << setw(12) << "BirthDate"
        << "Subjects\n";
    cout << string(70, '=') << "\n";
    for (const auto& t : teachers) {
        t.display();
    }
}

// груп
void printAllGroups() {
    if (groups.empty()) {
        cout << "No groups in database.\n";
        return;
    }
    cout << left << setw(8) << "GroupID" << "\n";
    cout << string(8, '=') << "\n";
    for (const auto& g : groups) {
        g.display();
    }
}

// предметів
void printAllSubjects() {
    if (subjects.empty()) {
        cout << "No subjects in database.\n";
        return;
    }
    cout << left << setw(30) << "Subject Name" << "\n";
    cout << string(30, '=') << "\n";
    for (const auto& sub : subjects) {
        sub.display();
    }
}

//додавання

void addStudent() {
    try {
        int id = 1;
        if (!students.empty()) {
            for (const auto& s : students) {
                id = max(id, s.getId() + 1);  //шукаєм наступне айді
            }
        }
        cout << "Assigned student ID: " << id << "\n";

        string name, birth, gid;
        cout << "Enter student full name: ";
        getline(cin, name);

        cout << "Enter birth date (DD.MM.YYYY): ";
        getline(cin, birth);

        
        printAllGroups();
        cout << "Enter group ID: ";
        getline(cin, gid);

        //унікальність
        checkStudentUnique(id, name);

        // чи існує группа
        if (findGroupIndexByID(gid) < 0) {
            throw invalid_argument("Group ID does not exist.");
        }

        
        validateNonEmptyString(name, "Student full name");
        validateDate(birth);
        validateNonEmptyString(gid, "Group ID");

        Student s(id, name, birth, gid);
        students.push_back(s);
        cout << "Student added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error adding student: " << e.what() << "\n";
    }
}


void addTeacher() {
    try {
        int id = 1;
        if (!teachers.empty()) {
            for (const auto& t : teachers) {
                id = max(id, t.getId() + 1);
            }
        }
        cout << "Assigned teacher ID: " << id << "\n";

        string name, birth;
        vector<string> tsubs;
        cout << "Enter teacher full name: ";
        getline(cin, name);

        cout << "Enter birth date (DD.MM.YYYY): ";
        getline(cin, birth);

        
        if (subjects.empty()) {
            throw runtime_error("No subjects available. Add subjects first.");
        }
        cout << "Available subjects:\n";
        printAllSubjects();
        cout << "Enter number of subjects this teacher will teach: ";
        int count;
        cin >> count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //до победного конца
        if (count <= 0) throw invalid_argument("Teacher must teach at least one subject.");

        for (int i = 0; i < count; ++i) {
            string sname;
            cout << "Enter subject name #" << (i + 1) << ": ";
            getline(cin, sname);
            if (findSubjectIndexByName(sname) < 0) {
                throw invalid_argument("Subject '" + sname + "' does not exist.");
            }
            tsubs.push_back(sname);
        }

        
        checkTeacherUnique(id, name);

        
        validateNonEmptyString(name, "Teacher full name");
        validateDate(birth);

        Teacher t(id, name, birth, tsubs);
        teachers.push_back(t);
        cout << "Teacher added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error adding teacher: " << e.what() << "\n";
    }
}


void addSubject() {
    try {
        string name;
        cout << "Enter subject name: ";
        getline(cin, name);
        validateNonEmptyString(name, "Subject name");
        
        checkSubjectUnique(name);
        Subject sub(name);
        subjects.push_back(sub);
        cout << "Subject added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error adding subject: " << e.what() << "\n";
    }
}


void addGroup() {
    try {
        string gid;
        cout << "Enter group ID (e.g., PV01): ";
        getline(cin, gid);
        validateNonEmptyString(gid, "Group ID");
        checkGroupUnique(gid);
        Group g(gid);
        groups.push_back(g);
        cout << "Group added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error adding group: " << e.what() << "\n";
    }
}

//видалення

// дел студента по айді
void deleteStudent() {
    if (students.empty()) {
        cout << "No students to delete.\n";
        return;
    }
    printAllStudents();
    cout << "Enter student ID to delete: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int idx = findStudentIndexByID(id);
    if (idx < 0) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }
    students.erase(students.begin() + idx);
    cout << "Student deleted successfully.\n";
}

// викладача за айді
void deleteTeacher() {
    if (teachers.empty()) {
        cout << "No teachers to delete.\n";
        return;
    }
    printAllTeachers();
    cout << "Enter teacher ID to delete: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int idx = findTeacherIndexByID(id);
    if (idx < 0) {
        cout << "Teacher with ID " << id << " not found.\n";
        return;
    }
    teachers.erase(teachers.begin() + idx);
    cout << "Teacher deleted successfully.\n";
}

// Видалення предмета за назвою
void deleteSubject() {
    if (subjects.empty()) {
        cout << "No subjects to delete.\n";
        return;
    }
    printAllSubjects();
    cout << "Enter subject name to delete: ";
    string name;
    getline(cin, name);
    int idx = findSubjectIndexByName(name);
    if (idx < 0) {
        cout << "Subject '" << name << "' not found.\n";
        return;
    }
    // чистим оцінки
    for (auto& s : students) {
        s.removeGrade(name);
    }
    subjects.erase(subjects.begin() + idx);
    cout << "Subject deleted successfully.\n";
}

// групу за айді
void deleteGroup() {
    if (groups.empty()) {
        cout << "No groups to delete.\n";
        return;
    }
    printAllGroups();
    cout << "Enter group ID to delete: ";
    string gid;
    getline(cin, gid);
    int idx = findGroupIndexByID(gid);
    if (idx < 0) {
        cout << "Group '" << gid << "' not found.\n";
        return;
    }
    // чистим номер групи студентам
    for (auto& s : students) {
        if (s.getGroupID() == gid) {
            s.setGroupID("");  
        }
    }
    groups.erase(groups.begin() + idx);
    cout << "Group deleted successfully.\n";
}

//редагування


void editStudent() {
    if (students.empty()) {
        cout << "No students to edit.\n";
        return;
    }
    printAllStudents();
    cout << "Enter student ID to edit: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int idx = findStudentIndexByID(id);
    if (idx < 0) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    try {
        Student& s = students[idx];
        cout << "Editing student ID " << s.getId() << ". Leave field empty to keep current value.\n";
        cout << "Current full name: " << s.getFullName() << "\nEnter new full name: ";
        string name;
        getline(cin, name);
        if (!name.empty()) {
            validateNonEmptyString(name, "Student full name");
            if (name != s.getFullName()) {
                for (const auto& other : students) {
                    if (other.getFullName() == name) throw invalid_argument("Duplicate student name.");
                }
                s.setFullName(name);
            }
        }
        cout << "Current birth date: " << s.getBirthDate() << "\nEnter new birth date (DD.MM.YYYY): ";
        string birth;
        getline(cin, birth);
        if (!birth.empty()) {
            validateDate(birth);
            s.setBirthDate(birth);
        }
        cout << "Current group ID: " << s.getGroupID() << "\n";
        printAllGroups();
        cout << "Enter new group ID: ";
        string gid;
        getline(cin, gid);
        if (!gid.empty()) {
            if (findGroupIndexByID(gid) < 0) throw invalid_argument("Group ID does not exist.");
            s.setGroupID(gid);
        }
        cout << "Student edited successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error editing student: " << e.what() << "\n";
    }
}


void editTeacher() {
    if (teachers.empty()) {
        cout << "No teachers to edit.\n";
        return;
    }
    printAllTeachers();
    cout << "Enter teacher ID to edit: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int idx = findTeacherIndexByID(id);
    if (idx < 0) {
        cout << "Teacher with ID " << id << " not found.\n";
        return;
    }

    try {
        Teacher& t = teachers[idx];
        cout << "Editing teacher ID " << t.getId() << ". Leave field empty to keep current value.\n";
        cout << "Current full name: " << t.getFullName() << "\nEnter new full name: ";
        string name;
        getline(cin, name);
        if (!name.empty()) {
            validateNonEmptyString(name, "Teacher full name");
            if (name != t.getFullName()) {
                for (const auto& other : teachers) {
                    if (other.getFullName() == name) throw invalid_argument("Duplicate teacher name.");
                }
                t.setFullName(name);
            }
        }
        cout << "Current birth date: " << t.getBirthDate() << "\nEnter new birth date (DD.MM.YYYY): ";
        string birth;
        getline(cin, birth);
        if (!birth.empty()) {
            validateDate(birth);
            t.setBirthDate(birth);
        }
        // список предметів
        cout << "Current subjects taught: ";
        vector<string> currSubs = t.getSubjects();
        for (size_t i = 0; i < currSubs.size(); ++i) {
            cout << currSubs[i] << (i + 1 < currSubs.size() ? ", " : "\n");
        }
        cout << "Do you want to edit subjects list? (yes/no): ";
        string ans;
        getline(cin, ans);
        if (ans == "yes" || ans == "y") {
            if (subjects.empty()) {
                throw runtime_error("No subjects available. Add subjects first.");
            }
            cout << "Available subjects:\n";
            printAllSubjects();
            cout << "Enter number of subjects this teacher will teach: ";
            int count;
            cin >> count;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (count <= 0) throw invalid_argument("Teacher must teach at least one subject.");
            
            for (auto& sname : currSubs) {
                t.removeSubject(sname);
            }
            for (int i = 0; i < count; ++i) {
                string sname;
                cout << "Enter subject name #" << (i + 1) << ": ";
                getline(cin, sname);
                if (findSubjectIndexByName(sname) < 0) {
                    throw invalid_argument("Subject '" + sname + "' does not exist.");
                }
                t.addSubject(sname);
            }
        }
        cout << "Teacher edited successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error editing teacher: " << e.what() << "\n";
    }
}

// група
void editGroup() {
    if (groups.empty()) {
        cout << "No groups to edit.\n";
        return;
    }
    printAllGroups();
    cout << "Enter group ID to edit: ";
    string gid;
    getline(cin, gid);
    int idx = findGroupIndexByID(gid);
    if (idx < 0) {
        cout << "Group '" << gid << "' not found.\n";
        return;
    }

    try {
        Group& g = groups[idx];
        cout << "Editing group ID " << g.getId() << ". Enter new group ID: ";
        string newGid;
        getline(cin, newGid);
        if (!newGid.empty()) {
            validateNonEmptyString(newGid, "Group ID");
            if (newGid != g.getId()) {
                for (const auto& other : groups) {
                    if (other.getId() == newGid) throw invalid_argument("Duplicate group ID.");
                }
                // перепрописуємо студентам групу
                for (auto& s : students) {
                    if (s.getGroupID() == g.getId()) {
                        s.setGroupID(newGid);
                    }
                }
                g.setId(newGid);
            }
        }
        cout << "Group edited successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error editing group: " << e.what() << "\n";
    }
}


void editSubject() {
    if (subjects.empty()) {
        cout << "No subjects to edit.\n";
        return;
    }
    printAllSubjects();
    cout << "Enter subject name to edit: ";
    string name;
    getline(cin, name);
    int idx = findSubjectIndexByName(name);
    if (idx < 0) {
        cout << "Subject '" << name << "' not found.\n";
        return;
    }

    try {
        Subject& sub = subjects[idx];
        cout << "Editing subject '" << sub.getName() << "'. Enter new subject name: ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            validateNonEmptyString(newName, "Subject name");
            if (newName != sub.getName()) {
                for (const auto& other : subjects) {
                    if (other.getName() == newName) throw invalid_argument("Duplicate subject name.");
                }
                // редактуємо назву у викладачів
                for (auto& t : teachers) {
                    vector<string> ts = t.getSubjects();
                    for (auto& tsub : ts) {
                        if (tsub == sub.getName()) {
                            t.removeSubject(sub.getName());
                            t.addSubject(newName);
                        }
                    }
                }
                // оновляємо оцінки студентам
                for (auto& s : students) {
                    auto grades = s.getGrades();
                    auto it = grades.find(sub.getName());
                    if (it != grades.end()) {
                        int grade = it->second;
                        s.removeGrade(sub.getName());
                        s.assignGrade(newName, grade);
                    }
                }
                sub.setName(newName);
            }
        }
        cout << "Subject edited successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error editing subject: " << e.what() << "\n";
    }
}

//пошук

// пошук предметів студента за айді або іменем
void searchStudentSubjects() {
    if (students.empty()) {
        cout << "No students in database.\n";
        return;
    }
    cout << "Find student by:\n1. ID\n2. Full Name\nChoose option: ";
    int opt;
    cin >> opt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int sidx = -1;
    if (opt == 1) {
        cout << "Enter student ID: ";
        int id;
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        sidx = findStudentIndexByID(id);
    }
    else if (opt == 2) {
        cout << "Enter student full name: ";
        string name;
        getline(cin, name);
        sidx = findStudentIndexByName(name);
    }
    else {
        cout << "Invalid option.\n";
        return;
    }
    if (sidx < 0) {
        cout << "Student not found.\n";
        return;
    }
    
    cout << "Subjects for student " << students[sidx].getFullName() << ":\n";
    printAllSubjects();
}

// пошук предметів групи
void searchGroupSubjects() {
    if (groups.empty()) {
        cout << "No groups in database.\n";
        return;
    }
    cout << "Enter group ID: ";
    string gid;
    getline(cin, gid);
    int gidx = findGroupIndexByID(gid);
    if (gidx < 0) {
        cout << "Group not found.\n";
        return;
    }
    
    cout << "Subjects for group " << gid << ":\n";
    printAllSubjects();
}




//ставим оцінки



void assignGrade() {
    if (students.empty()) {
        cout << "No students in database.\n";
        return;
    }
    printAllStudents();
    cout << "Enter student ID to assign grade: ";
    int sid;
    cin >> sid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int sidx = findStudentIndexByID(sid);
    if (sidx < 0) {
        cout << "Student not found.\n";
        return;
    }
    if (subjects.empty()) {
        cout << "No subjects available.\n";
        return;
    }
    printAllSubjects();
    cout << "Enter subject name to assign grade: ";
    string subName;
    getline(cin, subName);
    int subIdx = findSubjectIndexByName(subName);
    if (subIdx < 0) {
        cout << "Subject not found.\n";
        return;
    }
    cout << "Enter grade (0–100): ";
    int gr;
    cin >> gr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try {
        students[sidx].assignGrade(subName, gr);
        cout << "Grade assigned successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
}

//збереження

// збереження всього в тхт
void saveDatabase() {
    try {
        ofstream ofs("database.txt", ios::binary);
        if (!ofs) throw runtime_error("Cannot open file for writing.");

        // предмети
        size_t subCount = subjects.size();
        ofs.write(reinterpret_cast<const char*>(&subCount), sizeof(subCount));
        for (const auto& sub : subjects) sub.save(ofs);

        // групи
        size_t grpCount = groups.size();
        ofs.write(reinterpret_cast<const char*>(&grpCount), sizeof(grpCount));
        for (const auto& g : groups) g.save(ofs);

        // вчителі
        size_t tCount = teachers.size();
        ofs.write(reinterpret_cast<const char*>(&tCount), sizeof(tCount));
        for (const auto& t : teachers) t.save(ofs);

        // студенти
        size_t stCount = students.size();
        ofs.write(reinterpret_cast<const char*>(&stCount), sizeof(stCount));
        for (const auto& s : students) s.save(ofs);

        ofs.close();
        cout << "Database saved successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error saving database: " << e.what() << "\n";
    }
}

// завантажуєм з тхт

void loadDatabase() {
    try {
        ifstream ifs("database.txt", ios::binary);
        if (!ifs) throw runtime_error("Cannot open file for reading.");

        subjects.clear();
        groups.clear();
        teachers.clear();
        students.clear();

        // предмети
        size_t subCount;
        ifs.read(reinterpret_cast<char*>(&subCount), sizeof(subCount));
        for (size_t i = 0; i < subCount; ++i) {
            Subject sub;
            sub.load(ifs);
            subjects.push_back(sub);
        }

        // групи
        size_t grpCount;
        ifs.read(reinterpret_cast<char*>(&grpCount), sizeof(grpCount));
        for (size_t i = 0; i < grpCount; ++i) {
            Group g;
            g.load(ifs);
            groups.push_back(g);
        }

        // вчителі
        size_t tCount;
        ifs.read(reinterpret_cast<char*>(&tCount), sizeof(tCount));
        for (size_t i = 0; i < tCount; ++i) {
            Teacher t;
            t.load(ifs);
            teachers.push_back(t);
        }

        // студенти
        size_t stCount;
        ifs.read(reinterpret_cast<char*>(&stCount), sizeof(stCount));
        for (size_t i = 0; i < stCount; ++i) {
            Student s;
            s.load(ifs);
            students.push_back(s);
        }

        ifs.close();
        cout << "Database loaded successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error loading database: " << e.what() << "\n";
    }
}

//перший раз в перший клас


void initializeData() {
    

    //предмети

    vector<string> initialSubjects = {
        "Mathematics",
        "Physics",
        "Programming",
        "Algorithms",
        "DataStructures"
    };
    for (auto& name : initialSubjects) {
        Subject sub;
        sub.setName(name);
        subjects.push_back(sub);
    }

    // групи
    vector<string> initialGroups = { "PV01", "PV02", "PV03" };
    for (auto& gid : initialGroups) {
        Group g;
        g.setId(gid);
        groups.push_back(g);
    }

    // викладачі 
    vector<string> teacherNames = {
        "Alice Johnson", "Bob Smith", "Carol Lee", "David Brown", "Eve Davis",
        "Frank Miller", "Grace Wilson", "Hank Moore", "Ivy Taylor", "Jack Anderson"
    };
    vector<string> initialDates = {
        "15.05.1975", "22.11.1980", "30.01.1972", "07.07.1978", "19.09.1970",
        "04.04.1976", "10.10.1979", "25.12.1973", "11.06.1982", "02.02.1977"
    };
    // предмети викладачам, кожному по 2шт
    for (int i = 0; i < 10; ++i) {
        int id = i + 1;
        string fname = teacherNames[i];
        string birth = initialDates[i];
        vector<string> subs;
        subs.push_back(initialSubjects[(i * 2) % 5]);
        subs.push_back(initialSubjects[(i * 2 + 1) % 5]);
        Teacher t(id, fname, birth, subs);
        teachers.push_back(t);
    }

    // студенти..... нє, 45 імен я вигадувати не буду )))
    int sid = 1;
    for (auto& gid : initialGroups) {
        for (int i = 0; i < 15; ++i) {
            string name = "Student" + to_string(sid);
            
            string birth = "01.01.2000";
            Student s(sid, name, birth, gid);
            students.push_back(s);
            sid++;
        }
    }

    
    saveDatabase();

    
}

// головне меню

void studentMenu() {
    while (true) {
        cout << "\n--- STUDENT MENU ---\n";
        cout << "1. Show all students\n";
        cout << "2. Delete student\n";
        cout << "3. Add student\n";
        cout << "4. Edit student\n";
        cout << "5. Back to main menu\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: printAllStudents(); break;
        case 2: deleteStudent(); break;
        case 3: addStudent(); break;
        case 4: editStudent(); break;
        case 5: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}

void teacherMenu() {
    while (true) {
        cout << "\n--- TEACHER MENU ---\n";
        cout << "1. Show all teachers\n";
        cout << "2. Delete teacher\n";
        cout << "3. Add teacher\n";
        cout << "4. Edit teacher\n";
        cout << "5. Back to main menu\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: printAllTeachers(); break;
        case 2: deleteTeacher(); break;
        case 3: addTeacher(); break;
        case 4: editTeacher(); break;
        case 5: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}

void groupMenu() {
    while (true) {
        cout << "\n--- GROUP MENU ---\n";
        cout << "1. Show all groups\n";
        cout << "2. Delete group\n";
        cout << "3. Add group\n";
        cout << "4. Edit group\n";
        cout << "5. Back to main menu\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: printAllGroups(); break;
        case 2: deleteGroup(); break;
        case 3: addGroup(); break;
        case 4: editGroup(); break;
        case 5: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}

void subjectMenu() {
    while (true) {
        cout << "\n--- SUBJECT MENU ---\n";
        cout << "1. Show all subjects\n";
        cout << "2. Delete subject\n";
        cout << "3. Add subject\n";
        cout << "4. Edit subject\n";
        cout << "5. Back to main menu\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: printAllSubjects(); break;
        case 2: deleteSubject(); break;
        case 3: addSubject(); break;
        case 4: editSubject(); break;
        case 5: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // initializeData();

    
    loadDatabase();

    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Students\n";
        cout << "2. Teachers\n";
        cout << "3. Groups\n";
        cout << "4. Subjects\n";
        cout << "5. Search\n";
        cout << "6. Assign Grade\n";
        cout << "7. Load database from file\n";
        cout << "8. Save database to file\n";
        cout << "9. Exit\n";
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: studentMenu(); break;
        case 2: teacherMenu(); break;
        case 3: groupMenu(); break;
        case 4: subjectMenu(); break;
        case 5: {
            cout << "\n--- SEARCH MENU ---\n";
            cout << "1. Search student subjects\n";
            cout << "2. Search group subjects\n";
            cout << "Choose option: ";
            int opt;
            cin >> opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt == 1) searchStudentSubjects();
            else if (opt == 2) searchGroupSubjects();
            else cout << "Invalid option.\n";
            break;
        }
        case 6: assignGrade(); break;
        case 7: loadDatabase(); break;
        case 8: saveDatabase(); break;
        case 9:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid option.\n";
            break;
        }
    }

    return 0;
}
