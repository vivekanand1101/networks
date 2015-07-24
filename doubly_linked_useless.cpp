// Program to create a doubly linked list with
// priority as an integer. The input will be based
// on the priority and the fields of source and
// destination will be integers for now - representing
// the source and destination ip addresses of the
// packets. Each node will denote different packets.
// Also, give the option of deletion based on source
// ip address. Also if some packets arrive whose
// destination address is not same as our ip address
// then drop the packet

#include <iostream>
#include <cstdlib>

#define IP 1

using namespace std;

struct node {
    int data;
    int src;
    int dest;
    int priority;
    struct node* left;
    struct node* right;
};

struct node* newPacket(struct node* head, int data, \
                            int src, int dest, int priority)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = data;
    tmp -> src = src;
    tmp -> dest = dest;
    tmp -> priority = priority;
    tmp -> left = NULL;
    tmp -> right = NULL;
}

struct node* queue_packets(struct node* head, int data, \
                                int src, int dest, int priority)
{
    struct node* new_node = newPacket(head, data, src, dest, priority);

    if (head == NULL) {
        return new_node;
    }

    struct node* tmp = head;
    for (; tmp != NULL && new_node -> priority > tmp -> priority;) {
        if (tmp -> right == NULL) {
            break;
        }

        tmp = tmp -> right;
    }

    if (tmp -> left == NULL) {
        tmp -> left = new_node;
        new_node -> right = tmp;
        head = new_node;
        return head;
    }

    tmp = tmp -> left;
    new_node -> left = tmp;
    new_node -> right = tmp -> right;
    tmp -> right = new_node;

    return head;
}

struct node* discard_packet(struct node* head, struct node* tmp)
{
    struct node* trav = head;
    if (trav == tmp) {
        return trav -> right;
    } else if (trav -> right == NULL) {
        tmp = tmp -> right;
        trav -> right = NULL;
        tmp = NULL;
    }

    for (; trav -> right -> right != NULL && trav -> right != tmp; \
            trav = trav -> right);

    tmp = tmp -> right;
    trav -> right = trav -> right -> right;
    trav -> right -> right -> left = trav;
    trav -> right -> right = NULL;
    trav -> right -> left = NULL;

    return head;
}

void print_packets(struct node* head)
{
    struct node* tmp = head;

    for (; tmp != NULL; tmp = tmp -> right) {
        cout << " Data " << tmp -> data;
        cout << " Source " << tmp -> src;
        cout << " Destination " << tmp -> dest;
        cout << " Priority " << tmp -> priority;
        cout << endl;
    }

    cout << "Over" << endl;
}

int main()
{
    int n;
    cout << "Enter number of packets: " << endl;
    cin >> n;
    int priority;
    int data;
    int src;
    int dest;
    int discard_src;
    struct node* head = NULL;

    for (int i = 0; i < n; i++) {
        cout << "Insert new packet" << endl;
        cout << endl;
        cout << "Priority of the packet: " << endl;
        cin >> priority;
        cout << "Source Address of the packet: " << endl;
        cin >> src;
        cout << "Destination Address of the packet: " << endl;
        cin >> dest;

        if (dest != IP) {
            cout << "The packet doesn't belong to this destination" << endl;
            cout << "The pakcet was discarded, enter other packets" << endl;
            continue;
        }

        cout << "Data to be stored in the packet: " << endl;
        cin >> data;

        head = queue_packets(head, data, src, dest, priority);
        cout << endl;
        cout << "done" << endl;
    }

    print_packets(head);

    /*
    cout << "Enter the src of which the packets should be discarded: " << endl;
    cin >> discard_src;

    struct node* tmp = head;
    struct node* tmp2 = head;
    for (; tmp != NULL; tmp = tmp -> right) {
        if (tmp -> src == discard_src) {
            tmp2 = tmp;
            head = discard_packet(head, tmp2);
        }
    }

    print_packets(head);
    */
    return 0;
}
