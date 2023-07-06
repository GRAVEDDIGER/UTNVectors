# UTN CYBERMONDAY EXERCICE

Un reconocido sitio en Internet de compras y ventas cuenta con la siguiente información de todas sus publicaciones realizadas durante el pasado CyberMonday:
* Código de publicación (número entero no correlativo de cinco cifras).
* Código de producto (número del 1 al 1500).
* Ventas concretadas (cantidad, número entero).
* Código de vendedor (1 a 300).
* Código de descuento (1 a 5).
### Este lote termina con número de descuento negativo.


Además cuenta con la información de los 1500 productos, por cada uno se conoce:

* Código de producto (1 a 1500).
* Precio por unidad.
* Aplica descuento (booleano: 1 aplica descuento, 0 no aplica descuento).
### Este lote se ingresa ordenado por número de producto.

A partir de dichos datos se desea conocer:

a - El monto total sobre el cual se aplicaron descuentos.

b - El código de producto que haya acumulado mayor monto en ventas.

## FUNCTIONS

```c++
void clearArray(int workingArray[], int lengthArray)
{
    for (size_t i = 0; i < lengthArray; i++)
    {
        workingArray[i] = 0;
    }
}
```
This function initilizes the working array needs 2 params 
1 - the array
2 - the length of the array 


```c++
int askQuestion(char question[])
{
    int answer;
    cout << question << endl;
    cin >> answer;
    return answer;
}
```
This function shows in console the string contained on the char[] named question and returns the answer as an integer

```c++
char askQuestionChar(string question)
{
    char answer;
    cout << question << endl;
    cin >> answer;
    return answer;
}

```
This function shows in console the string contained on the char[] named question and returns the answer as a char array

```c++
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
```
This function takes 3 params 
1 - A int vector named price
2 - A int vector named discount 
3 - An int that represents the number of iterations for this function.
During the iterations the function will fill the provided vectors with data entred by console intervention

```c++
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

```
This function returns an integer that represents the product code -1