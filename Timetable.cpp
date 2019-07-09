#include <iostream>
#include <string>
#include<cstring>
#include <fstream>
#include<iomanip>
using namespace std;

class ClassRecord
{
	private:
	string className;    // 과목명
	string yoil;              //  요일
	float startTime;      // 시작시간
	float duration;       //  수업시간
 	string classRoom;   // 강의실

    public:
	void setRecord(string cN,string y, float s,float d,string cR);
	void getRecord(string &cN,string &y, float &s,float &d,string &cR);
};

void ClassRecord::getRecord(string &cN,string &y, float &s,float &d,string &cR)
{
	cN = className;
	y= yoil;
	s = startTime;
	d = duration;
	cR = classRoom;
}

void ClassRecord::setRecord(string cN,string y, float s,float d,string cR)
{
	className=cN;
    yoil= y;
	startTime = s;
	duration = d;
	classRoom = cR;
}

class Myclass
{
	protected:
    int size;
	ClassRecord *mc;
	string timeTable[22][6];

	public:
	Myclass();
	~Myclass();
	Myclass(const string& fileName);
	void readData();   
    void SetFileName(const string& fileName);
    void showTT();    
	void buildTT();  
	void ShowTT();
   				  
    protected:
    string _fileName;
};

Myclass::Myclass()
{
   size = 0;
	mc = new ClassRecord[20];	
}

Myclass::~Myclass()
{
	delete mc;
}

void Myclass::SetFileName(const string& fileName)
{
	_fileName = fileName;
}

void Myclass::ShowTT()
{
	ofstream of(_fileName.c_str() );
}

void Myclass::readData()
{
	string className;
	string yoil;
	float startTime;
	float duration;
	string classRoom;

	ifstream ifread("input.txt");
    	while(!ifread.eof())
		{
    		ifread >> className >> yoil >> startTime >> duration >> classRoom;
			mc[size].setRecord(className, yoil, startTime, duration, classRoom);
    		size++;
		}
    ifread.close();
}

void Myclass::buildTT()
{
	string className;
	string yoil;
	float startTime;
	float duration;
	string classRoom;
	
	int i,j,s,e,c;  //s: 시작시간 인덱스, e: 종료시간 인덱스 c: TT의 column 인덱스
		
	for(i=0; i<size; i++) {
		mc[i].getRecord(className, yoil, startTime, duration, classRoom);
			
		string A[6] = {"","Mon","Tue","Wed","Thu","Fri"}; 
		string B[22] = {"", "1A", "1B", "2A", "2B", "3A", "3B", "4A", "4B", "5A", "5B", "6A", "6B", "7A", "7B", "8A", "8B", "9A", "9B", "10A", "10B"};

		for(int g=0; g<6; g++){
			timeTable[0][g] = A[g];
		}
     
    	for(int h=0; h<22; h++){
			timeTable[h][0] = B[h];
		}
		
		    int s=2*(startTime-1);
	        int e=s+(duration/30)-1;

			if( yoil.compare("Mon") == 0 )  c=0;
			else if( yoil.compare("Tue") == 0 )  c=1;
			else if( yoil.compare("Wed") == 0 )  c=2;
			else if( yoil.compare("Thu") == 0 )  c=3;
			else if( yoil.compare("Fri") == 0 )  c=4;

			for( int r = s; r <= e; r++ ) {
				string s = className+classRoom;
				timeTable[r+1][c+1] = s; 
	      }
	 }
}

void Myclass::showTT()
{
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<6;j++)
		{  	     
			if(timeTable[i][j]==""){
				cout<<setw(10);
			}		
			cout << setw(20) <<timeTable[i][j];
		}
		cout <<endl;
	}
}

class MyclassHTML : public Myclass
{
	 public:
	  void ShowTT();
	  void SetFont(const string& fontName, int fontSize,const string& fontColor);
	
	protected:
	  string _fontName;
	  int    _fontSize;
	  string _fontColor;
};

void MyclassHTML::SetFont(const string& fontName, int fontSize, const string& fontColor)
{
	_fontName = fontName;
	_fontSize = fontSize;
	_fontColor = fontColor;
}

void MyclassHTML::ShowTT()
{
	ofstream of( _fileName.c_str() );
	of << "<HTML><META CHARSET= UTF-8><HEAD><TITLE>2018 Timetable</TITLE></HEAD><BODY>";
	of << "<H1>2018 Timetable</H1>";
	of<< "<table border>";
	
	for(int i=0; i<21; i++) {
		of << "<tr>";
		for(int j = 0; j < 6; j++ ) {
			of << "<td align = center >" << timeTable[i][j] <<  "</td>"  ;
		}
		of<< "</tr>";
	}
	  of<< "</table>";
	of << "</BODY></HTML>";
}
	
int main()
{
	Myclass mco;
	
	mco.readData();	
	mco.buildTT();
	mco.showTT(); //text 형식으로 시간표 출력

	MyclassHTML mch;
	 mch.readData();
	 mch.buildTT();
     mch.SetFileName("test.html");
	 mch.SetFont("Arial", 16, "blue ");
	 mch.ShowTT();
 
	return 0;
}



 

 


