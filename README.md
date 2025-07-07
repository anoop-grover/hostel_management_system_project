
# 🏨 Hostel Management System (C++ with DSA)

A console-based Hostel Management System developed in C++ using linked lists as the core data structure. It allows hostel administrators to manage room bookings, cancellations, view status, and handle student-related operations efficiently.

---

## 📌 Features

| Feature                         | Description |
|----------------------------------|-------------|
| 🛏️ Room Booking                | Book a room for 1, 2, or 3 persons on any floor (1 to 3). |
| ❌ Cancel Booking              | Cancel an individual room booking by providing the student name. |
| 🔍 Search Student             | Search for a student's room/floor by their name. |
| 📊 Room Status Display         | See which rooms are vacant or occupied floor-wise. |
| 🍽️ Mess Menu Display          | Shows the daily hostel mess menu. |
| 📝 Complaint Registration      | Allows students to submit complaints. |
| 📋 View All Complaints         | Admin can see all registered complaints. |
| 🧾 Vacant Room Listing         | Lists all available rooms floor-wise. |
| 🧑‍🤝‍🧑 Floor-wise Occupancy Count | See how many students are currently on each floor. |

---

## 🧠 Data Structures Used

- Doubly Linked List for room and floor management.  
- 2D Array for student name tracking (`name_save[10][3]`).  
- Vector for complaint storage.

---

## 🛠️ How to Run

### 1. Clone or Download the Repository
```bash
git clone https://github.com/yourusername/hostel-management-dsa.git
```

### 2. Navigate to the Folder
```bash
cd hostel-management-dsa
```

### 3. Compile the Code
```bash
g++ HostelManagementSystem_Enhanced.cpp -o hostel
```

### 4. Run the Executable
```bash
./hostel
```

---

## 🔐 Input Constraints

- **Floors**: 1 to 3  
- **Rooms per Floor**: 1 to 9  
- **Room Capacity**: Varies (1, 2, or 3 persons based on room number)

---

## ✅ Sample Menu

```text
========= Hostel Management System =========
1. Display Current Status of Rooms
2. Book a Room for 1 person
3. Book a Room for 2 persons
4. Book a Room for 3 persons
5. Cancel a Room
6. Search a Name
7. View Mess Menu
8. Register a Complaint
9. View All Complaints
10. List Vacant Rooms
11. Show Floor Occupancy Count
```

---

## 🧑‍💻 Author

**Anoop Grover**  
B.Tech Computer Science  
Lovely Professional University

---

## 💡 Future Improvements

- Login System (Admin/Student)  
- File I/O to save records permanently  
- GUI version using Qt or web frontend  
- Monthly occupancy and billing reports  
