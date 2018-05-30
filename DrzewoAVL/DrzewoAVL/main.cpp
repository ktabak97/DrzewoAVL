#include "Header.h"


void save(node*root)
{
	ofstream out;
	out.open("save.txt", ios::out | ios::app);
	if (root != NULL)
	{
		save(root->left);
		out << root->key << " ";
		save(root->right);

	}
	out.close();
}

int main()
{
	struct node *root = NULL;

	ifstream input;
	input.open("data.txt");
	int liczba;
	while (input >> liczba)
	{
		root = add(root, liczba);
		cout << "I've added element " << liczba << endl;
	}

	display(root);
	paint(root, 0);
	deleteNode(root, 8);
	deleteNode(root, 22);
	display(root);
	paint(root, 0);
	
	save(root);
	getchar();

		return 0;

}

/*
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

*/