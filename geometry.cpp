#include <iostream>
#include <vector>

std::vector<int> makePr(std::vector<int> arrow, std::vector<int> lower);
double sclaledMultiplicate(std::vector<int> vector1, std::vector<int> vector2);
bool checkLinear(std::vector<int> vector1, std::vector<int> vector2, std::vector<int> vector3);
std::vector<int> substract(std::vector<int> vector1, std::vector<int> vector2);

int main()
{
    std::vector <int> vector1 = { 2, -3, 1 }; //
    std::vector <int> vector2 = { 3, -1, 5 }; //
    std::vector <int> vector3 = { 1, -4, 3 }; //

    if (checkLinear(vector1, vector2, vector3))
    {
        std::vector <int> e1 = { 0, 0, 0 };
        std::vector <int> e2 = { 0, 0, 0 };
        std::vector <int> e3 = { 0, 0, 0 };

        e1 = vector1;

        e2 = substract(vector2, makePr(vector2, vector1));

        e3 = substract(substract(vector3, makePr(vector3, vector1)), makePr(vector3, vector2));

        std::cout << "e1 = {" << e1[0] << ", " << e1[1] << ", " << e1[2] << " }\n";
        std::cout << "e2 = {" << e2[0] << ", " << e2[1] << ", " << e2[2] << " }\n";
        std::cout << "e3 = {" << e3[0] << ", " << e3[1] << ", " << e3[2] << " }\n";
    }//endif



    
   
}


std::vector<int> substract(std::vector<int> vector1, std::vector<int> vector2)
{
    std::vector<int> result = { 0, 0, 0 };
   
    for (int i = 0; i < 3; ++i)
    {
        result[i] = vector1[i] - vector2[i];
    }

    return result;
}


std::vector<int> makePr(std::vector<int> arrow, std::vector<int> lower)
{
    std::vector<int> pr = { 0, 0, 0 };

    for (int i = 0; i < 3; ++i)
        pr[i] = sclaledMultiplicate(arrow, lower) / sclaledMultiplicate(lower, lower) * lower[i];

    return pr;
}

double sclaledMultiplicate(std::vector<int> vector1, std::vector<int> vector2)
{
    double result = 0;

    for (int i = 0; i < 3; ++i)
        result += vector1[i] * vector2[i];

    return result;
}

bool checkLinear(std::vector<int> vector1, std::vector<int> vector2, std::vector<int> vector3)
{
    int matrix[3][3];

    for (int i = 0; i < 3; ++i)
        matrix[0][i] = vector1[i];
    for (int i = 0; i < 3; ++i)
        matrix[1][i] = vector2[i];
    for (int i = 0; i < 3; ++i)
        matrix[2][i] = vector3[i];

    for (int i = 1; i < 3; ++i)
    {
        if (matrix[0][0] == matrix[i][0])
        {
            for (int j = 0; j < 3; ++j)
            {
                matrix[i][j] -= matrix[0][j];
            }
        }//endif
        else
        {
            if ((matrix[0][0] == -matrix[i][0]) || (-matrix[0][0] == matrix[i][0]))
            {
                for (int j = 0; j < 3; ++j)
                {
                    matrix[i][j] += matrix[0][j];
                }
            }//endif
            else
            {
                if (matrix[0][0] * matrix[i][0] > 0)
                {
                    
                }
            }//endelse
        }//endelse
        
    }

    return true;
}



