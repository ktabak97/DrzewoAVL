#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct node //struktura wezla
{
	int key;
	struct node *left;
	struct node *right;
	int level;
};


int level(struct Node *l);
int max(int a, int b);
int getBalance(struct node *bf);

struct node *newNode(int value);
struct node *rightRotate(struct node *y);
struct node *leftRotate(struct node *x);
void display(struct node *root);
struct node* add(struct node* node, int key);
struct node * findMinNode(struct node* node);
struct node* deleteNode(struct node* root, int key);
void paint(node *root, int distance);

