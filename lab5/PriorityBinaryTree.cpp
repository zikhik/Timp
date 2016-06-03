#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class BinaryTree {
private:
	vector<int> data;
public:
	void	add(int value);
	void	del();
	void	orderTree(int i);
	int		get() const { return data[0]; };
	void	show() const;
};

void BinaryTree::add(int value) {
	data.push_back(value);
	int i = data.size() - 1;
	int parent = (i - 1)/2;

	while (i > 0 && data[parent] > data[i]) {
		int temp = data[i];
		data[i] = data[parent];
		data[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
}

void BinaryTree::del() {
	if (data.size() == 0) {
		throw std::logic_error("Tree is empty");
	}
	int result = data[0];
	data[0] = data[data.size() - 1];
	data.erase(data.begin() + data.size() - 1);

	for (int i = data.size() / 2; i >= 0; i--) {
		orderTree(i);
	}
}

void BinaryTree::show() const {
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << "  ";
	}
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

void BinaryTree::orderTree(int i) {
	int leftChild;
	int rightChild;
	int leastChild;

	while (true) {
		leftChild = 2*i + 1;
		rightChild = 2*i + 2;
		leastChild = i;

		if ((leftChild < data.size()) && (data[leftChild] < data[leastChild])) {
			leastChild = leftChild;
		}
		if ((rightChild < data.size()) && (data[rightChild] < data[leastChild])) {
			leastChild = rightChild;
		}
		if (leastChild == i) {
			break;
		}
		int temp = data[i];
		data[i] = data[leastChild];
		data[leastChild] = temp;
		i = leastChild;
	}
}

int main(int argc, char* argv[]) {
	BinaryTree tree;
	string command;
	vector<string> commands;
	int N;
	int i = 0;
	int size;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (i < N && i >= 0) {
		getline(cin, command);
		commands = split(command, ' ');
		size = commands.size();
		if (size == 0) {
			cout << "Incorrect command. Try again.\n";
			i--;
		}
		else if (size == 2) {
			if (commands[0] == "add")
				tree.add(stoi(commands[1]));
			else {
				cout << "Incorrect command. Try again.\n";
				i--;
			}
		}
		else if (size == 1) {
			try {
				if (commands[0] == "del")
					tree.del();
				else if (commands[0] == "get")
					cout << tree.get() << endl;
				else if (commands[0] == "show") {
					tree.show();
					cout << endl;
				}
				else {
					cout << "Incorrect command. Try again.\n";
					i--;
				}
			}
			catch (char* message) {
				cout << message << endl;
			}
		}
		else {
			cout << "Incorrect command. Try again.\n";
			i--;
		}
		i++;
	}
	system("pause");
	return 0;
}
