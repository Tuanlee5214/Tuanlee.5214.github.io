#include<iostream>
#include<memory>

using namespace std;

class Matran
{
public:
    void setRow(int r)
    {
        numberofrow = r;
    }

    int getRow() 
    {
        return numberofrow;
    }

    void setColumn(int c)
    {
        numberofcolumn = c;
    }

    int getColumn() 
    {
        return numberofcolumn;
    }
    
    void setMatran(int a[][100], int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matran[i][j] = a[i][j];
            }
        }
    }
    
    int getMatran(int t, int z)
    { 
        return matran[t][z];    
    } 
private:
    int numberofrow;
    int numberofcolumn;
    int matran[100][100];
};

class Tichmatran
{
public:
   void TichMatran(Matran* Mt1, Matran* Mt2, int result[][100])
   {
        row1 = Mt1->getRow();
        column1 = Mt1->getColumn();
        row2 = Mt2->getRow();
        column2 = Mt2->getColumn();
        
        for (int i = 0; i < row1; i++)
        { 
            for (int j = 0; j < column2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < row2; k++)
                {
                    result[i][j] += Mt1->getMatran(i, k) * Mt2->getMatran(k, j);
                }
            }
        }
   }

   void Printmatrix(int a[][100], int l, int m)
   { 
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }     
   }

private:
   int column1;
   int row1;
   int column2;
   int row2;
};
int main()
{
    cout << "- De nhan hai ma tran, thi ban can chu y den thu tu nhan hai ma tran." << endl;
    cout << "- Dong thoi ban can chu y den so hang va cot neu ban muon nhan hai ma tran" << " " << "ko la ma tran vuong." << endl;
    cout << "- Dieu kien la cot cua ma tran dung truoc phai bang hang cua ma tran dung sau trong phep nhan." << endl;

    int number;
    int x[100][100];
    int y[100][100];

    Matran* Matran1 = new Matran;
    Matran* Matran2 = new Matran;

    cout << "Nhap du lieu cho ma tran 1: " << endl;
    cout << "So hang: ";
    cin >> number;
    Matran1->setRow(number);
    cout << "So cot: ";
    cin >> number;
    Matran1->setColumn(number);

    cout << "Nhap gia tri ma tran: " << endl;

    for (int i = 0; i < Matran1->getRow(); i++)
    {
        for (int j = 0; j < Matran1->getColumn(); j++)
        {
             cin >> x[i][j];
        }
    }
    
    Matran1->setMatran(x, Matran1->getRow() , Matran1->getColumn());

    cout << "Nhap du lieu cho ma tran 2: " << endl;
    cout << "So hang: ";
    cin >> number;
    Matran2->setRow(number);
    cout << "So cot: ";
    cin >> number;
    Matran2->setColumn(number);

    cout << "Nhap gia tri ma tran: " << endl;

    for (int i = 0; i < Matran2->getRow(); i++)
    {
        for (int j = 0; j < Matran2->getColumn(); j++)
        {
             cin >> y[i][j];
        }
    }
    
    Matran2->setMatran(y, Matran2->getRow() , Matran2->getColumn());
    
    Tichmatran* Tichmt = new Tichmatran;
    int result[100][100];
    cout << "Ma tran tich cua 2 ma tran la: " << endl;
    Tichmt->TichMatran(Matran1, Matran2, result);
    Tichmt->Printmatrix(result, Matran1->getRow(), Matran2->getColumn());

    delete Matran1;
    delete Matran2;
    delete Tichmt;
}
