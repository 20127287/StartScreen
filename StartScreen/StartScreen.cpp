#include "StartScreen.h"


void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void goToXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void textcolor(int x) {
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}


void SetWindowSize(SHORT width, SHORT height) {
	RECT rect;
	HWND console = GetConsoleWindow();
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, width, height, TRUE);
}


// Hidden pointer function
void noCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


//***************************************************************************
// ******************************* Vẽ logo **********************************
// x: Hoành độ
// y: Tung độ
// speed: Tốc độ vẽ
// delay: Thời gian delay
// color: Màu sắc


void khtn(int x, int y, int speed, int delay, int color)
{
	ifstream fi("KHTN.txt");

	if (fi.fail()) return;

	string s;
	textcolor(color);

	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		goToXY(x, y + i);
		cout << s;
		Sleep(speed);
	}

	textcolor(15);
	fi.close();
	Sleep(delay);
}


void team5(int x, int y, int speed, int delay, int color)
{
	ifstream fi("Team5.txt");

	if (fi.fail()) return;

	string s;
	textcolor(color);

	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		goToXY(x, y + i);
		cout << s;
		Sleep(speed);
	}

	textcolor(15);
	fi.close();
	Sleep(delay);
}
//**************************************************************
// Vẽ xe
void drawCarRight3(int x, int y)
{
	goToXY(x, y);
	cout << "    _________    ";

	goToXY(x, y + 1);
	cout << " __/__|___|__" << char(92) << "__ ";

	goToXY(x, y + 2);
	cout << "/______________" << char(248) << char(92);

	goToXY(x, y + 3);
	cout << "'-(o)-------(o)-" << char(34);
}


// Xe chạy:
// x0, y0: Tọa độ gốc
// x1: Tọa độ điểm đến (Xe chạy ngang nên chỉ có x thay đổi, y vẫn giữ nguyên, nên không cần đến y1)
// speed: Tốc độ xe
void carRight3move(int x0, int y0, int x1, int speed)
{
	if (x1 <= x0 || x1 - 18 <= 0) return;

	for (int i = x0; i < x1 - 18; i++) {
		drawCarRight3(i + x0, y0);
		Sleep(speed);
		textcolor(0);
		drawCarRight3(i + x0, y0);
		textcolor(15);
	}
}

//******************************************************************

// Vẽ title:
// x0, y0: Tọa độ
// color: Màu sắc
void drawTitle(int x0, int y0, int color)
{
	ifstream fi("Title.txt");

	if (fi.fail()) return;

	int x, y;
	textcolor(color);

	PlaySound(TEXT("Writing.wav"), NULL, SND_ASYNC);
	Sleep(200);
	while (!fi.eof()) {
		fi >> x >> y;
		goToXY(x0 + x, y0 + y);
		cout << char(254);
		Sleep(8);
	}

	textcolor(15);
	fi.close();
}


// Vẽ màn hình start:
// x0, y0: Tọa độ
void startScreen(int x0, int y0)
{
	// Vẽ title:
	drawTitle(x0, y0, 151);
	Sleep(300);

	// Vẽ xe:
	PlaySound(TEXT("Car.wav"), NULL, SND_ASYNC);
	carRight3move(0, y0 + 5, 164, 18);

	// Vẽ đường nằm ngang:
	textcolor(151);
	for (int i = 0; i < 127; i++) {
		goToXY(i + x0, 6 + y0);
		cout << char(254);
		Sleep(3);
	}

	// Nhạc nền:
	PlaySound(TEXT("ForestWalk.wav"), NULL, SND_LOOP);

	// Đổi màu lại:
	textcolor(15);
}