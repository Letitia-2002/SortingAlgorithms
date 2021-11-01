#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sizeArray;

    int smallerValue;
    int savedValue;


    cout << "input the size of the array\n";
    cin >> sizeArray;

    vector<int> arrayList(sizeArray);

    cout << endl << endl;

    for(int i = 0; i < sizeArray; i++)
    {
        cout << "enter value ;\t";
        cin >> arrayList[i];
        cout << endl;
    }


    cout << "the values to sort are ; ";

    for(int i = 0; i < sizeArray; i++)
    {
        cout << arrayList[i] << ", ";
    }


    for(int i = 0; i < sizeArray; i++)
    {
        smallerValue = arrayList[i];
        int j = i;
        j++;

        while(j < sizeArray)
            {

                if(smallerValue > arrayList[j])
                    {
                        smallerValue = arrayList[j];
                        savedValue = j;
                        j++;

                        continue;
                    }

                else j++;

            }

        if(smallerValue < arrayList[i])
            {
                arrayList[savedValue] = arrayList[i];
                arrayList[i] = smallerValue;

                cout << "\nthe value of smallerValue" << smallerValue;
                cout << endl;

            }


    }

    cout << endl;
    cout << endl;

    cout << "the sorted values are; ";

    for(int i = 0; i < sizeArray; i++)
    {
        cout << arrayList[i] << ", ";
    }


}
