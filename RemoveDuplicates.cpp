#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	
	int data;
	struct node * next;
	node(int x) : data(x), next(NULL) {}

}
NODE;


NODE * addNodeAtEnd(NODE* head , int x){
	
	if(head == NULL){
		
		head = new NODE(x);
		return head;

	}

	NODE * h = head;
	while(h->next != NULL)
		h = h->next;

	h->next = new NODE(x);

	return head;
}

void printList(NODE * head) {

	NODE * h = head;
	while(h != NULL){
		
		cout << h->data << " ";
		h = h->next;

	}
}

NODE  * reverseByK(NODE * head){

	if(head == NULL)
		return NULL;

	if(head->next == NULL)
		return head;

	
	NODE * rem = head->next->next;
	head->next->next = head;
	NODE * h = head;
	head = head->next;
	h->next = reverseByK(rem);

	return head;


}

NODE * sortInsert(NODE * head ,int k)
{
	NODE * newNode = new NODE(k);
	
	if(head == NULL || head->data > k)
	{
		newNode->next = head;
		head = newNode;

		return head;
	}

	NODE * h1 = head;

	while(h1->next != NULL && h1->next->data < k)
	{
		h1 = h1->next;
	}

	NODE * nextNode = h1->next;
	h1->next = newNode;
	newNode->next = nextNode;

	return head; 
}


bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

int main() 
{
  
  int n;

  cin >> n;

  vector < int > v(n);

  for(int i=0 ; i < n ; i++)
  {
  	cin >> v[i];
  }
  
  map < int , int > m;

  
  for(int i=0 ; i< n ; i++)
  {
  		m[v[i]]++;
  }

  vector < pair < int , int > > feq;

  std::map<int, int > :: iterator it;

  	cout << "kk" << endl;
  for(it = m.begin() ; it != m.end() ; it++)
  {
  	pair < int , int > p = make_pair(it->second , it->first);

  	cout << it->second << " " << it->first << endl;
  	feq.push_back(p);
  }

  sort(feq.begin() , feq.end(), sortinrev);

  for(int i=0 ; i< feq.size() ; i++)
  	cout << feq[i].first << " " << feq[i].second << endl;

  for(int i=0 ; i<feq.size() ; i++)
  {
  	for(int k = 0 ; k < feq[i].first; k++)
  	{
  		//if(feq[i].second != 0)
  		//cout << i << " ";
  			ncout << feq[i].second << endl;
  	}
  }


}


