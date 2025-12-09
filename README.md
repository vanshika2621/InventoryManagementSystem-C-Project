# Inventory Management System in C

A simple **console-based Inventory Management System** written in the C programming language. This program allows users to add, view, update, delete, and search products, and finally save all data into a CSV file.

----------------------------------------------------------------------------------------------------------------------------------------

## Project Report Overview:-


Abstract:-
This project implements a simple Inventory Management System using the C programming language. It allows users to add products, view inventory, update stock, delete products, search for products and save the inventory data to a file. The project demonstrates the use of arrays, functions, loops, file handling, and string manipulation.



Problem Definition:-
The goal of this project is to design and implement a console-based Inventory Management System. The system must allow users to manage product records efficiently with options to add, update, delete, search, and store inventory records permanently.


System Design:-
The system is divided into the following functional modules:
•1. Add Product
•2. View Inventory
•3. Update Stock
•4. Delete Product
•5. Search Product
•6. Save & Exit


Algorithm (Simplified):-
•1. Display menu options.
•2. Take user choice.
•3. Perform selected operation.
•4. Repeat until Save & Exit is chosen.


Testing & Results:-
The system was tested using multiple product entries. All operations such as add, update, delete, and search worked successfully. The inventory file was correctly saved in CSV format.


Conclusion & Future Scope:-
The Inventory Management System works efficiently for small businesses. Future improvements can include database connectivity, login authentication, graphical user interface, and barcode scanning.


----------------------------------------------------------------------------------------------------------------------------------

## 📌 Features

- Add new products
- View all inventory items
- Update product stock
- Delete existing products
- Search products by name
- Save inventory to `inventory.csv`
- Uses arrays and file handling in C

----------------------------------------------------------------------------------------------------------------------------------

## 🛠 Technologies Used

- Language: C
- Compiler: GCC / Turbo C / VS Code C Compiler
- File Handling: CSV File (`inventory.csv`)

------------------------------------------------------------------------------------------------------------------------------------

## 🧠 Algorithm

1. Start
2. Initialize productNames, productQuantities, productPrices arrays
3. Set count = 0

4. Repeat until user chooses Exit:
   a. Display Menu
      1. Add Product
      2. View Inventory
      3. Update Stock
      4. Delete Product
      5. Search Product
      6. Save & Exit

   b. Read user choice

   c. If choice == 1 then
        - Input product name, quantity, price
        - If product already exists
            Update quantity and price
          Else
            Add new product
      End If

   d. If choice == 2 then
        - Display all products
      End IF

   e. If choice == 3 then
        - Input product name
        - Update product quantity
      End If

   f. If choice == 4 then
        - Input product name
        - Delete product
      End If

   g. If choice == 5 then
        - Input product name
        - Search and display product details
      End If

   h. If choice == 6 then
        - Save data into file (inventory.csv)
        - Exit program
      End If

   i. If choice is invalid then
        - Display error message
      End If

5. Stop

-----------------------------------------------------------------------------------------------------------------------------------

## 🔄 Flowchart (Text Representation)

START
↓
Display Menu
↓
Enter Choice
↓
Is Choice = 1?
├─ Yes → Add Product → Menu
├─ No
↓
Is Choice = 2?
├─ Yes → View Inventory → Menu
├─ No
↓
Is Choice = 3?
├─ Yes → Update Stock → Menu
├─ No
↓
Is Choice = 4?
├─ Yes → Delete Product → Menu
├─ No
↓
Is Choice = 5?
├─ Yes → Search Product → Menu
├─ No
↓
Is Choice = 6?
├─ Yes → Save to File → Exit
├─ No → Invalid Choice → Menu

-------------------------------------------------------------------------------------------------------------------------------------------

## ✅ Input Validation

----------------------------------------------------------
|Input	           |          Validation Done            |
|--------------------------------------------------------|
|Menu choice	   |      Checks if between 1 to 6       |
|Product name	   |      Checked using strcmp()         |
|Quantity	   |      Must be integer                | 
|Price	           |      Must be float                  |
|Duplicate Product |	  Existing name updates quantity |
|File Save	   |      fp == NULL error checked       |
----------------------------------------------------------

✅ The program ensures:

xNo duplicate product entries

xInvalid menu choices are rejected

xFile open errors are handled

-----------------------------------------------------------------------------------------------------------------------------------------

## ✅ Sample Output

▶ Main Menu:
---------------------------------
   INVENTORY MANAGEMENT SYSTEM
---------------------------------
1. Add Product
2. View Inventory
3. Update Stock
4. Delete Product
5. Search Product
6. Save & Exit
---------------------------------
Enter your choice: 1


▶ Add Product:
Enter Product Name: Pen
Enter Quantity: 10
Enter Price: 5.50

Product 'Pen' added successfully!


▶ View Inventory:
-----------------------------------------
Product         Quantity    Price
-----------------------------------------
Pen             10          5.50
-----------------------------------------


▶ Search Product:
Enter Product Name to Search: Pen

Product Found!
Name: Pen
Quantity: 10
Price: 5.50


▶ Save & Exit:
Inventory saved to inventory.csv
Exiting program...

----------------------------------------------------------------------------------------------------------------------------------------

## 🛠 System Architecture Structure

+---------------------------+
|        USER               |
+------------+--------------+
             ↓
+---------------------------+
|    MAIN MENU (main)       |
+------------+--------------+
             ↓
+---------------------------------------------+
| Functional Modules                          |
|---------------------------------------------|
| addProduct()                                |
| viewInventory()                             |
| updateStock()                               |
| deleteProduct()                             |
| searchProduct()                             |
| saveAndExit()                               |
+---------------------------------------------+
             ↓
+---------------------------+
| Global Arrays (Memory)    |
| productNames[]            |
| productQuantities[]       |
| productPrices[]           |
+---------------------------+
             ↓
+---------------------------+
|  File Storage (CSV File)  |
|   inventory.csv           |
+---------------------------+

-------------------------------------------------------------------------------------------------------------------------------------------

##  Project Code

    #include <stdio.h>
    #include <string.h>

    #define MAX 100

    // Global Arrays
    char productNames[MAX][50];
    int productQuantities[MAX];
    float productPrices[MAX];

    int count = 0;   // Total number of products

    // Function Declarations
    void addProduct();
    void viewInventory();
    void updateStock();
    void deleteProduct();
    void searchProduct();
    void saveAndExit();

    int main()
    {
    int choice;

    while (1)
    {
        printf("\n---------------------------------");
        printf("\n   INVENTORY MANAGEMENT SYSTEM");
        printf("\n---------------------------------");
        printf("\n1. Add Product");
        printf("\n2. View Inventory");
        printf("\n3. Update Stock");
        printf("\n4. Delete Product");
        printf("\n5. Search Product");
        printf("\n6. Save & Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addProduct();
        else if (choice == 2)
            viewInventory();
        else if (choice == 3)
            updateStock();
        else if (choice == 4)
            deleteProduct();
        else if (choice == 5)
            searchProduct();
        else if (choice == 6)
        {
            saveAndExit();
            break;
        }
        else
            printf("\nInvalid choice! Try again.");
    }

    return 0;
    }

    //  Add Product
    void addProduct()
    {
    char name[50];
    int qty;
    float price;
    int found = 0;

    printf("\nEnter Product Name: ");
    scanf("%s", name);

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    printf("Enter Price: ");
    scanf("%f", &price);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(productNames[i], name) == 0)
        {
            productQuantities[i] += qty;
            productPrices[i] = price;
            printf("\nProduct '%s' updated successfully!\n", name);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        strcpy(productNames[count], name);
        productQuantities[count] = qty;
        productPrices[count] = price;
        count++;
        printf("\nProduct '%s' added successfully!\n", name);
    }
    }

    //  View Inventory
    void viewInventory()
    {
    if (count == 0)
    {
        printf("\nInventory is empty.\n");
        return;
    }

    printf("\n-----------------------------------------");
    printf("\n%-15s %-10s %-10s", "Product", "Quantity", "Price");
    printf("\n-----------------------------------------");

    for (int i = 0; i < count; i++)
    {
        printf("\n%-15s %-10d %-10.2f",
               productNames[i],
               productQuantities[i],
               productPrices[i]);
    }
    printf("\n-----------------------------------------\n");
    }

    //  Update Stock
    void updateStock()
    {
    char name[50];
    int newQty, found = 0;

    printf("\nEnter Product Name to Update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(productNames[i], name) == 0)
        {
            printf("Enter New Quantity: ");
            scanf("%d", &newQty);
            productQuantities[i] = newQty;
            printf("\nStock updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct not found!\n");
    }

    //  Delete Product
    void deleteProduct()
    {
    char name[50];
    int found = 0;

    printf("\nEnter Product Name to Delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(productNames[i], name) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(productNames[j], productNames[j + 1]);
                productQuantities[j] = productQuantities[j + 1];
                productPrices[j] = productPrices[j + 1];
            }
            count--;
            printf("\nProduct deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct not found!\n");
    }

    //  Search Product
    void searchProduct()
    {
    char name[50];
    int found = 0;

    printf("\nEnter Product Name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(productNames[i], name) == 0)
        {
            printf("\nProduct Found!");
            printf("\nName: %s", productNames[i]);
            printf("\nQuantity: %d", productQuantities[i]);
            printf("\nPrice: %.2f\n", productPrices[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct not found!\n");
    }
 
    //  Save & Exit
    void saveAndExit()
    {
    FILE *fp;
    fp = fopen("inventory.csv", "w");

    if (fp == NULL)
    {
        printf("\nError saving file!\n");
        return;
    }

    fprintf(fp, "Product,Quantity,Price\n");

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%d,%.2f\n",
                productNames[i],
                productQuantities[i],
                productPrices[i]);
    }

    fclose(fp);

    printf("\nInventory saved to inventory.csv");
    printf("\nExiting program...\n");
}
