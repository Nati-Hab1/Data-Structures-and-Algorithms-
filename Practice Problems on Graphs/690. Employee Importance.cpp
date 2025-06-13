#include <vector>
using namespace std;
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        for (int i = 0; i < employees.size(); ++i)
        {
            if (employees[i]->id == id)
            {
                return DFS(employees, employees[i]);
            }
        }
        return 0;
    }

    int DFS(vector<Employee *> &EmpList, Employee *emp)
    {
        int result = emp->importance;
        for (int e : emp->subordinates)
        {
            for (int i = 0; i < EmpList.size(); ++i)
                if (EmpList[i]->id == e)
                    result += DFS(EmpList, EmpList[i]);
        }
        return result;
    }
};
