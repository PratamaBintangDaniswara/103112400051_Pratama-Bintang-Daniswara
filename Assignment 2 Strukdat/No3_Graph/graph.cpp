#include <iostream>
#include <string>
using namespace std;

struct Node;
struct Edge;

struct Edge {
    Node *to;
    Edge *next;
};

struct Node {
    string name;
    Edge *firstEdge;
    Node *nextNode;
    bool visited;
    bool active;
};

Node *head = NULL;

Node* createNode(string name) {
    Node *n = new Node;
    n->name = name;
    n->firstEdge = NULL;
    n->nextNode = NULL;
    n->visited = false;
    n->active = true;
    return n;
}

Edge* createEdge(Node *to) {
    Edge *e = new Edge;
    e->to = to;
    e->next = NULL;
    return e;
}

void addNode(string name) {
    Node *n = createNode(name);

    if (head == NULL) {
        head = n;
    } else {
        Node *temp = head;
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = n;
    }
}


Node* findNode(string name) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->name == name)
            return temp;
        temp = temp->nextNode;
    }
    return NULL;
}

void addEdge(string from, string to) {
    Node *A = findNode(from);
    Node *B = findNode(to);

    Edge *e1 = createEdge(B);
    e1->next = A->firstEdge;
    A->firstEdge = e1;

    Edge *e2 = createEdge(A);
    e2->next = B->firstEdge;
    B->firstEdge = e2;
}

void resetVisited() {
    Node *temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->nextNode;
    }
}

void DFS(Node *start) {
    if (start == NULL || !start->active)
        return;

    start->visited = true;

    Edge *e = start->firstEdge;
    while (e != NULL) {
        if (!e->to->visited && e->to->active)
            DFS(e->to);
        e = e->next;
    }
}

bool isCritical(Node *target) {
    target->active = false;
    resetVisited();

    Node *start = head;
    while (start != NULL && !start->active)
        start = start->nextNode;

    if (start != NULL)
        DFS(start);

    Node *temp = head;
    while (temp != NULL) {
        if (temp->active && !temp->visited) {
            target->active = true;
            return true;
        }
        temp = temp->nextNode;
    }

    target->active = true;
    return false;
}

void printGraph() {
    Node *n = head;
    while (n != NULL) {
        cout << "Node " << n->name << " terhubung ke: ";
        Edge *e = n->firstEdge;
        while (e != NULL) {
            cout << e->to->name << " ";
            e = e->next;
        }
        cout << endl;
        n = n->nextNode;
    }
}

int main() {
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    addNode("A");
    addNode("B");
    addNode("C");
    addNode("D");
    addNode("E");
    addEdge("A", "B");
    addEdge("B", "C");
    addEdge("B", "E");
    addEdge("C", "D");
    printGraph();
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";

    Node *temp = head;
    while (temp != NULL) {
        if (isCritical(temp)) {
            cout << "[PERINGATAN] Kota " << temp->name << " adalah KOTA KRITIS!\n";
            cout << "Jika " << temp->name << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << temp->name << " aman (redundansi oke)\n";
        }
        temp = temp->nextNode;
    }

    return 0;
}
