#include <iostream>
#include <stdio.h>
using namespace std;

class NodeClass{
private:
	int v;
	NodeClass* next;

public: NodeClass(int v) {
	this->v = v;
	this->next = NULL;
}
	  int getValue() {
		  return v;
	  }

	  NodeClass* getNext() {
		  return next;
	  }

	  void setNext(NodeClass* n) {
		  next = n;
	  }
};


class ListClass {
	//propriedades 
	private:
		NodeClass* head;
		NodeClass* tail;
	//construtor vazio
	public: ListClass() {
		head = NULL;
		tail = NULL;
	}
	//construtor com valor inicial
	public: ListClass(int v) {
		head = new NodeClass(v);
		tail = head;
	}
	  //destrutor
	  virtual ~ListClass() {
		  delete head;
	  }
	  //verifica se a lista está vazia
	  bool isEmpty() {
		  return (head == NULL);
	  }
	  //imprime valores da lista 
	  void show() {
		  NodeClass* h = head;
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
	  void showRecursive(ListClass* l) {
		  NodeClass* h = l->head;
		  if (h->getValue() == NULL) return;
		  else {
			  cout << h->getValue() << " ";
			  l->head = h->getNext();
			  showRecursive(l);
		  }

	  }
	  //imprime valores da ListClassa de forma recursiva reversa
	  void showReverseRecursive(ListClass* l) {
		  NodeClass* h = l->head;
		  if (!l->isEmpty()) {
			  l->head = h->getNext();
			  showReverseRecursive(l);
			  printf("%d ", h->getValue());
		  }
	  }
	  //insere no inicio da ListClassa 
	  void pushFront(int v) {
		  NodeClass* newNodeClass = new NodeClass(v);
		  newNodeClass->setNext(head);
		  head = newNodeClass;
	  }
	  //insere no final da ListClassa
	  void pushBack(int v) {
		  NodeClass* newNodeClass = new NodeClass(v);
		  if (isEmpty()) {
			  head = newNodeClass;
		  }
		  else {
			  tail->setNext(newNodeClass);
			  tail = newNodeClass;
		  }
	  }
	  //retorna tamanho da lista
	  int size() {
		  NodeClass* h = head;
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
		  NodeClass* h = head;

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
				  NodeClass* first = head;
				  NodeClass* second = first->getNext();
				  NodeClass* current = second->getNext();
				  while (current) {
					  NodeClass* aux = second;
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
		  NodeClass* h = head;
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
		  NodeClass* n = head;
		  NodeClass* aux = NULL;
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