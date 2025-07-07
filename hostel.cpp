#include <bits/stdc++.h>
using namespace std;

string name_save[10][3];

class Node {
public:
    int room_capacity = 1;
    int fill_room = 0;
    char name[3][10];
    Node *next;
    Node *previous;
};

class hostel {
public:
    Node *head[3];
    Node *created_node;
    hostel() {
        for (int i = 0; i < 3; i++)
            head[i] = NULL;
    }
    void create();
    void book(int);
    void cancel(int);
    void display();
    void search(string);
};

void hostel::create() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            Node *newnode = new Node;
            newnode->next = NULL;
            newnode->previous = NULL;
            if (head[i] == NULL) {
                head[i] = newnode;
                newnode->room_capacity = 1;
            } else {
                Node *created_node = head[i];
                while (created_node->next != NULL) {
                    created_node = created_node->next;
                }
                if (j == 3 || j == 5 || j == 7 || j == 8)
                    created_node->room_capacity = 3;
                if (j == 2 || j == 4 || j == 6)
                    created_node->room_capacity = 2;

                created_node->next = newnode;
                newnode->previous = created_node;
            }
        }
    }
}

void hostel::book(int people) {
    int floor, room;
    cout << "Enter the floor number: ";
    cin >> floor;
    if (floor < 1 || floor > 3) {
        cout << "Invalid floor number: " << floor << endl;
        return;
    }

    created_node = head[floor - 1];
    cout << "Enter the room number: ";
    cin >> room;
    if (room < 1 || room > 9) {
        cout << "Invalid room number: " << room << endl;
        return;
    }

    int i = 1;
    while (i < room) {
        created_node = created_node->next;
        i++;
    }

    if (created_node->room_capacity >= people) {
        cout << "Room is Available! You can Apply for the Room!" << endl;
        int count = 0;
        while (created_node->fill_room < 3 && count < people) {
            cout << "Enter Name - " << created_node->fill_room + 1 << ": ";
            cin >> created_node->name[created_node->fill_room];
            cout << "Re-Enter Name - " << created_node->fill_room + 1 << ": ";
            cin >> name_save[room - 1][floor - 1];
            created_node->fill_room++;
            count++;
        }
        created_node->room_capacity -= people;
    } else {
        cout << "Room of Your Choice is Currently Not Available" << endl;
    }
}

void hostel::cancel(int check) {
    char namecheck[10];
    int flag = 0;
    int room, i = 1;
    if (check < 1 || check > 3) {
        cout << "Invalid Floor No.: " << check << endl;
        return;
    }

    cout << "Enter Room Number: ";
    cin >> room;
    if (room < 1 || room > 9) {
        cout << "Invalid Room number: " << room << endl;
        return;
    }

    cout << "Enter the name to be deleted: ";
    cin >> namecheck;
    string ncheck = namecheck;
    search(ncheck);

    created_node = head[check - 1];
    while (i < room) {
        created_node = created_node->next;
        i++;
    }

    for (i = 0; i < 3; i++) {
        if (!strcmp(namecheck, created_node->name[i])) {
            flag = 1;
            break;
        }
    }

    if (flag == 1 && created_node->fill_room != 0) {
        cout << "Record deleted: " << created_node->name[i] << endl;
        created_node->name[i][0] = 'A';
        created_node->name[i][1] = '\0';
        created_node->fill_room--;
        created_node->room_capacity++;
    } else {
        cout << "\nRecord Not Available" << endl;
    }
}

void hostel::display() {
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < 60; i++) cout << "--";
    cout << endl;

    for (int i = 1; i < 4; i++)
        cout << " Floor number : " << i << " \t\t\t";
    cout << endl;

    for (int i = 0; i < 60; i++) cout << "--";
    cout << endl;

    created_node = head[0];
    Node *secondfloor_node = head[1];
    Node *thirdfloor_node = head[2];

    while (created_node != NULL) {
        j++;
        cout << " Room no: " << j;
        if (created_node->fill_room != created_node->room_capacity && created_node->room_capacity != 0)
            cout << ":-- Vacant Room --: " << created_node->room_capacity;
        else
            cout << " Already Booked by: " << name_save[j - 1][0];

        k++;
        cout << "\t Room no: " << k;
        if (secondfloor_node->fill_room != secondfloor_node->room_capacity && secondfloor_node->room_capacity != 0)
            cout << ":-- Vacant Room --: " << secondfloor_node->room_capacity;
        else
            cout << "\t Already Booked by: " << name_save[k - 1][1];

        l++;
        cout << "\t Room no: " << l;
        if (thirdfloor_node->fill_room != thirdfloor_node->room_capacity && thirdfloor_node->room_capacity != 0)
            cout << ":-- Vacant Room --: " << thirdfloor_node->room_capacity << "| ";
        else
            cout << "\t Already Booked by: " << name_save[l - 1][2];

        cout << "\n\n";

        created_node = created_node->next;
        secondfloor_node = secondfloor_node->next;
        thirdfloor_node = thirdfloor_node->next;
    }

    for (int i = 0; i < 60; i++) cout << "--";
    cout << endl;
}

void hostel::search(string key) {
    bool found = false;
    int i_position = -1, j_position = -1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (name_save[i][j] == key) {
                found = true;
                i_position = i;
                j_position = j;
                break;
            }
        }
        if (found) break;
    }

    if (found)
        cout << "Name Found at:\nRoom no " << i_position + 1 << "\nFloor no. " << j_position + 1 << endl;
    else
        cout << "Name not found" << endl;
}

// === Extra Features ===

vector<string> complaint_box;

void display_mess_menu() {
    cout << "\n--- Today's Mess Menu ---\n";
    cout << "Breakfast: Aloo Paratha + Curd\n";
    cout << "Lunch: Rajma + Rice + Salad\n";
    cout << "Snacks: Samosa + Tea\n";
    cout << "Dinner: Paneer Butter Masala + Roti + Gulab Jamun\n";
    cout << "-------------------------\n";
}

void register_complaint() {
    string complaint;
    cout << "\nEnter your complaint: ";
    cin.ignore();
    getline(cin, complaint);
    complaint_box.push_back(complaint);
    cout << "Complaint registered successfully!\n";
}

void view_complaints() {
    cout << "\n--- Registered Complaints ---\n";
    if (complaint_box.empty()) {
        cout << "No complaints yet.\n";
    } else {
        for (int i = 0; i < complaint_box.size(); ++i) {
            cout << i + 1 << ". " << complaint_box[i] << endl;
        }
    }
    cout << "-----------------------------\n";
}

void list_vacant_rooms(hostel &management) {
    cout << "\n--- Vacant Room List ---\n";
    for (int f = 1; f <= 3; f++) {
        cout << "Floor " << f << ": ";
        Node *node = management.head[f - 1];
        int room_no = 1;
        while (node != NULL) {
            if (node->fill_room < node->room_capacity)
                cout << room_no << " ";
            node = node->next;
            room_no++;
        }
        cout << endl;
    }
    cout << "-------------------------\n";
}

void show_total_occupancy(hostel &management) {
    cout << "\n--- Total Occupancy Floor-wise ---\n";
    for (int f = 1; f <= 3; f++) {
        int total = 0;
        Node *node = management.head[f - 1];
        while (node != NULL) {
            total += node->fill_room;
            node = node->next;
        }
        cout << "Floor " << f << ": " << total << " students\n";
    }
    cout << "----------------------------------\n";
}

// === Main ===
int main() {
    hostel management;
    int choice, floorcheck;
    char ch;
    string namecheck;
    management.create();

    do {
        cout << "\n========= Hostel Management System =========" << endl;
        cout << "1. Display Current Status of Rooms" << endl;
        cout << "2. Book a Room for 1 person" << endl;
        cout << "3. Book a Room for 2 persons" << endl;
        cout << "4. Book a Room for 3 persons" << endl;
        cout << "5. Cancel a Room" << endl;
        cout << "6. Search a Name" << endl;
        cout << "7. View Mess Menu" << endl;
        cout << "8. Register a Complaint" << endl;
        cout << "9. View All Complaints" << endl;
        cout << "10. List Vacant Rooms" << endl;
        cout << "11. Show Floor Occupancy Count" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: management.display(); break;
            case 2: management.book(1); break;
            case 3: management.book(2); break;
            case 4: management.book(3); break;
            case 5: cout << "Enter Floor no.: "; cin >> floorcheck; management.cancel(floorcheck); break;
            case 6: cout << "Enter name: "; cin >> namecheck; management.search(namecheck); break;
            case 7: display_mess_menu(); break;
            case 8: register_complaint(); break;
            case 9: view_complaints(); break;
            case 10: list_vacant_rooms(management); break;
            case 11: show_total_occupancy(management); break;
            default: cout << "Invalid Choice" << endl;
        }

        cout << "Do You want to Continue (Y/N): ";
        cin >> ch;
        cout << endl;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
