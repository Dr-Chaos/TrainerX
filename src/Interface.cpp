#include "Interface.hpp"

void Interface::Start()
{
	/*
		printf(" _____          _               __  __\n");
		printf("|_   _| __ __ _(_)_ __   ___ _ _\ \/ /\n");
		printf("  | || '__/ _` | | '_ \ / _ \ '__\  / \n");
		printf("  | || | | (_| | | | | |  __/ |  /  \ \n");
		printf("  |_||_|  \__,_|_|_| |_|\___|_| /_/\_\\n");
		printf("\n\n");*/
		printf("Seja bem vindo ao TrainerX, com este programa voc� poder� alterar \"valores do Grand Theft Auto San Andreas\n");
		printf("Utilizamos a manipula��o de endere�os de mem�ria para alterar os valores, voc� pode ver o programa no GitHub.");
		printf("Github: www.github.com\\TrainerX\n ");
		printf("Existem 3 coisas poss�veis de se mudarem, vida, dinheiro e armadura, basta s� escrever uma destas, tambem pode escrever sair para sair.");
		printf("\n");
		printf("A inicializar o programa..");
		if (!trainer.memory.InitializeMemoryHandler())
		{
			printf("n�o foi poss�vel iniciar!");
			Interface::Close();
		}
}

void Interface::ShowMenu()
{
	system("cls");
	printf("O que deseja alterar? ");
	std::cin >> Interface::input;
	Interface::ProcessInput();
}


int Interface::ProcessInput()
{
	if (Interface::input == "vida")
	{
		float value = 0;
		ReadProcessMemory(Interface::trainer.memory.hProc, (LPCVOID)Interface::trainer.TRAINER_LIFE, &value, sizeof(value), 0);

		system("cls");
		std::cout << "Valor atual: " << value << std::endl;
		printf("Novo valor: ");
		std::cin >> value;
		trainer.SetLife(value);

	} else if (Interface::input == "dinheiro") {
		int value;
		system("cls");
		printf("Novo valor: ");
		std::cin >> value;
		trainer.SetMoney(value);
	}else if (Interface::input == "armadura") {
		float  value;
		system("cls");


		printf("Novo valor: ");
		std::cin >> value;
		trainer.SetArmor(value);
	}else if (Interface::input == "sair") {
		Interface::Close();
	}
	return 1;
}

void Interface::Close()
{
	this->opened = false;
	
}

bool Interface::IsOpen(){ return opened; }