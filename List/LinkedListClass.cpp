#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
private:
	int v;
	Node* next;

public: Node(int v) {
	this->v = v;
	this->next = NULL;
}
	  int getValue() {
		  return v;
	  }

	  Node* getNext() {
		  return next;
	  }

	  void setNext(Node* n) {
		  next = n;
	  }
};


class List {
	//propriedades 
	private:
		Node* head;
		Node* tail;
	//construtor vazio
	public: List() {
		head = NULL;
		tail = NULL;
	}
	//construtor com valor inicial
	public: List(int v) {
		head = new Node(v);
		tail = head;
	}
	  //destrutor
	  virtual ~List() {
		  delete head;
	  }
	  //verifica se a lista está vazia
	  bool isEmpty() {
		  return (head == NULL);
	  }
	  //imprime valores da lista 
	  void show() {
		  Node* h = head;
		  cout << "\nElementos da lista\n";
		  if (isEmpty()) {
			  cout << "Lista vazia!";
			  return;
		  }
		  while (h) {
			  cout << h->getValue() << " ";
			  h = h->getNext();
		  }
		  cout << endl;
	  }
	  //imprime valores da lista de forma recursiva
	  void showRecursive(List* l) {
		  Node* h = l->head;
		  if (h->getValue() == NULL) return;
		  else {
			  cout << h->getValue() << " ";
			  l->head = h->getNext();
			  showRecursive(l);
		  }

	  }
	  //imprime valores da lista de forma recursiva reversa
	  void showReverseRecursive(List* l) {
		  Node* h = l->head;
		  if (!l->isEmpty()) {
			  l->head = h->getNext();
			  showReverseRecursive(l);
			  printf("%d ", h->getValue());
		  }
	  }
	  //insere no inicio da lista 
	  void pushFront(int v) {
		  Node* newNode = new Node(v);
		  newNode->setNext(head);
		  head = newNode;
	  }
	  //insere no final da lista
	  void pushBack(int v) {
		  Node* newNode = new Node(v);
		  if (isEmpty()) {
			  head = newNode;
		  }
		  else {
			  tail->setNext(newNode);
			  tail = newNode;
		  }
	  }
	  //retorna tamanho da lista
	  int size() {
		  Node* h = head;
		  int size = 0;
		  if (isEmpty())
			  return size;
		  do {
			  h = h->getNext();
			  size++;
		  } while (h);
		  return size;
	  }
	  //verifica se elemento existe na lista
	  bool hasElement(int v) {
		  Node* h = head;

		  if (isEmpty())
			  return false;
		  do {
			  if (h->getValue() == v)
				  return true;
			  h = h->getNext();
		  } while (h);
		  return false;
	  }
	  //remove ultimo elemento da lista
	  void removeBack() {
		  if (!isEmpty()) {
			  //1 elemento
			  if (head->getNext() == NULL) {
				  head = NULL;
			  }
			  //2 elementos
			  else if (head->getNext()->getNext() == NULL) {
				  head->setNext(NULL);
			  }
			  //mais de dois elementos
			  else {
				  Node* first = head;
				  Node* second = first->getNext();
				  Node* current = second->getNext();
				  while (current) {
					  Node* aux = second;
					  second = current;
					  first = aux;
					  current = current->getNext();
				  }
				  delete first->getNext();
				  first->setNext(NULL);
				  tail = first;
			  }

		  }
	  }
	  //retorna um elemento da lista 
	  int findElement(int element) {
		  Node* h = head;
		  int i = 0;
		  do {
			  i++;
			  if (h->getValue() == element) {
				  return i;
			  }
			  else {
				  h = h->getNext();
			  }
		  } while (h != NULL);
		  return -1;
	  }
	  //remove um elemento da lista
	  int removeElement(int element) {
		  Node* n = head;
		  Node* aux = NULL;
		  for (int i = 0; i < size(); i++) {
			  if (n->getValue() == element) {
				  if (i == 0) {
					  head = n->getNext();
					  return i + 1;
				  }
				  aux->setNext(n->getNext());
				  return i + 1;
			  }
			  aux = n;
			  n = n->getNext();
		  }
		  return -1;
	  }
};