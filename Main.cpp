#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

bool clickerStatus = false;

void menu(bool clickerStatus)
{
	system("cls");

	string status = clickerStatus ? "ON" : "OFF";

	cout << "CPP-Clicker | Status: " << status;
}

int main()
{
	menu(clickerStatus);

	while (true)
	{
		if (GetAsyncKeyState('X') & 1)
		{
			clickerStatus = !clickerStatus;
			menu(clickerStatus);
		}

		if (clickerStatus)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		
		Sleep(100);
	}
}