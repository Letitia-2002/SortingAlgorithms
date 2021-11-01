#include <iostream>

using namespace std;




int main()
{

    int* size_array = new int;
    int * save = new int;

    cout << "input the size of the array " << endl;
    cin >> *(size_array);

    int* value = new int [size_array[0]];

    cout << endl;

    for(int i = 0; i < size_array[0]; i++)
    {

        cout << "enter value" << endl;
        cin >> *(value + i);

    }



      for (int i = 0, j = 1; j < *size_array; i++, j++)
   {
       int a = value[i];
       int b = value[j];

       if(a > b)
       {
           *save = value[i];
           value[i] = value[j];
           value[j] = *save;
       }

       if (j == (*size_array -1))
       {
           for (int m = 0, n = 1;; m++, n++)
           {
               int c = value[m];
               int d = value[n];

               if (c > d)
               {
                   i = -1;
                   j = 0;
                   break;
               }

               if (n == (*size_array -1))
               {
                   j = 10;
                   break;
               }


           }
        }


    }

    cout << endl << endl << "the sorted values are: ";

   for (int i = 0; i < *size_array; i++)
   {
       cout << value[i] << ", ";
   }

   delete[] value;
   delete size_array;
   delete save;



}

