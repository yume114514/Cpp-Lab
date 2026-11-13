#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y = 2000, int m = 1, int d = 1) : year(y), month(m), day(d) {}
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}
    ~Date() {}

    void setDate(int y, int m, int d) { year = y; month = m; day = d; }
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    void input() {
        cin >> year >> month >> day;
    }

    void show() const {
        cout << year << "-" << month << "-" << day;
    }
};

class Person {
private:
    string id;
    string gender;
    Date birth;
    string idCard;
public:
    Person(string i = "0000", string g = "未知",
           const Date& d = Date(), string card = "无")
        : id(i), gender(g), birth(d), idCard(card) {
    }

    Person(const Person& other)
        : id(other.id), gender(other.gender), birth(other.birth), idCard(other.idCard) {
    }

    ~Person() {
        cout << "析构 Person：" << id << endl;
    }

    void setId(const string& v) { id = v; }
    void setGender(const string& v) { gender = v; }
    void setIdCard(const string& v) { idCard = v; }

    string getId() const { return id; }
    string getGender() const { return gender; }
    string getIdCard() const { return idCard; }
    Date getBirth() const { return birth; }

    void input() {
        cin >> id >> gender;
        birth.input();
        cin >> idCard;
    }

    void show() const {
        cout << "编号    ：" << id << endl;
        cout << "性别    ：" << gender << endl;
        cout << "出生日期：";
        birth.show();
        cout << endl;
        cout << "身份证号：" << idCard << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Person p1;
    cout << "请输入人员信息（编号 性别 出生年 月 日 身份证号）：" << endl;
    p1.input();

    cout << "\n--- 录入结果 ---" << endl;
    p1.show();

    Person p2(p1);
    cout << "\n--- 复制构造出的副本 ---" << endl;
    p2.show();

    Person p3("1002", "女", Date(2006, 5, 20), "420106200605200123");
    cout << "\n--- 直接构造的对象 ---" << endl;
    p3.show();

    return 0;
}
