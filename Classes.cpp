// classes.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
 
#include <iostream>
using namespace std;
class ModelC; //äðóæåñòâåííûé êëàññ
class Composition 
{
private: 
	friend ModelC;
    int day, 
        month, 
        year;
public:
	static int goldYear; //ñòàòèñòè÷åñêèé ÷ëåí
	
    Composition(int sDay, int sMonth, int sYear) // êîíñòðóêòîð êëàññà
    {
    	cout << "Êëàññ ñêîíñòðóèðîâàí\n";
        setDate(sDay, sMonth, sYear); 
    }
    ~Composition() // äåñòðóêòîð êëàññà
    {
    	cout << "Êëàññ äåñòðóêòèðîâàí\nÎêîí÷àòåëüíûå äàííûå:";
        
    }
    void setDate(int sDay, int sMonth, int sYear) 
    {
        day   = sDay; 
        month = sMonth; 
        year  = sYear; 
    }
    void getDate()
    {
        cout << "Äàòà ÷åðåç óêàçàòåëü this: " << (*this).day << "." << (*this).month << "." << (*this).year << endl; //óêàçàòåëü this
    }
}; 
class ModelC 
{
private: 
	
    int day, 
        month, 
        year;
public:
    ModelC(int sDay, int sMonth, int sYear) 
    {
    	cout << "Äðóæåñòâåííûé êëàññ âûçâàí\n";
    }
    ~ModelC()
    {
    	cout << "Êëàññ äåñòðóêòèðîâàí\nÎêîí÷àòåëüíûå äàííûå:";
        
    }

}; 
int Composition::goldYear = 2007;
int main()
{
	setlocale(LC_ALL, "rus");
	int day, month, year;
    cout << "Äàòà ñîçäàíèÿ òðåêà:\n";
    cout << "äåíü: ";     cin >> day;
    cout << "ìåñÿö: ";    cin >> month;
    cout << "ãîä: ";  cin >> year;
    Composition song(01,01,1970);
    ModelC model(01,01,1970);
    song.setDate(day, month, year);
    song.getDate(); 
    cout << endl << "Ñòàòèñòè÷åñêèé ÷ëåí - çîëîòîé ãîä:" << Composition::goldYear << endl;
    system("pause");
    return 0;
}
