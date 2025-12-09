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
