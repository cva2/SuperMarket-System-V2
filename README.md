# supermarket-system-v2
# 🛒 Supermarket System V2 (The OOP Evolution)

**Supermarket System V2** represents a significant advancement over the initial procedural version. While Version 1 focused on the basic mechanics of input, calculation, and currency-based change return, V2 evolves the codebase into a structured, authenticated application with an emphasis on role-based access control and administrative functionality.

This release transitions the project from a simple cashier tool to a multifaceted prototype, laying the groundwork for scalable application development in C++.

---

## 🚀 Key Improvements & V1 vs. V2 Comparison

V2 focuses heavily on stability, usability, and introducing security layers to simulate a real-world business environment.

| Feature | Version 1 (Procedural Base) | Version 2 (Evolved V2) | Impact of Improvement |
| :--- | :--- | :--- | :--- |
| **Authentication** | **Open:** No login required. The application started directly in the cashier simulation. | **Secured Access:** Introduces a multi-try login system (`usernameCheck`, `passwordCheck`) before accessing any core functionality. | **Security:** Protects sensitive management operations and authorizes users. |
| **Authorization (RBAC)**| **N/A:** A single anonymous user type (the cashier). | **Role-Based:** Uses `Sign struct` to assign `rankManager` (1: Employee, 2: Manager). Managers gain access to exclusive tools. | **Control:** Restricts Employee access to specific tasks, ensuring data integrity. |
| **Data Structure** | **Primitive:** Used primitive 2D integer arrays to store product IDs and prices. Static menu display. | **Modular Structs:** Implements `Items struct` to store `ID`, `Name`, and `Price`. | **Critical:** Menu display (`menuItems`) now iterates through data dynamically. V1 display was independent of the backend data. |
| **Input Validation** | **Minimal:** Basic checks on item count. Incorrect inputs often caused unexpected behavior. | **Robust:** Uses standard libraries (`limits`) to handle `cin.ignore()` and input clearing. Validates choice numbers and ranks rigorously. | **Stability:** prevents the application from crashing when users enter non-integer data. |
| **User Interface (UI)** | **Static Display:** The menu was a set of non-iterative output statements. | **Dynamic Display:** The menu clears before showing, uses consistent delimiters, and includes startup splash screen prompts (`getchar`). | **Usability:** A more professional, organized, and reliable user experience. |
| **Workflow** | **Linear:** Executed one transaction and prompted to restart or exit. | **Recursive Menu:** The application loops back to the Main Menu after operations, designed for continuous use. | **Efficiency:** Users can log out, manage employees, and switch tasks without restarting the application. |

---

## 📌 New V2 Exclusives (Management Features)

The primary achievement of V2 is the creation of the `System` menu, providing authorized users (Managers) with tools unavailable in V1.

### 🛠️ Menu Management (CRUD)
Managers (Rank 1 & 2) now have complete control over the dynamic product database. The static `Items` structure can support up to 100 products.

* **Show Menu:** Displays all products, prices, and IDs directly from the structure array.
* **Add Item:** Allows Managers to enter a dynamic name (supports spaces via `getline`) and price to populate a new slot in the `Items` array.
* **Update Item:** Permits editing either the Name or the Price of an existing product.
* **Delete Item:** Removes an item from the structure array and shifts subsequent items to prevent array fragmentation.

### 👤 User/Employee Management (Manager Rank 2 Only)
A new tier of permission was introduced to control system access for other employees.

* **Add Employee:** Registers new users with a Username, Password (legacy feature), and Authorization Rank (1 or 2).
* **Kick Employee:** Removes a low-ranking Employee (Rank 1) permanently. *Managers are protected from this feature.*
* **Promotion:** Changes an existing Rank 1 Employee into a Rank 2 Manager.

---

## 📈 Architecture Note

V2 represents a necessary structural migration to move the procedural foundation into a managed application. By minimizing globals and emphasizing function encapsulation, the code becomes more maintainable. V2 focuses primarily on **Authorization and CRUD Operations** before the complete transition to modular, Object-Oriented design patterns (V3).

---
