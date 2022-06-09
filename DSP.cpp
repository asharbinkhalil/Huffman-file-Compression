#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<vector>
#include<Windows.h>
using namespace std;
class hnode
{
public:
	int frequecy;
	char character;
	double comp = 0;//for compression of codes
	hnode* left;
	hnode* right;

	hnode(const hnode& c) {  //copy constructor
		this->character = c.character;
		this->frequecy = c.frequecy;
		this->left = c.left;
		this->right = c.right;
	}
	hnode(char c = NULL, int f = 0)
	{
		frequecy = f;
		character = c;
		left = NULL;
		right = NULL;
	}
	bool operator <(const hnode& rhs) const  //operator overloading for priority_queue of type hnode
	{
		if (frequecy == rhs.frequecy)
			return character > rhs.character;
		return frequecy > rhs.frequecy;
	}
};
struct compareStuff {
	bool operator()(const hnode& rhs, const hnode& lhs)//operator overloading for vector sort of type node
	{
		if (lhs.frequecy == rhs.frequecy)
			return lhs.character > rhs.character;
		return lhs.frequecy > rhs.frequecy;
	}
};
class htree
{
public:
	hnode* root;
	htree()
	{
		root = NULL;
	}
	void insert_task_one(vector<hnode>& l)
	{
		auto it1 = l.begin();   //extracting first element of vector
		hnode* f1 = new hnode(*it1);    
		l.erase(l.begin());//deleteing it

		auto it = l.begin(); //extracting second element of vector
		hnode* f2 = new hnode(*it);
		l.erase(l.begin()); //deleteing it
		 
		hnode* temp1 = new hnode;      //saving in temp node to be inserted as a new root
		temp1->frequecy = f1->frequecy + f2->frequecy;
		temp1->right = f1;
		temp1->left = f2;
		cout << temp1->character;
		root = temp1;
		l.push_back(*root);//insering the new root node in vector 
		std::sort(l.begin(), l.end(), compareStuff());   //sorting once again
	}
	void insert(hnode* f1, hnode* f2, priority_queue<hnode>& p)
	{
		if (f1 != NULL)
			if (f2 != NULL)
			{
				hnode* temp = new hnode;
				temp->frequecy = f1->frequecy + f2->frequecy;
				temp->left = f1;
				temp->right = f2;

				root = temp;
				p.push(*temp);
			}
		if (f2 == NULL)
			if (f1 != NULL)
				return;
	}
	int isLeaf(hnode* root) {
		return !(root->left) && !(root->right);
	}
	void printcodes(hnode* root, int arr[], int top)
	{
		double count = 0;
		if (root->left) {
			arr[top] = 0;
			printcodes(root->left, arr, top+1);
		}
		if (root->right) {
			arr[top] = 1;
			printcodes(root->right, arr, top+1);
		}
		if (isLeaf(root)) {
			cout << "\t\t\t\t\t" << root->character << "  | ";
			for (int i = 0; i < top; ++i) {
				count++;
				cout << arr[i];
			}
			root->comp = count * root->frequecy;
			cout << "\n";
		}
	}
	void makeHuff(priority_queue<hnode>* p)
	{
		int count = 0;
		while (!p->empty())
		{
			if (count == 0)  //for initial node
			{
				hnode* min1 = NULL;
				hnode* min2 = NULL;
				min1 = new hnode(p->top().character, p->top().frequecy);
				p->pop();
				min2 = new hnode(p->top().character, p->top().frequecy);
				p->pop();
				insert(min1, min2, *p);
				count++;
				if (p->size() == 1 || p->size() == 0)
					return;
			}
			else if (!p->empty() && count != 0)// for next nodes
			{
				hnode* h1 = new hnode;
				*h1 = p->top();
				p->pop();
				hnode* h2 = new hnode;
				if (!p->empty())
				{
					*h2 = p->top();
					p->pop();
				}
				insert(h1, h2, *p);
				if (p->size() == 1 || p->size() == 0)
					return;
			}
		}
	}
	double showcompression(hnode* root) {
		static double compresion = 0;
		if (root == NULL)
			return compresion;
		showcompression(root->left);
		if (isLeaf(root))
			compresion += root->comp;
		showcompression(root->right);
	}
};
class freqarray     //temp node for returning with correct frequencies and charcater from a function
{
public:
	string arr;
	int* freq;
	freqarray()
	{
		arr = "";
		freq = NULL;
	}
};
freqarray* frequecny(string n)
{
	freqarray* a = new freqarray;

	string str = "";
	for (int i = 0; i < n.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < i; j++)
		{
			if (n[i] == n[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			str += n[i];
	}
	const int var = str.size();
	int* freq = new int[var];

	for (int i = 0; i < var; i++)
		freq[i] = 0;

	for (int i = 0; i < str.size(); i++)
		for (int j = 0; j < n.size(); j++)
			if (str[i] == n[j])
				freq[i]++;

	a->arr = str;
	a->freq = freq;
	return a;
}
void design1();
void design2();
void design3();
int main()
{
	design1();
	design2();
	string fname;
	cout << "\t\t\t\t\tEnter file name: ";
	cin >> fname;
	fstream ifile(fname, ios::in);
	if (!ifile.is_open())
	{
		cout << "\t\t\t\tError opening file 404";
		exit(1);
	}
	design3();

	string character = "", array = "";
	while (getline(ifile, character)) {
		for (int i = 0; i < character.length(); i++)
			array += character[i];
	}
	if (array.length() == 0) { cout << "Empty file: "; exit(1); }
	freqarray* fq = frequecny(array);
	string arr = fq->arr;
	int* freq = fq->freq;

	cout << "\t\t\t\t\tOriginal file:           " << array << endl;
	cout << "\t\t\t\t\tRemoved duplicates:      " << arr << endl;
	cout << "\t\t\t\t\tRespective frquencies:   ";
	for (int i = 0; i < arr.size(); i++)
		cout << freq[i];


	cout << "\n\t\t\t\t\t----------------------TASK 1-----------------------------\n";
	vector<hnode> v;
	for (int i = 0; i < arr.size(); i++) {
		hnode q;
		q.character = arr[i];
		q.frequecy = freq[i];
		v.push_back(q);
	}

	vector<hnode> s;   //making copy of vector for task 2
	s = v;

	htree ht1;
	sort(v.begin(), v.end(), compareStuff());//sorting the vector

	for (int i = 0; i < arr.length() - 1; i++)//making tree of task1 in this function/ passed the vector by reference
		ht1.insert_task_one(v);

	const int cv = arr.length();
	int* arrr = new int[cv];
	int  top = 0;
	ht1.printcodes(ht1.root, arrr, top);//printing huffman codes
	cout << "\n\t\t\t\t\tRoot  " << ht1.root->frequecy;


	cout << "\n\t\t\t\t\t----------------------TASK 2-----------------------------\n";
	priority_queue<hnode> pq;
	for (auto it = s.cbegin(); it != s.cend(); it++)
		pq.push(*it);

	htree ht;
	ht.makeHuff(&pq);    //making huffman tree for task 2....passing priority queue by reference 

	arrr = new int[cv];
	top = 0;
	ht.printcodes(ht.root, arrr, top);//printing huffman codes
	cout << "\n\t\t\t\t\troot  " << ht.root->frequecy;
	cout << "\n\t\t\t\t\tCompression ratio " << (array.length() * 8) / ht.showcompression(ht.root)<<"\n\n\n";


}
void design1()
{
	cout << "\t\t\t\t------------------- ASHAR KHALIL----------------------\n";
	cout << "\t\t\t\t-------------	      20K - 1724         --------------\n";
	cout << "\t\t\t\t---------------- DATA STRUCTURES(A) ------------------\n";
	cout << "\t\t\t\t------------- HUFFMAN ENCODING PROJECT ---------------\n\n\n";
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t|      Made with love by ASHAR  :)     | ";
	cout << "\n\t\t\t\t\t| -> Loads data from a file.           |";
	cout << "\n\t\t\t\t\t| -> Compress through encoding.        |";
	cout << "\n\t\t\t\t\t| -> Get Huffman code.                 |";
	cout << "\n\t\t\t\t\t| -> Get Optimaized Huffman code.      |";
	cout << "\n\t\t\t\t\t| -> Get Compression ratio.            |";
	cout << "\n\t\t\t\t\t/--------------------------------------/\n\n\n\n";
}
void design2()
{
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\tFILE LOADED SUCESSFULLY.\n";
	cout << "\t\t\t\t\t/--------------------------------------/\n\n\n\n";
}
void design3()
{
	string design = "ENCODING YOUR FILES";
	cout << "\t\t\t\t\t/--------------------------------------/";
	cout << "\n\t\t\t\t\t\t";
	for (int i = 0; i < design.length(); i++)
	{
		cout << design[i];
		Sleep(100);
	}
	cout << "\n\t\t\t\t\t/--------------------------------------/\n\n\n\n";
	system("cls");
}
