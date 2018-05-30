#include "Header.h"

struct node *newNode(int value) //struktura nowego wezla
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = value;
	temp->left = temp->right = NULL;
	temp->level = 1;
	return temp;
}

int level(struct node *l) //funkcja zwraca poziom (wysokosc) na jakiej znajduje sie konkretny wezel
{
	if (l == NULL)
		return 0;

	return l->level;
}

int getBalance(struct node *bf)
{
	if (bf == NULL)
		return 0;
	return level(bf->left) - level(bf->right);
}

int max(int a, int b) //sprawdza, ktory argument jest wiekszy, potrzebne do nadawania poziomu nowemu wezlowi
{
	return (a > b) ? a : b;
}

struct node *rightRotate(struct node *y) //rotacja w prawo
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->level = max(level(y->left), level(y->right)) + 1;
	x->level = max(level(x->left), level(x->right)) + 1;

	return x;
}


struct node *leftRotate(struct node *x) //rotacja w lewo
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->level = max(level(x->left), level(x->right)) + 1;
	y->level = max(level(y->left), level(y->right)) + 1;

	return y;
}

struct node * findMinNode(struct node* node) //znajdz najmniejszy wezel
{
	struct node* seek = node;

	while (seek->left != NULL)
		seek = seek->left;

//	cout << seek->key << " <- This is min value" << endl;
	return seek;
}
/*
struct node * findMaxNode(struct node* node) //z
{
	struct node* seek = node;

	while (seek->right != NULL)
		seek = seek->right;

	cout << seek->key << " <- This is max value" << endl;
	return seek;
}
*/

struct node* add(struct node* node, int key) //dodawanie nowego wezla
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = add(node->left, key);
	else if (key > node->key)
		node->right = add(node->right, key);
	else
		return node;

	node->level = max(level(node->left), level(node->right)) + 1;

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key) //LL
		return rightRotate(node);

	if (balance < -1 && key > node->right->key) //RR
		return leftRotate(node);

	if (balance > 1 && key > node->left->key) //LR
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key) //RL
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

//	cout << "I've added element " << node->key << endl;
	return node;
}
/*
struct node* add(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = add(node->left, key);
	else if (key > node->key)
		node->right = add(node->right, key);

	return node;
}
*/
struct node* deleteNode(struct node* root, int key) //usuwanie wezla
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			struct node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp; 
			free(temp);
		}
		else
		{
			struct node* temp = findMinNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->level = 1 + max(level(root->left),
		level(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0) //LL
		return rightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0) //LR
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0) //RR
		return leftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0) //RL
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
//	cout << "I've deleted element " << key << endl;
	return root;
}

/*struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = findMinNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
*/
void display(struct node *root) //wyswietlanie proste
{
	if (root != NULL)
	{
		cout << root->key << endl;
		display(root->left);
		display(root->right);
	}
}

void paint(struct node *root, int distance) //wyswietlanie graficzne
{
	int place = 10;

	if (root == NULL)
		return;

	distance += place;
	paint(root->right, distance);

	cout << endl;
	for (int i = place; i < distance; i++)
	{
		cout << " ";
	}
	cout << root->key << endl;
	paint(root->left, distance);
}