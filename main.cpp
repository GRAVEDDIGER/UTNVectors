#include <iostream>
using namespace std;

/*
CONSTANTS
*/
const int N_PRODUCTS = 5;

/*
FUNCTIONS
*/
void clearArray(int workingArray[], int lengthArray)
{
    for (size_t i = 0; i < lengthArray; i++)
    {
        workingArray[i] = 0;
    }
}
int askQuestion(char question[])
{
    int answer;
    cout << question << endl;
    cin >> answer;
    return answer;
}
char askQuestionChar(string question)
{
    char answer;
    cout << question << endl;
    cin >> answer;
    return answer;
}

void loadBatch(int price[], bool discount[], int iterations)
{
    int productCode;
    char discoutnChar;
    for (size_t i = 0; i < iterations; i++)
    {

        productCode = askQuestion("Ingrese el codigo del producto (1-1500)");
        price[productCode - 1] = askQuestion("Ingrese el precio del producto");
        discoutnChar = askQuestionChar("Aplica descuento (S/N)");
        if (discoutnChar == 'S' || discoutnChar == 's')
        {
            discount[productCode - 1] = 1;
        }
        else if (discoutnChar == 'N' || discoutnChar == 'n')
        {
            discount[productCode - 1] = 0;
        }
    }
    cout << "****************************************************************" << endl;
}
int productCodeMostSales(int vectorSales[])
{
    int salesAccu = 0, code = 0;
    for (int i = 0; i < N_PRODUCTS; i++)
    {
        if (vectorSales[i] > salesAccu)
        {
            salesAccu += vectorSales[i];
            code = i;
        }
    }
    return code;
}
void processBatch(int price[], bool discounts[])
{
    int discountCode = 0, productCode = 0, totalSales = 0, totalDiscounts = 0, amount = 0;
    int vectorProductPost[N_PRODUCTS], vectorProductSeller[N_PRODUCTS], vectorProductSales[N_PRODUCTS];
    clearArray(vectorProductPost, N_PRODUCTS);
    clearArray(vectorProductSeller, N_PRODUCTS);
    clearArray(vectorProductSales, N_PRODUCTS);
    while (discountCode >= 0)
    {
        discountCode = askQuestion("Ingrese el codigo de descuento (1-5): ");
        if (discountCode >= 0)
        {
            totalSales++;
            productCode = askQuestion("Ingrese el codigo de producto (1-1500)");
            amount = askQuestion("Cantidad vendida:");
            vectorProductPost[productCode - 1] = askQuestion("Ingrese el codigo de la publicacion (4 digitos no correlativos)");
            vectorProductSeller[productCode - 1] = askQuestion("Ingrese el codigo del Vendedor (1-300)");
            vectorProductSales[productCode - 1] += price[productCode - 1] * amount;
            if (discounts[productCode - 1] == 1)
            {
                totalDiscounts += price[productCode - 1] * amount;
            }
        }
        cout << "****************************************************************" << endl;
    }

    cout << "Importe total al que se le aplicaron descuentos: " << totalDiscounts << endl;
    cout << "Codigo de producto con mayor monto de ventas: " << productCodeMostSales(vectorProductSales) + 1 << endl;
}

/*
MAIN
*/
int main()
{
    int productPrice[N_PRODUCTS];     //= {111, 222, 333, 444, 555};
    bool productDiscount[N_PRODUCTS]; //= {true, true, true, false, false};
    clearArray(productPrice, N_PRODUCTS);
    loadBatch(productPrice, productDiscount, N_PRODUCTS);
    processBatch(productPrice, productDiscount);
    return 0;
}
