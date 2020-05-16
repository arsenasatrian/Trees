#include<iostream>
using namespace std;


#pragma once

template<class T>
struct BSTNode {
	T info_;
	BSTNode* left_;
	BSTNode* right_;

	BSTNode()
		: info_(T())
		, left_(nullptr)
		, right_(nullptr)
	{}
	BSTNode(const T& info)
		: info_(info)
		, left_(nullptr)
		, right_(nullptr)
	{}
};

template<class T>
class BST {
public:
	BST();
	BST(const BST& st);
	BST(BST&& st);
	BST<T>& operator = (const BST<T>& st);
	BST<T>& operator = (BST<T>&& st);
	virtual ~BST();

	void insert(const T& info);
	void remove(const T& info);
	bool find(const T& info);
	bool empty()const;
	void printInorderTraverse();
	void printPreorderTraverse();
	void printPostorderTraverse();
	void printLevelorderTraverse();
	
protected:
	void inor(BSTNode<T>* node);
	void preor(BSTNode<T>* node);
	void postor(BSTNode<T>* node);
	void levelor(BSTNode<T>* node);
	void copy(BSTNode<T>* from);
	void clear(BSTNode<T>* node);
	BSTNode<T>* travel(const T&, BSTNode<T>*&);
	BSTNode<T>* root_;
};