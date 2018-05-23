#include "Header.h"


void doOperation(struct node *root, string instruction, int number)
{
	if (instruction == "add")
	{
		add(root, number);
	}
	else if (instruction == "display")
	{
		display(root);
	}
	else if (instruction == "min")
	{
		findMinNode(root);
	}
	else if (instruction == "max")
	{
		findMaxNode(root);
	}
	else if (instruction == "delete")
	{
		deleteNode(root, number);
	}
	else if (instruction == "paint")
	{
		paint(root, 0);
	}
	else
	{
		cout << "Error" << endl;
	}
}

bool loadFile(struct node *root, string fileName)
{
	ifstream file;
	file.open(fileName.c_str());
	if (!file.good())
		return false;

	while (true)
	{
		string a;
		int b;
		file >> a >> b;
		if (file.good()) {
			doOperation(root, a, b);
			//cout << a << b;//kontrola wejscia
		}
		else
			break;

	}
	return true;
}

void stop() 
{
	cout << "Give me anything" << endl;
	int r;
	cin >> r;
	cout << "WOW";
}
/*
void safe(node *root)
{
	string linia;
	fstream sfile;

	sfile.open("safe.txt", ios::out | ios::trunc);
	if (sfile.good() == true)
	{
		safeFile(root);
		sfile.close();
	}
}

void safeFile(node *root) {

		if (root != NULL)
		{
			safeFile(root->left);
			sfile << root->key << endl;
			safeFile(root->right);
		}
}

*/
int main()
{
	struct node *root = NULL;
	root = add(root, 2);

	root = add(root, 2);
	root = add(root, 4);
	root = add(root, 10);
	root = add(root, 6);
	root = add(root, 8);
	root = add(root, 22);
	root = add(root, 12);
	root = add(root, 32);
	root = add(root, 16);
	display(root);
	paint(root, 0);
	deleteNode(root, 8);
	deleteNode(root, 22);
	display(root);
	paint(root, 0);
	
	
	//	if (!loadFile(root, "data.txt"))
	//		std::cout << "Error, cant open file" << std::endl;
	//safeFile(root);
	stop();


		return 0;

}
