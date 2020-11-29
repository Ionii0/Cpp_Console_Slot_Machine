#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <MMsystem.h>
#include <cstdlib>
#include <mutex>

using namespace std;
std::mutex K;

/*
┐ \xBF

└ \xC0

│ \xB3

┘ \xD9

┌ \xDA
─ \xC4

█ \xDB

▀ \xDF

▄ \xDC
*/
bool luminand=true,dublajAnim=false;
enum ecran { play, pause, menu,dublaj };
enum forme { unu, doi, trei, patru, cinci, sase, sapte, opt, noua ,dreptunghi, linie,  zero,trifoi,romb};
enum orientare { sus, jos, dreapta, stanga };
enum cazuri{adevarat,intre,fals};
int Bani=1000 ,Prize=0,Bet=20;
cazuri BagaFisa=intre;
cazuri dublajRN=intre;
void luminite(){
while (luminand){
		system("color 4");
		Sleep(150);
		system("color 5");
		Sleep(150);
		system("color 3");
		Sleep(150);
		system("color 6");
        Sleep(150);}}
void luminite2()
{for(int i=1;i<=10;i++)
{
system("color 4");
		Sleep(150);
		system("color 5");
		Sleep(150);
		system("color 3");
		Sleep(150);
		system("color 6");
        Sleep(150);
}

}

class Desen
{
private:
	int lungime, latime, Xul, Yul;
	forme _forma;
	orientare _orientare;
	HANDLE consola;

public:
	Desen(forme f, orientare o, int lun)
	{
		this->lungime = lun;
		this->_forma = f;
		this->_orientare = o;
	}

	Desen(forme f, int lun, int lat)
	{

		this->_forma = f;

		switch (f)
		{
		case dreptunghi:
			this->lungime = lun;
			this->latime = lat;
			break;
		case linie:
			this->latime = lat;
			this->lungime = lun;
			break;
		}
	}

	void DeseneazaLa(int x, int y)
	{std::lock_guard<mutex>locker(K);
		this->Xul = x;
		this->Yul = y;
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        consola = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coordonata;
		coordonata.X = x;
		coordonata.Y = y;
		switch (this->_forma)
		{
		case dreptunghi:
		{
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDA";

			for (int i = 0; i < this->latime - 1; i++)
			{
				x = x + 1;
				coordonata.X = x;
				SetConsoleCursorPosition(consola, coordonata);
				cout << "\xC4";
			}

			cout << "\xBF";
			x = x + 1;
			coordonata.X = x;

			for (int i = 0; i < this->lungime - 1; i++)
			{
				y = y + 1;
				coordonata.Y = y;
				SetConsoleCursorPosition(consola, coordonata);
				cout << "\xB3";
			}

			y = y + 1;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xD9";

			for (int i = 0; i < this->latime - 1; i++)
			{
				x = x - 1;
				coordonata.X = x;
				SetConsoleCursorPosition(consola, coordonata);
				cout << "\xC4";
			}
			x = x - 1;
			coordonata.X = x;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xC0";

			for (int i = 0; i < this->lungime - 1; i++)
			{
				y = y - 1;
				coordonata.Y = y;
				SetConsoleCursorPosition(consola, coordonata);
				cout << "\xB3";
			}

			for (int i = 0; i < this->latime - 1; i++)
			{
				y = y + 1;
			}
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << endl;

			break;
		}
		case linie:
		{
			x = this->Xul;
			y = this->Yul;
			switch (this->_orientare)
			{
			case sus:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << "\xB3";
					y--;
					coordonata.Y = y;
				}
				break;
			case jos:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << "\xB3";
					y++;
					coordonata.Y = y;
				}
				break;
			case dreapta:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << "\xC4";
					x++;
					coordonata.X = x;
				}
				break;
			case stanga:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << "\xC4";
					x--;
					coordonata.X = x;
				}
				break;
			}
			break;
		}
		case zero:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC" << "\xDC" << "\xDC" << "\xDC" << "\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB" << "   " << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB" << "   " << "\xDB";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB" << "   " << "\xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF" << "\xDF" << "\xDF" << "\xDF" << "\xDF";
			break;
		}
		case unu:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x+1;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF";

			break;
		}
		case doi:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "\xDC" << "\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF" << "  " << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "\xDC" << "\xDF";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF" << "\xDF" << "\xDF" << "\xDF";
			break;
		}
		case trei:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "\xDC" << "\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF" << "  " << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "  " << "\xDF" << "\xDC";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC" << "  " << "\xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "\xDF" << "\xDF";
			break;
		}
		case patru:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB\xDC\xDB\xDC";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "  \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "  \xDF";
			break;
		}
		case cinci:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC\xDC\xDC\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF\xDF\xDF\xDC";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF\xDF\xDF";
			break;
		}
		case sase:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC\xDC\xDC\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB  \xDF";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB\xDF\xDF\xDB";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB  \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF\xDF\xDF\xDF";
			break;
		}
		case sapte:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC\xDC\xDC\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   \xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   \xDB";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   \xDF";
			break;
		}
		case opt:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " \xDC\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB  \xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC\xDF\xDF\xDC";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB  \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " \xDF\xDF";
			break;
		}
		case noua:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC\xDC\xDC\xDC";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDB  \xDB";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF\xDF\xDF\xDB";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDC  \xDB";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "\xDF\xDF\xDF\xDF";
			break;
		}
		case trifoi:
		{


		coordonata.X = this->Xul;
		coordonata.Y = this->Yul;
		SetConsoleCursorPosition(consola, coordonata);
	    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE );
cout<<"     .-~~-."<<endl;
coordonata.Y=y+1;
SetConsoleCursorPosition(consola, coordonata);
cout<<"    {      }"<<endl;
coordonata.Y=y+2;
SetConsoleCursorPosition(consola, coordonata);
cout<<".-~-.    .-~-."<<endl;
coordonata.Y=y+3;
SetConsoleCursorPosition(consola, coordonata);
cout<<"{              }"<<endl;
coordonata.Y=y+4;
SetConsoleCursorPosition(consola, coordonata);
cout<<" `.__.'||`.__.'"<<endl;
coordonata.Y=y+5;
SetConsoleCursorPosition(consola, coordonata);
cout<<"       ||"<<endl;
coordonata.Y=y+6;
SetConsoleCursorPosition(consola, coordonata);
cout<<"      '--`"<<endl;
break;
}
        case romb :{
        coordonata.X = this->Xul;
		coordonata.Y = this->Yul;
		SetConsoleCursorPosition(consola, coordonata);
	    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
cout<<"     /\\"<<endl;
coordonata.Y=y+1;
SetConsoleCursorPosition(consola, coordonata);
cout<<"   .'  `."<<endl;
coordonata.Y=y+2;
SetConsoleCursorPosition(consola, coordonata);
cout<<"  '      `."<<endl;
coordonata.Y=y+3;
SetConsoleCursorPosition(consola, coordonata);
cout<<"<          >"<<endl;
coordonata.Y=y+4;
SetConsoleCursorPosition(consola, coordonata);
cout<<" `.      .'"<<endl;
coordonata.Y=y+5;
SetConsoleCursorPosition(consola, coordonata);
cout<<"   `.  .'"<<endl;
coordonata.Y=y+6;
SetConsoleCursorPosition(consola, coordonata);
cout<<"     \\/"<<endl;

 break;
  }
	}
	  }

	void ClearShape()
	{std::lock_guard<mutex>locker(K);
		int x, y;
		x = this->Xul;
		y = this->Yul;
		consola = GetStdHandle(STD_OUTPUT_HANDLE);
		forme f = this->_forma;
		COORD coordonata;
		coordonata.X = x;
		coordonata.Y = y;

		switch (f)
		{
		case dreptunghi:
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";

			for (int i = 0; i < this->latime - 1; i++)
			{
				x = x + 1;
				coordonata.X = x;
				SetConsoleCursorPosition(consola, coordonata);
				cout << " ";
			}

			cout << " ";
			x = x + 1;
			coordonata.X = x;

			for (int i = 0; i < this->lungime - 1; i++)
			{
				y = y + 1;
				coordonata.Y = y;
				SetConsoleCursorPosition(consola, coordonata);
				cout << " ";
			}

			y = y + 1;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout <<  " ";

			for (int i = 0; i < this->latime - 1; i++)
			{
				x = x - 1;
				coordonata.X = x;
				SetConsoleCursorPosition(consola, coordonata);
				cout << " ";
			}
			x = x - 1;
			coordonata.X = x;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";

			for (int i = 0; i < this->lungime - 1; i++)
			{
				y = y - 1;
				coordonata.Y = y;
				SetConsoleCursorPosition(consola, coordonata);
				cout << " ";
			}

			for (int i = 0; i < this->latime - 1; i++)
			{
				y = y + 1;
			}
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << endl;
			break;
		case linie:
			switch (this->_orientare)
			{
			case sus:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << " ";
					y--;
					coordonata.Y = y;
				}
				break;
			case jos:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << " ";
					y++;
					coordonata.Y = y;
				}
				break;
			case dreapta:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << " ";
					x++;
					coordonata.X = x;
				}
				break;
			case stanga:
				for (int i = 1; i <= this->lungime; i++)
				{
					SetConsoleCursorPosition(consola, coordonata);
					cout << " ";
					x--;
					coordonata.X = x;
				}
				break;
			}
			break;

		case zero:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " " << " " << " ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "   " << " B";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " B" << "   " << " ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "   " << " ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " " << " " << " ";
			break;
		}
		case unu:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x+1;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			break;
		}
		case doi:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "  " << " ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " " << " ";
			break;
		}
		case trei:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "  " << " ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "  " << " " << " ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << "  " << " ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " " << " " << " ";
			break;
		}
		case patru:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   ";
			break;
		}
		case cinci:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << " ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   ";
			break;
		}
		case sase:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			break;
		}
		case sapte:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			break;
		}
		case opt:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "   ";
			break;
		}
		case noua:
		{
			x = this->Xul;
			y = this->Yul;
			coordonata.X = x;
			coordonata.Y = y;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 1;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 2;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			coordonata.Y = y + 3;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "     ";
			coordonata.Y = y + 4;
			SetConsoleCursorPosition(consola, coordonata);
			cout << "    ";
			break;
		}
		case trifoi:
		{

       x = this->Xul;
			y = this->Yul;
		coordonata.X = x;
		coordonata.Y = y;
		SetConsoleCursorPosition(consola, coordonata);

cout<<"           "<<endl;
coordonata.Y=y+1;
SetConsoleCursorPosition(consola, coordonata);
cout<<"            "<<endl;
coordonata.Y=y+2;
SetConsoleCursorPosition(consola, coordonata);
cout<<"              "<<endl;
coordonata.Y=y+3;
SetConsoleCursorPosition(consola, coordonata);
cout<<"                "<<endl;
coordonata.Y=y+4;
SetConsoleCursorPosition(consola, coordonata);
cout<<"               "<<endl;
coordonata.Y=y+5;
SetConsoleCursorPosition(consola, coordonata);
cout<<"         "<<endl;
coordonata.Y=y+6;
SetConsoleCursorPosition(consola, coordonata);
cout<<"          "<<endl;
break;
}
        case romb :{
        x = this->Xul;
			y = this->Yul;
        coordonata.X =x;
		coordonata.Y =y;
		SetConsoleCursorPosition(consola, coordonata);

cout<<"        "<<endl;
coordonata.Y=y+1;
SetConsoleCursorPosition(consola, coordonata);
cout<<"         "<<endl;
coordonata.Y=y+2;
SetConsoleCursorPosition(consola, coordonata);
cout<<"           "<<endl;
coordonata.Y=y+3;
SetConsoleCursorPosition(consola, coordonata);
cout<<"            "<<endl;
coordonata.Y=y+4;
SetConsoleCursorPosition(consola, coordonata);
cout<<"           "<<endl;
coordonata.Y=y+5;
SetConsoleCursorPosition(consola, coordonata);
cout<<"         "<<endl;
coordonata.Y=y+6;
SetConsoleCursorPosition(consola, coordonata);
cout<<"        "<<endl;

 break;
  }
		default:
			break;
		}
	}
};

void ClearSpace(int x1, int y1, int x2, int y2)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	c.X = 0;
	c.Y = 0;
	for (int i = y1; i < y2+1; i++)
	{
		for (int j = x1; j < x2+1; j++)
		{
			c.X = j;
			c.Y = i;
			SetConsoleCursorPosition(h, c);
			cout << " ";
		}
	}

}

class Screen
{
private:
	ecran _ecran;
	int lungime, latime;
public:
	Screen(ecran e, int lun, int lat)
	{
		this->_ecran = e;
		this->latime = lat;
		this->lungime = lun;
	}
	void RenderScreen()
	{
		ecran e = this->_ecran;
		Desen Boreder(dreptunghi, this->lungime, this->latime);
		Desen CasutaSlot(dreptunghi, 7, 8);
		Desen CasutaBani(dreptunghi, 3, 10);
		Desen CasutaInfo(dreptunghi,7,50);
		Desen CasutaDublaj(dreptunghi,14,19);
		Desen CasutaMenu1(dreptunghi,3,14);
		Desen CasutaMenu2(dreptunghi,3,14);
		Desen CasutaMenu3(dreptunghi,15,120);
		Desen CasutaDublajInfo(dreptunghi,12,50);
		HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bani;
		bani.X=4;
		bani.Y=28;
		COORD bet;
		bet.X=18;
		bet.Y=28;
		HANDLE consol= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD info;
		info.X=3 ;
		info.Y=34 ;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (e)
		{
		case play:
			Boreder.DeseneazaLa(0, 0);
			CasutaSlot.DeseneazaLa(13, 5);
			CasutaSlot.DeseneazaLa(13, 12);
			CasutaSlot.DeseneazaLa(13, 19);
			///Separare
			CasutaSlot.DeseneazaLa(22, 5);
			CasutaSlot.DeseneazaLa(22, 12);
			CasutaSlot.DeseneazaLa(22, 19);
			///Separare
			CasutaSlot.DeseneazaLa(31, 5);
			CasutaSlot.DeseneazaLa(31, 12);
			CasutaSlot.DeseneazaLa(31, 19);
			///Separare
			CasutaBani.DeseneazaLa(3, 27);
			CasutaBani.DeseneazaLa(14, 27);
			///Separare
			CasutaInfo.DeseneazaLa(1,32);
			SetConsoleCursorPosition(h,bani);
			cout<<Bani;
			SetConsoleCursorPosition(h,bet);
			cout<<Bet;



			break;
			case dublaj:
			    {
			    Boreder.DeseneazaLa(0, 0);
			    CasutaDublaj.DeseneazaLa(4,5);
			    CasutaDublajInfo.DeseneazaLa(1,32);
			    CasutaDublaj.DeseneazaLa(32,5);
			    CasutaDublaj.DeseneazaLa(52,5);
			    CasutaDublaj.DeseneazaLa(72,5);
			    CasutaDublaj.DeseneazaLa(92,5);
			    CasutaDublaj.DeseneazaLa(112,5);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
              info.X=3 ;
		      info.Y=34 ;
		      SetConsoleCursorPosition(consol,info);
			    cout<<"*APASA {4} pentru ROSU,";
			    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE );
			    cout<<"APASA {6} pentru NEGRU ";
			    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
			    info.Y=info.Y+2;
			    SetConsoleCursorPosition(consol,info);
			    cout<<"*Daca nimeresti culoarea se dubleaza PREMIUL";
			    info.Y=info.Y+2;
			    SetConsoleCursorPosition(consol,info);
			    cout<<"*Daca gresesti culoarea PIERZI TOT !";
			    info.Y=info.Y+2;
			    SetConsoleCursorPosition(consol,info);
			    cout<<"*Ai voie SA DUBLEZI de 5 ORI";
			    info.Y=info.Y+2;
			    SetConsoleCursorPosition(consol,info);
			    cout<<"*Daca vrei sa revii la pacanea apasa {0}";



			    break;}

		case pause:
			cout << "mama";
			break;
		case menu:
		{
		    std::thread lumina(luminite);
		    lumina.detach();
		    if(lumina.joinable())
		    lumina.join();

		     cout<<"        ___                             ___          ___          ___          ___                   ___          ___     "<<endl;
  cout<<"       /\\  \\        ___                /\\__\\        /\\  \\        /\\  \\        /\\__\\        ___      /\\__\\        /\\  \\    "<<endl;
  cout<<"      /::\\  \\      /\\  \\              /::|  |      /::\\  \\      /::\\  \\      /:/  /       /\\  \\    /::|  |      /::\\  \\   "<<endl;
  cout<<"     /:/\\:\\  \\     \\:\\  \\            /:|:|  |     /:/\\:\\  \\    /:/\\:\\  \\    /:/__/        \\:\\  \\  /:|:|  |     /:/\\:\\  \\  "<<endl;
  cout<<"    /::\\~\\:\\  \\    /::\\__\\          /:/|:|__|__  /::\\~\\:\\  \\  /:/  \\:\\  \\  /::\\  \\ ___    /::\\__\\/:/|:|  |__  /::\\~\\:\\  \\ "<<endl;
  cout<<"   /:/\\:\\ \\:\\__\\__/:/\\/__/         /:/ |::::\\__\\/:/\\:\\ \\:\\__\\/:/__/ \\:\\__\\/:/\\:\\  /\\__\\__/:/\\/__/:/ |:| /\\__\\/:/\\:\\ \\:\\__\\"<<endl;
  cout<<"   \\/__\\:\\/:/  /\\/:/  /            \\/__/~~/:/  /\\/__\\:\\/:/  /\\:\\  \\  \\/__/\\/__\\:\\/:/  /\\/:/  /  \\/__|:|/:/  /\\:\\~\\:\\ \\/__/"<<endl;
  cout<<"        \\::/  /\\::/__/                   /:/  /      \\::/  /  \\:\\  \\           \\::/  /\\::/__/       |:/:/  /  \\:\\ \\:\\__\\  "<<endl;
  cout<<"         \\/__/  \\:\\__\\                  /:/  /       /:/  /    \\:\\  \\          /:/  /  \\:\\__\\       |::/  /    \\:\\ \\/__/  "<<endl;
  cout<<"                 \\/__/                 /:/  /       /:/  /      \\:\\__\\        /:/  /    \\/__/       /:/  /      \\:\\__\\    "<<endl;
  cout<<"                                       \\/__/        \\/__/        \\/__/        \\/__/                 \\/__/        \\/__/    "<<endl;
HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
COORD buton1;
COORD buton2;
buton1.X=12;
buton1.Y=26;
buton2.X=12;
buton2.Y=31;
CasutaMenu1.DeseneazaLa(10,25);
CasutaMenu2.DeseneazaLa(10,30);
SetConsoleCursorPosition(consola,buton1);
cout<<"PLAY={SPACE}";
SetConsoleCursorPosition(consola,buton2);
cout<<"QUIT={X}";
buton2.X=23;
buton2.Y=21;
SetConsoleCursorPosition(consola,buton2);
cout<<"Alpha 1.1";
CasutaMenu3.DeseneazaLa(1,34);
buton2.X=12;
buton2.Y=36;
SetConsoleCursorPosition(consola,buton2);
cout<<"INFO !"<<endl;
buton2.X=3;
buton2.Y=38;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *Primul spin este free , apasa o singura data {SPACE} dupa ce intrii in play screen ! NU poti mari BET prima data"<<endl;
buton2.Y=buton2.Y+2;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *Dupa primul spin ai voie sa maresti BET"<<endl;
buton2.Y=buton2.Y+2;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *NU apasa de mai multe ori pe {SPACE} !!"<<endl;
buton2.Y=buton2.Y+2;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *Castigi daca ai 3 numere la fel pe o linie sau pe diagonala , castigi BETx10 pentru fiecare linie sau diagonala";
buton2.Y=buton2.Y+2;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *Daca o sa ai minim o linie completa intrii direct in GAMBLING screen";
buton2.Y=buton2.Y+2;
SetConsoleCursorPosition(consola,buton2);
cout<<"   *DISTRACTIE PLACUTA !";




			break;}


		default:
			cout << "mama";
			break;
		}

	}
};

class Joc{
private:
    int Coordx1,Coordx2,Coordx3,CoordY1,CoordY2,CoordY3,NrR,slep;
public:
    Joc(int KX1,int KX2,int KX3,int KY1,int KY2,int KY3,int nr,int dormi){
    this->Coordx1=KX1;
    this->Coordx2=KX2;
    this->Coordx3=KX3;
    this->CoordY1=KY1;
    this->CoordY2=KY2;
    this->CoordY3=KY3;
    this->NrR=nr;
    this->slep=dormi;
    }
    void Anim (){
srand(time(NULL));
int nry=this->NrR;
    int dormit=this->slep;
    forme Casuta11,Casuta22,Casuta33;

for(int qnry=nry;qnry>0;qnry--){

Casuta11=forme(rand()%9);
    Casuta22=forme(rand()%9);
    Casuta33=forme(rand()%9);

Desen numar1(Casuta11,0,0);
Desen numar2(Casuta22,0,0);
Desen numar3(Casuta33,0,0);

numar1.DeseneazaLa(this->Coordx1,this->CoordY1);
numar2.DeseneazaLa(this->Coordx2,this->CoordY1);
numar3.DeseneazaLa(this->Coordx3,this->CoordY1);
Sleep(dormit);

numar1.ClearShape();
numar2.ClearShape();
numar3.ClearShape();
/// Primul rand[sus]
Desen numar4(Casuta11,0,0);
Desen numar5(Casuta22,0,0);
Desen numar6(Casuta33,0,0);

numar4.DeseneazaLa(this->Coordx1,this->CoordY2);
numar5.DeseneazaLa(this->Coordx2,this->CoordY2);
numar6.DeseneazaLa(this->Coordx3,this->CoordY2);
Sleep(dormit);

numar4.ClearShape();
numar5.ClearShape();
numar6.ClearShape();
/// Al doilea rand [sus]

Desen numar7(Casuta11,0,0);
Desen numar8(Casuta22,0,0);
Desen numar9(Casuta33,0,0);

numar7.DeseneazaLa(this->Coordx1,this->CoordY3);
numar8.DeseneazaLa(this->Coordx2,this->CoordY3);
numar9.DeseneazaLa(this->Coordx3,this->CoordY3);
Sleep(dormit);

numar7.ClearShape();
numar8.ClearShape();
numar9.ClearShape();
/// Al treilea rand [sus]





}

}

};


int Casuta1,Casuta3,Casuta2;int y=0;int Coloana ,VectorCasuta[11],NrCasuta=1;

 void FctAfiseazaInfo()
 {
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Info ;
Info.X=4;
Info.Y=35;
COORD prize;
	prize.X =4;
	prize.Y = 34;
	COORD bani;
	bani.X=4;
	bani.Y=28;
	COORD bet;
	bet.X=18;
	bet.Y=28;
	COORD InfoBet;
	InfoBet.X=4;
	InfoBet.Y=36;
	COORD Warning;
	Warning.X=4;
	Warning.Y=38;
	SetConsoleCursorPosition(h,bani);
	cout<<"     ";
    SetConsoleCursorPosition(h,bani);
    cout<<Bani;
	SetConsoleCursorPosition(h, prize);
cout<<"Ai castigat " <<"["<<Prize<<"]"<<" bani";
SetConsoleCursorPosition(h,Info);
cout<<"Daca bagi o fisa apasa {SPACE},altfel apasa{X}";
SetConsoleCursorPosition(h,InfoBet);
cout<<"Mareste BET cu{+},micsoreaza(nu recomand) cu{-}";}
 void MergiSus(){
HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);
COORD o;
o.X=0;
o.Y=0;
SetConsoleCursorPosition(q,o);}


void fctAnimDublaj(){
while(!dublajAnim)
    {
    Desen trifoii(trifoi,0,0);
    Desen rombb(romb,0,0);
    trifoii.DeseneazaLa(6,8);
    Sleep(200);
    trifoii.ClearShape();
    rombb.DeseneazaLa(6,8);
    Sleep(200);
    rombb.ClearShape();}
}


int main()
{system("mode 650");

    int CoordColoana;
bool Jucand,MeniuJoc=false;

Screen meniu(menu,0,0);
meniu.RenderScreen();
Screen mainScreen(play, 41,56);

while(MeniuJoc==false){
    switch(_getch())
    {
        case ' ':MeniuJoc=true;system("cls");mainScreen.RenderScreen();luminand=false;system("color 5");
	break;
case 'x':exit(0);

    }
}
MergiSus();
FctAfiseazaInfo();
   switch (_getch()){
   case ' ':BagaFisa=adevarat;
   break;
   case 'x':BagaFisa=fals;
   break;}
if(BagaFisa==adevarat)
 Jucand=true;
    else
    Jucand=false;
MergiSus();
while (Jucand){
MergiSus();
PlaySound(TEXT("Money-sound-insert-coin.wav"),NULL,SND_SYNC);
PlaySound(TEXT("Spin.wav"),NULL,SND_ASYNC|SND_ALIAS);
forme Casutaa1,Casutaa2,Casutaa3,Casutaa4,Casutaa5,Casutaa6,Casutaa7,Casutaa8,Casutaa9;
srand(time(NULL));
///Init casute
Casutaa1=forme(rand()%9);
Casutaa2=forme(rand()%9);
Casutaa3=forme(rand()%9);
Casutaa4=forme(rand()%9);
Casutaa5=forme(rand()%9);
Casutaa6=forme(rand()%9);
Casutaa7=forme(rand()%9);
Casutaa8=forme(rand()%9);
Casutaa9=forme(rand()%9);
///Anim coloana
Joc anima(14,24,34,6,14,20,13,100);///(KX1,KX2,KX3,KY1,KY2,KY3,nr,sleep)
anima.Anim();




///1 la 9
Desen numar1(Casutaa1,0,0);
Desen numar2(Casutaa2,0,0);
Desen numar3(Casutaa3,0,0);
Desen numar4(Casutaa4,0,0);
Desen numar5(Casutaa5,0,0);
Desen numar6(Casutaa6,0,0);
Desen numar7(Casutaa7,0,0);
Desen numar8(Casutaa8,0,0);
Desen numar9(Casutaa9,0,0);

///Treia (III)
numar3.DeseneazaLa(14,6);
numar6.DeseneazaLa(24,6);
numar9.DeseneazaLa(34,6);
Sleep(100);
///Clear
numar3.ClearShape();
numar6.ClearShape();
numar9.ClearShape();
///Clear[sus]
numar3.DeseneazaLa(14,14);
numar6.DeseneazaLa(24,14);
numar9.DeseneazaLa(34,14);
Sleep(100);
///Clear
numar3.ClearShape();
numar6.ClearShape();
numar9.ClearShape();
///Clear[sus]
numar3.DeseneazaLa(14,20);
numar6.DeseneazaLa(24,20);
numar9.DeseneazaLa(34,20);
Sleep(150);///(III)
///Doua (II)
numar2.DeseneazaLa(14,6);
numar5.DeseneazaLa(24,6);
numar8.DeseneazaLa(34,6);
Sleep(100);
///Clear
numar2.ClearShape();
numar5.ClearShape();
numar8.ClearShape();
///Clear[sus]
numar2.DeseneazaLa(14,14);
numar5.DeseneazaLa(24,14);
numar8.DeseneazaLa(34,14);
Sleep(150);///(II)
///Prima
numar1.DeseneazaLa(14,6);
numar4.DeseneazaLa(24,6);
numar7.DeseneazaLa(34,6);
Sleep(150);
///Init final
forme K1=Casutaa1,K2=Casutaa2,K3=Casutaa3,K4=Casutaa4,K5=Casutaa5,K6=Casutaa6,K7=Casutaa7,K8=Casutaa8,K9=Casutaa9;
///K1=casuta1,K2=casuta2,K3=casuta3,etc
PlaySound(TEXT("Cha-ching-sound.wav"),NULL,SND_SYNC);
PlaySound(TEXT("Spin.wav"),NULL,SND_ALIAS_SYSTEMEXIT);
int Multiplier=0;Prize=0;
///Space
if(K1==K4&&K4==K7&&K1==K7)
Multiplier=Multiplier+10;
    ///Linia 1[sus]
    if(K2==K5&&K5==K8&&K2==K8)
    Multiplier=Multiplier+10;
    ///Linia2[sus]
if(K3==K6&&K6==K9&&K3==K9)
    Multiplier=Multiplier+10;
    ///Linia3[sus]
    if(K1==K5&&K5==K9&&K1==K9)
        Multiplier=Multiplier+10;
    ///Diagonala principala[sus]
    if(K3==K5&&K5==K7&&K3==K7)
        Multiplier=Multiplier+10;
    ///Diagonala sec[sus]
    if(Multiplier>0){
        PlaySound(TEXT("Slot-machine-jackpot-sound-effect.wav"),NULL,SND_ASYNC);
        luminite2();}
    Prize=Prize+(Bet*Multiplier);


    ///Tryhard

    if(Multiplier>0){
    int NrDublari=1;
    bool ScreenDublaj=true;
    system("cls");
        Screen Dublaj(dublaj,0,0);
        Dublaj.RenderScreen();

    while(ScreenDublaj){
            bool Rosu=false,Negru=false;
            int RosuNegru=rand()%2+1;
            if(RosuNegru==2)
                Rosu=true;
                else{
                  Negru=true;}
dublajAnim=false;
Desen trifoii(trifoi,0,0);
    Desen rombb(romb,0,0);
std::thread t1(fctAnimDublaj);

        switch (_getch()){
        case '4':
            if(NrDublari>5){ScreenDublaj=false;}
            if(Rosu){Prize=Prize*2;
            dublajAnim=true;t1.join();rombb.DeseneazaLa(6,8);Sleep(400); rombb.ClearShape();
            switch(NrDublari){
            case 1:{Desen rosu(romb,0,0);
            rosu.DeseneazaLa(114,8);
            break;}
            case 2:{Desen rosu(romb,0,0);
            rosu.DeseneazaLa(94,8);
            break;}
            case 3:{Desen rosu(romb,0,0);
            rosu.DeseneazaLa(74,8);
            break;}
            case 4:{Desen rosu(romb,0,0);
            rosu.DeseneazaLa(54,8);
            break;}
            case 5:{Desen rosu(romb,0,0);
            rosu.DeseneazaLa(34,8);
            break;}
            }
            NrDublari++; }
            if(!Rosu){ScreenDublaj=false;Prize=0;dublajAnim=true;t1.join();trifoii.DeseneazaLa(6,8);Sleep(400);trifoii.ClearShape();}
            break;
        case '6':
            if(NrDublari>5){ScreenDublaj=false;}
            if(Negru){
            Prize=Prize*2;
            dublajAnim=true;t1.join();trifoii.DeseneazaLa(6,8);Sleep(400);trifoii.ClearShape();
            switch(NrDublari){
            case 1:{Desen negru(trifoi,0,0);
            negru.DeseneazaLa(114,8);
            break;}
            case 2:{Desen negru(trifoi,0,0);
            negru.DeseneazaLa(94,8);
            break;}
            case 3:{Desen negru(trifoi,0,0);
            negru.DeseneazaLa(74,8);
            break;}
            case 4:{Desen negru(trifoi,0,0);
            negru.DeseneazaLa(54,8);
            break;}
            case 5:{Desen negru(trifoi,0,0);
            negru.DeseneazaLa(34,8);
            break;}
            }
           NrDublari++; }
            if(!Negru){ScreenDublaj=false;Prize=0;dublajAnim=true;t1.join();rombb.DeseneazaLa(6,8);Sleep(400); rombb.ClearShape();}
            break;
        case '0':ScreenDublaj=false;system("color 6");break;}





        if(NrDublari==6){

     dublajAnim=true;

    ScreenDublaj=false;}
    if(dublajAnim==false)
      t1.join();

      }

       Sleep(500);
	system("cls");
        Screen mainScreen(play, 41,56);
	mainScreen.RenderScreen();
system("color 6");
    }

    Bani=Bani+Prize;

///Tryhard[sus]

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Info ;
Info.X=4;
Info.Y=35;
COORD prize;
	prize.X =4;
	prize.Y = 34;
	COORD bani;
	bani.X=4;
	bani.Y=28;
	COORD bet;
	bet.X=18;
	bet.Y=28;
	COORD InfoBet;
	InfoBet.X=4;
	InfoBet.Y=36;
	COORD Warning;
	Warning.X=30;
	Warning.Y=28;
	SetConsoleCursorPosition(h,bani);
	cout<<"     ";
    SetConsoleCursorPosition(h,bani);
    cout<<Bani;
	SetConsoleCursorPosition(h, prize);
cout<<"Ai castigat " <<"["<<Prize<<"]"<<" bani";
SetConsoleCursorPosition(h,Info);
cout<<"Daca bagi o fisa apasa {SPACE},altfel apasa{X}";
SetConsoleCursorPosition(h,InfoBet);
cout<<"Mareste BET cu{+},micsoreaza(nu recomand) cu{-}";


BagaFisa=intre;
bool Micsoreaza=false;
while(BagaFisa==intre){
switch (_getch()){
    case ' ':
    if (Bani<=19)BagaFisa=fals;
    if(Bani>=Bet)BagaFisa=adevarat;
    else {SetConsoleCursorPosition(h,Warning);cout<<"Micsoreaza BET";Micsoreaza=true;}
   break;
   case 'x':BagaFisa=fals;
   break;
   case '+': Bet=Bet+20; SetConsoleCursorPosition(h,bet);cout<<"      ";SetConsoleCursorPosition(h,bet);cout<<Bet;
   break;
   case '-':if(Bet>20){
    if(Micsoreaza==true)
   {SetConsoleCursorPosition(h,Warning);
   cout<<"              ";}
   Bet=Bet-20;SetConsoleCursorPosition(h,bet);cout<<"      ";SetConsoleCursorPosition(h,bet);cout<<Bet;}
   break;
}}

if(BagaFisa !=adevarat||Bani<20){
     PlaySound(TEXT("Game-over-robotic-voice.wav"),NULL,SND_SYNC) ;
     exit(0);
}
    Bani=Bani-Bet;
  system("cls");
        Screen mainScreen(play, 41,56);
	mainScreen.RenderScreen();
	Sleep(50);
	y=0;
}






	return 0;
}
