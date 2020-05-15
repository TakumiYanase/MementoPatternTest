//=====================================================================
/// File Name	: main.cpp
/// Date		: 2020.05.15
/// Author		: Takumi Yanase
//=====================================================================
#include <iostream>
#include "Originator.h"
#include "CareTaker.h"
#include "Memento.h"
//=====================================================================
int main()
{
	Originator* originator = new Originator();
	CareTaker* caretaker = new CareTaker(originator);

	originator->Write("１世代\n");
	caretaker->Save(); // 最初の状態を記録（１世代目）

	originator->Write("２世代\n");
	caretaker->Save(); // ２世代目の状態を記録

	originator->Write("３世代");
	caretaker->Save(); // ３世代目の状態を記録
	originator->Print();

	// ２世代の状態にセット
	caretaker->PutBack(1);
	originator->Print();

	// 最初の状態にセット
	caretaker->PutBack(0);
	originator->Print();

	// ３世代目の状態に戻す
	caretaker->PutBack(2);
	originator->Print();

	delete caretaker;
	delete originator;

	return 0;
}