#include "MemoryHandler.hpp" //MemoryHandler Class defenition 

bool MemoryHandler::InitializeMemoryHandler()
{
	HWND hWnd = FindWindowA(0, "GTA:SA:MP"); //Finds the GTA:SA-MP window, you can change it to the GTA itself if you want to

	if (hWnd == 0){ //if the window isn't opened it sends an error
		std::cerr << "N�o foi poss�vel encontrar o programa" << std::endl;
		return false; // There isn't anything else to do.
	}

	DWORD PID; //Stores the process id
	GetWindowThreadProcessId(hWnd, &PID); //Gets the process ID
	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, PID); //Opens the process
	if (!hProc) { //Cannot open the process
		std::cerr << "N�o foi poss�vel abrir o processo." << std::endl;
		return false; // THere isn't anything to do.

	}
	return true;
}

void MemoryHandler::CloseMemoryHandler()
{
	CloseHandle(MemoryHandler::hProc); //Close the Handler.
}