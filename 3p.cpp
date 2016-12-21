#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

int main()
{
    int numOfElement = 0;       // Total number of element in the set. Initialize with zero and later will be reset by user.
    int sum = 0;                // Total sum of the elements in the set.
    int n = 0;                  // Number of new subset can be created.
    int newSum = 0;             // NewSum = t. new sum for the subset(s). using float because the result might have point.
    float conditionT = 0.00;    // Checking if t is having point or no.

    bool loop = true;

    do{
        system("cls");
        // Input from user of how many number in the sets they want to enter.
        while(loop){
            cout << "Enter the number of element you want to insert into the set: ";
            cin >> numOfElement;
            if (numOfElement<0 || numOfElement%3 != 0){
                cout << "The number you entered is not applicable for 3 partition program.\n";
            }
            else
                loop = false;
        }

        int r[numOfElement];    // initialize array with the size of given input from user.
        int element = 0;        // element will be use to get input of element from the user.
        cout << "Enter the set accordingly: \n";
        // Getting the element from user.
        for (int m=0; m<numOfElement; m++){
            cin >> element;
            r[m] = element;
        }
        cout << endl;
        system("cls");

        int copyElement[numOfElement];  // Store the element of the sets to use in modification of calculation.
        // Copy the element in another array.
        for (int i=0; i<numOfElement; i++){
            copyElement[i] = r[i];
        }

        // Print the set:
        cout << "Set A = {";
        for (int p=0; p<numOfElement; p++){
            if (p == numOfElement-1){
                cout << r[p] << "}\n";
            }
            else
                cout << r[p] << ", ";
        }

        // Step 1: Calculate the total number of element in the set.
        // Given by user.
        cout << "Total number of element(s) in the set: " << numOfElement << endl;

        // Step 2: Calculate the total sum of the element(s) in the set.
        for(int i=0; i<numOfElement; i++){
            sum += r[i];
        }
        cout << "Sum of the set = " << sum << endl;

        // Step 3: Calculate the number of new subsets that will be created.
        n = numOfElement/3;
        cout << "Number of new subsets: " << n << endl;

        // Step 4: Calculate t, the new sum for all the subsets created.
        newSum = sum/n;
        conditionT = (float)sum/n;
        conditionT -= newSum;

        cout << endl;
        // Checking condition for 3 partition.
        if (conditionT == 0.00){
            // *********************** Starting 3 partition process **************************************************
            // new partition has n number with t number of sum.
            int e1=0, e2=0, e3=0;
            // so it will loop n number:
            for (int i=0; i<n; i++){
                cout << "Subset[" << i+1 << "]:";
                if (i == 0){
                    e1 = copyElement[i];
                    copyElement[i] = 0;
                    // Finding the t-sum of 3 elements from the set.
                    while (e1+e2+e3 != newSum){
                        for (int j=1; j<numOfElement; j++){
                            e2 = copyElement[j];
                            for (int k=n; k<numOfElement; k++){
                                e3 = copyElement[k];
                                if (e1+e2+e3 == newSum){
                                    e3 = copyElement[k];
                                    copyElement[j] = 0;
                                    copyElement[k] = 0;
                                    k = numOfElement;
                                    j = numOfElement;
                                }
                            }
                        }
                    }
                    cout << e1 << ", " << e2 << ", " << e3 << endl;
                }
                else{
                    // for second and afterwards subsets. finding the first element.
                    for (int p=0; p<numOfElement; p++){
                        if (copyElement[p] != 0){
                            e1 = copyElement[p];
                            copyElement[p] = 0;
                            p = numOfElement;
                        }
                    }
                    while (e1+e2+e3 != newSum){
                        for (int j=0; j<numOfElement; j++){
                            e2 = copyElement[j];
                            for (int k=n; k<numOfElement; k++){
                                e3 = copyElement[k];
                                if (e1+e2+e3 == newSum){
                                    e3 = copyElement[k];
                                    copyElement[j] = 0;
                                    copyElement[k] = 0;
                                    k = numOfElement;
                                    j = numOfElement;
                                }
                            }
                        }
                    }
                    cout << e1 << ", " << e2 << ", " << e3 << endl;

                }

            }
            // *******************************************************************************************************
        }
        else{
            cout << "3 Partition is not computable with the given set." << endl;
            cout << "Because of the sum for the new subset is not balanced. \n";
        }

        char program;
        bool restart;
        do{
            cout << "Restart the program? (y or n): ";
            cin >> program;
            if (program == 'y' || program == 'Y' || program == 'n' || program == 'N')
                restart = false;
            else
                restart = true;
        }while(restart);

        if (program == 'y' || program == 'Y')
            loop = true;
        else
            loop = false;

    }while(loop);
}
