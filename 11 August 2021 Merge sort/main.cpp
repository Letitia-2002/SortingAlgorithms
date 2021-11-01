#include <iostream>
#include <vector>


namespace displayOderNameSpace
{
    int arraySize;
    int numbTimes;
    int q;
    int r = 0;
    int base_2 = 2;
    int ind = 0;
    int addon;
    int limit;
}

namespace groupingNamespace
{
    int groups;
    int groupA_1;
    int groupA_2;
    int groupB_1;
    int groupB_2;

    int first_index;
    int jump;
    int sizeToSort;
    int sum;
    int rem;
    int limite;
    int n;
    int numb;
}

void sortFunction(int a_1, int a_2, int b_1, int b_2, std::vector<int> & arrayList);


void userInput() // GOOD TO GO
{
    using namespace displayOderNameSpace;

    std::cout << "enter the size of the array " << std::endl;
    std::cin >> arraySize;
}

void inputValues(std::vector<int> & arrayList) //GOOD TO GO
{
    std::cout << std::endl;

    for(int i = 0; i < int(arrayList.size()); i++)
    {
        std::cout << "enter value of arrayList" << " [" << i << "] :" << std::endl;
        std::cin >> arrayList[i];
    }

    std::cout << std::endl;
    std::cout << std::endl;

}

void displayOder(std::vector<int> arrayList, int arraySize) // GOOD TO GO
{

    using namespace displayOderNameSpace;

    q = arraySize;

    for(int i = 0;; i++)
    {
        if(r != 1) r = q % 2;
        q /= 2;
        limit = q;
        addon = arraySize - (base_2*q);
        if ((base_2*q) > arraySize) addon = 0;
        limit = q + addon;

        for (int j = 1; j <= limit; j++)
        {

            for(int k = 0; k < base_2; k++)
            {

                if (ind == arraySize) continue;
                std::cout << arrayList.at(ind) << ",";
                ind++;
            }

            std::cout << "\t\t";

        }

        std::cout << std::endl;

        ind = 0;
        base_2 *= 2;
        numbTimes = i + 1;

        if((q == 1) & (r == 0)) break;

       long int sum = r + q;

        if ((sum % 2 == 0) & (r != 0))
        {
            q += r;
            r--;
        }

    }

     std::cout << std::endl;
   // std::cout <<  numbTimes << std::endl;
}

int numbTimes(int arraySize1) // GOOD TO GO
{
    int q = arraySize1;
    int r = 0;
    int numb;

    for(int i = 0;; i++)
    {
        if(r != 1) r = q % 2;
        q /= 2;

        numb = i + 1;

        if((q == 1) & (r == 0)) break;

       long int sum = r + q;

        if ((sum % 2 == 0) & (r != 0))
        {
            q += r;
            r--;
        }
    }

    return numb;
}

void groupingFunction(int arraySize,  std::vector<int> & arrayList) // GOOD TO GO
{

    using namespace groupingNamespace;


    numb = numbTimes(displayOderNameSpace::arraySize);

    groups = displayOderNameSpace::arraySize;
    rem = 0;

    first_index = 0;
    n = 1;
    jump = n - 1;

    for(int i = 0; i <= numb; i++)
    {

        if(rem!= 1) rem = groups % 2;
        groups /= 2;

        for(int j = 1; j <= groups; j++)
        {

            groupA_1 = first_index;
            groupA_2 = groupA_1 + jump;

            groupB_1 = groupA_2 + 1;
            groupB_2 = groupB_1 + jump;

            first_index = groupB_2 + 1;

            sortFunction(groupA_1, groupA_2, groupB_1, groupB_2, arrayList);

        }

        first_index = 0;
        n *= 2;
        jump = n - 1;

        if((groups == 1) & (rem== 0)) break;

        sum = rem + groups;

        if ((sum % 2 == 0) & (rem != 0))
        {
            groups += rem;
            rem--;
        }

    }
}


void shiftFunction(int start_index, int end_index, std::vector<int> & arrayList) // GOOD TO GO
{

    int arraySize = sizeof(arrayList) / sizeof(int);

    int tempSave = arrayList[end_index];



    for(int i = end_index, j = (end_index - 1);; i--, j--)
    {
        if ((i == displayOderNameSpace::arraySize) | (j == displayOderNameSpace::arraySize))
        {
            continue;
        }
        arrayList[i] = arrayList[j];

        if (j == start_index)
        {
            arrayList[j] = tempSave;
            break;
        }

    }

    for(int i = 0;; i++)
    {
        if(i == displayOderNameSpace::arraySize) break;
        std::cout << arrayList[i] << ", ";

    }

    std::cout << "\n";
    std::cout << "\n";
}


void sortFunction(int a_1, int a_2, int b_1, int b_2, std::vector<int> & arrayList) // GOOD TO GO
{
    int i = a_1;
    int j = b_1;
    int B = j;

    for(;;)
    {
        if ((i == displayOderNameSpace::arraySize) | (j == displayOderNameSpace::arraySize))
        {
            i++;
            if((i == j) & (j == B)) break;
            continue;
        }
        if(arrayList[j] < arrayList[i])
        {
            shiftFunction(i,j, arrayList);
            i++;
            if(j != b_2) B = ++j;
        }
        else i++;
        if((i == j) & (j == B)) break;
    }
}

int main()
{
    using namespace displayOderNameSpace;

    userInput();

    std::vector<int> arrayList(arraySize);


    inputValues(arrayList);

    for(int i = 0;; i++)
    {
        if(i == displayOderNameSpace::arraySize) break;
        std::cout << arrayList[i] << ", ";

    }

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    groupingFunction(arraySize, arrayList);

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    for(int i = 0;; i++)
    {
        if(i == displayOderNameSpace::arraySize) break;
        std::cout << arrayList[i] << ", ";

    }


}
