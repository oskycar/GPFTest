// GPFWriter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.pb.h"
#include <fstream>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	lm::helloworld msg1;
	msg1.set_id(11);
	msg1.set_str("hello");
	fstream output("./log",ios::out | ios::trunc | ios::binary);
	
	if (!msg1.SerializePartialToOstream(&output))
	{
		cerr << "failed to write msg."<<endl;
		return -1;
	}
	output.close();

	string strt;
	msg1.SerializeToString(&strt);

	lm::helloworld msg2;
	fstream input("./log",ios::in | ios::binary);
	if (!msg2.ParseFromIstream(&input))
	{
		cerr<<"Failed to parse address book"<<endl;
		return -1;
	}

	input.close();
	cout<< msg2.id()<<endl;
	cout<<msg2.str() <<endl;

	return 0;
}

