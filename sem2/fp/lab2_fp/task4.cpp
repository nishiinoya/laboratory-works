#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void transformArray(int **array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2 == 0) {
                array[i][j] *= array[i][j];
            }
        }
    }
}

int main() {
    const int n = 5;
    ifstream inputFile("data.txt");

    // Reading integer values, storing them in a linked list
    Node *head = nullptr;
    Node *temp = nullptr;
    int value;
    while (inputFile >> value) {
        if (!head) {
            head = new Node{value, nullptr};
            temp = head;
        } else {
            temp->next = new Node{value, nullptr};
            temp = temp->next;
        }
    }
    inputFile.close();

    // row count
    int count = 0;
    temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    int m = (count + n - 1) / n; //  rows

    int **array = new int *[m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
    }

    temp = head;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (temp) {
                array[i][j] = temp->data;
                temp = temp->next;
            } else {
                array[i][j] = 0;
            }
        }
    }

    temp = head;
    while (temp) {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    transformArray(array, m, n);

    // Storing results
    ofstream outputFile("results.txt");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << array[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();

    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
