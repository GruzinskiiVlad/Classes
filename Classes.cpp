// classes.cpp: opredelyaet tochku vhoda dlya konsol'nogo prilozheniya.
 
#include <iostream>
using namespace std;
class ModelC; //druzhestvennyj klass
class Composition 
{
private: 
	friend ModelC; //dostup druzhestvennogo klassa
    int day, 
        month, 
        year;
public:
	 class BufferData //vlozenniy class
		   {  
		   public:  
		      int reserve1;  
		      int reserve2; 
		   };  
   class BufferData1 : public BufferData //vlozenniy class - obrachenie
	   {  
	   public:  
	      int reserve1;  
	      int reserve2; 
	   };  
   
	int rating, 
	number; 
	
	static int goldYear; //statisticheskij chlen
	
    Composition(int sDay, int sMonth, int sYear) // konstruktor klassa
	    {
	    	cout << "Klass skonstruirovan\n";
	        setDate(sDay, sMonth, sYear); 
	    }
    ~Composition() // destruktor klassa
	    {
	    	cout << "Klass destruktirovan\nOkonchatel'nye dannye:";
	        
	    }
    void setDate(int sDay, int sMonth, int sYear) 
	    {
	        day   = sDay; 
	        month = sMonth; 
	        year  = sYear; 
	    }
    void getDate()
	    {
	        cout << "Data cherez ukazatel' this: " << (*this).day << "." << (*this).month << "." << (*this).year << endl; //ukazatel' this
	    }
   friend const Composition operator++(Composition& day, int)
   {}
protected:

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
	    	cout << "Druzhestvennyj klass vyzvan\n";
	    }
    ~ModelC()
	    {
	    	cout << "Klass destruktirovan\nOkonchatel'nye dannye:";
	        
	    }
   Composition operator = (Composition &song){
	return Composition(this->day = song.day, this->month = song.month, this->year = 0);}//peregruzka: ogrannichennoe priravnivanie structur classa
}; 
int Composition::goldYear = 2007;

class Marking : public Composition, public ModelC{  //nasledovanie
public:
	virtual void mark(Composition &b){ //virtual method //abstract class
		b.rating +=20;
		b.number +=150;

	}

};
class StartMark : public Marking{ 
	public:
		mark(Composition&rating, Composition&number); //method ot abstraktnogo classa

};

int main()
{
	int day, month, year;
    cout << "Data sozdaniya treka:\n";
    cout << "den': ";     cin >> day;
    cout << "mesyac: ";    cin >> month;
    cout << "god: ";  cin >> year;
    Composition song(01,01,1970);
    ModelC model(01,01,1970);
    song.setDate(day, month, year);
    song.getDate(); 
    cout << endl << "Statisticheskij chlen - zolotoj god:" << Composition::goldYear << endl;
    system("pause");
    return 0;
}
