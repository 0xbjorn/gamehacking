#include <Windows.h>
#include <iostream>

using namespace std;

int main() {


	HWND sof2_window = FindWindow(NULL, "SoF2 MP Test");
	DWORD process_id = 0; //placeholder
	GetWindowThreadProcessId(sof2_window, &process_id); //give value to process_id
	HANDLE sof2_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	DWORD gold_value = 0;
	DWORD bytes_read = 0;
	DWORD base_address = 0x017EECB8;

	ReadProcessMemory(sof2_process, (LPCVOID)base_address, &gold_value, 4, &bytes_read);


	return 0;
}
